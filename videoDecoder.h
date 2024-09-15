#ifndef VIDEODECODER_H
#define VIDEODECODER_H

#include <QString>
extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
}

class MainWindow;

class videoDecoder {
public:
    videoDecoder(MainWindow *mainWindow);
    ~videoDecoder();
    void averageFrameRate(const QString &filePath);

private:
    QString filePath;
    MainWindow *m_mainWindow;
};

#endif // VIDEODECODER_H
