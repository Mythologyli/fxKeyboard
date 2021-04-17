#ifdef __cplusplus
extern "C" 
{
#endif


#include <fxlib.h>

#include "log.h"
#include "usb.h"
#include "sendkey.h"
#include "syscall.h"


Log log;
USB usb;
SendKey sendkey;


// Quit handler to close the port.
void QuitHandler(void);


int AddIn_main(int isAppli, unsigned short OptionNum)
{
    log.Init(); // init log

    log.PrintLn((const unsigned char*)"fxKeyboard v0.1");
    log.PrintLn((const unsigned char*)"Copyright 2021 Myth");

    usb.Init(); // open port
    SetQuitHandler(QuitHandler); // set quit handler

    sendkey.Send();

    return 1;
}


// Quit handler to close the port.
void QuitHandler(void)
{
    unsigned int key;

    usb.Close(); // close the port before quit

    Bdisp_AllClr_DDVRAM();

    PopUpWin(1);
    locate(4, 4);
    Print((const unsigned char*)"Close USB Port!");

    GetKey(&key); // wait for any key pressed
}




#pragma section _BR_Size
unsigned long BR_Size;
#pragma section

#pragma section _TOP

int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#ifdef __cplusplus
}
#endif

#pragma section