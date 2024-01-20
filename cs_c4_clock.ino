#include "Applicaiton.hpp"
#include "Hardware.hpp"

#include <DS3231.h>
#include <LCD_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <SoftwareSerial.h>


DS3231 rtc;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int MP3_TX_PIN = 10;
int MP3_RX_PIN = 12;
SoftwareSerial mp3(MP3_TX_PIN, MP3_RX_PIN);

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

    Hardware hw(lcd, mp3, rtc);
    Application app(hw);
    app.run();
}
