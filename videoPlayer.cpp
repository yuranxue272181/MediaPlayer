#include "videoPlayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QOpenGLWidget(parent)
{
    connect(&m_timer, &QTimer::timeout, this, QOverload<>::of(&QOpenGLWidget::update));
    m_timer.start(1); // 尝试每毫秒更新一次
}

void VideoPlayer::initializeGL()
{
    initializeOpenGLFunctions();
    // 初始化 OpenGL 资源和设置
}

void VideoPlayer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!m_currentFrame.isNull()) {
        // 将 QImage 转换为 OpenGL 纹理并绘制
        // 这里你需要实现将 QImage 渲染到 OpenGL 的具体逻辑
    }
}

void VideoPlayer::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void VideoPlayer::setVideoFrame(const QImage &frame)
{
    m_currentFrame = frame;
    update(); // 请求重新绘制
}
