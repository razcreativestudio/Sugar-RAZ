/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Panel Samping (Web Panel).
 */

#ifndef RAZSIDEPANEL_H
#define RAZSIDEPANEL_H

#include <string>

#ifdef QT_CORE_LIB
    #include <QWidget>
    #include <QVBoxLayout>
    #include <QLabel>
#else
    #include "RAZMockCommon.h"
#endif

// Kelas RAZSidePanel
// Penjelasan: Panel web yang dapat di-toggle (muncul/hilang) untuk aplikasi sidebar (Twitch, Discord, dll).
class RAZSidePanel : public QWidget {
public:
    explicit RAZSidePanel(QWidget* parent = nullptr);
    ~RAZSidePanel();

    // Fungsi: Memuat URL ke dalam panel
    void loadUrl(const std::string& url);

    // Fungsi: Menampilkan atau menyembunyikan panel
    void togglePanel();

private:
    void setupUI();
    bool isVisible;

    // Placeholder untuk judul/header panel
    QLabel* headerLabel;
};

#endif // RAZSIDEPANEL_H
