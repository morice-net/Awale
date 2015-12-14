import QtQuick 2.3
import QtGraphicalEffects 1.0
//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: boardButton
    anchors.right: parent.right
    width: parent.width / 11
    height: width
    property string source

    Image {
        id: buttonPict
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
        source: parent.source
        width: boardButton.width
    }
/*
    SequentialAnimation {
        running: true
        loops: Animation.Infinite
        NumberAnimation {
            id: bigBoardButton
            target: buttonPict
            property: "width"
            to: boardButton.width
            easing.type: Easing.InOutElastic
            duration: 1000
        }
        NumberAnimation { id: smallBoardButton; target: buttonPict; property: "width"; to: boardButton.height - 10; easing.type: Easing.InOutElastic; duration: 1000 }
        PauseAnimation { duration: 5000 }
    }

    Component.onCompleted: {
        console.log(boardButton.width)
    }
    onWidthChanged: {
        console.log(boardButton.width)
    }*/
}
