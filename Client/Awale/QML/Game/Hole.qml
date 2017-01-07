import QtQuick 2.4
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
    property int enlightMode

    Glow {
        id: holePlayable
        anchors.fill: holeImage
        radius: 7
        samples: 16
        color: "white"
        source: holeImage
        visible: enlightMode === 1
        SequentialAnimation {
            running: true
            loops: Animation.Infinite
            NumberAnimation { target: holePlayable; property: "spread"; duration: 800; to: 0.7 }
            NumberAnimation { target: holePlayable; property: "spread"; duration: 800; to: 0.3 }
        }
    }

    Glow {
        id: lastPlayed
        anchors.fill: holeImage
        radius: 7
        samples: 16
        color: "yellow"
        source: holeImage
        visible: enlightMode === 2
    }

    Image {
        id: holeImage
        width: parent.width*2
        height: width
        anchors.centerIn: parent
        source: "../../Images/Hole.png"

        Stone {
            id: stones
            numberOfStone: hole.numberOfStone
        }

        Glow {
            anchors.fill: stones
            radius: 6
            samples: 16
            color: "white"
            source: stones
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {

            // CPU turn
            if (main.playerTurn == 2 && main.mode == 1)
                return;

            // 1v1
            var side = board.side()
            if (main.playerTurn != side && main.mode == 2)
                return;
            if (side != player)
                return

            // No blocker, you can take the hole
            if (numberOfStone > 0)
                main.takeHole(index);

        }
    }

    transform: Rotation { origin.x: width/2 ; origin.y: height/2; angle: halve.player == 1 ? 0 : 180 }

    onPlayerChanged: {
        alreadyPlayed = false;
    }
}
