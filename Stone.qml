import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Image {
    id: hole
    height: parent.height - 0.2 * parent.height
    width: height
    source: "Stone.png"
    anchors.centerIn: parent
    visible: false
    property int numberOfStone
    Rectangle {
        id: textBack
        height: parent.height /2
        width: height
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        color: "#88FFFFBB"
        radius: 10
        Text {
            anchors.fill: parent
            text: hole.numberOfStone
            color: "black"
            font.pixelSize: height - 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
