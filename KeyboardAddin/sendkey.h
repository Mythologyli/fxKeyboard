/*
File: key.h 
Author: Myth
Usage: Get key and send.
*/


#ifndef _SENDKEY_H_
#define _SENDKEY_H_

#ifdef __cplusplus
extern "C" 
{
#endif


class SendKey
{
public:
    SendKey();

    void Send(void); // Send pressed key by usb port.

private:
    
};


#ifdef __cplusplus
}
#endif

#endif