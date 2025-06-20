# dummyPayload
This project is designed for me to test a "Bad USB" type functionality with an Arduino Due (Or any supports the Keyboard library).
(https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/).

It contains dummyPayload.ps1 a powershell script that will dump information from RAM about your currently running applications into C://, and badUSB_memDump.ino which is the Arduino script file.

Once the Arduino is plugged into an already unlocked Windows 10/11 PC, it will open Powershell with admin rights using keyboard shortcuts.
Then proceed to type in the command which will pull and run dummyPayload.ps1 on the target PC.
