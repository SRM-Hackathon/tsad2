
#include "stdafx.h"
<? xml version = "1.0" encoding = "utf-8" ? >
<Project DefaultTargets = "Build" ToolsVersion = "15.0" xmlns = "http://schemas.microsoft.com/developer/msbuild/2003">
<ItemGroup Label = "ProjectConfigurations">
<ProjectConfiguration Include = "Debug|Win32">
<Configuration>Debug< / Configuration>
<Platform>Win32< / Platform>
< / ProjectConfiguration>
<ProjectConfiguration Include = "Release|Win32">
<Configuration>Release< / Configuration>
<Platform>Win32< / Platform>
< / ProjectConfiguration>
<ProjectConfiguration Include = "Debug|x64">
<Configuration>Debug< / Configuration>
<Platform>x64< / Platform>
< / ProjectConfiguration>
<ProjectConfiguration Include = "Release|x64">
<Configuration>Release< / Configuration>
<Platform>x64< / Platform>
< / ProjectConfiguration>
< / ItemGroup>
<PropertyGroup Label = "Globals">
<ProjectGuid>{1A2F5D82 - 6345 - 4601 - 8CE8 - 0BF3A1FD8145}< / ProjectGuid>
<RootNamespace>LightDetection_HaarCascade< / RootNamespace>
<WindowsTargetPlatformVersion>10.0.15063.0< / WindowsTargetPlatformVersion>
< / PropertyGroup>
<Import Project = "$(VCTargetsPath)\Microsoft.Cpp.Default.props" / >
<PropertyGroup Condition = "'$(Configuration)|$(Platform)'=='Debug|Win32'" Label = "Configuration">
<ConfigurationType>Application< / ConfigurationType>
<UseDebugLibraries>true< / UseDebugLibraries>
<PlatformToolset>v141< / PlatformToolset>
<CharacterSet>MultiByte< / CharacterSet>
< / PropertyGroup>
<PropertyGroup Condition = "'$(Configuration)|$(Platform)'=='Release|Win32'" Label = "Configuration">
<ConfigurationType>Application< / ConfigurationType>
<UseDebugLibraries>false< / UseDebugLibraries>
<PlatformToolset>v141< / PlatformToolset>
<WholeProgramOptimization>true< / WholeProgramOptimization>
<CharacterSet>MultiByte< / CharacterSet>
< / PropertyGroup>
<PropertyGroup Condition = "'$(Configuration)|$(Platform)'=='Debug|x64'" Label = "Configuration">
<ConfigurationType>Application< / ConfigurationType>
<UseDebugLibraries>true< / UseDebugLibraries>
<PlatformToolset>v141< / PlatformToolset>
<CharacterSet>MultiByte< / CharacterSet>
< / PropertyGroup>
<PropertyGroup Condition = "'$(Configuration)|$(Platform)'=='Release|x64'" Label = "Configuration">
<ConfigurationType>Application< / ConfigurationType>
<UseDebugLibraries>false< / UseDebugLibraries>
<PlatformToolset>v141< / PlatformToolset>
<WholeProgramOptimization>true< / WholeProgramOptimization>
<CharacterSet>MultiByte< / CharacterSet>
< / PropertyGroup>
<Import Project = "$(VCTargetsPath)\Microsoft.Cpp.props" / >
<ImportGroup Label = "ExtensionSettings">
< / ImportGroup>
<ImportGroup Label = "Shared">
< / ImportGroup>
<ImportGroup Label = "PropertySheets" Condition = "'$(Configuration)|$(Platform)'=='Debug|Win32'">
<Import Project = "$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition = "exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label = "LocalAppDataPlatform" / >
< / ImportGroup>
<ImportGroup Label = "PropertySheets" Condition = "'$(Configuration)|$(Platform)'=='Release|Win32'">
<Import Project = "$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition = "exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label = "LocalAppDataPlatform" / >
< / ImportGroup>
<ImportGroup Label = "PropertySheets" Condition = "'$(Configuration)|$(Platform)'=='Debug|x64'">
<Import Project = "$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition = "exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label = "LocalAppDataPlatform" / >
< / ImportGroup>
<ImportGroup Label = "PropertySheets" Condition = "'$(Configuration)|$(Platform)'=='Release|x64'">
<Import Project = "$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition = "exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label = "LocalAppDataPlatform" / >
< / ImportGroup>
<PropertyGroup Label = "UserMacros" / >
<PropertyGroup Condition = "'$(Configuration)|$(Platform)'=='Debug|x64'">
<ExecutablePath> C:\CNTT\DoAn1_v2\opencv\build\x64\vc14\bin </ExecutablePath>
< / PropertyGroup>
<ItemDefinitionGroup Condition = "'$(Configuration)|$(Platform)'=='Debug|Win32'">
<ClCompile>
<WarningLevel>Level3< / WarningLevel>
<Optimization>Disabled< / Optimization>
<SDLCheck>true< / SDLCheck>
< / ClCompile>
<Link>
<GenerateDebugInformation>true< / GenerateDebugInformation>
< / Link>
< / ItemDefinitionGroup>
<ItemDefinitionGroup Condition = "'$(Configuration)|$(Platform)'=='Debug|x64'">
<ClCompile>
<WarningLevel>Level3< / WarningLevel>
<Optimization>Disabled< / Optimization>
<SDLCheck>true< / SDLCheck>
<AdditionalIncludeDirectories>E:\CNTT\DoAn1_v2\opencv\build\include; % (AdditionalIncludeDirectories)< / AdditionalIncludeDirectories>
<PreprocessorDefinitions>_CRT_SECURE_NO_WARNINGS; % (PreprocessorDefinitions)< / PreprocessorDefinitions>
< / ClCompile>
<Link>
<GenerateDebugInformation>true< / GenerateDebugInformation>
<AdditionalLibraryDirectories>E:\CNTT\DoAn1_v2\opencv\build\x64\vc14\lib; % (AdditionalLibraryDirectories)< / AdditionalLibraryDirectories>
<AdditionalDependencies>opencv_world320d.lib; % (AdditionalDependencies)< / AdditionalDependencies>
< / Link>
< / ItemDefinitionGroup>
<ItemDefinitionGroup Condition = "'$(Configuration)|$(Platform)'=='Release|Win32'">
<ClCompile>
<WarningLevel>Level3< / WarningLevel>
<Optimization>MaxSpeed< / Optimization>
<FunctionLevelLinking>true< / FunctionLevelLinking>
<IntrinsicFunctions>true< / IntrinsicFunctions>
<SDLCheck>true< / SDLCheck>
< / ClCompile>
<Link>
<GenerateDebugInformation>true< / GenerateDebugInformation>
<EnableCOMDATFolding>true< / EnableCOMDATFolding>
<OptimizeReferences>true< / OptimizeReferences>
< / Link>
< / ItemDefinitionGroup>
<ItemDefinitionGroup Condition = "'$(Configuration)|$(Platform)'=='Release|x64'">
<ClCompile>
<WarningLevel>Level3< / WarningLevel>
<Optimization>MaxSpeed< / Optimization>
<FunctionLevelLinking>true< / FunctionLevelLinking>
<IntrinsicFunctions>true< / IntrinsicFunctions>
<SDLCheck>true< / SDLCheck>
< / ClCompile>
<Link>
<GenerateDebugInformation>true< / GenerateDebugInformation>
<EnableCOMDATFolding>true< / EnableCOMDATFolding>
<OptimizeReferences>true< / OptimizeReferences>
< / Link>
< / ItemDefinitionGroup>
<ItemGroup>
<ClCompile Include = "LightColor.cpp" / >
<ClCompile Include = "SourceHaar.cpp" / >
<ClCompile Include = "SourceHaarImage.cpp" / >
<ClCompile Include = "SourceHaarRealTime.cpp" / >
< / ItemGroup>
<ItemGroup>
<ClInclude Include = "LightColor.h" / >
< / ItemGroup>
<Import Project = "$(VCTargetsPath)\Microsoft.Cpp.targets" / >
<ImportGroup Label = "ExtensionTargets">
< / ImportGroup>
< / Project>