#include "Hardware.hpp"

Hardware::Hardware(LiquidCrystal_I2C& lcd, SoftwareSerial& mp3, DS3231& rtc, Keypad& keypad)
  : lcd(lcd),
    mp3(mp3),
    rtc(rtc),
    keypad(keypad)
{
}
