#include "ClockState.hpp"

#include "MenuState.hpp"

ClockState::ClockState(Hardware const& hw, StateMachine& state)
    : State(hw, state)
{
    hw.lcd.clear();
}

void ClockState::update()
{
    if (hw().keypad.getKey() == '*')
    {
        state().replace(new MenuState(hw(), state()));
    }
}

void ClockState::render()
{
    bool h12_flag = false;
    bool pm_time = false;

    auto hours = hw().rtc.getHour(h12_flag, pm_time);
    auto minutes = hw().rtc.getMinute();
    auto seconds = hw().rtc.getSecond();

    char str[17];
    sprintf(str, "%02d:%02d:%02d", hours, minutes, seconds);

    hw().lcd.setCursor(4, 1);
    hw().lcd.print(str);
}
