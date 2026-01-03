@echo off
echo === PANDUAN BUILD WINDOWS (INSTALLER) ===
echo Pastikan Anda sudah menginstal:
echo 1. CMake (https://cmake.org/download/)
echo 2. Qt6 WebEngine (via Qt Online Installer)
echo 3. Visual Studio C++ Compiler (MSVC)
echo 4. NSIS (Nullsoft Scriptable Install System) untuk generate .exe
echo.

mkdir build_win
cd build_win

echo [1/3] Mengonfigurasi Proyek...
cmake .. -G "Visual Studio 17 2022" -A x64
if %errorlevel% neq 0 exit /b %errorlevel%

echo [2/3] Membangun Aplikasi (Release)...
cmake --build . --config Release
if %errorlevel% neq 0 exit /b %errorlevel%

echo [3/3] Membuat Installer Package...
cpack -C Release
if %errorlevel% neq 0 exit /b %errorlevel%

echo.
echo SUKSES! Installer .exe seharusnya ada di folder build_win/
pause
