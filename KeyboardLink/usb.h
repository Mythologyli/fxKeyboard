/*
File: usb.h
Author: Myth
Usage: USB I/O functions.
*/


#ifndef _USB_H_
#define _USB_H_


#include "libusb.h"


#define DEBUG_USB

// usb related
#define RECEIVE_ENDPOINT 0x82

#define MAX_PACKET_SIZE 256

#define TIMEOUT 2000


class USB
{
public:
	USB();

	int Connect(void); // Connect by usb port.
	int Receive(unsigned char* ustr); // Receive. 

private:
	libusb_device_handle* device_handle;
};


#endif