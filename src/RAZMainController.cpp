/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Inisialisasi jendela utama Sugar RAZ dan pengaturan pembatas RAM.
 */

#include <iostream>
#include "RAZBrowserCore.h"

// Implementasi Constructor
RAZBrowser::RAZBrowser() {
    ramLimit = 0; // Default tidak terbatas
    webView = nullptr;

    // Inisialisasi komponen engine
    // Di lingkungan nyata dengan Qt, kita akan melakukan 'new QWebEngineView()' di sini
    std::cout << "[INFO] RAZBrowser Core diinisialisasi." << std::endl;
}

// Implementasi Destructor
RAZBrowser::~RAZBrowser() {
    // Membersihkan resource
    if (webView) {
        // delete webView; // Uncomment jika menggunakan alokasi dinamis nyata
    }
    std::cout << "[INFO] RAZBrowser Core ditutup." << std::endl;
}

// Implementasi setRamLimit
void RAZBrowser::setRamLimit(int limitMB) {
    this->ramLimit = limitMB;

    // Logika simulasi pembatasan RAM
    // Di Chromium asli, ini akan berinteraksi dengan V8 heap limit atau process renderer
    std::cout << "[SYSTEM] Batas RAM diatur ke: " << limitMB << " MB" << std::endl;
    std::cout << "[EDUKASI] Fungsi ini memberi instruksi ke allocator untuk membatasi heap." << std::endl;
}

// Implementasi launchUI
void RAZBrowser::launchUI() {
    std::cout << "[UI] Memulai Antarmuka Pengguna Sugar RAZ..." << std::endl;

    #ifdef QT_CORE_LIB
        // Kode Qt nyata akan berjalan di sini
        // webView->show();
    #else
        std::cout << "[MODE DEV] Menjalankan simulasi UI (Tanpa Qt Engine)." << std::endl;
        std::cout << "         Jendela browser 'virtual' terbuka." << std::endl;
    #endif
}

// --- MAIN FUNCTION ---

// Fungsi utama untuk menjalankan browser
// Penjelasan: Titik masuk (Entry Point) aplikasi C++
int main(int argc, char *argv[]) {
    std::cout << "=== SUGAR RAZ BROWSER STARTUP ===" << std::endl;

    // Di aplikasi Qt, kita butuh QApplication
    #ifdef QT_CORE_LIB
    QApplication app(argc, argv);
    #endif

    // Membuat instance baru dari Sugar RAZ
    RAZBrowser sugarRaz;

    // Mengatur batas penggunaan RAM agar tetap ringan (Limit 2GB)
    // Penjelasan: Ini memanggil fungsi internal engine untuk alokasi memori
    sugarRaz.setRamLimit(2048);

    // Menampilkan Antarmuka Pengguna (UI)
    sugarRaz.launchUI();

    std::cout << "=== SUGAR RAZ BROWSER RUNNING ===" << std::endl;

    // Event loop untuk GUI
    #ifdef QT_CORE_LIB
    return app.exec();
    #else
    // Simulasi loop agar program tidak langsung keluar (opsional, di sini langsung return)
    return 0;
    #endif
}
