/*
File: usb.cpp
Author: Myth
*/


#include "libusb.h"

#include "usb.h"

#ifdef DEBUG_USB
#include <iostream>
#endif


USB::USB() : device_handle(NULL)
{
    
}


// Connect by usb port.
// Return
// 0 : success
// -1 : not found
// -2 : access error
// -3 : driver error
// -4 : other error
int USB::Connect(void)
{
    libusb_context* context = NULL;
    libusb_device** device_list = NULL;

    libusb_init(&context);
    int device_num = libusb_get_device_list(context, &device_list);

    libusb_device* device = NULL;

    for (size_t i = 0; i < device_num; i++)
    {
        libusb_device* temp_device = device_list[i];
        libusb_device_descriptor device_descriptor = { 0 };

        // if device is fx-9860 calculator
        if (
            libusb_get_device_descriptor(temp_device, &device_descriptor) == LIBUSB_SUCCESS
            && device_descriptor.idVendor == 0x07CF
            && device_descriptor.idProduct == 0x6101
            )
            device = temp_device;
    }

    // fx-9860 not found
    if (device == NULL)
        return -1;

    switch (libusb_open(device, &device_handle))
    {
    case LIBUSB_SUCCESS: // success
    {
        libusb_claim_interface(device_handle, 0);

        return 0;
    }

    case LIBUSB_ERROR_ACCESS: // access error
    {
        return -2;
    }

    case LIBUSB_ERROR_NOT_SUPPORTED: // If don't use Zadig to replace the origin driver with WinUSB, this error will occur.
    {
        return -3;
    }

    default:
    {
        return -4;
    }
    }
}


// Receive. 
// Until receive > 0 byte or error occur will this function exit.
// Return
// 0 : success
// -1 : disconnect
// -2 : other error
int USB::Receive(unsigned char* ustr)
{
    unsigned char temp_ustr[MAX_PACKET_SIZE];
    int actual_length = 0;

    while (1)
    {
        switch (libusb_bulk_transfer(device_handle, RECEIVE_ENDPOINT, temp_ustr, MAX_PACKET_SIZE, &actual_length, TIMEOUT))
        {
        case LIBUSB_SUCCESS: // success
        {
            if (actual_length == 0)
            {
                continue;
            }
            else
            {
                strcpy((char*)ustr, (char*)temp_ustr);

                #ifdef DEBUG_USB
                std::cout << "#Receive: " << (char*)ustr << std::endl;
                #endif

                return 0;
            }
        }

        case LIBUSB_ERROR_PIPE: // disconnect
        {
            return -1;
        }

        default: // other error
        {
            return -2;
        }
        }
    }
}