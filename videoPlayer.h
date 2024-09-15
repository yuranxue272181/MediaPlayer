#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QImage>
#include <QTimer>

class VideoPlayer : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = nullptr);
    void setVideoFrame(const QImage &frame);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    QImage m_currentFrame;
    QTimer m_timer;
};

#endif // VIDEOPLAYER_H
