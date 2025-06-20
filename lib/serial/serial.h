#ifndef SERIAL_H
#define SERIAL_H

#include <Arduino.h>

class SERIALCOM
{
public:
    SERIALCOM();
    void up();
};

extern SERIALCOM serialCom;

#endif