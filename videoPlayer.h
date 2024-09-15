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
    void setVideoFrame(const QImage &frame); // 设置当前视频帧

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    QImage m_currentFrame; // 当前视频帧
    QTimer m_timer;        // 定时器用于控制帧率
};

#endif // VIDEOPLAYER_H
