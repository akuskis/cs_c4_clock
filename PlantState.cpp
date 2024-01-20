#include "PlantState.hpp"


PlantState::PlantState(Hardware const& hw, StateMachine& state)
    : State(hw, state)
{
    hw.lcd.clear();
}

void PlantState::update()
{
}

void PlantState::render()
{
    hw().lcd.setCursor(0, 0);
    hw().lcd.print("--- PLANTING ---");

    // hw().lcd.setCursor(0, 1);
    // hw().lcd.print();
}
