# Step_Runner Library

`Step_Runner` is a lightweight, non-blocking timer library for Arduino or other microcontrollers. It allows you to run functions (callbacks) at specific intervals without using the `delay()` function, keeping your main `loop()` free to process other tasks like reading sensors or handling button presses.

## Features
- **Non-blocking Execution:** Replaces the `delay()` function using a `millis()`-based approach.
- **Easy Callback Integration:** Pass any void function to be executed periodically.
- **Drift Correction:** Designed to maintain accurate timing even if the main loop experiences minor delays.
- **Timer Controls:** Ability to pause, resume, reset, and change intervals on the fly.

## Installation

1. Download this repository as a `.zip` file.
2. Open the Arduino IDE.
3. Go to **Sketch** -> **Include Library** -> **Add .ZIP Library...**
4. Select the downloaded `.zip` file.
5. Include the library in your code: `#include "Step_Runner.h"`