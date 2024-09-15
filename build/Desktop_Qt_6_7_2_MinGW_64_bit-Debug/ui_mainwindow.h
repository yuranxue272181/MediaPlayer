/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *volumnSlider;
    QPushButton *playPause;
    QPushButton *muteButton;
    QVideoWidget *videoWidgetPlaceholder;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSlider *positionSlider;
    QLabel *timeLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *openFile;
    QLabel *fileName;
    QSplitter *splitter;
    QLabel *avgFPS;
    QLabel *FPS;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        volumnSlider = new QSlider(centralwidget);
        volumnSlider->setObjectName("volumnSlider");
        volumnSlider->setGeometry(QRect(656, 532, 84, 22));
        volumnSlider->setOrientation(Qt::Orientation::Horizontal);
        playPause = new QPushButton(centralwidget);
        playPause->setObjectName("playPause");
        playPause->setGeometry(QRect(380, 530, 28, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playPause->setIcon(icon);
        muteButton = new QPushButton(centralwidget);
        muteButton->setObjectName("muteButton");
        muteButton->setGeometry(QRect(622, 531, 28, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/loud.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        muteButton->setIcon(icon1);
        videoWidgetPlaceholder = new QVideoWidget(centralwidget);
        videoWidgetPlaceholder->setObjectName("videoWidgetPlaceholder");
        videoWidgetPlaceholder->setGeometry(QRect(20, 30, 751, 481));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoWidgetPlaceholder->sizePolicy().hasHeightForWidth());
        videoWidgetPlaceholder->setSizePolicy(sizePolicy);
        videoWidgetPlaceholder->setSizeIncrement(QSize(50, 50));
        videoWidgetPlaceholder->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 30, 751, 481));
        graphicsView->setSizeIncrement(QSize(50, 50));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 560, 741, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        positionSlider = new QSlider(layoutWidget);
        positionSlider->setObjectName("positionSlider");
        positionSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(positionSlider);

        timeLabel = new QLabel(layoutWidget);
        timeLabel->setObjectName("timeLabel");

        horizontalLayout_2->addWidget(timeLabel);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(32, 530, 331, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        openFile = new QPushButton(layoutWidget1);
        openFile->setObjectName("openFile");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/image.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openFile->setIcon(icon2);

        horizontalLayout->addWidget(openFile);

        fileName = new QLabel(layoutWidget1);
        fileName->setObjectName("fileName");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileName->sizePolicy().hasHeightForWidth());
        fileName->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(fileName);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(452, 10, 311, 20));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        avgFPS = new QLabel(splitter);
        avgFPS->setObjectName("avgFPS");
        sizePolicy1.setHeightForWidth(avgFPS->sizePolicy().hasHeightForWidth());
        avgFPS->setSizePolicy(sizePolicy1);
        splitter->addWidget(avgFPS);
        FPS = new QLabel(splitter);
        FPS->setObjectName("FPS");
        sizePolicy1.setHeightForWidth(FPS->sizePolicy().hasHeightForWidth());
        FPS->setSizePolicy(sizePolicy1);
        splitter->addWidget(FPS);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playPause->setText(QString());
        muteButton->setText(QString());
        timeLabel->setText(QCoreApplication::translate("MainWindow", "00:00/00:00", nullptr));
        openFile->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        fileName->setText(QString());
        avgFPS->setText(QCoreApplication::translate("MainWindow", "Average FPS: 0", nullptr));
        FPS->setText(QCoreApplication::translate("MainWindow", "FPS: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
