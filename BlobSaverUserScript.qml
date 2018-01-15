import QtQuick 2.4
import Ubuntu.Components 1.3
import com.canonical.Oxide 1.0 as Oxide

Oxide.UserScript {
    context: 'oxide://main-world'
    emulateGreasemonkey: true
    url: Qt.resolvedUrl('blobsaver.js')
}
