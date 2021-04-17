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
    unsigned int key = 0;

    while (1)
    {
        GetKey(&key);

        switch (key)
        {
        case KEY_CHAR_0:
        {
            usb.Send((unsigned char *)"0");
        } break;

        case KEY_CHAR_1:
        {
            usb.Send((unsigned char *)"1");
        } break;

        case KEY_CHAR_2:
        {
            usb.Send((unsigned char *)"2");
        } break;

        case KEY_CHAR_3:
        {
            usb.Send((unsigned char *)"3");
        } break;

        case KEY_CHAR_4:
        {
            usb.Send((unsigned char *)"4");
        } break;

        case KEY_CHAR_5:
        {
            usb.Send((unsigned char *)"5");
        } break;

        case KEY_CHAR_6:
        {
            usb.Send((unsigned char *)"6");
        } break;

        case KEY_CHAR_7:
        {
            usb.Send((unsigned char *)"7");
        } break;

        case KEY_CHAR_8:
        {
            usb.Send((unsigned char *)"8");
        } break;

        case KEY_CHAR_9:
        {
            usb.Send((unsigned char *)"9");
        } break;

        case KEY_CHAR_DP:
        {
            usb.Send((unsigned char *)".");
        } break;

        case KEY_CHAR_EXP:
        {
            usb.Send((unsigned char *)"$exp");
        } break;

        case KEY_CHAR_PMINUS:
        {
            usb.Send((unsigned char *)"-");
        } break;

        case KEY_CHAR_PLUS:
        {
            usb.Send((unsigned char *)"+");
        } break;

        case KEY_CHAR_MINUS:
        {
            usb.Send((unsigned char *)"-");
        } break;

        case KEY_CHAR_MULT:
        {
            usb.Send((unsigned char *)"*");
        } break;

        case KEY_CHAR_DIV:
        {
            usb.Send((unsigned char *)"/");
        } break;

        case KEY_CTRL_EXE:
        {
            usb.Send((unsigned char *)"$exe");
        } break;

        case KEY_CTRL_DEL:
        {
            usb.Send((unsigned char *)"$del");
        } break;

        case KEY_CHAR_FRAC:
        {
            usb.Send((unsigned char *)"/");
        } break;

        case KEY_CHAR_LPAR:
        {
            usb.Send((unsigned char *)"(");
        } break;

        case KEY_CHAR_RPAR:
        {
            usb.Send((unsigned char *)")");
        } break;

        case KEY_CHAR_COMMA:
        {
            usb.Send((unsigned char *)",");
        } break;

        case KEY_CTRL_XTT:
        {
            usb.Send((unsigned char *)"x");
        } break;

        case KEY_CHAR_LOG:
        {
            usb.Send((unsigned char *)"log");
        } break;

        case KEY_CHAR_LN:
        {
            usb.Send((unsigned char *)"ln");
        } break;

        case KEY_CHAR_SIN:
        {
            usb.Send((unsigned char *)"sin");
        } break;

        case KEY_CHAR_COS:
        {
            usb.Send((unsigned char *)"cos");
        } break;

        case KEY_CHAR_TAN:
        {
            usb.Send((unsigned char *)"tan");
        } break;

        case KEY_CHAR_SQUARE:
        {
            usb.Send((unsigned char *)"^2");
        } break;

        case KEY_CHAR_POW:
        {
            usb.Send((unsigned char *)"^");
        } break;

        case KEY_CTRL_EXIT:
        {
            usb.Send((unsigned char *)"$exit");
        } break;

        case KEY_CTRL_OPTN:
        {
            usb.Send((unsigned char *)"$optn");
        } break;

        case KEY_CTRL_UP:
        {
            usb.Send((unsigned char *)"$up");
        } break;

        case KEY_CTRL_DOWN:
        {
            usb.Send((unsigned char *)"$down");
        } break;

        case KEY_CTRL_LEFT:
        {
            usb.Send((unsigned char *)"$left");
        } break;

        case KEY_CTRL_RIGHT:
        {
            usb.Send((unsigned char *)"$right");
        } break;

        case KEY_CTRL_F1:
        {
            usb.Send((unsigned char *)"$f1");
        } break;

        case KEY_CTRL_F2:
        {
            usb.Send((unsigned char *)"$f2");
        } break;

        case KEY_CTRL_F3:
        {
            usb.Send((unsigned char *)"$f3");
        } break;

        case KEY_CTRL_F4:
        {
            usb.Send((unsigned char *)"$f4");
        } break;

        case KEY_CTRL_F5:
        {
            usb.Send((unsigned char *)"$f5");
        } break;

        case KEY_CTRL_F6:
        {
            usb.Send((unsigned char *)"$f6");
        } break;

        case KEY_CHAR_IMGNRY:
        {
            usb.Send((unsigned char *)"i");
        } break;

        case KEY_CTRL_CAPTURE:
        {
            usb.Send((unsigned char *)"$capture");
        } break;

        case KEY_CTRL_CLIP:
        {
            usb.Send((unsigned char *)"$clip");
        } break;

        case KEY_CTRL_PASTE:
        {
            usb.Send((unsigned char *)"$paste");
        } break;

        case KEY_CHAR_EQUAL:
        {
            usb.Send((unsigned char *)"=");
        } break;

        case KEY_CHAR_PI:
        {
            usb.Send((unsigned char *)"pi");
        } break;

        case KEY_CHAR_LBRCKT:
        {
            usb.Send((unsigned char *)"[");
        } break;

        case KEY_CHAR_RBRCKT:
        {
            usb.Send((unsigned char *)"]");
        } break;

        case KEY_CHAR_LBRACE:
        {
            usb.Send((unsigned char *)"{");
        } break;

        case KEY_CHAR_RBRACE:
        {
            usb.Send((unsigned char *)"}");
        } break;

        case KEY_CHAR_CR:
        {
            usb.Send((unsigned char *)"$return");
        } break;

        case KEY_CTRL_INS:
        {
            usb.Send((unsigned char *)"$insert");
        } break;

        case KEY_CHAR_CUBEROOT:
        {
            usb.Send((unsigned char *)"^(1/3)");
        } break;

        case KEY_CHAR_RECIP:
        {
            usb.Send((unsigned char *)"^(-1)");
        } break;

        case KEY_CHAR_ANGLE:
        {
            usb.Send((unsigned char *)"<");
        } break;

        case KEY_CHAR_EXPN10:
        {
            usb.Send((unsigned char *)"10^");
        } break;

        case KEY_CHAR_EXPN:
        {
            usb.Send((unsigned char *)"e^");
        } break;

        case KEY_CHAR_ASIN:
        {
            usb.Send((unsigned char *)"arcsin");
        } break;

        case KEY_CHAR_ACOS:
        {
            usb.Send((unsigned char *)"arccos");
        } break;

        case KEY_CHAR_ATAN:
        {
            usb.Send((unsigned char *)"arctan");
        } break;

        case KEY_CHAR_ROOT:
        {
            usb.Send((unsigned char *)"^(1/2)");
        } break;

        case KEY_CHAR_POWROOT:
        {
            usb.Send((unsigned char *)"^(1/");
        } break;

        case KEY_CTRL_QUIT:
        {
            usb.Send((unsigned char *)"$quit");
        } break;

        case KEY_CTRL_PAGEUP:
        {
            usb.Send((unsigned char *)"$pageup");
        } break;

        case KEY_CTRL_PAGEDOWN:
        {
            usb.Send((unsigned char *)"$pagedown");
        } break;

        case KEY_CHAR_Z:
        {
            usb.Send((unsigned char *)"Z");
        } break;

        case KEY_CHAR_U:
        {
            usb.Send((unsigned char *)"U");
        } break;

        case KEY_CHAR_V:
        {
            usb.Send((unsigned char *)"V");
        } break;

        case KEY_CHAR_W:
        {
            usb.Send((unsigned char *)"W");
        } break;

        case KEY_CHAR_P:
        {
            usb.Send((unsigned char *)"P");
        } break;

        case KEY_CHAR_Q:
        {
            usb.Send((unsigned char *)"Q");
        } break;

        case KEY_CHAR_R:
        {
            usb.Send((unsigned char *)"R");
        } break;

        case KEY_CHAR_M:
        {
            usb.Send((unsigned char *)"M");
        } break;

        case KEY_CHAR_O:
        {
            usb.Send((unsigned char *)"O");
        } break;

        case KEY_CHAR_SPACE:
        {
            usb.Send((unsigned char *)" ");
        } break;

        case KEY_CHAR_DQUATE:
        {
            usb.Send((unsigned char *)"\"");
        } break;

        case KEY_CHAR_X:
        {
            usb.Send((unsigned char *)"X");
        } break;

        case KEY_CHAR_Y:
        {
            usb.Send((unsigned char *)"Y");
        } break;

        case KEY_CHAR_S:
        {
            usb.Send((unsigned char *)"S");
        } break;

        case KEY_CHAR_T:
        {
            usb.Send((unsigned char *)"T");
        } break;

        case KEY_CHAR_G:
        {
            usb.Send((unsigned char *)"G");
        } break;

        case KEY_CHAR_H:
        {
            usb.Send((unsigned char *)"H");
        } break;

        case KEY_CHAR_I:
        {
            usb.Send((unsigned char *)"I");
        } break;

        case KEY_CHAR_J:
        {
            usb.Send((unsigned char *)"J");
        } break;

        case KEY_CHAR_K:
        {
            usb.Send((unsigned char *)"K");
        } break;

        case KEY_CHAR_L:
        {
            usb.Send((unsigned char *)"L");
        } break;

        case KEY_CHAR_A:
        {
            usb.Send((unsigned char *)"A");
        } break;

        case KEY_CHAR_B:
        {
            usb.Send((unsigned char *)"B");
        } break;

        case KEY_CHAR_C:
        {
            usb.Send((unsigned char *)"C");
        } break;

        case KEY_CHAR_D:
        {
            usb.Send((unsigned char *)"D");
        } break;

        case KEY_CHAR_E:
        {
            usb.Send((unsigned char *)"E");
        } break;

        case KEY_CHAR_F:
        {
            usb.Send((unsigned char *)"F");
        } break;

        case KEY_CHAR_VALR:
        {
            usb.Send((unsigned char *)"r");
        } break;

        case KEY_CHAR_THETA:
        {
            usb.Send((unsigned char *)"theta");
        }
        }
    }
}


#ifdef __cplusplus
}
#endif