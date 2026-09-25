#include "Step_Runner.h"

Step_Runner::Step_Runner() {is_running_ = true;}

bool Step_Runner::run(unsigned long interval)
{
  if (!is_running_)
  {
    return false;
  }

  if (millis() - last_time_ >= interval)
  {
    reset();
    return true;
  }
  return false;
}

bool Step_Runner::on_run(unsigned long duration, bool once)
{
  if (!on_run_start_)
  {
    reset();
    on_run_start_ = true;
  }
  
  if (millis() - last_time_ > duration && !on_run_done_)
  {
    if (once) {on_run_done_ = true;}
    return true;
  }
  return false;
}

bool Step_Runner::off_run(unsigned long duration)
{
  if (!off_run_start_)
  {
    reset();
    off_run_start_ = true;
  }
  
  if (millis() - last_time_ > duration)
  {
    return false;
  }
  return true;
}

void Step_Runner::reset()
{
  last_time_ = millis();
  on_run_start_ = false;
  on_run_done_ = false;
  off_run_start_ = false;
}

void Step_Runner::pause() {is_running_ = false;}

void Step_Runner::resume() {is_running_ = true;}