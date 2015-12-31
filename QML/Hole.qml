import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: hole
    height: width

    property int numberOfStone
    property int player: main.playerTurn
    property bool alreadyPlayed

    Image {
        width: parent.width
        height: width
        anchors.centerIn: parent
        source: "../Images/Hole.png"

        Stone {
            numberOfStone: hole.numberOfStone
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (main.playerTurn != halve.player) {
                return;
            }

            if (numberOfStone > 0) {
                main.takeHole(player,index);
            }
        }
    }

    onPlayerChanged: {
        alreadyPlayed = false;
    }
}
