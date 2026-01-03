/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi logika tema gelap dan neon.
 */

#include "RAZThemeManager.h"
#include <iostream>

// Constructor
RAZThemeManager::RAZThemeManager() {
    // Default warna aksen (Neon Red khas GX)
    currentAccentColor = "#FA1E4E";
    // Warna dasar gelap
    baseDarkColor = "#1C1C1C";
}

// Destructor
RAZThemeManager::~RAZThemeManager() {}

// Mengubah warna aksen
void RAZThemeManager::setAccentColor(const std::string& hexColor) {
    this->currentAccentColor = hexColor;
    std::cout << "[THEME] Warna aksen diubah ke: " << hexColor << std::endl;
}

// Menghasilkan stylesheet CSS untuk Qt (QSS)
std::string RAZThemeManager::getGlobalStyleSheet() {
    // Membangun string CSS dengan warna dinamis
    std::string qss =
        "QMainWindow { background-color: " + baseDarkColor + "; }"
        "QWidget { color: white; font-family: 'Segoe UI', sans-serif; }"
        "/* Sidebar Styling */"
        "QWidget#RAZSidebar { background-color: #0F0F0F; border-right: 2px solid " + currentAccentColor + "; }"
        "QPushButton { background-color: transparent; border: none; color: #AAAAAA; padding: 10px; text-align: left; }"
        "QPushButton:hover { background-color: " + currentAccentColor + "; color: white; }"
        "/* Resource Limiter Styling */"
        "QDialog { background-color: #252525; border: 1px solid " + currentAccentColor + "; }";

    return qss;
}
