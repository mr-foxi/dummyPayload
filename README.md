# A Bad USB Arduino, that opens admin Powershell. Then pulls and runs a Powershell script from this repo.

Paired functionality with FoxFeather (as of 21/06/2025)

When the "A" button is pressed on the FoxFeather. It will make the Arduino Due check it's SD card for a payload. 
If found it will check whether it is a known command and therefore run a pre-determined sequence of events.
If the command is not "pre-determined" it will attempt to use keyboard commands to open admin powershell through usb connection.
Then input whatever was in the payload.

When the "B" button is pressed on the FoxFeather. It will attempt to open admin powershell, and call a powershell script (dummyPayload.ps1) from this repo.
