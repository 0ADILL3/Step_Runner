#pragma once

#include <Arduino.h>

class Step_Runner
{
  private:
    unsigned long last_time_ = 0;
    unsigned long interval_;
    bool is_running_ = false;

    void (*process_)() = nullptr;

  public:
    // Constructor
    Step_Runner(void (*process)(), unsigned long interval);

    // Run the process
    void run();
    // Set the interval for the process
    void set_interval(unsigned long interval);
    // Reset the timer to the current time
    void timer_reset();
    // Pause the timer
    void timer_pause();
    // Resume the timer
    void timer_resume();
};