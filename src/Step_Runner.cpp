#include "Step_Runner.h"

Step_Runner::Step_Runner(void (*process)(), unsigned long interval)
{
  _process = process;
  _interval = interval;
  _is_running = true;
  _last_time = millis();
}

void Step_Runner::run()
{
  if (_is_running)
  {
    if (millis() - _last_time >= _interval)
    {
      if (_process != nullptr) {_process();}
      _last_time = millis();
    }
  }
}

void Step_Runner::set_interval(unsigned long interval) {_interval = interval;}

void Step_Runner::timer_reset() {_last_time = millis();}

void Step_Runner::timer_pause() {_is_running = false;}

void Step_Runner::timer_resume() {_is_running = true;}