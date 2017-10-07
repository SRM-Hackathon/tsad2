
import argparse
import cv2
import numpy as np
import scipy.io as sio
import time

frame = None

# returns red and green color LED position
#tracks color on intensity thresholded spots
def colorTracking(thresholdedImage, originalImage):
    # LED positions
    redLEDPos = (-1,-1)
    greenLEDPos = (-1,-1)

    #convert color from BGR to HSV
    hsvThresholdedImage = cv2.cvtColor(thresholdedImage, cv2.COLOR_BGR2HSV)

    #define lower and upper limit of hue range for red color
    lowerRedHueRange = cv2.inRange(hsvThresholdedImage, np.array([0, 100, 100]), np.array([10, 255, 255]))
    upperRedHueRange = cv2.inRange(hsvThresholdedImage, np.array([160, 100, 100]), np.array([179, 255, 255]))

    #Hue Range for Green
    lowerGreenHue = np.array([50, 50, 120])
    upperGreenHue = np.array([70, 255, 255])
    greenMask = cv2.inRange(hsvThresholdedImage, lowerGreenHue, upperGreenHue)

    #Calculates the weighted sum of two arrays.
    redHueThresholdedImage = cv2.addWeighted(lowerRedHueRange, 1.0, upperRedHueRange, 1.0, 0.0)
    #Blurs an image using a Gaussian filter
    redHueThresholdedImage = cv2.GaussianBlur(redHueThresholdedImage, (9, 9), 2, 2)

    #Blurs an image using a Gaussian filter
    greenHueThresholdedImage = cv2.GaussianBlur(greenMask, (9, 9), 2, 2)

    #find contours in the red hue image formed after weighted adding of lower and upper ranges of red
    redContours = cv2.findContours(redHueThresholdedImage.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2]
    # only proceed if at least one contour was found
    if len(redContours) > 0:
        # find the largest contour in the mask, then use it to compute the minimum enclosing circle and centroid
        maxContour = max(redContours, key=cv2.contourArea)
        M = cv2.moments(maxContour)
        redLEDPos = int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"])

    #find contours in the green hue image formed
    greenContours = cv2.findContours(greenHueThresholdedImage.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2]
    # only proceed if at least one contour was found
    if len(greenContours) > 0:
        # find the largest contour in the mask, then use it to compute the minimum enclosing circle and centroid
        maxContour = max(greenContours, key=cv2.contourArea)
        M = cv2.moments(maxContour)
        greenLEDPos = int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"])

    return redLEDPos, greenLEDPos

#main loop
def posTrack():
    red_x = []
    red_y = []
    green_x = []
    green_y = []

    # construct the argument parser and parse the arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-v", "--video",required=True, help="Path to the video file")
    ap.add_argument("-pf","--posFileName",required=True, help="Path to the mat file")
    args = vars(ap.parse_args())

    # load the video,and setup the mouse callback function
    cap = cv2.VideoCapture(args["video"])
    width = cap.get(3)
    height = cap.get(4)
    if not cap.isOpened():
        print "Fatal Error: Could not open the specified file."
        exit(-1)
    #cv2.namedWindow("VideoFrame")

    # keep looping until the 'q' key is pressed
    while True:
        #read the vide frame by frame
        ret, frame = cap.read()

        if frame is None:
            break
        frameClone = frame.copy()
        #display the frame and wait for a keypress
        #Median Blur: smoothening the images makes median of all the pixels under kernel area and central element= median value.
        frame = cv2.medianBlur(frame,5)
        #Intensity threholding the Main Frame
        thresholdedFrame = cv2.threshold(frame, 160, 255, cv2.THRESH_BINARY)[-1]
        #red and green LED position in Main Video
        redLED, greenLED = colorTracking(thresholdedFrame, frame)

        red_x.append(redLED[0])
        red_y.append(redLED[1])
        green_x.append(greenLED[0])
        green_y.append(greenLED[1])

        key = cv2.waitKey(1) & 0xFF
        # if the 'q' key is pressed, break from the loop
        if key == ord("q"):
            break

    # close all open windows
    cv2.destroyAllWindows()

    return args["posFileName"], red_x, red_y, green_x, green_y, width, height

startTime = time.time()
print startTime
#retrieves red_x, red_y, green_x, green_y
filename, red_x, red_y, green_x, green_y, width, height = posTrack()
print "\n"
print time.time() - startTime
#save the mat file
sio.savemat(filename, mdict={'width':width, 'height': height, 'red_x':red_x, 'red_y':red_y, 'green_x':green_x, 'green_y':green_y})