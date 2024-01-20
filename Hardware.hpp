#pragma once

#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Key.h>
#include <Keypad.h>

struct Hardware
{
    LiquidCrystal_I2C& lcd;
    SoftwareSerial& mp3;
    DS3231& rtc;
    Keypad& keypad;

    Hardware(LiquidCrystal_I2C& lcd, SoftwareSerial& mp3, DS3231& rtc, Keypad& keypad);
};
