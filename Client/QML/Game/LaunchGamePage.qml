import QtQuick 2.4

import "../Elements"

Item {
    id: accountPage
    height: parent.height
    width: height * 0.42


    // Button 1 player
    MenuButton {
        id: button1player
        text: qsTr("Fight the machine");
        anchors.bottom: buttonLadder.top
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(1);
                fadeEffect.start()
            }
        }
        Separator {}

    }

    // Button ladder
    MenuButton {
        id: buttonLadder
        text: qsTr("Run the ladder");
        anchors.bottom: buttonChallenge.top
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(2);
                fadeEffect.start()
            }
        }
        Separator {}
    }

    // Button Challenge
    MenuButton {
        id: buttonChallenge
        text: qsTr("Challenge a friend");
        y: parent.height * 0.8
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.rules();
            }
        }
    }
}
