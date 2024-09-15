// #ifndef FPS_H
// #define FPS_H

// #include <QObject>
// #include <QMediaPlayer>
// #include <QElapsedTimer>
// #include <QTimer>

// class fps : public QObject
// {
//     Q_OBJECT

// public:
//     explicit fps(QMediaPlayer *player, QObject *parent = nullptr);

// public slots:
//     void updateFrameRate(); // 更新帧率

//     float getFPS() const;   // 获取当前帧率

// private:
//     QMediaPlayer *m_player; // 媒体播放器实例
//     QElapsedTimer m_elapsedTimer; // 用于计算时间
//     QTimer *m_timer; // 定时器，用于定期更新帧率
//     qint64 m_lastPosition; // 上一个位置
//     int m_frameCount; // 帧计数器
//     float m_fps; // 当前帧率
// };

// #endif // FPS_H
