// #include "fpgainterface.h"
// #include <libusb-1.0/libusb.h>

// FPGAInterface::FPGAInterface(QObject *parent) :
//     QObject(parent),
//     handle(nullptr),
//     context(nullptr)
// {
// }

// FPGAInterface::~FPGAInterface()
// {
//     closeUSB();  // Ensure USB connection is closed when object is destroyed
// }

// bool FPGAInterface::initializeUSB()
// {
//     int r = libusb_init(&context);
//     if (r < 0) {
//         emit errorOccurred("Failed to initialize libusb");
//         return false;
//     }

//     // Open the FPGA USB device
//     handle = libusb_open_device_with_vid_pid(context, VENDOR_ID, PRODUCT_ID);
//     if (!handle) {
//         emit errorOccurred("Failed to open FPGA USB device");
//         libusb_exit(context);
//         return false;
//     }

//     // Claim the first interface (interface 0)
//     r = libusb_claim_interface(handle, 0);
//     if (r < 0) {
//         emit errorOccurred("Failed to claim FPGA USB interface");
//         libusb_close(handle);
//         libusb_exit(context);
//         return false;
//     }

//     return true;
// }

// bool FPGAInterface::pullImageData(unsigned char *buffer, int size)
// {
//     int transferred = 0;
//     int r = libusb_bulk_transfer(handle, ENDPOINT, buffer, size, &transferred, TIMEOUT);

//     if (r == 0 && transferred == size) {
//         emit dataReceived();  // Emit signal to notify successful data reception
//         return true;
//     } else {
//         emit errorOccurred("Failed to receive image data from FPGA");
//         return false;
//     }
// }

// void FPGAInterface::closeUSB()
// {
//     if (handle) {
//         libusb_release_interface(handle, 0);
//         libusb_close(handle);
//     }

//     if (context) {
//         libusb_exit(context);
//     }
// }
