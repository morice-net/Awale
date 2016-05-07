import QtQuick 2.4
import QtGraphicalEffects 1.0
//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: boardButton
    anchors.margins: 10
    anchors.right: parent.right
    width: main.width / 11
    height: width
    property string source

    Image {
        id: buttonPict
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
        source: parent.source
        width: boardButton.width
    }
}
