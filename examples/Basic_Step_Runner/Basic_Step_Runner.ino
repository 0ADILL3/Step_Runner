#include <Step_Runner.h>

#define LED1 13
#define LED2 12

void blinkLed1() {
  digitalWrite(LED1, !digitalRead(LED1));
}

void blinkLed2() {
  digitalWrite(LED2, !digitalRead(LED2));
}

void printSerial() {
  Serial.println("Running periodic task...");
}

Step_Runner led1Task(blinkLed1, 500);
Step_Runner led2Task(blinkLed2, 300);
Step_Runner printTask(printSerial, 2000);

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  led1Task.run();   // LED1 blink tiap 500ms
  led2Task.run();   // LED2 blink tiap 300ms
  printTask.run();  // Serial print tiap 2 detik

  led1Task.set_interval(1000); // Ubah interval LED1 menjadi 1 detik setelah beberapa waktu
  led2Task.timer_reset(); // Reset timer LED2 setelah beberapa waktu
}