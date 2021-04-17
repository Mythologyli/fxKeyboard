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

    static int Init(void); // Try to open the usb port.

    static int Send(unsigned char* ustr); // Send ustr to usb port.

    static void ClearSendBuffer(void); // Clear send buffer.
    
    static void Close(void); // Close the usb port.

private:
    static void ForceExit(void); // Force exit.
};


#ifdef __cplusplus
}
#endif

#endif