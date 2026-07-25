#pragma once

#include <Arduino.h>

class Step_Runner
{
  private:
    unsigned long _last_time;
    unsigned long _interval;
    bool _is_running;

    void (*_process)();

  public:
    Step_Runner(void (*process)(), unsigned long interval);

    void run();
    void set_interval(unsigned long interval);
    void timer_reset();
    void timer_pause();
    void timer_resume();
};