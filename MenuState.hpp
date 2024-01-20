#pragma once

#include "State.hpp"

class MenuState : public State
{
public:
    MenuState(Hardware const& hw, StateMachine& state);

    void update() override;
    void render() override;

private:
    int index_ = 0;

    void select_item_();
};
