#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "videoDecoder.h"



#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QMessageBox>
#include <QAudioOutput>
#include <QMediaMetaData>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connected with UI
    graphicsView = ui->graphicsView;
    videoWidget = ui->videoWidgetPlaceholder;
    mediaPlayer = new QMediaPlayer(this);
    openButton = ui->openFile;
    playButton = ui->playPause;
    positionSlider = ui->positionSlider;
    volumnSlider = ui->volumnSlider;
    muteButton = ui->muteButton;
    fileName = ui -> fileName;
    timeLabel = ui-> timeLabel;
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setVideoOutput(videoWidget);


    hideComponents();

    // Connect the signal to the slot
    connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::playPause);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::setSliderRange);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::updateSlider);
    connect(positionSlider, &QSlider::sliderMoved, this, &MainWindow::setPosition);
    connect(volumnSlider, &QSlider::valueChanged, this, &MainWindow::setVolume);


}



MainWindow::~MainWindow()
{
    delete ui;
}
//open file
void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Videos(*.mp4 *.avi);;Images(*.png *.jpg *.bmp)");
    if (fileName.isEmpty()){
        QMessageBox::critical(this,"Error","Failed to open the image/video.",QMessageBox::Yes);
        return;
    }

    //get the information of file
    QFileInfo fileInfos(fileName);
    ui->fileName->setText(fileInfos.fileName());

    if (fileName.endsWith(".png") || fileName.endsWith(".jpg") || fileName.endsWith(".bmp")) {
        // show image
        QPixmap pixmap(fileName);
        QGraphicsScene *scene = new QGraphicsScene(this);
        scene->addPixmap(pixmap);
        graphicsView->setScene(scene);
        graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

        //hide the videoWidetr
        mediaPlayer->pause();
        ui->playPause->setIcon(QIcon(":/new/prefix1/icons/on.png"));
        videoWidget->hide();
        hideComponents();

        graphicsView->show();

    } else {
        // show video
        mediaPlayer->setSource(QUrl::fromLocalFile(fileName));
        mediaPlayer->play();
        graphicsView->hide();
        videoWidget->show();
        volumnSlider->setValue(audioOutput->volume() * 100);
        ui->playPause->setIcon(QIcon(":/new/prefix1/icons/stop.png"));
        //show components
        showComponents();



        //average frame rate
        decoder = new videoDecoder(this);
        decoder->testFromPath(fileName);

    }
}
//play or pause the video
void MainWindow::playPause() {
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
        ui->playPause->setIcon(QIcon(":/new/prefix1/icons/on.png"));
    } else {
        mediaPlayer->play();
        ui->playPause->setIcon(QIcon(":/new/prefix1/icons/stop.png"));
    }
}

//set the position slider
void MainWindow::setSliderRange(qint64 duration) {
    positionSlider->setRange(0, duration);
    updateTimeLabel();
}

//update the position slider
void MainWindow::updateSlider(qint64 position) {
    positionSlider->setValue(position);
    updateTimeLabel();
}
//set the position the video plays
void MainWindow::setPosition(int position) {
    mediaPlayer->setPosition(position);
}
//set the volume
void MainWindow::setVolume(int value) {
    qreal volumeNormalized = value / 100.0;
    audioOutput->setVolume(volumeNormalized);
    qDebug() << "Volume set to:" << volumeNormalized;
}

//mute
void MainWindow::on_muteButton_clicked()
{
    bool mte =audioOutput->isMuted();
    audioOutput->setMuted(!mte);
    if(mte){
        ui->muteButton->setIcon(QIcon(":/new/prefix1/icons/loud.png"));
        volumnSlider->setEnabled(true);
    }else{
        ui->muteButton->setIcon(QIcon(":/new/prefix1/icons/quiet.png"));
        volumnSlider->setEnabled(false);
    }

}

//display the position of the video
void MainWindow::updateTimeLabel() {
    qint64 position = mediaPlayer->position();
    qint64 duration = mediaPlayer->duration();

    QString positionStr = QString("%1:%2")
                              .arg(position / 60000, 2, 10, QChar('0'))
                              .arg((position % 60000) / 1000, 2, 10, QChar('0'));

    QString durationStr = QString("%1:%2")
                              .arg(duration / 60000, 2, 10, QChar('0'))
                              .arg((duration % 60000) / 1000, 2, 10, QChar('0'));

    timeLabel->setText(positionStr + " / " + durationStr);

}

//hide unusable buttons and sliders
void MainWindow::hideComponents(){
    playButton->hide();
    positionSlider->hide();
    volumnSlider->hide();
    muteButton->hide();
    timeLabel->hide();
}

//show usabel buttons and sliders
void MainWindow::showComponents(){
    playButton->show();
    positionSlider->show();
    volumnSlider->show();
    muteButton->show();
    timeLabel->show();
}
//display framerate
void MainWindow::setFrameRateText(const QString &text)
{
    ui->FPS->setText(text);
}

//display average framerate
void MainWindow::setAverageFrameRateText(const QString &text)
{
    ui->avgFPS->setText(text);
}









