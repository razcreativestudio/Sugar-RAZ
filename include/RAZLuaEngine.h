/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Engine Lua (Modding Support).
 */

#ifndef RAZLUAENGINE_H
#define RAZLUAENGINE_H

#include <string>

// Kelas RAZLuaEngine
// Penjelasan: Menyediakan interface untuk menjalankan skrip Lua.
//            Digunakan untuk modifikasi antarmuka dan logika sederhana (Mods).
class RAZLuaEngine {
public:
    RAZLuaEngine();
    ~RAZLuaEngine();

    // Fungsi: Menjalankan file skrip Lua
    void runScript(const std::string& filepath);

    // Fungsi: Mendaftarkan fungsi C++ agar bisa dipanggil dari Lua
    void registerNativeFunctions();
};

#endif // RAZLUAENGINE_H
