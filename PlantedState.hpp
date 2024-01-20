#pragma once

#include "State.hpp"

class PlantedState : public State
{
public:
    PlantedState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;

private:
    int index_ = 0;
    char str[8] = "*******";

    void handle_value_(byte key);
};
