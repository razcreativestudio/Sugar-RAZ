/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi logika pengelolaan tab.
 */

#include "RAZTabManager.h"
#include "RAZHub.h"
#include <iostream>

#ifdef QT_CORE_LIB
    #include <QWebEngineView>
#else
    // Mock WebEngineView jika belum ada di RAZMockCommon untuk penggunaan pointer
    // Tapi biasanya kita include RAZMockCommon di header.
    // Kita asumsikan QWebEngineView turunan QWidget.
#endif

RAZTabManager::RAZTabManager(QWidget* parent) : QTabWidget(parent) {
    // Aktifkan tombol close pada tab
    setTabsClosable(true);

    // Buka tab pertama saat inisialisasi
    openNewTab();

    std::cout << "[TAB] RAZTabManager diinisialisasi." << std::endl;
}

RAZTabManager::~RAZTabManager() {}

void RAZTabManager::openNewTab() {
    RAZHub hub;
    std::string htmlContent = hub.getDashboardHTML();

    #ifdef QT_CORE_LIB
        QWebEngineView* view = new QWebEngineView(this);
        view->setHtml(QString::fromStdString(htmlContent));

        addTab(view, "New Tab");
        std::cout << "[TAB] Tab baru dibuka (RAZ Hub)." << std::endl;
    #else
        // Mock implementation
        QWidget* mockView = new QWidget(this);
        addTab(mockView, "New Tab");
        std::cout << "[TAB-MOCK] Tab baru ditambahkan. Konten: RAZ Hub." << std::endl;
    #endif
}

void RAZTabManager::closeTab(int index) {
    // Logika penutupan tab
    // removeTab(index); // Qt function
    std::cout << "[TAB] Menutup tab index: " << index << std::endl;
}
