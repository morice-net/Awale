import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: board
    anchors.fill: parent

    Receipe {
        anchors.top: parent.top
    }
    Item {
        height: parent.height * 2 / 3
        width: parent.width
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
