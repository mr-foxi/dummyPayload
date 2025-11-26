# dummyPayload
This project is designed for me to test a "Bad USB" type functionality with an Arduino Due (Or any supports the Keyboard library - https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/). Once the Arduino is plugged into an already unlocked Windows 10/11 PC, it will open Powershell with admin rights using keyboard shortcuts. Then proceed to type in a command which will pull and run dummyPayload.ps1 from this Github repo on the target PC.

The main branch contains dummyPayload.ps1 a powershell script that will dump information about your currently running applications into C:/.

The CPP_PlatformIO branch is a Visual Studio, C++ project build with PLatformIO for loading the firmware. IT IS IMPORTANT TO ADJUST PLATFORMIO.INI if you use this with anything other than Arduino Due.

The Arduino_Script branch is for use with Arduino IDE.


