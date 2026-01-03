/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Manajer Tab Browser.
 */

#ifndef RAZTABMANAGER_H
#define RAZTABMANAGER_H

#ifdef QT_CORE_LIB
    #include <QTabWidget>
    #include <QWidget>
#else
    #include "RAZMockCommon.h"
#endif

// Kelas RAZTabManager
// Penjelasan: Mengelola daftar tab yang terbuka dan konten di dalamnya.
class RAZTabManager : public QTabWidget {
public:
    explicit RAZTabManager(QWidget* parent = nullptr);
    ~RAZTabManager();

    // Fungsi: Membuka tab baru dengan konten default (RAZ Hub)
    void openNewTab();

    // Fungsi: Menutup tab pada indeks tertentu
    void closeTab(int index);
};

#endif // RAZTABMANAGER_H
