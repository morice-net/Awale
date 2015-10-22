import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: hole
    width: halve.width / 6 - 2
    height: width

    property int numberOfStone
    Image {
        width: halve.width / 6 - 2
        height: width
        anchors.centerIn: parent
        source: "Hole.png"

        Stone {
            numberOfStone: hole.numberOfStone
        }
    }
    transform: Rotation { origin.x: width/2 ; origin.y: height/2; angle: halve.player == 1 ? 0 : 180 }
    MouseArea {
        anchors.fill: parent
        onClicked: main.takeHole(player,index)
    }
}
