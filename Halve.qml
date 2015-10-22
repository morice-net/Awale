import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Image {
    id: halve
    source: "Halve.png"
    width: parent.width
    height: parent.height/2

    property int player

    Row {
        anchors.centerIn: parent
        Repeater {
            model: 6
            Hole {
                numberOfStone: halve.player == 1 ? main.playerHalve1[index] : main.playerHalve2[index]
            }
        }
    }
    
}
