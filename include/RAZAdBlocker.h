/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Sistem Pemblokir Iklan Native.
 */

#ifndef RAZADBLOCKER_H
#define RAZADBLOCKER_H

#ifdef QT_CORE_LIB
    #include <QWebEngineUrlRequestInterceptor>
    #include <QSet>
    #include <QString>
#else
    #include "RAZMockCommon.h"
    #include <string>
    #include <vector>
#endif

// Kelas RAZAdBlocker
// Penjelasan: Mencegat setiap permintaan jaringan dan memblokir URL yang ada di daftar hitam.
class RAZAdBlocker : public QWebEngineUrlRequestInterceptor {
public:
    RAZAdBlocker(QObject* parent = nullptr);
    ~RAZAdBlocker();

    // Fungsi override dari Qt untuk mencegat request
    void interceptRequest(QWebEngineUrlRequestInfo &info) override;

private:
    void loadBlockList();

    #ifdef QT_CORE_LIB
    QSet<QString> blockList;
    #else
    std::vector<std::string> blockList;
    #endif
};

#endif // RAZADBLOCKER_H
