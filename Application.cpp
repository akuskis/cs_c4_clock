#include "Applicaiton.hpp"

#include "ClockState.hpp"

#include <Arduino.h>


Application::Application(Hardware& hw)
  : hw_(hw)
{
    state_.replace(new ClockState{hw, state_});
}

void Application::run()
{
    while (true)
    {
        update_();
        render_();
        delay_();
    }
}

void Application::update_()
{
    state_.update();
}

void Application::render_()
{
    state_.render();
}

void Application::delay_()
{
    delay(state_.getDelay());
}
