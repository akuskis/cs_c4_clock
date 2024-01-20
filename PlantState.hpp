#pragma once

#include "State.hpp"

class PlantState : public State
{
public:
    PlantState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;
};
