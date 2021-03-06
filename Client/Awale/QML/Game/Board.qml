import QtQuick 2.4
import QtGraphicalEffects 1.0
//import "QML/JavaScript/Palette.js" as Palette

import "../Elements"

Item {
    id: board
    anchors.fill: parent
    anchors.margins: 5

    property string loginPlayer1
    property string faceIconPlayer1
    property string loginPlayer2
    property string faceIconPlayer2

    Item {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: halves.top

        Receipe {
            anchors.centerIn: parent
            player: 2
        }
    }

    Item {
        id: halves
        height: width * 2 / 3
        width: Math.min(parent.width,parent.height) - 6
        anchors.centerIn: parent
        Halve {
            id: halve1
            player: 2
        }
        Halve {
            id: halve2
            anchors.top: halve1.bottom
            player: 1
        }
    }

    DropShadow {
        anchors.fill: halves
        horizontalOffset: 4
        verticalOffset: main.playerTurn == 1 ? -8 : 8
        spread: 0.5
        radius:  8.0
        samples: 16
        color: "#80000000"
        source: halves
    }


    Item {
        anchors.top: halves.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Receipe {
            anchors.centerIn: parent
            player: 1
        }
    }

    StoneParticles {
        id: particles
    }

    function resetAnimation() {
        if (playerTurn == 1) {
            halve2.alreadyPlayed = false;
            halve1.alreadyPlayed = true;
        } else if (playerTurn == 2) {
            halve1.alreadyPlayed = false;
            halve2.alreadyPlayed = true;
        }
    }

    function side() {
        if (loginPlayer1 == main.login) {
            return 1;
        }
        if (loginPlayer2 == main.login) {
            return 2;
        }
        return 0;
    }
}
