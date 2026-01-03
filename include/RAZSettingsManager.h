/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Manajer Pengaturan (Persistence).
 */

#ifndef RAZSETTINGSMANAGER_H
#define RAZSETTINGSMANAGER_H

#include <string>
#include <map>

// Kelas RAZSettingsManager
// Penjelasan: Menyimpan dan memuat konfigurasi pengguna dari disk (file raz_config.ini).
class RAZSettingsManager {
public:
    static RAZSettingsManager& instance();

    void loadSettings();
    void saveSettings();

    // Getters & Setters
    void setRamLimit(int limitMB);
    int getRamLimit() const;

    void setAccentColor(const std::string& hexColor);
    std::string getAccentColor() const;

    void setAdBlockerEnabled(bool enabled);
    bool isAdBlockerEnabled() const;

private:
    RAZSettingsManager();
    ~RAZSettingsManager();

    // Mencegah copy
    RAZSettingsManager(const RAZSettingsManager&) = delete;
    void operator=(const RAZSettingsManager&) = delete;

    std::string configFilePath;
    std::map<std::string, std::string> settingsData;
};

#endif // RAZSETTINGSMANAGER_H
