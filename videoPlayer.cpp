#include "videoPlayer.h"

//This part used to test the feasibility of OpenGL, not used in the mediaplayer
VideoPlayer::VideoPlayer(QWidget *parent)
    : QOpenGLWidget(parent)
{
    connect(&m_timer, &QTimer::timeout, this, QOverload<>::of(&QOpenGLWidget::update));
    m_timer.start(1); // try refresh every 1ms
}

void VideoPlayer::initializeGL()
{
    initializeOpenGLFunctions();
}

void VideoPlayer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (!m_currentFrame.isNull()) {
        // Converts a QImage to an OpenGL texture and draws it.
    }
}

void VideoPlayer::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void VideoPlayer::setVideoFrame(const QImage &frame)
{
    m_currentFrame = frame;
    update(); // Request for redrawing
}
