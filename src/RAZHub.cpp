/* * DESKRIPSI UPDATE: 25-05-2024
 * Versi: 1.0.0
 * Pembaruan: Implementasi generator HTML untuk RAZ Hub.
 */

#include "RAZHub.h"
#include <iostream>

RAZHub::RAZHub() {
    std::cout << "[HUB] RAZ Hub Service dimulai." << std::endl;
}

RAZHub::~RAZHub() {}

std::string RAZHub::createSystemStatusWidget() {
    return R"(
        <div class="widget status-widget">
            <h3>SYSTEM STATUS</h3>
            <div class="stat-row">
                <span>RAM Usage:</span> <span class="value safe">1.2 GB / 2.0 GB</span>
            </div>
            <div class="stat-row">
                <span>CPU Load:</span> <span class="value warning">12%</span>
            </div>
        </div>
    )";
}

std::string RAZHub::createNewsWidget(const std::string& title, const std::string& snippet) {
    return R"(
        <div class="widget news-widget">
            <h4>)" + title + R"(</h4>
            <p>)" + snippet + R"(</p>
        </div>
    )";
}

std::string RAZHub::getDashboardHTML() {
    std::string html = R"(
    <!DOCTYPE html>
    <html>
    <head>
        <style>
            body { background-color: #121212; color: white; font-family: 'Segoe UI', sans-serif; }
            .container { padding: 20px; display: grid; grid-template-columns: repeat(auto-fill, minmax(250px, 1fr)); gap: 20px; }
            .widget { background-color: #1E1E1E; border: 1px solid #FA1E4E; padding: 15px; border-radius: 5px; }
            h3 { color: #FA1E4E; margin-top: 0; }
            .value.safe { color: #00FF00; }
            .value.warning { color: yellow; }
        </style>
    </head>
    <body>
        <h1>SUGAR RAZ HUB</h1>
        <div class="container">
    )";

    // Tambahkan widget
    html += createSystemStatusWidget();
    html += createNewsWidget("Update Gaming Terbaru", "Sugar RAZ Browser versi Beta 1.0 dirilis dengan fitur limitasi RAM!");
    html += createNewsWidget("E-Sports News", "Turnamen Major DOTA 2 dimulai minggu ini.");
    html += createNewsWidget("Tech Daily", "Optimasi Chromium engine meningkatkan performa hingga 20%.");

    html += R"(
        </div>
    </body>
    </html>
    )";

    return html;
}
