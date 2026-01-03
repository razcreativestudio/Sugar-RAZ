/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Manajer Tema untuk styling UI GX.
 */

#ifndef RAZTHEMEMANAGER_H
#define RAZTHEMEMANAGER_H

#include <string>

// Kelas RAZThemeManager
// Penjelasan: Mengelola skema warna dan style sheet (QSS) aplikasi.
class RAZThemeManager {
public:
    RAZThemeManager();
    ~RAZThemeManager();

    // Fungsi: Mengatur warna aksen utama (Format Hex: #RRGGBB)
    void setAccentColor(const std::string& hexColor);

    // Fungsi: Mendapatkan style sheet global untuk aplikasi
    std::string getGlobalStyleSheet();

private:
    std::string currentAccentColor;
    std::string baseDarkColor;
};

#endif // RAZTHEMEMANAGER_H
