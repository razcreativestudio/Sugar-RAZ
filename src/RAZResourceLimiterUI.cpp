/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi UI Slider untuk limitasi resource.
 */

#include "RAZResourceLimiterUI.h"
#include <iostream>

#ifdef QT_CORE_LIB
    #include <QVBoxLayout>
#endif

#include <string>

RAZResourceLimiterUI::RAZResourceLimiterUI(QWidget* parent) : QWidget(parent) {
    limitCallback = nullptr;
    setupUI();
}

RAZResourceLimiterUI::~RAZResourceLimiterUI() {}

void RAZResourceLimiterUI::setLimitCallback(void (*callback)(int)) {
    limitCallback = callback;
}

void RAZResourceLimiterUI::onSliderValueChanged(int value) {
    // Update label
    std::string text = std::to_string(value) + " MB";
    // lblRamValue->setText(...) // Di mock

    std::cout << "[UI] Slider digeser ke: " << value << " MB" << std::endl;

    // Emit signal (panggil callback)
    if (limitCallback) {
        limitCallback(value);
    }
}

void RAZResourceLimiterUI::setupUI() {
    #ifdef QT_CORE_LIB
        QVBoxLayout* layout = new QVBoxLayout(this);

        // Label Judul
        QLabel* title = new QLabel("GX CONTROL: RAM LIMITER", this);
        layout->addWidget(title);

        // Slider RAM
        ramSlider = new QSlider(Qt::Horizontal, this);
        ramSlider->setRange(1024, 16384); // 1GB - 16GB
        ramSlider->setValue(2048); // Default 2GB

        // Connect signal (Qt Style)
        // connect(ramSlider, &QSlider::valueChanged, this, &RAZResourceLimiterUI::onSliderValueChanged);

        layout->addWidget(ramSlider);

        // Label Value
        lblRamValue = new QLabel("2048 MB", this);
        layout->addWidget(lblRamValue);
    #else
        std::cout << "[UI-MOCK] Resource Limiter UI dibuat (Slider RAM 1GB-16GB)." << std::endl;
    #endif
}
