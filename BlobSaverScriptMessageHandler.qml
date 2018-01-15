import QtQuick 2.4
import com.canonical.Oxide 1.0 as Oxide
import BlobSaver 1.0


Oxide.ScriptMessageHandler {
    property var cb

    msgId: 'createObjectURL'
    contexts: ['oxide://main-world']
    callback: function(msg, frame) {
        console.log('blobsaver createObjectURL handler');
        var path = BlobSaver.write(msg.payload.base64data);
        cb(path);
    }
}
