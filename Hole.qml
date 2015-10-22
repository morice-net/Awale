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
    MouseArea {
        anchors.fill: parent
        onClicked: main.takeHole(player,index)
    }
}
