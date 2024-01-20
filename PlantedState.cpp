#include "PlantedState.hpp"

#include "ClockState.hpp"
#include "sound.hpp"

namespace
{
int const CODE_SIZE = 7;
char const CODE[CODE_SIZE + 1] = "7355608";
char const* const HIDDEN_CODE = "*******";
} // namespace

PlantedState::PlantedState(Hardware const& hw, StateMachine& state)
  : State(hw, state)
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

    switch (key)
    {
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
            sound::play_charging(hw().mp3);

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
