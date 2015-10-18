import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    width: halve.width / 6 - 2
    height: width
    Image {
        width: halve.width / 6 - 2
        height: width
        anchors.centerIn: parent
        source: "Hole.png"
    }
}
