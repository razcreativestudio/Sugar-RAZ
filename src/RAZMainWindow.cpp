/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi tata letak jendela utama.
 */

#include "RAZMainWindow.h"
#include "RAZSidebar.h"
#include "RAZThemeManager.h"
#include "RAZTabManager.h"
#include "RAZLuaEngine.h"
#include <iostream>

#ifdef QT_CORE_LIB
    #include <QHBoxLayout>
    #include <QApplication>
#endif

// Constructor
RAZMainWindow::RAZMainWindow() {
    std::cout << "[UI] RAZMainWindow dibuat." << std::endl;
    initUI();
}

// Destructor
RAZMainWindow::~RAZMainWindow() {
    std::cout << "[UI] RAZMainWindow ditutup." << std::endl;
}

// Implementasi initUI
void RAZMainWindow::initUI() {
    // Pengaturan judul jendela
    // setWindowTitle("Sugar RAZ Browser"); // Qt specific
    // resize(1280, 720); // Qt specific

    // Terapkan Tema Global
    RAZThemeManager themeMgr;
    std::string style = themeMgr.getGlobalStyleSheet();
    #ifdef QT_CORE_LIB
        // qApp adalah pointer global ke QApplication
        if (qApp) {
            qApp->setStyleSheet(QString::fromStdString(style));
        }

        centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        // Layout utama (Horizontal: Sidebar - WebView)
        QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(0);

        // Tambahkan Sidebar
        RAZSidebar* sidebar = new RAZSidebar(centralWidget);
        mainLayout->addWidget(sidebar);

        // Implementasi Tab Manager sebagai widget utama
        RAZTabManager* tabManager = new RAZTabManager(centralWidget);
        mainLayout->addWidget(tabManager, 1); // Stretch factor 1

    #else
        RAZTabManager* mockTabs = new RAZTabManager(nullptr);

        std::cout << "[UI-MOCK] Layout utama diinisialisasi (Horizontal Split)." << std::endl;
        std::cout << "[UI-MOCK] Sidebar ditambahkan ke kiri." << std::endl;
        std::cout << "[UI-MOCK] Tab Manager ditambahkan ke kanan." << std::endl;

        // [FASE 5] Simulasi Modding Load saat startup
        RAZLuaEngine modEngine;
        modEngine.registerNativeFunctions();
        modEngine.runScript("mods/autorun.lua");
    #endif
}
