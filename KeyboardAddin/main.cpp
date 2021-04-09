#ifdef __cplusplus
extern "C" 
{
#endif


#include <fxlib.h>

#include "log.h"
#include "syscall.h"


Log log;


int AddIn_main(int isAppli, unsigned short OptionNum)
{
    unsigned int key;

    log.Init();

    log.PrintLn((const unsigned char*)"fxKeyboard v0.1");
    log.PrintLn((const unsigned char*)"Copyright 2021 Myth");

    while(1)
    {
        GetKey(&key);
    }

    return 1;
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