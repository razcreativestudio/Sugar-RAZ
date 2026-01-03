#ifndef RAZ_MOCK_COMMON_H
#define RAZ_MOCK_COMMON_H

#ifndef QT_CORE_LIB
// Cegah redefinisi jika multiple header di-include
#ifndef MOCK_CLASSES_DEFINED
#define MOCK_CLASSES_DEFINED

class QObject {};
class QWidget : public QObject {
public:
    QWidget(QWidget* parent = nullptr) {}
    virtual ~QWidget() {}
    void setObjectName(const char*) {}
    void setFixedWidth(int) {}
    void setStyleSheet(const char*) {}
    void show() {}
};
class QMainWindow : public QWidget {
public:
    void setCentralWidget(QWidget*) {}
};
class QApplication {
public:
    QApplication(int&, char**) {}
    int exec() { return 0; }
    void setStyleSheet(const char*) {}
    static QApplication* instance() { return nullptr; }
};
// Global pointer mock
#define qApp ((QApplication*)0)

class QVBoxLayout {
public:
    QVBoxLayout(QWidget*) {}
    void setContentsMargins(int,int,int,int) {}
    void setSpacing(int) {}
    void addWidget(QWidget*, int = 0) {}
    void addStretch() {}
};
class QHBoxLayout : public QVBoxLayout {
public:
    QHBoxLayout(QWidget* w) : QVBoxLayout(w) {}
};
class QPushButton : public QWidget {
public:
    QPushButton(const char*, QWidget*) {}
};
class QSlider : public QWidget {
public:
    QSlider(int, QWidget*) {}
    void setRange(int, int) {}
    void setValue(int) {}
};
class QLabel : public QWidget {
public:
    QLabel(const char*, QWidget*) {}
};

namespace Qt {
    enum Orientation { Horizontal, Vertical };
}

class QWebEngineView : public QWidget {};

// --- Mocks untuk Fase 3 (Network & Settings) ---

class QWebEngineUrlRequestInfo {
public:
    enum ResourceType { ResourceTypeMainFrame, ResourceTypeImage, ResourceTypeXhr };
    void block(bool) {}
    const char* requestUrl() { return "https://googleads.g.doubleclick.net/pagead/ads"; } // Mock URL
};

class QWebEngineUrlRequestInterceptor : public QObject {
public:
    QWebEngineUrlRequestInterceptor(QObject* parent = nullptr) {} // Tambahkan constructor yang menerima parent
    virtual void interceptRequest(QWebEngineUrlRequestInfo &info) = 0;
};

class QWebEngineSettings {
public:
    enum WebAttribute {
        JavascriptEnabled,
        PluginsEnabled,
        LocalStorageEnabled,
        AutoLoadImages,
        DnsPrefetchEnabled
    };
    void setAttribute(WebAttribute, bool) {}
};

class QWebEngineProfile {
public:
    static QWebEngineProfile* defaultProfile() { return nullptr; }
    void setRequestInterceptor(QWebEngineUrlRequestInterceptor*) {}
    QWebEngineSettings* settings() { return nullptr; }
};

class QTabWidget : public QWidget {
public:
    QTabWidget(QWidget* p) : QWidget(p) {}
    void addTab(QWidget*, const char*) {}
    void setTabsClosable(bool) {}
    QWidget* currentWidget() { return nullptr; }
};

#endif // MOCK_CLASSES_DEFINED
#endif // !QT_CORE_LIB

#endif // RAZ_MOCK_COMMON_H
