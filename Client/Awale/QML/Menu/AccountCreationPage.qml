import QtQuick 2.4

import "../Elements"

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


    Rectangle {
        id: faceBorder
        anchors.fill: pictChooser
        color: "#935925"
        radius: height/6
        Rectangle {
            color: "#f8e8b0"
            anchors.fill: parent
            anchors.margins: 5
            radius: height/5
        }
    }

    PictureChooser {
        id: pictChooser
        anchors.top: passField.bottom
        anchors.margins: 60
    }


    MenuButton {
        id: validateAccountCreation
        text: qsTr("Create the account");
        anchors.top: pictChooser.bottom
        anchors.margins: 55
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webSocket.sendMessage("createAccount|"+loginField.value()+"|"+passField.value()+"|"+pictChooser.value())
                fadeEffect.start()
            }
        }
    }
}
