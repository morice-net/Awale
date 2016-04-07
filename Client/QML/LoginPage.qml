import QtQuick 2.4
import QtGraphicalEffects 1.0

Page {

    TextField {
        id: loginField
        label: qsTr("Choose a login")
        anchors.centerIn: parent
    }

    /*TextField {
        id: passField
        label: qsTr("Password")
        hideText: true
        anchors.top: loginField.bottom
    }*/

    // Button connect
    MenuButton {
        id: connectButton
        text: qsTr("Connect");

        anchors.top: passField.bottom
        
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webSocket.sendMessage("connect|" + loginField.value());
                console.log("Let's play, " + loginField.value());
            }
        }
        Separator {}
    }

    // Button create account
    MenuButton {
        id: createAccountButton
        text: qsTr("Create account");
        anchors.bottom: parent.bottom
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
