#pragma once

#include "State.hpp"

class SetTimeState : public State
{
public:
    SetTimeState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;
};
