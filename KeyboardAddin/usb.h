/*
File: usb.h 
Author: Myth
Usage: USB I/O functions.
*/


#ifndef _USB_H_
#define _USB_H_

#ifdef __cplusplus
extern "C" 
{
#endif


// Remove this to disable debug.
#define DEBUG_USB


class USB
{
public:
    USB();

    int Init(void); // Try to open the usb port.

    int Send(unsigned char* ustr); // Send ustr to usb port.

    void ClearSendBuffer(void); // Clear send buffer.
    
    void Close(void); // Close the usb port.

private:
    
};


#ifdef __cplusplus
}
#endif

#endif