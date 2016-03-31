import QtQuick 2.3
import QtGraphicalEffects 1.0

Page {

    TextField {
        id: loginField
        label: qsTr("Login")
    }

    TextField {
        id: passField
        label: qsTr("Password")
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
