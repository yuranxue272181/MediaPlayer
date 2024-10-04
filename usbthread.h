// #ifndef USBTHREAD_H
// #define USBTHREAD_H

// #include <QObject>
// #include "fpgainterface.h"

// class USBThread : public QObject
// {
//     Q_OBJECT
// public:
//     explicit USBThread(QObject *parent = nullptr);
//     ~USBThread();

//     void stop();  // Add a public method to stop the thread

// public slots:
//     void startPullingData();  // Remove the override keyword

// signals:
//     void imageDataReceived(unsigned char* data, int size);
//     void errorOccurred(const QString &error);

// private:
//     FPGAInterface *fpgaInterface;
//     bool running;
// };

// #endif // USBTHREAD_H
