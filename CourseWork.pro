#-------------------------------------------------
#
# Project created by QtCreator 2018-12-09T18:11:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork
TEMPLATE = app

win32:RC_FILE = camera.rc

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    camerasource.cpp \
    mediawriter.cpp \
    writersettings.cpp \
    camerasource.cpp \
    main.cpp \
    mainwindow.cpp \
    mediawriter.cpp \
    writersettings.cpp \
    camerasource.cpp \
    main.cpp \
    mainwindow.cpp \
    mediawriter.cpp \
    writersettings.cpp \
    camerasource.cpp \
    main.cpp \
    mainwindow.cpp \
    mediawriter.cpp \
    writersettings.cpp \
    camerasource.cpp \
    main.cpp \
    mainwindow.cpp \
    mediawriter.cpp \
    writersettings.cpp \
    Filters/abstractkernelfilter.cpp \
    imagecontroller.cpp \
    Filters/abstractfilter.cpp \
    Filters/KernelFilters/gaussianblur.cpp \
    Filters/KernelFilters/medianblur.cpp \
    Filters/KernelFilters/kernelfiltereditor.cpp \
    ImageControllerForm/imagecontrollersettings.cpp \
    Detectors/abstractshapedetector.cpp \
    Detectors/LBPDetector/lbpdetector.cpp \
    Detectors/LBPDetector/lbpdetector.cpp \
    Detectors/abstractshapedetector.cpp \
    Filters/KernelFilters/gaussianblur.cpp \
    Filters/KernelFilters/kernelfiltereditor.cpp \
    Filters/KernelFilters/medianblur.cpp \
    Filters/abstractfilter.cpp \
    Filters/abstractkernelfilter.cpp \
    ImageControllerForm/imagecontrollersettings.cpp \
    camerasource.cpp \
    imagecontroller.cpp \
    main.cpp \
    mainwindow.cpp \
    mediawriter.cpp \
    writersettings.cpp \
    Filters/abstractmorphfilter.cpp \
    Filters/MorphFilters/morphdilate.cpp \
    Filters/MorphFilters/morpherode.cpp \
    Filters/MorphFilters/morphopen.cpp \
    Filters/MorphFilters/morphclose.cpp \
    Detectors/LBPDetector/lbpdetector.cpp \
    Detectors/abstractshapedetector.cpp \
    Detectors/LBPDetector/lbpdetector.cpp \
    Detectors/abstractshapedetector.cpp \
    Detectors/DetectorControllerForm/dcontroller.cpp \
    Filters/MorphFilters/MorphFilterEditor/morphfilterform.cpp \
    Filters/AbstractFilterEditor/abstractfiltereditor.cpp \
    Filters/ColorSpaceFilters/negativefilter.cpp \
    Filters/abstractcolorfilter.cpp \
    Filters/ColorSpaceFilters/sepiafilter.cpp \
    Filters/ColorSpaceFilters/weightedcolorchannelfilter.cpp \
    Filters/ColorSpaceFilters/ColorFilterEditor/colorfiltereditor.cpp \
    Filters/ColorSpaceFilters/grayscalefilter.cpp \
    Utils/applicationprocessor.cpp

HEADERS += \
        mainwindow.h \
    camerasource.h \
    mediawriter.h \
    writersettings.h \
    camerasource.h \
    mainwindow.h \
    mediawriter.h \
    writersettings.h \
    camerasource.h \
    mainwindow.h \
    mediawriter.h \
    writersettings.h \
    camerasource.h \
    mainwindow.h \
    mediawriter.h \
    writersettings.h \
    camerasource.h \
    mainwindow.h \
    mediawriter.h \
    writersettings.h \
    Filters/abstractkernelfilter.h \
    imagecontroller.h \
    Filters/abstractfilter.h \
    Filters/KernelFilters/gaussianblur.h \
    Filters/KernelFilters/medianblur.h \
    Filters/KernelFilters/kernelfiltereditor.h \
    ImageControllerForm/imagecontrollersettings.h \
    Detectors/abstractshapedetector.h \
    Detectors/LBPDetector/lbpdetector.h \
    Detectors/LBPDetector/lbpdetector.h \
    Detectors/abstractshapedetector.h \
    Filters/KernelFilters/gaussianblur.h \
    Filters/KernelFilters/kernelfiltereditor.h \
    Filters/KernelFilters/medianblur.h \
    Filters/abstractfilter.h \
    Filters/abstractkernelfilter.h \
    ImageControllerForm/imagecontrollersettings.h \
    camerasource.h \
    imagecontroller.h \
    mainwindow.h \
    mediawriter.h \
    writersettings.h \
    Filters/abstractmorphfilter.h \
    Filters/MorphFilters/morphdilate.h \
    Filters/MorphFilters/morpherode.h \
    Filters/MorphFilters/morphopen.h \
    Filters/MorphFilters/morphclose.h \
    Detectors/LBPDetector/lbpdetector.h \
    Detectors/abstractshapedetector.h \
    Detectors/LBPDetector/lbpdetector.h \
    Detectors/abstractshapedetector.h \
    Detectors/DetectorControllerForm/dcontroller.h \
    Filters/MorphFilters/MorphFilterEditor/morphfilterform.h \
    Filters/AbstractFilterEditor/abstractfiltereditor.h \
    Filters/ColorSpaceFilters/negativefilter.h \
    Filters/abstractcolorfilter.h \
    Filters/ColorSpaceFilters/sepiafilter.h \
    Filters/ColorSpaceFilters/weightedcolorchannelfilter.h \
    Filters/ColorSpaceFilters/ColorFilterEditor/colorfiltereditor.h \
    Filters/ColorSpaceFilters/grayscalefilter.h \
    Utils/applicationprocessor.h

FORMS += \
        mainwindow.ui \
    writersettings.ui \
    Filters/KernelFilters/kernelfiltereditor.ui \
    ImageControllerForm/imagecontrollersettings.ui \
    Detectors/DetectorControllerForm/dcontroller.ui \
    Filters/MorphFilters/MorphFilterEditor/morphfilterform.ui \
    Filters/ColorSpaceFilters/ColorFilterEditor/colorfiltereditor.ui



INCLUDEPATH += C:/opencv2/opencv/build/include
DEPENDPATH += C:/opencv2/opencv/build/include

LIBS += -LC:/opencv2/myBuild/lib/debug/ -lopencv_imgcodecs344d -lopencv_imgproc344d -lopencv_ml344d -lopencv_objdetect344d -lopencv_photo344d -lopencv_shape344d -lopencv_stitching344d -lopencv_superres344d -lopencv_ts344d -lopencv_video344d -lopencv_videoio344d -lopencv_videostab344d -lopencv_calib3d344d -lopencv_core344d -lopencv_features2d344d -lopencv_flann344d -lopencv_highgui344d

#LIBS += -L../libs/ -lopencv_imgcodecs344d -lopencv_imgproc344d -lopencv_ml344d -lopencv_objdetect344d -lopencv_photo344d -lopencv_shape344d -lopencv_stitching344d -lopencv_superres344d -lopencv_ts344d -lopencv_video344d -lopencv_videoio344d -lopencv_videostab344d -lopencv_calib3d344d -lopencv_core344d -lopencv_features2d344d -lopencv_flann344d -lopencv_highgui344d

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Filters/Лист Microsoft Excel.xlsx
