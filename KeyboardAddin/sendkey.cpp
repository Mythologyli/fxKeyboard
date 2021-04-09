/*
File: key.cpp
Author: Myth
*/


#ifdef __cplusplus
extern "C" 
{
#endif


#include <fxlib.h>

#include "usb.h"
#include "sendkey.h"


extern USB usb;


SendKey::SendKey()
{
    
}


// Send pressed key by usb port.
void SendKey::Send(void)
{
    unsigned int key;
    
    while (1)
    {
        GetKey(&key);

        switch (key)
        {
        case KEY_CHAR_0:
        {
            usb.Send((unsigned char *)"0");
        }
        break;

        case KEY_CHAR_1:
        {
            usb.Send((unsigned char *)"1");
        }
        break;

        case KEY_CHAR_2:
        {
            usb.Send((unsigned char *)"2");
        }
        break;

        case KEY_CHAR_3:
        {
            usb.Send((unsigned char *)"3");
        }
        break;

        case KEY_CHAR_4:
        {
            usb.Send((unsigned char *)"4");
        }
        break;

        case KEY_CHAR_5:
        {
            usb.Send((unsigned char *)"5");
        }
        break;

        case KEY_CHAR_6:
        {
            usb.Send((unsigned char *)"6");
        }
        break;

        case KEY_CHAR_7:
        {
            usb.Send((unsigned char *)"7");
        }
        break;

        case KEY_CHAR_8:
        {
            usb.Send((unsigned char *)"8");
        }
        break;

        case KEY_CHAR_9:
        {
            usb.Send((unsigned char *)"9");
        }
        }
    }
}


#ifdef __cplusplus
}
#endif