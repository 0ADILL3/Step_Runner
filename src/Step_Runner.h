#pragma once

#include <Arduino.h>

class Step_Runner
{
  private:
    unsigned long last_time_ = 0;
    bool is_running_ = false;
    bool on_run_start_ = false;
    bool on_run_done_ = false;
    bool off_run_start_ = false;
    
  public:
    /**
     * @brief Constructor: Menginisialisasi objek Step_Runner.
     * @note  ATURAN DESAIN: Gunakan 1 objek eksklusif untuk 1 jenis fungsi saja 
     *        (hanya run, hanya on_run, atau hanya off_run) untuk menghindari konflik memori waktu.
     */
    Step_Runner();
    
    /**
     * @brief Pengecekan interval secara periodik (Blink Without Delay).
     * @param interval Jeda waktu antar siklus (dalam milidetik).
     * @return true pada saat interval tercapai, false jika belum.
     */
    bool run(unsigned long interval);

    /**
     * @brief Eksekusi fungsi secara periodik (Blink Without Delay).
     * @param process Pointer ke fungsi yang akan dieksekusi (callback).
     * @param interval Jeda waktu antar eksekusi (dalam milidetik).
     * @return true jika fungsi dieksekusi pada siklus ini.
     */
    bool run(void (*process)(), unsigned long interval);

    /**
     * @brief Pengecekan penundaan (ON-Delay). Mengembalikan true SETELAH durasi terlampaui.
     * @param duration Lama waktu penundaan (dalam milidetik).
     * @param once Jika true, hanya akan mengembalikan true SATU KALI setelah durasi tercapai. 
     *             Perlu dipanggil reset() untuk mengulanginya.
     * @return true jika waktu sudah melewati durasi penundaan.
     */
    bool on_run(unsigned long duration, bool once = false);

    /**
     * @brief Mengeksekusi fungsi SETELAH penundaan waktu berlalu (ON-Delay).
     * @param process Pointer ke fungsi yang akan dieksekusi (callback).
     * @param duration Lama waktu penundaan sebelum fungsi dieksekusi (dalam milidetik).
     * @param once Jika true, eksekusi (One-Shot) hanya terjadi 1x. Jika false, dieksekusi berulang setelah jeda.
     * @return true jika fungsi dieksekusi pada siklus ini.
     */
    bool on_run(void (*process)(), unsigned long duration, bool once = false);

    /**
     * @brief Pengecekan durasi aktif (Pulse Timer).
     * @param duration Lama waktu aktif (dalam milidetik).
     * @return true SELAMA waktu belum melampaui durasi, false jika waktu sudah habis.
     */
    bool off_run(unsigned long duration);

    /**
     * @brief Mengeksekusi fungsi terus-menerus SELAMA durasi belum habis (Pulse Timer).
     * @param process Pointer ke fungsi yang akan dieksekusi (callback).
     * @param duration Batas waktu maksimal fungsi boleh dieksekusi (dalam milidetik).
     * @return true jika fungsi dieksekusi pada siklus ini.
     */
    bool off_run(void (*process)(), unsigned long duration);

    /**
     * @brief Mengatur ulang (reset) seluruh perhitungan waktu dan state.
     *        Sangat berguna untuk memicu ulang fungsi on_run dan off_run.
     */
    void reset();

    /**
     * @brief Menjeda perhitungan waktu. 
     * @note  PERINGATAN: Fitur ini HANYA BERLAKU untuk fungsi periodik run().
     *        Fungsi on_run() dan off_run() akan mengabaikan perintah pause().
     */
    void pause();

    /**
     * @brief Melanjutkan perhitungan waktu setelah di-jeda.
     */
    void resume();
};