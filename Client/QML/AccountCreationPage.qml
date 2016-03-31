import QtQuick 2.0

Page {

    TextField {
        id: loginField
        label: qsTr("Login")
    }

    TextField {
        id: mailField
        anchors.bottom: loginField.top
        label: qsTr("eMail@address")
    }

    TextField {
        id: passField
        anchors.bottom: mailField.top
        label: qsTr("Password")
        hideText: true

    }

    MenuButton {
        id: validateAccountCreation
        text: qsTr("Create account");
        anchors.bottom: passField.top
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(1);
                fadeEffect.start()
            }
        }
    }
}
