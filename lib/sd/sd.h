#ifndef SDBCARD_H
#define SDCARD_H

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int pinSD = 10;

class SDCARD
{
public:
    SDCARD();
    void init();
    void up();
    void down();
};

extern SDCARD sd;

#endif