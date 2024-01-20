#pragma once

#include "Hardware.hpp"
#include "StateMachine.hpp"

class State
{
public:
    State(Hardware const& hw, StateMachine& state);

    virtual void update() = 0;
    virtual void render() = 0;
    virtual int getDelay() const;

    Hardware const& hw() const;
    StateMachine& state();

private:
    Hardware const& hw_;
    StateMachine& state_;
};
