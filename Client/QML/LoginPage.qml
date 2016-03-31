import QtQuick 2.3
import QtGraphicalEffects 1.0

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
    }

    // Button connect
    MenuButton {
        id: connectButton
        text: qsTr("Connect");
        anchors.bottom: parent.bottom
        MouseArea {
            anchors.fill: parent
            onClicked: {

            }
        }
    }
}
