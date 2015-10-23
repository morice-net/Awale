import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: main
    visible: true
    anchors.fill: parent
    width: 800
    height:600

    property int playerScore1: 0
    property int playerScore2: 0
    property int takenHole: 0
    property var playerHalve1: [0,0,0,0,0,0]
    property var playerHalve2: [0,0,0,0,0,0]

    signal start()
    signal takeHole(int player,int index)

    Image {
        id: background
        source: "Background.png"
        width: Math.max(main.width,main.height)
        height: width
        anchors.centerIn: parent
        Rectangle {
            color: "white"
            opacity: 0.3
            anchors.fill: parent
        }
    }

    Board {
        id: board
    }

    StartPage {
    }
}
