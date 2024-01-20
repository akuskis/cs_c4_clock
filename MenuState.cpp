#include "MenuState.hpp"

#include "ClockState.hpp"
#include "PlantState.hpp"
#include "SetAlarmState.hpp"
#include "SetTimeState.hpp"

int const OPTIONS_COUNT = 3;
char const OPTIONS[OPTIONS_COUNT][16] = {"Plant bomb", "Set Alarm", "Set Current Time"};

MenuState::MenuState(Hardware const& hw, StateMachine& state)
  : State(hw, state)
{
    hw.lcd.clear();
}

void MenuState::update()
{
    auto const key = hw().keypad.getKey();

    switch (key)
    {
    case '2':
        index_ = (index_ == 0) ? OPTIONS_COUNT - 1 : index_ - 1;
        hw().lcd.clear();
        break;
    case '8':
        index_ = (index_ + 1) % OPTIONS_COUNT;
        hw().lcd.clear();
        break;
    case '*':
        select_item_();
        break;
    case '#':
        state().replace(new ClockState(hw(), state()));
        break;
    }
}

void MenuState::render()
{
    hw().lcd.setCursor(0, 0);
    hw().lcd.print("----- MENU -----");

    hw().lcd.setCursor(0, 1);
    hw().lcd.print(OPTIONS[index_]);
}

void MenuState::select_item_()
{
    switch (index_)
    {
    case 0:
        state().replace(new PlantState(hw(), state()));
        break;
    case 1:
        state().replace(new SetAlarmState(hw(), state()));
        break;
    case 2:
        state().replace(new SetTimeState(hw(), state()));
        break;
    }
}
