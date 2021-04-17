#include <iostream>

#include "usb.h"
#include "getkey.h"


USB usb;
GetKey getkey;


int main(int argc, char *argv[])
{
    std::cout << "fxKeyboardLink v0.1" << std::endl;
    std::cout << "Copyright 2021 Myth" << std::endl << std::endl;

    switch (usb.Connect())
    {
    case 0: 
    {
        std::cout << "Connect fx-9860 calculator!" << std::endl;
    } break;
    
    case -1:
    {
        std::cout << "fx-9860 not found! Check the USB port and Add-in status." << std::endl;

        return 1;
    }

    case -2:
    {
        std::cout << "Access error! Check if the USB port has been occupied." << std::endl;

        return 1;
    }

    case -3:
    {
        std::cout << "Driver error! Please read the doc and use Zadig to replace the driver." << std::endl;

        return 1;
    }

    default:
    {
        std::cout << "Other error in connect process!" << std::endl;

        return 1;
    }
    }

    while (1)
    {
        switch (getkey.GetAndSendSystem())
        {
        case 0:
        {

        } break;

        case -1:
        {
            std::cout << "Device disconnect!" << std::endl;

            return 1;
        }

        default:
        {
            std::cout << "Other error in transmit process!" << std::endl;

            return 1;
        }
        }
    }
}

