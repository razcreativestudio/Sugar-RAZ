/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Header untuk Halaman Dashboard Utama (RAZ Hub).
 */

#ifndef RAZHUB_H
#define RAZHUB_H

#include <string>

// Kelas RAZHub
// Penjelasan: Mengelola konten halaman "New Tab" atau Dashboard utama.
//            Menyediakan widget berita dan status sistem dalam format HTML.
class RAZHub {
public:
    RAZHub();
    ~RAZHub();

    // Fungsi: Menghasilkan kode HTML lengkap untuk halaman dashboard
    std::string getDashboardHTML();

private:
    // Fungsi bantuan untuk membuat widget HTML
    std::string createSystemStatusWidget();
    std::string createNewsWidget(const std::string& title, const std::string& snippet);
};

#endif // RAZHUB_H
