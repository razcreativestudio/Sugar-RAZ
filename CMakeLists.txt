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
)

set(HEADERS
    include/RAZBrowserCore.h
    include/RAZMainWindow.h
    include/RAZSidebar.h
    include/RAZResourceLimiterUI.h
    include/RAZThemeManager.h
)

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
