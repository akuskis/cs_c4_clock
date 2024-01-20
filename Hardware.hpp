#pragma once

#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


struct Hardware
{
    LiquidCrystal_I2C& lcd;
    SoftwareSerial& mp3;
    DS3231& rtc;

    Hardware(LiquidCrystal_I2C& lcd, SoftwareSerial& mp3, DS3231& rtc);
};
