import QtQuick 2.4

Page {

    TextField {
        id: loginField
        label: qsTr("Login")
        anchors.centerIn: parent
    }

    TextField {
        id: passField
        label: qsTr("Password")
        hideText: true
        anchors.top: mailField.bottom
    }

    PictureChooser {

    }

    MenuButton {
        id: validateAccountCreation
        text: qsTr("Validate");
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
