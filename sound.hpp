#pragma once

#include <SoftwareSerial.h>

namespace sound
{
void play_charging(SoftwareSerial& mp3);
void play_click(SoftwareSerial& mp3);
void play_planted(SoftwareSerial& mp3);
void play_beep(SoftwareSerial& mp3);
void play_difused(SoftwareSerial& mp3);
void play_boom(SoftwareSerial& mp3);

void set_low_volume(SoftwareSerial& mp3);
void set_mid_volume(SoftwareSerial& mp3);
void set_high_volume(SoftwareSerial& mp3);
} // namespace sound
