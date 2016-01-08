import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: hole
    height: width

    property int numberOfStone
    property int player: main.playerTurn
    property bool alreadyPlayed
    property int realIndex
    property int enlightMode: main.playable[realIndex]

    Image {
        width: parent.width
        height: width
        anchors.centerIn: parent
        source: "../Images/Hole.png"
        InnerShadow {
            id: holePlayable
            anchors.fill: parent
            color: "#ffffff"
            radius: 16
            samples: 16
            horizontalOffset: 1
            verticalOffset: 1
            spread: 0.1
            source: parent
            visible: enlightMode == 1
            SequentialAnimation {
                running: true
                loops: Animation.Infinite
                ColorAnimation { target: holePlayable; property: "color"; duration: 800; from: "black"; to: "white" }
                ColorAnimation { target: holePlayable; property: "color"; duration: 800; to: "black"; from: "white" }
            }
        }
        InnerShadow {
            id: lastPlayed
            anchors.fill: parent
            color: "yellow"
            radius: 16
            samples: 16
            horizontalOffset: 1
            verticalOffset: 1
            spread: 0.1
            source: parent
            visible: enlightMode == 2
        }

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
        enlightMode = main.playable[realIndex];
    }
}
