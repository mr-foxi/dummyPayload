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
};

extern KEYBOARD key;

#endif