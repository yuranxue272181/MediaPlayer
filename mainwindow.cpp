#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "videoDecoder.h"

#include <QAudioOutput>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QVideoWidget>
#include <QWidget>
// #include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)/*,
    usbThread(nullptr)*/
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
    fileName = ui->fileName;
    timeLabel = ui->timeLabel;
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setVideoOutput(videoWidget);

    hideComponents();

    // // Create a new QThread object
    // QThread *thread = new QThread();

    // // Instantiate the USBThread object (which now inherits QObject)
    // usbThread = new USBThread();

    // // Move the USBThread object to the worker thread
    // usbThread->moveToThread(thread);

    // // Connect the signal to the slot
    // connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    // connect(playButton, &QPushButton::clicked, this, &MainWindow::playPause);
    // connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::setSliderRange);
    // connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::updateSlider);
    // connect(positionSlider, &QSlider::sliderMoved, this, &MainWindow::setPosition);
    // connect(volumnSlider, &QSlider::valueChanged, this, &MainWindow::setVolume);

    // // Connect the signals and slots
    // connect(thread, &QThread::started, usbThread, &USBThread::startPullingData);  // Start pulling data when the thread starts
    // connect(usbThread, &USBThread::imageDataReceived, this, &MainWindow::handleImageData);
    // connect(usbThread, &USBThread::errorOccurred, this, &MainWindow::handleError);

    // // Connect the thread's finished signal to clean up
    // connect(thread, &QThread::finished, usbThread, &QObject::deleteLater);
    // connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    // // Start the thread
    // thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;

    // // Safely stop the USB thread by calling the stop method
    // usbThread->stop();

    // // Wait for the thread to finish
    // if (QThread *thread = usbThread->thread()) {
    //     thread->quit();
    //     thread->wait();
    // }

    // usbThread->deleteLater();
}
//open file
void MainWindow::openFile()
{
    QString fileName
        = QFileDialog::getOpenFileName(this,
                                       "Open File",
                                       "",
                                       "Videos(*.mp4 *.avi);;Images(*.png *.jpg *.bmp)");
    if (fileName.isEmpty()) {
        QMessageBox::critical(this, "Error", "Failed to open the image/video.", QMessageBox::Yes);
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
        decoder->averageFrameRate(fileName);
    }
}
//play or pause the video
void MainWindow::playPause()
{
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
        ui->playPause->setIcon(QIcon(":/new/prefix1/icons/on.png"));
    } else {
        mediaPlayer->play();
        ui->playPause->setIcon(QIcon(":/new/prefix1/icons/stop.png"));
    }
}

//set the position slider
void MainWindow::setSliderRange(qint64 duration)
{
    positionSlider->setRange(0, duration);
    updateTimeLabel();
}

//update the position slider
void MainWindow::updateSlider(qint64 position)
{
    positionSlider->setValue(position);
    updateTimeLabel();
}
//set the position the video plays
void MainWindow::setPosition(int position)
{
    mediaPlayer->setPosition(position);
}
//set the volume
void MainWindow::setVolume(int value)
{
    qreal volumeNormalized = value / 100.0;
    audioOutput->setVolume(volumeNormalized);
    qDebug() << "Volume set to:" << volumeNormalized;
}

//mute
void MainWindow::on_muteButton_clicked()
{
    bool mte = audioOutput->isMuted();
    audioOutput->setMuted(!mte);
    if (mte) {
        ui->muteButton->setIcon(QIcon(":/new/prefix1/icons/loud.png"));
        volumnSlider->setEnabled(true);
    } else {
        ui->muteButton->setIcon(QIcon(":/new/prefix1/icons/quiet.png"));
        volumnSlider->setEnabled(false);
    }
}

//display the position of the video
void MainWindow::updateTimeLabel()
{
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
void MainWindow::hideComponents()
{
    playButton->hide();
    positionSlider->hide();
    volumnSlider->hide();
    muteButton->hide();
    timeLabel->hide();
}

//show usabel buttons and sliders
void MainWindow::showComponents()
{
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

// void MainWindow::handleImageData(unsigned char *data, int size)
// {
//     // Handle the image data here (e.g., display it or process it)
// }

// void MainWindow::handleError(const QString &error)
// {
//     QMessageBox::critical(this, "USB Error", error);
// }
