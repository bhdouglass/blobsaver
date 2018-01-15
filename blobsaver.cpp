#include <QDebug>
#include <QByteArray>
#include <QUuid>
#include <QStandardPaths>
#include <QFile>
#include <QMimeDatabase>

#include "blobsaver.h"

BlobSaver::BlobSaver() {

}

QString BlobSaver::write(QString base64data) {
    qDebug() << "Writing base64 data to a file";

    QStringList parts = base64data.split("base64,");
    QByteArray data = QByteArray::fromBase64(parts[1].toUtf8());
    QMimeType mimeType = QMimeDatabase().mimeTypeForData(data);

    QUuid uuid = QUuid::createUuid();
    QString name = uuid.toString().remove("{").remove("}");
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/" + name + "." + mimeType.preferredSuffix();

    qDebug() << "Writing to file" << path;
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();

    qDebug() << "Done writing file";
    return path;
}

void BlobSaver::remove(QString path) {
    QFile file(path);
    file.remove();
}
