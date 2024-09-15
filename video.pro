QT       += core gui
QT += multimedia multimediawidgets opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


INCLUDEPATH += E:\APPData\Qtdocument\video\ffmpeg\include
LIBS += -LE:/APPData/Qtdocument/video/ffmpeg/lib \
        -lavcodec \
        -lavformat \
        -lavutil \
        -lswscale


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fps.cpp \
    main.cpp \
    mainwindow.cpp \
    videoDecoder.cpp \
    videoPlayer.cpp

HEADERS += \
    fps.h \
    mainwindow.h \
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
