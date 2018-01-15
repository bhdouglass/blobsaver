#ifndef BLOBSAVER_H
#define BLOBSAVER_H

#include <QObject>
#include <QString>

class BlobSaver: public QObject {
    Q_OBJECT

public:
    BlobSaver();
    ~BlobSaver() = default;

    Q_INVOKABLE QString write(const QString base64data);
    Q_INVOKABLE void remove(const QString path);
};

#endif
