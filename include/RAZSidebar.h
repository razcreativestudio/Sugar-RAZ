/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header Sidebar Navigasi Kiri.
 */

#ifndef RAZSIDEBAR_H
#define RAZSIDEBAR_H

#ifdef QT_CORE_LIB
    #include <QWidget>
    #include <QVBoxLayout>
    #include <QPushButton>
#else
    #include "RAZMockCommon.h"
#endif

// Kelas RAZSidebar
// Penjelasan: Widget sidebar vertikal untuk akses cepat fitur GX.
class RAZSidebar : public QWidget {
public:
    // Constructor menerima parent widget
    explicit RAZSidebar(QWidget* parent = nullptr);
    ~RAZSidebar();

private:
    void setupLayout();

    // Tombol-tombol navigasi
    // Penjelasan: Pointer ke tombol agar bisa dimanipulasi nanti
    QPushButton* btnGXControl;
    QPushButton* btnTwitch;
    QPushButton* btnDiscord;
    QPushButton* btnSettings;
};

#endif // RAZSIDEBAR_H
