#include "videoDecoder.h"
#include "mainwindow.h"
#include <QDebug>

videoDecoder::videoDecoder(MainWindow *mainWindow):m_mainWindow(mainWindow) {
    avformat_network_init();
}

videoDecoder::~videoDecoder() {
    avformat_network_deinit();
}

void videoDecoder::testFromPath(const QString &filePath) {
    AVFormatContext *formatContext = nullptr;

    // QString -> std::string
    std::string filePathStd = filePath.toStdString();

    // open file
    if (avformat_open_input(&formatContext, filePathStd.c_str(), nullptr, nullptr) < 0) {
        qDebug() << "Could not open video file:" << filePath;
        return;
    }

    // printout
    qDebug() << "Format:" << formatContext->iformat->long_name;

    // display average framerate
    for (unsigned int i = 0; i < formatContext->nb_streams; ++i) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            double frameRate = av_q2d(formatContext->streams[i]->avg_frame_rate);
            qDebug() << "Frame rate:" << frameRate << "fps";
            if (m_mainWindow) {
                m_mainWindow->setAverageFrameRateText(QString("Average FPS: %1").arg(frameRate));
            }
            break;
        }
    }

    avformat_close_input(&formatContext);
}
