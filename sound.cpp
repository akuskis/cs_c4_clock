#include "sound.hpp"

#include <Arduino.h>

namespace
{
int const CMD_DELAY = 100;
}

void sound::play_charging(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x04);
    mp3.write(0x42);
    mp3.write(0x01);
    mp3.write(0x03);
    mp3.write(0xEF);
}

void sound::play_click(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x04);
    mp3.write(0x42);
    mp3.write(0x01);
    mp3.write(0x02);
    mp3.write(0xEF);
}

void sound::play_planted(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x04);
    mp3.write(0x42);
    mp3.write(0x01);
    mp3.write(0x01);
    mp3.write(0xEF);
}

void sound::play_beep(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x04);
    mp3.write(0x42);
    mp3.write(0x01);
    mp3.write(0x04);
    mp3.write(0xEF);
}

void sound::play_difused(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x04);
    mp3.write(0x42);
    mp3.write(0x01);
    mp3.write(0x05);
    mp3.write(0xEF);
}

void sound::play_boom(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x04);
    mp3.write(0x42);
    mp3.write(0x01);
    mp3.write(0x06);
    mp3.write(0xEF);
}

void sound::set_low_volume(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x03);
    mp3.write(0x31);
    mp3.write(0x0E);
    mp3.write(0xEF);

    delay(CMD_DELAY);
    play_click(mp3);
}

void sound::set_mid_volume(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x03);
    mp3.write(0x31);
    mp3.write(0x19);
    mp3.write(0xEF);

    delay(CMD_DELAY);
    play_click(mp3);
}

void sound::set_high_volume(SoftwareSerial& mp3)
{
    mp3.write(0x7E);
    mp3.write(0x03);
    mp3.write(0x31);
    mp3.write(0x5F);
    mp3.write(0xEF);

    delay(CMD_DELAY);
    play_click(mp3);
}
