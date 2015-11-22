import QtQuick 2.3
import QtGraphicalEffects 1.0
//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: board
    anchors.fill: parent
    anchors.margins: 5

    Receipe {
        anchors.top: parent.top
        player: 2
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
        horizontalOffset: 10
        verticalOffset: main.playerTurn == 1 ? -6 : 6
        spread: 0.5
        radius:  8.0
        samples: 16
        color: "#60000000"
        source: halves
    }
    DropShadow {
        anchors.fill: halves
        horizontalOffset: 10
        verticalOffset: main.playerTurn == 1 ? -12 : 12
        spread: 0.5
        radius:  8.0
        samples: 16
        color: "#80000000"
        source: halves
    }
    Receipe {
        anchors.bottom: parent.bottom
        player: 1
    }
}
