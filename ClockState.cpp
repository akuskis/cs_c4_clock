#include "ClockState.hpp"

ClockState::ClockState(Hardware const& hw, StateMachine& state)
    : State(hw, state)
{
}

void ClockState::update()
{
    // if * was pressed -> show menu
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
