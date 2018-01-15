#ifndef BLOBSAVERPLUGIN_H
#define BLOBSAVERPLUGIN_H

#include <QQmlExtensionPlugin>

class BlobSaverPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif
