#pragma once

#include "State.hpp"

class SetTimeState : public State
{
public:
    SetTimeState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;

private:
    int index_ = 0;
    char str[9] = "__:__:__";

    void handle_value_(char v);
    void apply_time_();
};
