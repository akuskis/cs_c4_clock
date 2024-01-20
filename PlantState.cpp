#include "PlantState.hpp"

#include "ClockState.hpp"
#include "PlantedState.hpp"
#include "sound.hpp"

namespace
{
int const CODE_SIZE = 7;
char const CODE[CODE_SIZE + 1] = "7355608";
} // namespace

PlantState::PlantState(Hardware const& hw, StateMachine& state)
  : State(hw, state)
{
    hw.lcd.clear();

    hw.lcd.setCursor(0, 0);
    hw.lcd.print("--- PLANTING ---");

    hw.lcd.setCursor(0, 1);
    hw.lcd.print("CODE:");

    sound::play_charging(hw.mp3);
}

void PlantState::update()
{
    auto const key = hw().keypad.getKey();

    switch (key)
    {
    case '#':
        state().replace(new ClockState(hw(), state()));
        break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        handle_value_(key);
        break;
    }
}

void PlantState::render()
{
    hw().lcd.setCursor(6, 1);
    hw().lcd.print(str);
}

void PlantState::handle_value_(byte key)
{
    if (CODE[index_] == key)
    {
        str[index_++] = key;

        if (index_ == sizeof(CODE) - 1)
        {
            sound::play_planted(hw().mp3);
            state().replace(new PlantedState(hw(), state()));
        }
        else
        {
            sound::play_click(hw().mp3);
        }
    }
    else
    {
        state().replace(new PlantState(hw(), state()));
    }
}