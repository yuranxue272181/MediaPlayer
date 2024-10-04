#ifndef USBINTERFACE_H
#define USBINTERFACE_H

#include <libusb-1.0/libusb.h>
#include <vector>

class USBInterface {
public:
    // Constructor and destructor
    USBInterface(uint16_t vendor_id, uint16_t product_id, uint8_t endpoint_in);
    ~USBInterface();

    // Method to initialize the USB connection
    bool initializeUSB();

    // Method to pull image data from the FPGA
    bool pullImageData(std::vector<unsigned char>& buffer, int timeout = 1000);

    // Method to close the USB connection
    void closeUSB();

private:
    uint16_t vendor_id;
    uint16_t product_id;
    uint8_t endpoint_in;

    libusb_device_handle* handle;
    libusb_context* context;
};

#endif // USBINTERFACE_H
