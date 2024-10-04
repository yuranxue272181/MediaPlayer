// #ifndef FPGAINTERFACE_H
// #define FPGAINTERFACE_H

//  #include <QObject>
//  #include <libusb-1.0/libusb.h>

//  class FPGAInterface : public QObject
//  {
//      Q_OBJECT
//  public:
//      explicit FPGAInterface(QObject *parent = nullptr);
//      ~FPGAInterface();

//      // Function to initialize USB communication with FPGA
//      bool initializeUSB();

//      // Function to receive image data from FPGA
//      bool pullImageData(unsigned char *buffer, int size);

//      // Function to close the USB connection
//      void closeUSB();

//  signals:
//      void dataReceived();  // Signal to notify when data has been successfully received
//      void errorOccurred(const QString &error);  // Signal for error handling

//  private:
//      libusb_device_handle *handle;
//      libusb_context *context;
//      static const int VENDOR_ID = 0x0403;  // Replace with your FPGA's Vendor ID
//      static const int PRODUCT_ID = 0x6010; // Replace with your FPGA's Product ID
//      static const int ENDPOINT = 0x81;     // Replace with your FPGA's Bulk IN endpoint
//      static const int TIMEOUT = 1000;      // USB transfer timeout in ms
//  };

// #endif // FPGAINTERFACE_H
