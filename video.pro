QT       += core gui
QT += multimedia multimediawidgets opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += E:\Wpi\Project\MQP\MediaPlayer\libusb\include
LIBS += -LE:\Wpi\Project\MQP\MediaPlayer\libusb\bin\
        -lusb-1.0

INCLUDEPATH += E:\Wpi\Project\MQP\MediaPlayer\ffmpeg\include
LIBS += -LE:\Wpi\Project\MQP\MediaPlayer\ffmpeg\lib\
        -lavcodec \
        -lavformat \
        -lavutil \
        -lswscale

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fpgainterface.cpp \
    fps.cpp \
    main.cpp \
    mainwindow.cpp \
    usbinterface.cpp \
    usbthread.cpp \
    videoDecoder.cpp \
    videoPlayer.cpp

HEADERS += \
    fpgainterface.h \
    fps.h \
    mainwindow.h \
    usbinterface.h \
    usbthread.h \
    videoDecoder.h \
    videoPlayer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
