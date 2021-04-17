/*
File: getkey.h
Author: Myth
Usage: Get the key from calculator and send it to system.
*/


#ifndef _GETKEY_H_
#define _GETKEY_H_


#define DEBUG_GETKEY

// Cursor directions
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3


class GetKey
{
public:
	GetKey();

	int GetAndSendSystem(void);

private:
	void PressKey(BYTE bVk);
	void PressKey(BYTE bVk_1, BYTE bVk_2);
	void MoveCursor(int direction);
	void ClickMouse(void);

	bool is_cursor;
};


#endif