# Panduan Pengembangan Sugar RAZ

## Standar Kode
Proyek ini dibuat dengan tujuan edukasi. Oleh karena itu, konsistensi dan dokumentasi adalah prioritas utama.

### 1. Penamaan File & Kelas
*   Semua file source code C++ dan header harus memiliki prefix `RAZ`.
*   Contoh: `RAZMainController.cpp`, `RAZBrowserCore.h`.
*   Nama kelas harus sama dengan nama file (tanpa ekstensi).

### 2. Header Komentar (Wajib)
Setiap file harus dimulai dengan blok komentar yang menjelaskan riwayat pembaruan dan tujuan file dalam Bahasa Indonesia.

Format:
```cpp
/* * DESKRIPSI UPDATE: [TANGGAL]
 * Versi: [VERSI]
 * Pembaruan: [DESKRIPSI SINGKAT]
 */
```

### 3. Komentar Baris
Gunakan komentar untuk menjelaskan logika yang kompleks, terutama yang berkaitan dengan manajemen memori atau interaksi engine.

```cpp
// Mengatur batas penggunaan RAM agar tetap ringan (Limit 2GB)
sugarRaz.setRamLimit(2048);
```

## Tools
Gunakan skrip `scripts/raz_gen.py` untuk membuat file baru secara otomatis dengan template yang benar.
Cara pakai:
```bash
python3 scripts/raz_gen.py NamaFileBaru
```
(Akan menghasilkan `src/RAZNamaFileBaru.cpp` dan `include/RAZNamaFileBaru.h`)
