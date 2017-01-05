import QtQuick 2.4

import "../Elements"

Item {
    id: accountPage
    height: parent.height
    width: height * 0.42


    // Button 1 player
    MenuButton {
        id: button1player
        text: qsTr("Fight the\nmachine");
        anchors.bottom: buttonLadder.top
        MouseArea {
            anchors.fill: parent
            onClicked: main.start(1)
        }
        Separator {}

    }

    // Button ladder
    MenuButton {
        id: buttonLadder
        text: qsTr("Run the\nladder");
        anchors.bottom: buttonChallenge.top
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(2);
                // fadeEffect.start()
            }
        }
        Separator {}
    }

    // Button Challenge
    MenuButton {
        id: buttonChallenge
        text: qsTr("Challenge a\nfriend");
        y: parent.height * 0.8
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.rules();
            }
        }
    }
}
