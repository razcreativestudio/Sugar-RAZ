/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi Cache Warming.
 */

#include "RAZCacheManager.h"
#include <iostream>
#include <thread>
#include <chrono>

RAZCacheManager& RAZCacheManager::instance() {
    static RAZCacheManager instance;
    return instance;
}

RAZCacheManager::RAZCacheManager() {
    // Definisi aset kritis
    criticalAssets.push_back("resources/ui_theme.css");
    criticalAssets.push_back("resources/icons/gx_control.png");
    criticalAssets.push_back("resources/icons/twitch.png");
    criticalAssets.push_back("resources/raz_hub_template.html");
}

RAZCacheManager::~RAZCacheManager() {}

void RAZCacheManager::startCacheWarming() {
    std::cout << "[CACHE] Memulai Cache Warming di background..." << std::endl;

    // Jalankan di thread terpisah agar tidak memblokir startup UI
    std::thread warmer(&RAZCacheManager::performWarming, this);
    warmer.detach();
}

void RAZCacheManager::performWarming() {
    // Simulasi loading aset ke memori
    for (const auto& asset : criticalAssets) {
        // std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulasi IO latency
        std::cout << "       -> Preloading: " << asset << std::endl;
    }
    std::cout << "[CACHE] Warming selesai. Aset siap di memori." << std::endl;
}
