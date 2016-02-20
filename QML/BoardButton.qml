import QtQuick 2.3
import QtGraphicalEffects 1.0
//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: boardButton
    anchors.right: parent.right
    width: main.width / 11
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
        PauseAnimation { duration: 4500 }
        NumberAnimation { target: buttonPict; property: "width"; from: height; to: height + 8; easing.type: Easing.InElastic; duration: 400 }
        NumberAnimation { target: buttonPict; property: "width"; from: height + 8; to: height; easing.type: Easing.OutElastic; duration: 600 }
    }*/
}
