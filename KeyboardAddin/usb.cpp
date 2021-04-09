/*
File: usb.cpp
Author: Myth
*/


#ifdef __cplusplus
extern "C" 
{
#endif


#include "tool.h"
#include "syscall.h"
#include "usb.h"

#ifdef DEBUG_USB
#include "log.h"
extern Log log;
#endif


USB::USB()
{
    
}


// Try to open the usb port.
// Return
// 0 : success
// -1 : port already open
int USB::Init(void)
{
    if (!Comm_Open(0x20))
    {
        #ifdef DEBUG_USB
        log.PrintLn((const unsigned char*)"#Port open!");
        #endif

        ClearSendBuffer();
        
        return 0;
    }
    else 
    {
        #ifdef DEBUG_USB
        log.PrintLn((const unsigned char*)"#Port already open!");
        #endif

        return -1;
    }
}


// Send ustr to usb port.
// Return
// 0 : success
// -1 : buffer full
// -2 : port close
int USB::Send(unsigned char* ustr) 
{
    ClearSendBuffer();
    
    int length = uStrLen(ustr);
    
    switch (Comm_TransmitNBytes(ustr, length + 1))
    {
    case 0: 
    {
        #ifdef DEBUG_USB
        log.Print((const unsigned char*)"#Send:");
        log.PrintLn((ustr));
        #endif

        return 0;
    } break;

    case 2:
    {
        #ifdef DEBUG_USB
        log.PrintLn((const unsigned char*)"#Send error full!");
        #endif

        return -1;
    } break;

    case 3:
    {
        #ifdef DEBUG_USB
        log.PrintLn((const unsigned char*)"#Send error close!");
        #endif

        return -2;
    } break;
    }
}


// Clear send buffer.
void USB::ClearSendBuffer(void)
{
    Comm_ClearTransmitBuffer();
}


// Close the usb port.
void USB::Close(void)
{
    Comm_Close(1); // force close the port

    #ifdef DEBUG_USB
    log.PrintLn((const unsigned char*)"#Port close!");
    #endif
}


#ifdef __cplusplus
}
#endif