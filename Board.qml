import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: board
    anchors.fill: parent
    anchors.margins: 5

    Receipe {
        anchors.top: parent.top
    }
    Item {
        height: width * 2 / 3
        width: Math.min(parent.width,parent.height) - 6
        anchors.centerIn: parent
        Halve {
            id: halve1
        }
        Halve {
            id: halve2
            anchors.top: halve1.bottom
        }
    }
    Receipe {
        anchors.bottom: parent.bottom
    }
}
