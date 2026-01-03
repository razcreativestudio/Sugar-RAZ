/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi Side Web Panel.
 */

#include "RAZSidePanel.h"
#include <iostream>

#ifdef QT_CORE_LIB
    #include <QWebEngineView>
#endif

RAZSidePanel::RAZSidePanel(QWidget* parent) : QWidget(parent) {
    isVisible = false;
    // Sembunyikan secara default
    // hide(); // Qt function

    setupUI();
    std::cout << "[UI] RAZSidePanel dibuat (Hidden)." << std::endl;
}

RAZSidePanel::~RAZSidePanel() {}

void RAZSidePanel::setupUI() {
    #ifdef QT_CORE_LIB
        // Styling panel
        setFixedWidth(400); // Lebar tetap seperti Opera GX
        setStyleSheet("background-color: #1A1A1A; border-left: 1px solid #333;");

        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, 0);

        // Header sederhana
        headerLabel = new QLabel("Web Panel", this);
        headerLabel->setStyleSheet("padding: 10px; background-color: #FA1E4E; font-weight: bold;");
        layout->addWidget(headerLabel);

        // Web View (Placeholder logic)
        // QWebEngineView* view = new QWebEngineView(this);
        // layout->addWidget(view);
    #else
        headerLabel = new QLabel("Web Panel Mock", this);
    #endif
}

void RAZSidePanel::loadUrl(const std::string& url) {
    std::cout << "[PANEL] Memuat URL di Side Panel: " << url << std::endl;

    #ifdef QT_CORE_LIB
        headerLabel->setText(QString::fromStdString("Panel: " + url));
        // view->load(QUrl(url));
    #else
        // Mock behavior
    #endif

    // Otomatis tampilkan jika memuat URL baru
    if (!isVisible) {
        togglePanel();
    }
}

void RAZSidePanel::togglePanel() {
    isVisible = !isVisible;
    if (isVisible) {
        // show();
        std::cout << "[UI] Side Panel: DITAMPILKAN (Visible)" << std::endl;
    } else {
        // hide();
        std::cout << "[UI] Side Panel: DISEMBUNYIKAN (Hidden)" << std::endl;
    }
}
