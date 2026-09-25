#include <Step_Runner.h>

#define LED_BLINK 13
#define LED_PULSE 12

// --- DEKLARASI OBJEK (1 Objek = 1 Tugas) ---
Step_Runner taskBlink;
Step_Runner taskPrint;
Step_Runner taskOnDelay;
Step_Runner taskOffDelay;

// --- FUNGSI CALLBACK ---
void blinkLed() {
  digitalWrite(LED_BLINK, !digitalRead(LED_BLINK));
}

void print(int val, bool state) {
  Serial.printf("value: %d\n", val);
  Serial.printf("state: %d\n", state);
}

void printOneShot() {
  Serial.println("Pesan ON-Delay: Muncul 1 KALI setelah jeda 3 detik!");
}

void pulseLed() {
  digitalWrite(LED_PULSE, HIGH); // Nyalakan LED
  Serial.println("Pesan OFF-Delay: LED_PULSE menyala selama 5 detik pertama...");
}

void setup() {
  pinMode(LED_BLINK, OUTPUT);
  pinMode(LED_PULSE, OUTPUT);
  digitalWrite(LED_PULSE, LOW);
  
  Serial.begin(115200);
  Serial.println("Sistem Dimulai!");

  // Sinkronisasi waktu mulai agar akurat sejak setup selesai
  taskOnDelay.reset();
  taskOffDelay.reset();
}

void loop() {
  // 1. CONTOH PERIODIK (Berjalan terus-menerus setiap 500ms)
  taskBlink.run(blinkLed, 500);
  
  // 3. CONTOH FUNGSI PERIODIK dengan argumen dinamis (argumen diberikan setelah argumen interval)
  taskPrint.run(print, 1000, 1, false);

  // 3. CONTOH ON-DELAY / ONE-SHOT (Menunggu 3000ms, lalu dieksekusi 1x)
  // Parameter ketiga (true) mengunci fungsi agar tidak berulang.
  taskOnDelay.on_run(printOneShot, 3000, true);

  // 4. CONTOH OFF-DELAY / PULSE TIMER (Berjalan terus selama 5000ms, lalu berhenti)
  // Mengembalikan nilai 'false' jika waktu sudah habis.
  bool isPulseActive = taskOffDelay.off_run(pulseLed, 5000);
  
  if (!isPulseActive) {
    // Matikan LED jika durasi 5 detik sudah terlampaui
    digitalWrite(LED_PULSE, LOW); 
  }
}