#pragma once

#include <DS3231.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

struct Hardware
{
    LiquidCrystal_I2C& lcd;
    SoftwareSerial& mp3;
    DS3231& rtc;
    Keypad& keypad;

    Hardware(LiquidCrystal_I2C& lcd, SoftwareSerial& mp3, DS3231& rtc, Keypad& keypad);
};
