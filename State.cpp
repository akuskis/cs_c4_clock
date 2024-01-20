#include "State.hpp"

State::State(Hardware const& hw, StateMachine& state)
  : hw_(hw),
    state_(state)
{
}

int State::getDelay() const
{
    return 100;
}

Hardware const& State::hw() const
{
    return hw_;
}

StateMachine& State::state()
{
    return state_;
}
