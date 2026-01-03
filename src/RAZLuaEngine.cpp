/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi dasar Lua Engine (Simulasi).
 */

#include "RAZLuaEngine.h"
#include <iostream>
#include <fstream>

// Di implementasi nyata, kita akan include <lua.hpp> atau wrapper seperti Sol2

RAZLuaEngine::RAZLuaEngine() {
    std::cout << "[MODS] RAZ Lua Engine diinisialisasi." << std::endl;
}

RAZLuaEngine::~RAZLuaEngine() {}

void RAZLuaEngine::registerNativeFunctions() {
    // Mengekspos fungsi seperti 'raz.setThemeColor()' ke Lua global state
    std::cout << "[MODS] Fungsi native didaftarkan ke VM Lua." << std::endl;
}

void RAZLuaEngine::runScript(const std::string& filepath) {
    std::cout << "[MODS] Mencoba menjalankan skrip: " << filepath << std::endl;

    // Simulasi pembacaan file
    std::ifstream scriptFile(filepath);
    if (scriptFile.is_open()) {
        std::cout << "[MODS] File ditemukan. Menjalankan parser..." << std::endl;
        // Simulasi parsing: Jika file berisi "set_color", kita anggap sukses mengubah warna
        std::string line;
        while (std::getline(scriptFile, line)) {
            if (line.find("raz.setThemeColor") != std::string::npos) {
                std::cout << "       -> Lua memanggil: setThemeColor(...)" << std::endl;
            }
        }
        scriptFile.close();
    } else {
        std::cout << "[MODS] Gagal membuka file skrip." << std::endl;
    }
}
