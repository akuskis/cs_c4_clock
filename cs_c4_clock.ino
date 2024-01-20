#include "Applicaiton.hpp"
#include "Hardware.hpp"

#include <LCD_I2C.h>
#include <Wire.h>

#include <SoftwareSerial.h>


DS3231 rtc;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int const MP3_TX_PIN = 10;
int const MP3_RX_PIN = 12;
SoftwareSerial mp3(MP3_TX_PIN, MP3_RX_PIN);

byte const ROWS = 4;
byte const COLS = 3;
char const KEYS[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'},
};
byte const ROW_PINS[ROWS] = {5, 4, 3, 2};
byte const COL_PINS[COLS] = {11, 9, 8};
Keypad keypad(makeKeymap(KEYS), ROW_PINS, COL_PINS, ROWS, COLS);

namespace
{
void initialize_audio()
{
    mp3.begin(9600);

    // select SD card
    mp3.write(0x7E);
    mp3.write(0x03);
    mp3.write(0x35);
    mp3.write(0x01);
    mp3.write(0xEF);
}

void initialize_lcd()
{
    lcd.init();
    lcd.noBacklight();
}

void initialize_rtc()
{
    rtc.setClockMode(false);
}
} // namespace

void setup()
{
    initialize_audio();
    initialize_lcd();
    initialize_rtc();
}

void loop()
{
    delay(500);

    Hardware hw(lcd, mp3, rtc, keypad);
    Application app(hw);
    app.run();
}
