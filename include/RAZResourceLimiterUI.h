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
public:
    explicit RAZResourceLimiterUI(QWidget* parent = nullptr);
    ~RAZResourceLimiterUI();

private:
    void setupUI();

    QSlider* ramSlider;
    QLabel* lblRamValue;
};

#endif // RAZRESOURCELIMITERUI_H
