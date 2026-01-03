cmake_minimum_required(VERSION 3.16)

project(SugarRAZ VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Konfigurasi Qt ---
# Kita mencoba mencari paket Qt6. Jika tidak ditemukan (misal di lingkungan dev terbatas),
# kita akan menampilkan pesan peringatan namun tetap mengizinkan konfigurasi dasar
# agar struktur proyek tetap bisa dipelajari.

find_package(Qt6 COMPONENTS Core Widgets WebEngineCore WebEngineWidgets QUIET)

if(Qt6_FOUND)
    message(STATUS "Qt6 ditemukan. Mengonfigurasi untuk build penuh.")
else()
    message(WARNING "Qt6 tidak ditemukan. Pastikan Anda telah menginstal Qt WebEngine.")
    message(STATUS "Melanjutkan konfigurasi dalam mode 'Structure-Only' untuk pembelajaran.")
endif()

# --- Definisi Source Code ---
set(SOURCES
    src/RAZMainController.cpp
    src/RAZMainWindow.cpp
    src/RAZSidebar.cpp
    src/RAZResourceLimiterUI.cpp
    src/RAZThemeManager.cpp
    src/RAZAdBlocker.cpp
    src/RAZEngineOptimizer.cpp
    src/RAZHub.cpp
    src/RAZTabManager.cpp
    src/RAZLuaEngine.cpp
    src/RAZSidePanel.cpp
    src/RAZSettingsManager.cpp
    src/RAZCacheManager.cpp
)

set(HEADERS
    include/RAZBrowserCore.h
    include/RAZMainWindow.h
    include/RAZSidebar.h
    include/RAZResourceLimiterUI.h
    include/RAZThemeManager.h
    include/RAZAdBlocker.h
    include/RAZEngineOptimizer.h
    include/RAZHub.h
    include/RAZTabManager.h
    include/RAZLuaEngine.h
    include/RAZSidePanel.h
    include/RAZSettingsManager.h
    include/RAZCacheManager.h
)

# --- Test Suite ---
add_executable(RAZTestRunner src/RAZTestRunner.cpp src/RAZTestEngine.cpp src/RAZThemeManager.cpp src/RAZAdBlocker.cpp src/RAZHub.cpp)
target_include_directories(RAZTestRunner PRIVATE include)
if(WIN32)
    target_compile_definitions(RAZTestRunner PRIVATE PLATFORM_WINDOWS)
else()
    target_compile_definitions(RAZTestRunner PRIVATE PLATFORM_LINUX)
endif()

# --- Executable ---
if(ANDROID)
    add_library(SugarRAZ SHARED ${SOURCES} ${HEADERS})
    # Konfigurasi tambahan untuk Android deployment akan masuk di sini
elseif(Qt6_FOUND)
    qt_add_executable(SugarRAZ MANUAL_FINALIZATION ${SOURCES} ${HEADERS})
else()
    # Fallback untuk lingkungan tanpa Qt (hanya untuk cek syntax dasar)
    add_executable(SugarRAZ ${SOURCES} ${HEADERS})
endif()

# --- Include Directories ---
target_include_directories(SugarRAZ PRIVATE include)

# --- Linking ---
if(Qt6_FOUND)
    target_link_libraries(SugarRAZ PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::WebEngineCore
        Qt6::WebEngineWidgets
    )
endif()

# --- Platform Specific Definitions ---
if(WIN32)
    target_compile_definitions(SugarRAZ PRIVATE PLATFORM_WINDOWS)
elseif(ANDROID)
    target_compile_definitions(SugarRAZ PRIVATE PLATFORM_ANDROID)
else()
    target_compile_definitions(SugarRAZ PRIVATE PLATFORM_LINUX)
endif()

# --- Instalasi (Persiapan CPack) ---
# Mengatur kemana file akan dicopy saat "make install" atau pembuatan installer

# 1. Install Executable
install(TARGETS SugarRAZ DESTINATION bin)

# 2. Install Resources (Assets)
install(DIRECTORY resources DESTINATION .)

# 3. Install Mods (Contoh script)
install(DIRECTORY mods DESTINATION .)

# 4. Install Helper Scripts (Optional)
install(FILES scripts/run_tests.sh DESTINATION scripts)

# --- Konfigurasi CPack (Installer Generator) ---
set(CPACK_PACKAGE_NAME "SugarRAZBrowser")
set(CPACK_PACKAGE_VENDOR "RAZ Community")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Browser Gaming Ringan dengan AdBlocker Native")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "SugarRAZ")

# Lisensi (Opsional, buat dummy file jika belum ada)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")

if(WIN32)
    # Konfigurasi khusus Windows (NSIS Installer -> .exe)
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_NSIS_DISPLAY_NAME "Sugar RAZ Browser")
    set(CPACK_NSIS_CONTACT "support@sugarraz.com")
    set(CPACK_NSIS_MODIFY_PATH ON) # Tambahkan ke PATH variable
else()
    # Konfigurasi untuk Linux/Mac (Zip/TGZ)
    set(CPACK_GENERATOR "TGZ")
endif()

include(CPack)
