// #include "usbthread.h"
// #include <QThread>

// USBThread::USBThread(QObject *parent)
//     : QObject{parent},
//     fpgaInterface(new FPGAInterface(this)),
//     running(true)  // Set running to true so that the loop can run
// {}

// USBThread::~USBThread()
// {
//     // Clean up the FPGA interface
//     fpgaInterface->closeUSB();
// }

// void USBThread::startPullingData()
// {
//     if (!fpgaInterface->initializeUSB()) {
//         emit errorOccurred("Failed to initialize USB");
//         return;
//     }

//     const int imageSize = 176 * 144 * 3;  // For a QCIF 176x144 RGB image (3 bytes per pixel)
//     unsigned char buffer[imageSize];

//     while (running) {
//         if (fpgaInterface->pullImageData(buffer, imageSize)) {
//             emit imageDataReceived(buffer, imageSize);
//         } else {
//             emit errorOccurred("Failed to pull image data from FPGA");
//             break;
//         }

//         // Sleep for a bit to avoid overloading the USB transfer
//         QThread::msleep(100);
//     }

//     fpgaInterface->closeUSB();
// }

// void USBThread::stop()
// {
//     running = false;  // Safely stop the data pulling process
// }
