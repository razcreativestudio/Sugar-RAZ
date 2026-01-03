/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Mesin Pengujian Otomatis (Beta Testing Suite).
 */

#ifndef RAZTESTENGINE_H
#define RAZTESTENGINE_H

#include <vector>
#include <string>

// Kelas RAZTestEngine
// Penjelasan: Menjalankan serangkaian tes unit untuk memvalidasi fitur inti sebelum rilis.
class RAZTestEngine {
public:
    RAZTestEngine();
    ~RAZTestEngine();

    // Fungsi utama untuk menjalankan semua tes
    bool runTestSuite();

private:
    bool testThemeManager();
    bool testAdBlockerLogic();
    bool testHubGeneration();

    // Helper untuk log
    void logResult(const std::string& testName, bool passed);
};

#endif // RAZTESTENGINE_H
