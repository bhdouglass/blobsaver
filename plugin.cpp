#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "blobsaver.h"

void BlobSaverPlugin::registerTypes(const char *uri) {
    //@uri BlobSaver
    qmlRegisterSingletonType<BlobSaver>(uri, 1, 0, "BlobSaver", [](QQmlEngine*, QJSEngine*) -> QObject* { return new BlobSaver; });
}
