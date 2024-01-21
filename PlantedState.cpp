#include "PlantedState.hpp"

#include "ClockState.hpp"
#include "sound.hpp"

namespace
{
int const CODE_SIZE = 7;
char const CODE[CODE_SIZE + 1] = "7355608";
char const* const HIDDEN_CODE = "*******";

unsigned long const DURATION_MS = 20000;
} // namespace

PlantedState::PlantedState(Hardware const& hw, StateMachine& state)
  : State(hw, state),
    started_(millis()),
    deadline_(started_ + DURATION_MS),
    next_beep_(started_ + 3000)
{
    strcpy(str, HIDDEN_CODE);

    hw.lcd.clear();

    hw.lcd.setCursor(0, 0);
    hw.lcd.print("Count down: ");

    hw.lcd.setCursor(0, 1);
    hw.lcd.print("Defuse:");
}

void PlantedState::update()
{
    auto const key = hw().keypad.getKey();

    if ('0' <= key && key <= '9')
        handle_value_(key);

    auto current = millis();

    if (current > deadline_)
    {
        sound::play_boom(hw().mp3);
        state().replace(new ClockState(hw(), state()));
    }

    if (current > next_beep_)
    {
        sound::play_beep(hw().mp3);
        if (deadline_ - current < 2000)
            next_beep_ = deadline_;
        else if (deadline_ - current < 6000)
            next_beep_ = current + 600;
        else
            next_beep_ = current + (deadline_ - current) / 10;
    }
}

void PlantedState::render()
{
    hw().lcd.setCursor(8, 1);
    hw().lcd.print(str);
}

void PlantedState::handle_value_(byte key)
{
    if (CODE[index_] == key)
    {
        if (index_ == 0)
        {
            sound::play_charging(hw().mp3);
            next_beep_ = millis() + 1600;
        }

        str[index_++] = key;

        if (index_ == sizeof(CODE) - 1)
        {
            sound::play_difused(hw().mp3);
            state().replace(new ClockState(hw(), state()));
        }
    }
    else
    {
        index_ = 0;
        strcpy(str, HIDDEN_CODE);
    }
}
