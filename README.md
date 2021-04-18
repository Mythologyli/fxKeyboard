# fxKeyboard

Use fx-9860 series calculator as a keyboard for computer.

**WARNING: THIS TOOL MAY DAMAGE YOUR CALCULATOR OR COMPUTER. ALWAYS FOLLOW THE DOC AND I WILL NOT BE RESPONSIBLE FOR ANY DAMAGE.**

## Usage

+ Use FA-124 software to copy the Add-in to your calculator.
+ Use the LINK app in calcutor menu to connect the calculator to your computer.
+ *READ NOTICE BEFORE THIS STEP!* Download Zadig from [here](https://zadig.akeo.ie/). Open Zadig, click Options - List All Device, select CESG502, and replace the original driver with WinUSB.
+ Open the Add-in in your calculator. It will automatically connect to your computer. If you didn't plug the USB cable, it will exit after a short time.
+ Open the fxKeyboardLink software in your computer. Now you can use your calculator as a keyboard for your computer.
+ Some special keyboard mapping:

  | Calculator Key | Computer |
  | ---- | ---- |
  | OPTN | Switch between arrow mode and cursor mode |
  | Arrow keys | Arrow keys in arrow mode and cursor controller in cursor mode |
  | θ | Text: theta |
  | EXIT | ESC |
  | QUIT | ESC |
  | ∠ | < |
  | sin-1 | Text: arcsin |
  | ab/c | / |
  | CAPTURE | PrintScreen |
  | CLIP | Ctrl + C |
  | PASTE | Ctrl + V |
  | DEL | Backspace |
  | INS | Insert |
  | ÷ | / |
  | π | Text: pi |
  | EXE | Enter in arrow mode and click in cursor mode
  | EXE with SHIFT | Enter with Shift pressed. This is convenient for using Mathmetica


## Notice

+ This tool will automatically open the NumLock in your computer.
+ Once your use Zadig to replace the original driver, you can't use FA-124 to link your calculater. If you want to get back to the original driver, follow Zadig's FAQ [here](https://github.com/pbatard/libwdi/wiki/FAQ#Help_Zadig_replaced_the_driver_for_the_wrong_device_How_do_I_restore_it) carefully. You need to know that the USB device is CESG502.
+ If you can't connect your calculator to your computer in any way, try to restart your calculator by the button behind.

## Known Issue

+ Press the calculator key down continously will not work like that in your computer. The reason is that I only used GetKey function in this Add-in.
+ In cursor mode, the cursor moved slowly in a constant speed.
+ I would be glad if someone can fix the issues above.

## Thanks

Thanks Simon Lothar for his great work in syscall.

## Build
| Software | Tool |
| ---- | ---- |
| Add-in: fxKeyboardAddin | fx-9860G Software Development Kit |
| Win32: fxKeyboardLink | Visual Studio 2019 with libusb-1.0 |