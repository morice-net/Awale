import QtQuick 2.4
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: halve
    width: parent.width
    height: parent.height/2

    property int player
    property bool alreadyPlayed: false
    Image {
        id: halveImage
        source: "../Images/Halve.png"
        anchors.fill: parent
    }

    Row {
        anchors.centerIn: parent
        clip: false
        Repeater {
            model: 6
            clip: false
            Hole {
                width: halve.width / 6 - 2
                numberOfStone: halve.player == 1 ? main.playerHalve1[index] : main.playerHalve2[index]
                alreadyPlayed: halve.alreadyPlayed
                realIndex: (halve.player-1)*6+index
                enlightMode: main.playable[realIndex]
            }
        }
    }

    transform: Rotation { origin.x: width/2 ; origin.y: height/2; angle: halve.player == 1 ? 0 : 180 }
}
