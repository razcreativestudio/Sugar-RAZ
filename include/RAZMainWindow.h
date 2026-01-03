/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Definisi Jendela Utama Browser.
 */

#ifndef RAZMAINWINDOW_H
#define RAZMAINWINDOW_H

#ifdef QT_CORE_LIB
    #include <QMainWindow>
    #include <QWidget>
#else
    #include "RAZMockCommon.h"
#endif

// Kelas RAZMainWindow
// Penjelasan: Mengelola tata letak utama aplikasi (Sidebar + Web Content)
class RAZMainWindow : public QMainWindow {
public:
    RAZMainWindow();
    ~RAZMainWindow();

    // Fungsi: Inisialisasi komponen UI
    void initUI();

private:
    // Widget pusat penampung layout
    QWidget* centralWidget;
};

#endif // RAZMAINWINDOW_H
