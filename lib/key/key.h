#ifndef KEY_H
#define KEY_H

#include <Arduino.h>
#include <Keyboard.h>

class KEYBOARD
{
public:
    KEYBOARD();
    void up();
    void openPS();
    void pullScript();
    void pullScriptExit();
    void runPayload(String);
};

extern KEYBOARD key;

#endif