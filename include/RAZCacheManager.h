/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Manajer Cache (Fast Startup).
 */

#ifndef RAZCACHEMANAGER_H
#define RAZCACHEMANAGER_H

#include <string>
#include <vector>

// Kelas RAZCacheManager
// Penjelasan: Mengelola cache disk dan memori untuk mempercepat waktu startup.
//            Melakukan "Warming" (preload) aset kritis.
class RAZCacheManager {
public:
    static RAZCacheManager& instance();

    // Fungsi: Memulai proses cache warming di thread terpisah
    void startCacheWarming();

private:
    RAZCacheManager();
    ~RAZCacheManager();

    // List aset kritis yang perlu dipreload (misal: CSS UI, Icon Sidebar)
    std::vector<std::string> criticalAssets;

    void performWarming();
};

#endif // RAZCACHEMANAGER_H
