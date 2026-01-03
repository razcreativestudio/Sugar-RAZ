#!/bin/bash
echo "Menjalankan Build & Test Otomatis..."

# Hapus build lama
rm -rf build
mkdir build
cd build

# Konfigurasi & Build
cmake ..
if [ $? -ne 0 ]; then
    echo "ERROR: CMake gagal."
    exit 1
fi

make
if [ $? -ne 0 ]; then
    echo "ERROR: Kompilasi gagal."
    exit 1
fi

# Jalankan Unit Test
echo ""
echo "--- UNIT TEST RESULT ---"
./RAZTestRunner
if [ $? -ne 0 ]; then
    echo "ERROR: Test Suite gagal."
    exit 1
fi

echo ""
echo "--- SIMULASI RUN RESULT ---"
./SugarRAZ
echo ""
echo "SUKSES: Semua langkah verifikasi berhasil."
