import QtQuick 2.4

import "../Elements"

Item {
    id: launchGamePage

    // Button 1 player
    MenuButton {
        id: button1player
        text: qsTr("1 player");
        anchors.bottom: button2players.top
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(1);
                fadeEffect.start()
            }
        }
        Separator {}

    }

    // Button 2 players
    MenuButton {
        id: button2players
        text: qsTr("2 players");
        anchors.bottom: buttonRules.top
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(2);
                fadeEffect.start()
            }
        }
        Separator {}
    }

    // Button Rules
    MenuButton {
        id: buttonRules
        text: qsTr("Rules");
        y: parent.height * 0.8
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.rules();
            }
        }
    }
}
