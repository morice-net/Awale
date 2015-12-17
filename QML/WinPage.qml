import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    id: winPage
    anchors.fill: parent
    color: "black"

    Text {
        id: textPourri
        text: "Player " + winner + " wins !"
        font.pointSize: 24
        color: "red"
        anchors.centerIn: parent
    }

    NumberAnimation on opacity { id: winStart; duration: 10000; to: 1; easing.type: Easing.InOutQuad }
    NumberAnimation on opacity { id: winDone; duration: 1000; to: 0; easing.type: Easing.InOutQuad }
    MouseArea {
        anchors.fill: parent
        onClicked: winDone.start()
    }
    function start() {
        winStart.start();
    }

}
