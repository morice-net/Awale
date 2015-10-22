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

    Image {
        id: background
        source: "Background.png"
        width: Math.max(main.width,main.height)
        height: width
        anchors.centerIn: parent
    }

    Board {
        id: board
    }
}
