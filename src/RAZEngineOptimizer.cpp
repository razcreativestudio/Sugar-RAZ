/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi optimasi pengaturan browser.
 */

#include "RAZEngineOptimizer.h"
#include <iostream>

#ifdef QT_CORE_LIB
    #include <QWebEngineProfile>
    #include <QWebEngineSettings>
#else
    #include "RAZMockCommon.h"
#endif

void RAZEngineOptimizer::applyOptimizations() {
    std::cout << "[OPTIMIZER] Menerapkan profil performa..." << std::endl;

    // Mendapatkan profil default
    QWebEngineProfile* profile = QWebEngineProfile::defaultProfile();
    if (!profile) {
        // Handle case mock where defaultProfile returns nullptr usually,
        // but here we might simulate access
        #ifdef QT_CORE_LIB
        return;
        #else
        std::cout << "[OPTIMIZER-MOCK] Simulasi akses profil..." << std::endl;
        #endif
    }

    // Akses pengaturan (Settings)
    #ifdef QT_CORE_LIB
    QWebEngineSettings* settings = profile->settings();
    #else
    QWebEngineSettings mockSettings;
    QWebEngineSettings* settings = &mockSettings;
    #endif

    // 1. Matikan DNS Prefetching (Privasi & Hemat Bandwidth di kondisi tertentu)
    settings->setAttribute(QWebEngineSettings::DnsPrefetchEnabled, false);
    std::cout << "  [-] DNS Prefetch: DISABLED" << std::endl;

    // 2. Kontrol Plugin (Bloatware Removal)
    settings->setAttribute(QWebEngineSettings::PluginsEnabled, false); // Matikan Flash/PDF viewer berat jika tidak perlu
    std::cout << "  [-] External Plugins: DISABLED" << std::endl;

    // 3. (Opsional) Matikan Auto Load Images untuk mode "Lite"
    // settings->setAttribute(QWebEngineSettings::AutoLoadImages, false);

    std::cout << "[OPTIMIZER] Konfigurasi engine selesai." << std::endl;
}
