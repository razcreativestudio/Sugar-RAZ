/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi layout Sidebar dengan tombol ikonik.
 */

#include "RAZSidebar.h"
#include <iostream>

// Constructor
RAZSidebar::RAZSidebar(QWidget* parent) : QWidget(parent) {
    // Set nama object untuk styling CSS (ID selector)
    #ifdef QT_CORE_LIB
    setObjectName("RAZSidebar");
    // Set ukuran tetap (lebar)
    setFixedWidth(60);
    #endif

    setupLayout();
}

RAZSidebar::~RAZSidebar() {
    // Cleanup otomatis oleh parent Qt
}

void RAZSidebar::setupLayout() {
    #ifdef QT_CORE_LIB
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(5, 10, 5, 10);
        layout->setSpacing(15);

        // Membuat tombol dummy
        btnGXControl = new QPushButton("GX", this);
        btnTwitch = new QPushButton("Tw", this); // Harusnya Icon
        btnDiscord = new QPushButton("Dc", this);
        btnSettings = new QPushButton("Set", this);

        // Menambahkan ke layout
        layout->addWidget(btnGXControl);
        layout->addWidget(btnTwitch);
        layout->addWidget(btnDiscord);

        layout->addStretch(); // Spacer agar settings ada di bawah

        layout->addWidget(btnSettings);
    #else
        std::cout << "[UI-MOCK] Sidebar dibuat dengan tombol: GX, Twitch, Discord." << std::endl;
    #endif
}
