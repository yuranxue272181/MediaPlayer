#include "usbinterface.h"
#include <iostream>

// Constructor
USBInterface::USBInterface(uint16_t vendor_id, uint16_t product_id, uint8_t endpoint_in)
    : vendor_id(vendor_id), product_id(product_id), endpoint_in(endpoint_in), handle(nullptr), context(nullptr) {}

// Destructor
USBInterface::~USBInterface() {
    closeUSB();  // Ensure USB connection is closed when the object is destroyed
}

// Initialize USB communication with the FPGA
bool USBInterface::initializeUSB() {
    int result = libusb_init(&context);
    if (result < 0) {
        std::cerr << "Failed to initialize libusb: " << libusb_error_name(result) << std::endl;
        return false;
    }

    // Open the FPGA USB device
    handle = libusb_open_device_with_vid_pid(context, vendor_id, product_id);
    if (!handle) {
        std::cerr << "Could not open USB device." << std::endl;
        libusb_exit(context);
        return false;
    }

    // Claim the first interface (assuming interface 0)
    result = libusb_claim_interface(handle, 0);
    if (result < 0) {
        std::cerr << "Failed to claim interface: " << libusb_error_name(result) << std::endl;
        libusb_close(handle);
        libusb_exit(context);
        return false;
    }

    return true;
}

// Pull image data from the FPGA
bool USBInterface::pullImageData(std::vector<unsigned char>& buffer, int timeout) {
    int transferred = 0;
    int result = libusb_bulk_transfer(handle, endpoint_in, buffer.data(), buffer.size(), &transferred, timeout);

    if (result == 0 && transferred > 0) {
        std::cout << "Received " << transferred << " bytes from FPGA." << std::endl;
        return true;
    } else {
        std::cerr << "Error in bulk transfer: " << libusb_error_name(result) << std::endl;
        return false;
    }
}

// Close the USB connection
void USBInterface::closeUSB() {
    if (handle) {
        libusb_release_interface(handle, 0);
        libusb_close(handle);
    }

    if (context) {
        libusb_exit(context);
    }
}
