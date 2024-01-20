#include "SetAlarmState.hpp"


SetAlarmState::SetAlarmState(Hardware const& hw, StateMachine& state)
    : State(hw, state)
{
    hw.lcd.clear();
}

void SetAlarmState::update()
{
}

void SetAlarmState::render()
{
    hw().lcd.setCursor(0, 0);
    hw().lcd.print("-- set  alarm --");

    // hw().lcd.setCursor(0, 1);
    // hw().lcd.print();
}
