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

    /*     // Volume
        hw_.mp3.write(0x7E);
        hw_.mp3.write(0x03);
        hw_.mp3.write(0x31);
        hw_.mp3.write(0x0F);
        hw_.mp3.write(0xEF);

        delay(1000);

        // Play
        hw_.mp3.write(0x7E);
        hw_.mp3.write(0x04);
        hw_.mp3.write(0x42);
        hw_.mp3.write(0x01);
        hw_.mp3.write(0x01);
        hw_.mp3.write(0xEF); */
}

void Application::delay_()
{
    delay(state_.getDelay());
}
