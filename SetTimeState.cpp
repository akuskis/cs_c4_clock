#include "SetTimeState.hpp"


SetTimeState::SetTimeState(Hardware const& hw, StateMachine& state)
    : State(hw, state)
{
    hw.lcd.clear();
}

void SetTimeState::update()
{
}

void SetTimeState::render()
{
    hw().lcd.setCursor(0, 0);
    hw().lcd.print("--- set time ---");

    // hw().lcd.setCursor(0, 1);
    // hw().lcd.print();
}
