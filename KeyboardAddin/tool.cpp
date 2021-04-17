/*
File: tool.cpp
Author: Myth
*/


#ifdef __cplusplus
extern "C" 
{
#endif


#include "tool.h"


// Length of unsigned str. Max 256 bytes.
// Return
// -1 : input NULL
// -2 : no \0 in 256 bytes
int uStrLen(const unsigned char* ustr)
{
    if (ustr == 0)
        return -1;
    
    int i;
    
    for (i = 0; ; i++)
    {
        if (ustr[i] == '\0')
            break;
        else if (i == 256)
        {
            i = -2;
            break;
        }
    }

    return i;
}


#ifdef __cplusplus
}
#endif