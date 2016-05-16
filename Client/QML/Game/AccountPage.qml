import QtQuick 2.4

import "../Elements"

Item {
    id: accountPage
    anchors.fill: parent

    Image {
        id: face
        source: main.faceIcon
    }

    Text {
        id: login
        anchors.fill: parent
        text: main.login
        /*
        anchors.margins: 100
        anchors.top: face.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        */
        color: "#935925"
        font.family: candyFont.name
        font.pointSize: parent.height * 0.06

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
