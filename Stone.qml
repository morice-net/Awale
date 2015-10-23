import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: hole
    anchors.centerIn: parent
    height: parent.height - 0.35 * parent.height
    width: height
    property int numberOfStone

    Image {
        id: stoneImage
        anchors.fill: parent
        source: "Stone.png"
    }
    InnerShadow {
        anchors.fill: stoneImage
        radius: 8.0
        samples: 16
        horizontalOffset: -3
        verticalOffset: 3
        color: "#b0000000"
        source: stoneImage
    }
    DropShadow {
        anchors.fill: stoneImage
        horizontalOffset: 2
        verticalOffset: 1
        radius: 8.0
        samples: 16
        color: "#80000000"
        source: stoneImage
    }
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
