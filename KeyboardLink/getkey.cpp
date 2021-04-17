/*
File: getkey.cpp
Author: Myth
*/


#include <iostream>
#include <windows.h>

#include "usb.h"
#include "getkey.h"


extern USB usb;


GetKey::GetKey() : is_cursor(false)
{
    // Set NumLock on
    if ((GetKeyState(VK_NUMLOCK) & 0x0001) == 0)
        PressKey(VK_NUMLOCK);
}


// Get key from fx-9860 and send it to system.
// Return:
// 0 : success
// -1 : disconnect
// -2 : other link error
int GetKey::GetAndSendSystem(void)
{
    unsigned char temp_ustr[MAX_PACKET_SIZE];
    
    while (1)
    {
        switch (usb.Receive(temp_ustr))
        {
        case 0: // receive success
        {
            char temp_str[MAX_PACKET_SIZE];
            strcpy(temp_str, (const char*)temp_ustr);
            
            if (strcmp(temp_str, "0") == 0)
            {
                PressKey(VK_NUMPAD0);
            }
            else if (strcmp(temp_str, "1") == 0)
            {
                PressKey(VK_NUMPAD1);
            }
            else if (strcmp(temp_str, "2") == 0)
            {
                PressKey(VK_NUMPAD2);
            }
            else if (strcmp(temp_str, "3") == 0)
            {
                PressKey(VK_NUMPAD3);
            }
            else if (strcmp(temp_str, "4") == 0)
            {
                PressKey(VK_NUMPAD4);
            }
            else if (strcmp(temp_str, "5") == 0)
            {
                PressKey(VK_NUMPAD5);
            }
            else if (strcmp(temp_str, "6") == 0)
            {
                PressKey(VK_NUMPAD6);
            }
            else if (strcmp(temp_str, "7") == 0)
            {
                PressKey(VK_NUMPAD7);
            }
            else if (strcmp(temp_str, "8") == 0)
            {
                PressKey(VK_NUMPAD8);
            }
            else if (strcmp(temp_str, "9") == 0)
            {
                PressKey(VK_NUMPAD9);
            }
            else if (strcmp(temp_str, ".") == 0)
            {
                PressKey(VK_DECIMAL);
            }
            else if (strcmp(temp_str, "$exp") == 0)
            {
                PressKey('E');
            }
            else if (strcmp(temp_str, "+") == 0)
            {
                PressKey(VK_ADD);
            }
            else if (strcmp(temp_str, "-") == 0)
            {
                PressKey(VK_SUBTRACT);
            }
            else if (strcmp(temp_str, "*") == 0)
            {
                PressKey(VK_MULTIPLY);
            }
            else if (strcmp(temp_str, "/") == 0)
            {
                PressKey(VK_DIVIDE);
            }
            else if (strcmp(temp_str, "$exe") == 0)
            {
                if (is_cursor)
                    ClickMouse();
                else 
                    PressKey(VK_RETURN);
            }
            else if (strcmp(temp_str, "$del") == 0)
            {
                PressKey(VK_BACK);
            }
            else if (strcmp(temp_str, "(") == 0)
            {
                PressKey(VK_SHIFT, '9');
            }
            else if (strcmp(temp_str, ")") == 0)
            {
                PressKey(VK_SHIFT, '0');
            }
            else if (strcmp(temp_str, ",") == 0)
            {
                PressKey(VK_OEM_COMMA);
            }
            else if (strcmp(temp_str, "x") == 0)
            {
                PressKey('X');
            }
            else if (strcmp(temp_str, "log") == 0)
            {
                PressKey('L');
                PressKey('O');
                PressKey('G');
            }
            else if (strcmp(temp_str, "ln") == 0)
            {
                PressKey('L');
                PressKey('N');
            }
            else if (strcmp(temp_str, "sin") == 0)
            {
                PressKey('S');
                PressKey('I');
                PressKey('N');
            }
            else if (strcmp(temp_str, "cos") == 0)
            {
                PressKey('C');
                PressKey('O');
                PressKey('S');
            }
            else if (strcmp(temp_str, "tan") == 0)
            {
                PressKey('T');
                PressKey('A');
                PressKey('N');
            }
            else if (strcmp(temp_str, "^2") == 0)
            {
                PressKey(VK_SHIFT, '6');
                PressKey('2');
            }
            else if (strcmp(temp_str, "^") == 0)
            {
                PressKey(VK_SHIFT, '6');
            }
            else if (strcmp(temp_str, "$exit") == 0)
            {
                PressKey(VK_ESCAPE);
            }
            else if (strcmp(temp_str, "$optn") == 0)
            {
                is_cursor = !is_cursor;
            }
            else if (strcmp(temp_str, "$up") == 0)
            {
                if (is_cursor)
                    MoveCursor(UP);
                else
                    PressKey(VK_UP);
            }
            else if (strcmp(temp_str, "$down") == 0)
            {
                if (is_cursor)
                    MoveCursor(DOWN);
                else
                    PressKey(VK_DOWN);
            }
            else if (strcmp(temp_str, "$left") == 0)
            {
                if (is_cursor)
                    MoveCursor(LEFT);
                else
                    PressKey(VK_LEFT);
            }
            else if (strcmp(temp_str, "$right") == 0)
            {
                if (is_cursor)
                    MoveCursor(RIGHT);
                else
                    PressKey(VK_RIGHT);
            }
            else if (strcmp(temp_str, "$f1") == 0)
            {
                PressKey(VK_F1);
            }
            else if (strcmp(temp_str, "$f2") == 0)
            {
                PressKey(VK_F2);
            }
            else if (strcmp(temp_str, "$f3") == 0)
            {
                PressKey(VK_F3);
            }
            else if (strcmp(temp_str, "$f4") == 0)
            {
                PressKey(VK_F4);
            }
            else if (strcmp(temp_str, "$f5") == 0)
            {
                PressKey(VK_F5);
            }
            else if (strcmp(temp_str, "$f6") == 0)
            {
                PressKey(VK_F6);
            }
            else if (strcmp(temp_str, "i") == 0)
            {
                PressKey('I');
            }
            else if (strcmp(temp_str, "$capture") == 0)
            {
                PressKey(VK_SNAPSHOT);
            }
            else if (strcmp(temp_str, "$clip") == 0)
            {
                PressKey(VK_CONTROL, 'C');
            }
            else if (strcmp(temp_str, "$paste") == 0)
            {
                PressKey(VK_CONTROL, 'V');
            }
            else if (strcmp(temp_str, "=") == 0)
            {
                PressKey(VK_OEM_PLUS);
            }
            else if (strcmp(temp_str, "pi") == 0)
            {
                PressKey('P');
                PressKey('I');
            }
            else if (strcmp(temp_str, "[") == 0)
            {
                PressKey(VK_OEM_4);
            }
            else if (strcmp(temp_str, "]") == 0)
            {
                PressKey(VK_OEM_6);
            }
            else if (strcmp(temp_str, "{") == 0)
            {
                PressKey(VK_SHIFT, VK_OEM_4);
            }
            else if (strcmp(temp_str, "}") == 0)
            {
                PressKey(VK_SHIFT, VK_OEM_6);
            }
            else if (strcmp(temp_str, "$return") == 0)
            {
                PressKey(VK_SHIFT, VK_RETURN);
            }
            else if (strcmp(temp_str, "$insert") == 0)
            {
                PressKey(VK_INSERT);
            }
            else if (strcmp(temp_str, "^(1/3)") == 0)
            {
                PressKey(VK_SHIFT, '6');
                PressKey(VK_SHIFT, '9');
                PressKey('1');
                PressKey(VK_DIVIDE);
                PressKey('3');
                PressKey(VK_SHIFT, '0');
            }
            else if (strcmp(temp_str, "^(-1)") == 0)
            {
                PressKey(VK_SHIFT, '6');
                PressKey(VK_SHIFT, '9');
                PressKey(VK_SUBTRACT);
                PressKey('1');
                PressKey(VK_SHIFT, '0');
            }
            else if (strcmp(temp_str, "<") == 0)
            {
                PressKey(VK_SHIFT, VK_OEM_COMMA);
            }
            else if (strcmp(temp_str, "10^") == 0)
            {
                PressKey('1');
                PressKey('0');
                PressKey(VK_SHIFT, '6');
            }
            else if (strcmp(temp_str, "e^") == 0)
            {
                PressKey('E');
                PressKey(VK_SHIFT, '6');
            }
            else if (strcmp(temp_str, "arcsin") == 0)
            {
                PressKey('A');
                PressKey('R');
                PressKey('C');
                PressKey('S');
                PressKey('I');
                PressKey('N');
            }
            else if (strcmp(temp_str, "arccos") == 0)
            {
                PressKey('A');
                PressKey('R');
                PressKey('C');
                PressKey('C');
                PressKey('O');
                PressKey('S');
            }
            else if (strcmp(temp_str, "arctan") == 0)
            {
                PressKey('A');
                PressKey('R');
                PressKey('C');
                PressKey('T');
                PressKey('A');
                PressKey('N');
            }
            else if (strcmp(temp_str, "^(1/2)") == 0)
            {
                PressKey(VK_SHIFT, '6');
                PressKey(VK_SHIFT, '9');
                PressKey('1');
                PressKey(VK_DIVIDE);
                PressKey('2');
                PressKey(VK_SHIFT, '0');
            }
            else if (strcmp(temp_str, "^(1/") == 0)
            {
                PressKey(VK_SHIFT, '6');
                PressKey(VK_SHIFT, '9');
                PressKey('1');
                PressKey(VK_DIVIDE);
            }
            else if (strcmp(temp_str, "$quit") == 0)
            {
                PressKey(VK_ESCAPE);
            }
            else if (strcmp(temp_str, "$pageup") == 0)
            {
                PressKey(VK_PRIOR);
            }
            else if (strcmp(temp_str, "$pagedown") == 0)
            {
                PressKey(VK_NEXT);
            }
            else if (strcmp(temp_str, "A") == 0)
            {
                PressKey('A');
            }
            else if (strcmp(temp_str, "B") == 0)
            {
                PressKey('B');
            }
            else if (strcmp(temp_str, "C") == 0)
            {
                PressKey('C');
            }
            else if (strcmp(temp_str, "D") == 0)
            {
                PressKey('D');
            }
            else if (strcmp(temp_str, "E") == 0)
            {
                PressKey('E');
            }
            else if (strcmp(temp_str, "F") == 0)
            {
                PressKey('F');
            }
            else if (strcmp(temp_str, "G") == 0)
            {
                PressKey('G');
            }
            else if (strcmp(temp_str, "H") == 0)
            {
                PressKey('H');
            }
            else if (strcmp(temp_str, "I") == 0)
            {
                PressKey('I');
            }
            else if (strcmp(temp_str, "G") == 0)
            {
                PressKey('G');
            }
            else if (strcmp(temp_str, "K") == 0)
            {
                PressKey('K');
            }
            else if (strcmp(temp_str, "L") == 0)
            {
                PressKey('L');
            }
            else if (strcmp(temp_str, "M") == 0)
            {
                PressKey('M');
            }
            else if (strcmp(temp_str, "N") == 0)
            {
                PressKey('N');
            }
            else if (strcmp(temp_str, "O") == 0)
            {
                PressKey('O');
            }
            else if (strcmp(temp_str, "P") == 0)
            {
                PressKey('P');
            }
            else if (strcmp(temp_str, "Q") == 0)
            {
                PressKey('Q');
            }
            else if (strcmp(temp_str, "R") == 0)
            {
                PressKey('R');
            }
            else if (strcmp(temp_str, "S") == 0)
            {
                PressKey('S');
            }
            else if (strcmp(temp_str, "T") == 0)
            {
                PressKey('T');
            }
            else if (strcmp(temp_str, "U") == 0)
            {
                PressKey('U');
            }
            else if (strcmp(temp_str, "V") == 0)
            {
                PressKey('V');
            }
            else if (strcmp(temp_str, "W") == 0)
            {
                PressKey('W');
            }
            else if (strcmp(temp_str, "X") == 0)
            {
                PressKey('X');
            }
            else if (strcmp(temp_str, "Y") == 0)
            {
                PressKey('Y');
            }
            else if (strcmp(temp_str, "Z") == 0)
            {
                PressKey('Z');
            }
            else if (strcmp(temp_str, " ") == 0)
            {
                PressKey(VK_SPACE);
            }
            else if (strcmp(temp_str, "\"") == 0)
            {
                PressKey(VK_SHIFT, VK_OEM_7);
            }
            else if (strcmp(temp_str, "r") == 0)
            {
                PressKey('R');
            }
            else if (strcmp(temp_str, "theta") == 0)
            {
                PressKey('T');
                PressKey('H');
                PressKey('E');
                PressKey('T');
                PressKey('A');
            }
            else
            {
                continue;
            }

            return 0;
        }

        case -1: // disconnect
        {
            return -1;
        }

        default: // other error
        {
            return -2;
        }
        }
    }
}


void GetKey::PressKey(BYTE bVk)
{
    keybd_event(bVk, 0, 0, 0);
    keybd_event(bVk, 0, KEYEVENTF_KEYUP, 0);
}


void GetKey::PressKey(BYTE bVk_1, BYTE bVk_2)
{
    keybd_event(bVk_1, 0, 0, 0);
    keybd_event(bVk_2, 0, 0, 0);
    keybd_event(bVk_1, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(bVk_2, 0, KEYEVENTF_KEYUP, 0);
}


void GetKey::MoveCursor(int direction)
{
    switch (direction)
    {
    case LEFT: mouse_event(MOUSEEVENTF_MOVE, -5, 0, 0, 0); break;
    case RIGHT: mouse_event(MOUSEEVENTF_MOVE, 5, 0, 0, 0); break;
    case UP: mouse_event(MOUSEEVENTF_MOVE, 0, -5, 0, 0); break;
    case DOWN: mouse_event(MOUSEEVENTF_MOVE, 0, 5, 0, 0);
    }
}


void GetKey::ClickMouse(void)
{
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}