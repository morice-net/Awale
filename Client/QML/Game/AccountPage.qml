import QtQuick 2.4

import "../Elements"

Item {
    id: accountPage
    height: parent.height
    width: height * 0.42

    Image {
        id: face
        source: main.faceIcon

        anchors.margins: 100
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

    }

    MenuText {
        id: login
        text: main.login
        anchors.top: face.bottom
    }
}
