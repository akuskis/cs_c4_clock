#include "SetTimeState.hpp"

#include "ClockState.hpp"

namespace
{
byte get_byte(char const* arr, int a, int b)
{
    return (arr[a] - '0') * 10 + (arr[b] - '0');
}
}

SetTimeState::SetTimeState(Hardware const& hw, StateMachine& state)
    : State(hw, state)
{
    hw.lcd.clear();
}

void SetTimeState::update()
{
    auto const key = hw().keypad.getKey();
    switch (key)
    {
    case '#':
        state().replace(new ClockState(hw(), state()));
        break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        handle_value_(key);
        break;
    }
}

void SetTimeState::render()
{
    hw().lcd.setCursor(0, 0);
    hw().lcd.print("--- set time ---");

    hw().lcd.setCursor(4, 1);
    hw().lcd.print(str);
}

void SetTimeState::handle_value_(char v)
{
    str[index_ + index_ / 2] = v;
    ++index_;

    if (index_ == 6)
        apply_time_();
}

void SetTimeState::apply_time_()
{
    byte h = get_byte(str, 0, 1);
    byte m = get_byte(str, 3, 4);
    byte s = get_byte(str, 6, 7);

    if (h >= 24 || m >= 60 || s >= 60)
        state().replace(new SetTimeState(hw(), state()));

    hw().rtc.setHour(h);
    hw().rtc.setMinute(m);
    hw().rtc.setSecond(s);
    
    state().replace(new ClockState(hw(), state()));
}
