import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    color:"#000000"
    radius: 15
    height: halve1.height / 2
    width: halve1.width / 2
    anchors.horizontalCenter:  parent.horizontalCenter
    border {
        color: player != main.playerTurn ? "#000000" : "#ffffff";
        onColorChanged: Transition {
            NumberAnimation { property: "color"; duration: 400 }
        }
    }
    border.width: 2

    property int player
    Stone {
        numberOfStone: player == 1 ? main.playerScore1 : main.playerScore2
    }

    transform: Rotation { origin.x: width/2 ; origin.y: height/2; angle: player == 1 ? 0 : 180 }
}
