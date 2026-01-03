/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Definisi Core Browser dengan manajemen memori.
 */

#ifndef RAZBROWSERCORE_H
#define RAZBROWSERCORE_H

#include <iostream>
#include <string>

// Jika kita memiliki Qt, include header yang diperlukan.
// Jika tidak (mode struktur/pembelajaran), kita gunakan dummy types.
#ifdef QT_CORE_LIB
    #include <QObject>
    #include <QWebEngineView>
    #include <QApplication>
#else
    // Mock classes untuk keperluan kompilasi di lingkungan tanpa Qt
    class QApplication {};
    class QWebEngineView {};
#endif

// Kelas RAZBrowser
// Penjelasan: Kelas utama yang mengontrol instance browser dan konfigurasi sistem.
class RAZBrowser {
public:
    RAZBrowser();
    ~RAZBrowser();

    // Fungsi: Mengatur batas penggunaan RAM
    // Parameter: limitMB (int) - Batas dalam Megabytes
    void setRamLimit(int limitMB);

    // Fungsi: Menjalankan antarmuka pengguna
    void launchUI();

private:
    int ramLimit;

    // Pointer ke komponen engine utama (Qt WebEngine)
    // Penjelasan: Menggunakan pointer untuk manajemen memori manual jika diperlukan
    QWebEngineView* webView;
};

#endif // RAZBROWSERCORE_H
