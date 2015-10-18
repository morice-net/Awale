import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: main
    visible: true
    anchors.fill: parent
    width: 800
    height:600

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
