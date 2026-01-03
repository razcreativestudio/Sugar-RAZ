/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi logika pemblokiran iklan.
 */

#include "RAZAdBlocker.h"
#include <iostream>

RAZAdBlocker::RAZAdBlocker(QObject* parent) : QWebEngineUrlRequestInterceptor(parent) {
    loadBlockList();
}

RAZAdBlocker::~RAZAdBlocker() {}

void RAZAdBlocker::loadBlockList() {
    // Menambahkan domain iklan umum ke daftar blokir
    // Di aplikasi nyata, ini akan dimuat dari file filter (seperti EasyList)

    #ifdef QT_CORE_LIB
        blockList.insert("doubleclick.net");
        blockList.insert("googleadservices.com");
        blockList.insert("adservice.google.com");
        blockList.insert("facebook.com/tr/"); // Tracker
    #else
        blockList.push_back("doubleclick.net");
        blockList.push_back("googleadservices.com");
        blockList.push_back("adservice.google.com");
    #endif

    std::cout << "[ADBLOCK] Daftar blokir dimuat: " << blockList.size() << " aturan." << std::endl;
}

void RAZAdBlocker::interceptRequest(QWebEngineUrlRequestInfo &info) {
    #ifdef QT_CORE_LIB
        QString url = info.requestUrl().toString();

        for (const QString &domain : blockList) {
            if (url.contains(domain)) {
                info.block(true);
                std::cout << "[ADBLOCK] Memblokir request: " << url.toStdString() << std::endl;
                return;
            }
        }
    #else
        std::string url = "https://googleads.g.doubleclick.net/pagead/ads"; // Simulasi
        std::cout << "[ADBLOCK-MOCK] Mencegat request ke: " << url << std::endl;

        bool blocked = false;
        for (const auto &domain : blockList) {
            if (url.find(domain) != std::string::npos) {
                blocked = true;
                break;
            }
        }

        if (blocked) {
            info.block(true);
            std::cout << "[ADBLOCK] Memblokir request: " << url << std::endl;
        }
    #endif
}
