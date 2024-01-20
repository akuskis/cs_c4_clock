#pragma once

#include "State.hpp"

class SetAlarmState : public State
{
public:
    SetAlarmState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;
};
