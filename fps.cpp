// #include "fps.h"
// #include <QDebug>

// fps::fps(QMediaPlayer *player, QObject *parent)
//     : QObject(parent), m_player(player), m_frameCount(0),m_fps(0)
// {
//     m_elapsedTimer.start(); // 启动计时器
//     m_timer = new QTimer(this);
//     connect(m_timer, &QTimer::timeout, this, &fps::updateFrameRate);
//     m_timer->start(1000);  // 每秒更新一次
// }

// void fps::updateFrameRate()
// {
//     qint64 elapsedTime = m_elapsedTimer.elapsed(); // 获取已过时间
//     qDebug() << "Elapsed Time:" << elapsedTime << "ms";
//     qDebug() << "Frame Count:" << m_frameCount;
//     if (elapsedTime >= 1000) { // 每秒更新一次
//         m_fps = (m_frameCount * 1000.0f) / elapsedTime;
//         m_frameCount = 0; // 重置帧计数器
//         m_elapsedTimer.restart(); // 重启计时器
//     }

//     qDebug() << "Estimated FPS:" << m_fps;
// }

// float fps::getFPS() const
// {
//     return m_fps;
// }
