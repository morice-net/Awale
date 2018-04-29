import QtQuick 2.4

import "../Elements"

Page {
    id: launchGamePage

    // Button 1 player
    MenuButton {
        id: button1player
        text: qsTr("Fight the\nmachine");
        anchors.bottom: buttonChallenge.top
        font.pointSize: parent.height * 0.04
        MouseArea {
            anchors.fill: parent
            onClicked: main.start(1)
        }
        Separator {}

    }

    // Button Challenge
    MenuButton {
        id: buttonChallenge
        text: qsTr("Challenge a\nfriend");
        font.pointSize: parent.height * 0.04
        y: parent.height * 0.8
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(2);
            }
        }
    }
}
