#include "mainwindow.h"
#include "usbinterface.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Image & Video Viewer");
    mainWindow.resize(800, 600);
    mainWindow.show();

    uint16_t vendor_id = 0x04B4;
    uint16_t product_id = 0x00F1;
    uint8_t endpoint_in = 0x01;

    // Create an instance of USBInterface
    USBInterface usb(vendor_id, product_id, endpoint_in);

    // Initialize USB connection
    if (usb.initializeUSB()) {
        std::vector<unsigned char> buffer(512);  // Adjust buffer size as needed

        // Pull data from FPGA
        if (usb.pullImageData(buffer)) {
            // Print received data
            std::cout << "Data: ";
            for (auto byte : buffer) {
                std::cout << std::hex << static_cast<int>(byte) << " ";
            }
            std::cout << std::dec << std::endl;
        }

        // Close USB connection
        usb.closeUSB();
    }

    return app.exec();
}
