import QtQuick 2.4
import QtGraphicalEffects 1.0

import "../Elements"

Page {

    TextField {
        id: loginField
        label: qsTr("Choose a login")
        y: parent.height/2 - height
    }

    TextField {
        id: passField
        label: qsTr("Password")
        hideText: true
        anchors.top: loginField.bottom
        anchors.margins: parent.height * 0.1
    }

    // Button connect
    MenuButton {
        id: connectButton
        text: qsTr("Connect");

        anchors.top: passField.bottom
        anchors.margins: parent.height * 0.2
        
        MouseArea {
            anchors.fill: parent
            onClicked: webSocket.sendMessage("connectClient|" + loginField.value() + "|" + passField.value())
        }
        Separator {}
    }

    // Button create account
    MenuButton {
        id: createAccountButton
        text: qsTr("Create account");
        anchors.top: connectButton.bottom
        anchors.margins: parent.height * 0.2
        font.pointSize: parent.height * 0.02
        MouseArea {
            anchors.fill: parent
            onClicked: {
                accountCreationPage.init();
                loginPage.close();
            }
        }
    }
}
