import QtQuick 2.4
import QtGraphicalEffects 1.0

import "../Elements"

Page {

    TextField {
        id: loginField
        label: qsTr("Choose a login")
        y: parent.height/2 + parent.height*0.06
    }

    TextField {
        id: passField
        label: qsTr("Password")
        hideText: true
        anchors.top: loginField.bottom
    }

    // Button connect
    MenuButton {
        id: connectButton
        text: qsTr("Connect");

        anchors.top: passField.bottom
        
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webSocket.sendMessage("connect|" + loginField.value());
            }
        }
        Separator {}
    }

    // Button create account
    MenuButton {
        id: createAccountButton
        text: qsTr("Create account");
        anchors.top: connectButton.bottom
        font.pointSize: parent.height * 0.015
        MouseArea {
            anchors.fill: parent
            onClicked: {
                accountCreationPage.init();
                loginPage.close();
            }
        }
    }
}
