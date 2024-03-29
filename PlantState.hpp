#pragma once

#include "State.hpp"

class PlantState : public State
{
public:
    PlantState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;

private:
    int index_ = 0;
    char str[8] = "*******";

    void handle_value_(byte key);
};
