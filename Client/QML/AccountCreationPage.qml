import QtQuick 2.4

Page {

    TextField {
        id: loginField
        label: qsTr("Login")
        anchors.centerIn: parent
    }

    TextField {
        id: mailField
        label: qsTr("eMail@address")
        anchors.top: loginField.bottom
    }

    TextField {
        id: passField
        label: qsTr("Password")
        hideText: true
        anchors.top: mailField.bottom

    }

    MenuButton {
        id: validateAccountCreation
        text: qsTr("Create account");
        anchors.top: passField.bottom
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(1);
                fadeEffect.start()
            }
        }
    }
}
