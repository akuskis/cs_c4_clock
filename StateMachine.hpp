#pragma once

class State;

class StateMachine
{
public:
    StateMachine();
    ~StateMachine();

    void replace(State* state);

    void update();
    void render();
    int getDelay();

private:
    State* state_;
    State* replacement_state_;
};
