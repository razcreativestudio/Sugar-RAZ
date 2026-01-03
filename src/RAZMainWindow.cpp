/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi tata letak jendela utama.
 */

#include "RAZMainWindow.h"
#include "RAZSidebar.h"
#include "RAZSidePanel.h"
#include "RAZResourceLimiterUI.h"
#include "RAZThemeManager.h"
#include "RAZTabManager.h"
#include "RAZLuaEngine.h"
#include <iostream>

#ifdef QT_CORE_LIB
    #include <QHBoxLayout>
    #include <QApplication>
    #include <QSplitter>
#else
    class QSplitter : public QWidget {
    public:
        QSplitter(QWidget*) {}
        void addWidget(QWidget*) {}
    };
#endif

// Fungsi global statis untuk callback (karena pointer fungsi C klasik)
// Dalam Qt asli, kita pakai Slot member class
static void onRamLimitChanged(int value) {
    std::cout << "[LOGIC] Controller menerima perubahan limit RAM: " << value << " MB" << std::endl;
    // Panggil logika core di sini
}

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

        // Container Web Panel (Twitch/Discord) - Hidden by default
        RAZSidePanel* sidePanel = new RAZSidePanel(centralWidget);
        mainLayout->addWidget(sidePanel); // Tambahkan setelah sidebar, sebelum tab

        // Implementasi Tab Manager sebagai widget utama
        RAZTabManager* tabManager = new RAZTabManager(centralWidget);
        mainLayout->addWidget(tabManager, 1); // Stretch factor 1

        // Resource Limiter (Overlay/Window terpisah biasanya, tapi kita taruh di layout untuk demo)
        RAZResourceLimiterUI* limiter = new RAZResourceLimiterUI(nullptr);
        limiter->setLimitCallback(onRamLimitChanged);
        // limiter->show(); // Tampilkan jika tombol ditekan

    #else
        RAZSidePanel* mockPanel = new RAZSidePanel(nullptr);
        RAZTabManager* mockTabs = new RAZTabManager(nullptr);
        RAZResourceLimiterUI* mockLimiter = new RAZResourceLimiterUI(nullptr);

        // Wiring Callback Simulasi
        mockLimiter->setLimitCallback(onRamLimitChanged);

        std::cout << "[UI-MOCK] Layout utama diinisialisasi (Horizontal Split)." << std::endl;
        std::cout << "[UI-MOCK] Sidebar ditambahkan ke kiri." << std::endl;
        std::cout << "[UI-MOCK] Side Panel (Web) ditambahkan (Hidden)." << std::endl;
        std::cout << "[UI-MOCK] Tab Manager ditambahkan ke kanan." << std::endl;

        // [FASE 5] Simulasi Modding Load saat startup
        RAZLuaEngine modEngine;
        modEngine.registerNativeFunctions();
        modEngine.runScript("mods/autorun.lua");

        // [FASE 6] Simulasi Interaksi User
        std::cout << "\n--- SIMULASI INTERAKSI USER (FASE 6) ---" << std::endl;

        std::cout << "1. User menekan tombol 'Twitch' di Sidebar..." << std::endl;
        mockPanel->loadUrl("https://twitch.tv");

        std::cout << "2. User membuka 'GX Control' dan menggeser slider RAM..." << std::endl;
        // Simulasi event slider
        mockLimiter->onSliderValueChanged(4096);

        std::cout << "3. User menekan tombol 'Twitch' lagi (Toggle Off)..." << std::endl;
        mockPanel->togglePanel();

        std::cout << "----------------------------------------\n" << std::endl;
    #endif
}
