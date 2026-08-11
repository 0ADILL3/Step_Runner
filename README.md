# Step_Runner Library

`Step_Runner` is a lightweight, non-blocking timer library for Arduino or other microcontrollers. It allows you to run functions (callbacks) based on time intervals without using the `delay()` function, keeping your main `loop()` free to process other tasks like reading sensors or handling button presses.

## Key Features
- **Low Memory Footprint:** Uses a single timer variable per object for maximum efficiency.
- **Periodic Execution (`run`):** Run a function repeatedly at a specific interval.
- **ON-Delay / One-Shot (`on_run`):** Delay the execution of a function, with an option to run it only once after the delay.
- **Pulse Timer / OFF-Delay (`off_run`):** Run a function continuously *only for* a specified duration, then automatically stop.
- **Timer Controls:** Pause and resume (applies to periodic `run` only), and reset capabilities.

## ⚠️ Important Design Rule
To maintain its extreme low-memory architecture, **one `Step_Runner` object must be dedicated to only one type of task**. Do not mix `run()`, `on_run()`, and `off_run()` using the same object simultaneously, as they share the same internal timing state.

## Installation

1. Download this repository as a `.zip` file.
2. Open the Arduino IDE.
3. Go to **Sketch** -> **Include Library** -> **Add .ZIP Library...**
4. Select the downloaded `.zip` file.
5. Include the library in your code: `#include "Step_Runner.h"`