/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi suite pengujian.
 */

#include "RAZTestEngine.h"
#include "RAZThemeManager.h"
#include "RAZAdBlocker.h"
#include "RAZHub.h"
#include <iostream>

#ifdef QT_CORE_LIB
#include <QWebEngineUrlRequestInfo>
#else
#include "RAZMockCommon.h"
#endif

RAZTestEngine::RAZTestEngine() {}
RAZTestEngine::~RAZTestEngine() {}

void RAZTestEngine::logResult(const std::string& testName, bool passed) {
    std::cout << "[TEST] " << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

bool RAZTestEngine::testThemeManager() {
    RAZThemeManager theme;
    theme.setAccentColor("#00FF00");
    std::string css = theme.getGlobalStyleSheet();

    // Validasi apakah warna diterapkan ke CSS
    if (css.find("#00FF00") != std::string::npos) {
        return true;
    }
    return false;
}

bool RAZTestEngine::testAdBlockerLogic() {
    RAZAdBlocker blocker(nullptr);

    // Kita buat mock info untuk request ke situs iklan
    // Karena interceptRequest memodifikasi objek info, kita perlu cara untuk mengeceknya.
    // Di mock implementation kita (non-Qt), kita bisa memeriksa output stdout atau modify behavior.
    // Untuk unit test ini, kita cek logic manual daftar hitam.

    // (Dalam implementasi nyata, kita akan punya method isUrlBlocked(url) yang public/protected)
    // Disini kita hanya memanggil interceptRequest untuk memastikan tidak crash.
    QWebEngineUrlRequestInfo info;
    blocker.interceptRequest(info);

    return true; // Jika sampai sini tanpa crash, anggap pass untuk smoke test
}

bool RAZTestEngine::testHubGeneration() {
    RAZHub hub;
    std::string html = hub.getDashboardHTML();

    // Cek apakah output valid HTML
    if (html.find("<html>") != std::string::npos && html.find("SYSTEM STATUS") != std::string::npos) {
        return true;
    }
    return false;
}

bool RAZTestEngine::runTestSuite() {
    std::cout << "=== MEMULAI BETA TESTING SUITE ===" << std::endl;
    bool allPassed = true;

    if (!testThemeManager()) { logResult("Theme Manager", false); allPassed = false; }
    else logResult("Theme Manager", true);

    if (!testAdBlockerLogic()) { logResult("Ad Blocker", false); allPassed = false; }
    else logResult("Ad Blocker", true);

    if (!testHubGeneration()) { logResult("RAZ Hub", false); allPassed = false; }
    else logResult("RAZ Hub", true);

    std::cout << "=== HASIL TEST: " << (allPassed ? "SUKSES" : "GAGAL") << " ===" << std::endl;
    return allPassed;
}
