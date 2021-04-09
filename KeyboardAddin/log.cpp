/*
File: log.cpp
Author: Myth
*/


#ifdef __cplusplus
extern "C" 
{
#endif


#include <fxlib.h>

#include "syscall.h"
#include "log.h"


Log::Log() : cursor_x(1), cursor_y(1)
{
    
}


// Must call this function in main function once!
void Log::Init(void)
{
    Clear();
}


// Print space.
void Log::Print(void)
{
    if (cursor_y > 8)
    {
        Clear();
    }
    else if (cursor_x == 1)
    {
        locate(cursor_x, cursor_y);

        cursor_x = 0;
    }

    ::Print((const unsigned char*)" ");

    Bdisp_PutDisp_DD();
}


// Print uch.
void Log::Print(unsigned char uch)
{
    if (cursor_y > 8)
    {
        Clear();
    }
    else if (cursor_x == 1)
    {
        locate(cursor_x, cursor_y);

        cursor_x = 0;
    }

    // change uch to uch_ustr
    unsigned char uch_ustr[2] = {'\0', '\0'};
    uch_ustr[0] = uch;

    ::Print(uch_ustr);

    Bdisp_PutDisp_DD();
}


// Print ustr.
void Log::Print(const unsigned char* ustr)
{
    if (cursor_y > 8)
    {
        Clear();
    }
    else if (cursor_x == 1)
    {
        locate(cursor_x, cursor_y);

        cursor_x = 0;
    }

    ::Print(ustr);

    Bdisp_PutDisp_DD();
}


// Print int .
void Log::Print(int num)
{
    if (cursor_y > 8)
    {
        Clear();
    }
    else if (cursor_x == 1)
    {
        locate(cursor_x, cursor_y);

        cursor_x = 0;
    }
    
    // change num to num_ustr
    unsigned char num_ustr[12];
    itoa(num, (unsigned int*)num_ustr);

    ::Print(num_ustr);

    Bdisp_PutDisp_DD();
}


// Print a blank line.
void Log::PrintLn(void)
{
    if (cursor_y > 8)
        Clear();
    else if (cursor_x == 1)
        locate(cursor_x, cursor_y);

    cursor_x = 1;
    cursor_y++;
}


// Print uch with a new line.
void Log::PrintLn(unsigned char uch)
{
    if (cursor_y > 8)
        Clear();
    else if (cursor_x == 1)
        locate(cursor_x, cursor_y);

    // change uch to uch_ustr
    unsigned char uch_ustr[2] = {'\0', '\0'};
    uch_ustr[0] = uch;

    ::Print(uch_ustr);

    Bdisp_PutDisp_DD();

    cursor_x = 1;
    cursor_y++;
}


// Print ustr with a new line.
void Log::PrintLn(const unsigned char* ustr)
{
    if (cursor_y > 8)
        Clear();
    else if (cursor_x == 1)
        locate(cursor_x, cursor_y);

    ::Print(ustr);

    Bdisp_PutDisp_DD();

    cursor_x = 1;
    cursor_y++;
}


// Print int with a new line.
void Log::PrintLn(int num)
{
    if (cursor_y > 8)
        Clear();
    else if (cursor_x == 1)
        locate(cursor_x, cursor_y);
    
    // change num to num_ustr
    unsigned char num_ustr[12];
    itoa(num, (unsigned int*)num_ustr);

    ::Print(num_ustr);

    Bdisp_PutDisp_DD();

    cursor_x = 1;
    cursor_y++;
}


// Clear the screen and reset line position.
void Log::Clear(void)
{
    Bdisp_AllClr_DDVRAM();

    cursor_x = 1;
    cursor_y = 1;

    locate(cursor_x, cursor_y);
}


#ifdef __cplusplus
}
#endif