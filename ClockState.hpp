#pragma once

#include "State.hpp"

class ClockState : public State
{
public:
    ClockState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;
};
