#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPushButton>
#include <QSlider>
#include <QMainWindow>
#include <QVideoWidget>
#include <QLabel>

#include "fps.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class fps;
class videoDecoder;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setFrameRateText(const QString &text);
    void setAverageFrameRateText(const QString &text);

private slots:
    void openFile();
    void playPause();
    void setSliderRange(qint64 duration);
    void updateSlider(qint64 position);
    void setPosition(int position);
    void on_muteButton_clicked();
    void setVolume(int value);
    void updateTimeLabel();
    void hideComponents();
    void showComponents();


private:
    Ui::MainWindow *ui;

    QGraphicsView *graphicsView;
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *muteButton;
    QSlider *positionSlider;
    QSlider *volumnSlider;
    QLabel *fileName;
    QLabel *timeLabel;
    QAudioOutput *audioOutput;

    fps *m_fpsWidget;

    //average fps
    videoDecoder *decoder;

};
#endif // MAINWINDOW_H
