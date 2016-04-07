import QtQuick 2.3
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
        anchors.top: loginField.bottom
        anchors.margins: loginField.height
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webSocket.sendMessage("connect|" + loginField.value());
                console.log("Let's play, " + loginField.value());
            }
        }
    }
}
