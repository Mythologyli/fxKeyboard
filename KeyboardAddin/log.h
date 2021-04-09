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

    void Init(void); // Must call this function in main function once!

    void Print(void); // Print space.
    void Print(unsigned char uch); // Print uch.
    void Print(const unsigned char* ustr); // Print ustr.
    void Print(int num); // Print int.

    void PrintLn(void); // Print a blank line.
    void PrintLn(unsigned char uch); // Print uch with a new line.
    void PrintLn(const unsigned char* ustr); // Print ustr with a new line.
    void PrintLn(int num); // Print int with a new line.
    
    void Clear(void); // Clear the screen and reset line position.

private:
    int cursor_x;
    int cursor_y;
};


#ifdef __cplusplus
}
#endif

#endif