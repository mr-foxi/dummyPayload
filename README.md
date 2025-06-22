# A Bad USB Arduino, that opens admin Powershell. Then pulls and runs a Powershell script from this repo.
## This branch is for the dummyPayload activiation Arduino Due (Or other Keyboard Library Arduino)

It will recieve command via serial (TX1/RX1). This can be either with the FoxFeather Directly, or now you can use the badPycopm branch with a Pycom (currently using WiPy3). This will create an AP for the FoxFeather to send command remotely!

### Current "issue"
Depending on the speed of your pc and some other variables. Payload timings may not be long enough in certain sequneces to fully succeed.
