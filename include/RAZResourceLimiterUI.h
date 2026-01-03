/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header UI Pembatas Resource (RAM/CPU).
 */

#ifndef RAZRESOURCELIMITERUI_H
#define RAZRESOURCELIMITERUI_H

#ifdef QT_CORE_LIB
    #include <QWidget>
    #include <QSlider>
    #include <QLabel>
#else
    #include "RAZMockCommon.h"
#endif

// Kelas RAZResourceLimiterUI
// Penjelasan: Panel untuk mengatur batas penggunaan sistem.
class RAZResourceLimiterUI : public QWidget {
    // Q_OBJECT // Diperlukan di Qt asli untuk Signals & Slots
public:
    explicit RAZResourceLimiterUI(QWidget* parent = nullptr);
    ~RAZResourceLimiterUI();

    // Fungsi simulasi signal (karena kita tidak pakai MOC di environment ini)
    // Di aplikasi nyata, gunakan: signals: void ramLimitChanged(int limit);
    void onSliderValueChanged(int value);

    // Setter untuk callback eksternal (Mocking logic wiring)
    void setLimitCallback(void (*callback)(int));

private:
    void setupUI();

    QSlider* ramSlider;
    QLabel* lblRamValue;

    // Pointer fungsi callback untuk simulasi koneksi signal
    void (*limitCallback)(int);
};

#endif // RAZRESOURCELIMITERUI_H
