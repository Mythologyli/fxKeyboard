/*
File: log.h 
Author: Myth
Usage: Output logs in calculator screen.
*/


#ifndef _LOG_H_
#define _LOG_H_

#ifdef __cplusplus
extern "C" 
{
#endif


class Log
{
public:
    Log();

    static void Init(void); // Must call this function in main function once!

    static void Print(void); // Print space.
    static void Print(unsigned char uch); // Print uch.
    static void Print(const unsigned char* ustr); // Print ustr.
    static void Print(int num); // Print int.

    static void PrintLn(void); // Print a blank line.
    static void PrintLn(unsigned char uch); // Print uch with a new line.
    static void PrintLn(const unsigned char* ustr); // Print ustr with a new line.
    static void PrintLn(int num); // Print int with a new line.
    
    static void Clear(void); // Clear the screen and reset line position.

private:
    static int cursor_x;
    static int cursor_y;
};


#ifdef __cplusplus
}
#endif

#endif