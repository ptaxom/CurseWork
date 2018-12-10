#-------------------------------------------------
#
# Project created by QtCreator 2018-12-09T18:11:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork
TEMPLATE = app

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
    facedetector.cpp

HEADERS += \
        mainwindow.h \
    camerasource.h \
    mediawriter.h \
    writersettings.h \
    facedetector.h

FORMS += \
        mainwindow.ui \
    writersettings.ui



INCLUDEPATH += C:/opencv2/opencv/build/include
DEPENDPATH += C:/opencv2/opencv/build/include

LIBS += -LC:/opencv2/myBuild/lib/debug/ -lopencv_imgcodecs344d -lopencv_imgproc344d -lopencv_ml344d -lopencv_objdetect344d -lopencv_photo344d -lopencv_shape344d -lopencv_stitching344d -lopencv_superres344d -lopencv_ts344d -lopencv_video344d -lopencv_videoio344d -lopencv_videostab344d -lopencv_calib3d344d -lopencv_core344d -lopencv_features2d344d -lopencv_flann344d -lopencv_highgui344d



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
