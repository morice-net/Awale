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
        anchors.top: loginField.bottom
        anchors.margins: 20
    }

    PictureChooser {
        id: pictChooser
        anchors.top: passField.bottom
        anchors.margins: 20
    }

    MenuButton {
        id: validateAccountCreation
        text: qsTr("Validate");
        anchors.top: pictChooser.bottom
        anchors.margins: 55
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webSocket.sendMessage("createAccount|"+loginField.label+"|"+passField.label+"|"+pictChooser.value())
                fadeEffect.start()
            }
        }
    }
}
