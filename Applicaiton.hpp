#pragma once

#include "Hardware.hpp"
#include "StateMachine.hpp"

class Application
{
public:
    Application(Hardware& hw);

    void run();

private:
    Hardware& hw_;
    StateMachine state_;

    void update_();
    void render_();
    void delay_();
};
