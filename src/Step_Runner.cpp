#include "Step_Runner.h"

Step_Runner::Step_Runner(void (*process)(), unsigned long interval)
{
  process_ = process;
  interval_ = interval;
  is_running_ = true;
  last_time_ = millis();
}

void Step_Runner::run()
{
  if (is_running_)
  {
    if (millis() - last_time_ >= interval_)
    {
      if (process_ != nullptr) {process_();}
      last_time_ = millis();
    }
  }
}

void Step_Runner::set_interval(unsigned long interval) {interval_ = interval;}

void Step_Runner::timer_reset() {last_time_ = millis();}

void Step_Runner::timer_pause() {is_running_ = false;}

void Step_Runner::timer_resume() {is_running_ = true;}