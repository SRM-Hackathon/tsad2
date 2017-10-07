
import picamera
camera.rotation = 180
camera.start_preview()
sleep(10)
camera.stop_preview


from picamera import PiCamera
from time import sleep
camera = PiCamera()
camera.start_preview(alpha=100)
sleep(10)
camera.stop_preview()



