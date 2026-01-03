/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi penyimpanan konfigurasi sederhana (INI style).
 */

#include "RAZSettingsManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

RAZSettingsManager& RAZSettingsManager::instance() {
    static RAZSettingsManager instance;
    return instance;
}

RAZSettingsManager::RAZSettingsManager() {
    configFilePath = "raz_config.ini";
    // Default values
    settingsData["RamLimit"] = "2048";
    settingsData["AccentColor"] = "#FA1E4E";
    settingsData["AdBlocker"] = "1";
}

RAZSettingsManager::~RAZSettingsManager() {}

void RAZSettingsManager::loadSettings() {
    std::ifstream file(configFilePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Format sederhana: Key=Value
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos) {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                settingsData[key] = value;
            }
        }
        std::cout << "[CONFIG] Pengaturan dimuat dari " << configFilePath << std::endl;
    } else {
        std::cout << "[CONFIG] File konfigurasi tidak ditemukan. Menggunakan default." << std::endl;
    }
}

void RAZSettingsManager::saveSettings() {
    std::ofstream file(configFilePath);
    if (file.is_open()) {
        for (const auto& pair : settingsData) {
            file << pair.first << "=" << pair.second << "\n";
        }
        std::cout << "[CONFIG] Pengaturan disimpan ke " << configFilePath << std::endl;
    } else {
        std::cerr << "[ERROR] Gagal menyimpan konfigurasi." << std::endl;
    }
}

// --- Accessors ---

void RAZSettingsManager::setRamLimit(int limitMB) {
    settingsData["RamLimit"] = std::to_string(limitMB);
    saveSettings(); // Auto-save on change
}

int RAZSettingsManager::getRamLimit() const {
    try {
        return std::stoi(settingsData.at("RamLimit"));
    } catch (...) {
        return 2048;
    }
}

void RAZSettingsManager::setAccentColor(const std::string& hexColor) {
    settingsData["AccentColor"] = hexColor;
    saveSettings();
}

std::string RAZSettingsManager::getAccentColor() const {
    try {
        return settingsData.at("AccentColor");
    } catch (...) {
        return "#FA1E4E";
    }
}

void RAZSettingsManager::setAdBlockerEnabled(bool enabled) {
    settingsData["AdBlocker"] = enabled ? "1" : "0";
    saveSettings();
}

bool RAZSettingsManager::isAdBlockerEnabled() const {
    try {
        return settingsData.at("AdBlocker") == "1";
    } catch (...) {
        return true;
    }
}
