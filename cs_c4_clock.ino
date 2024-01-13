#include <LCD_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <SoftwareSerial.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
int MP3_TX_PIN = 10;
int MP3_RX_PIN = 12;

SoftwareSerial mp3(MP3_TX_PIN, MP3_RX_PIN);

void setup()
{
    Serial.begin(9600);
    Serial.println("Setting Up MP3");

    mp3.begin(9600);

    // select SD card
    mp3.write(0x7E);
    mp3.write(0x03);
    mp3.write(0x35);
    mp3.write(0x01);
    mp3.write(0xEF);

    lcd.init();
    // lcd.begin();
    lcd.noBacklight();
}

void loop()
{
    delay(1000);

    lcd.setCursor(0, 0);
    lcd.print("HELLO");

    // Volume
    /*    mp3.write(0x7E);
       mp3.write(0x03);
       mp3.write(0x31);
       mp3.write(0x0F);
       mp3.write(0xEF);

       delay(1000);

       // Play
       mp3.write(0x7E);
       mp3.write(0x04);
       mp3.write(0x42);
       mp3.write(0x01);
       mp3.write(0x01);P
       mp3.write(0xEF); */

    delay(50000);
}
