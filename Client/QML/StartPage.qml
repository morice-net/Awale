import QtQuick 2.4
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"
Page  {
    // Play button
    MenuButton {
        id: playButton
        text: qsTr("Play !");
        anchors.centerIn: parent
        anchors.margins: parent.height * 0.2
        font.pointSize: parent.height * 0.05
        MouseArea {
            anchors.fill: parent
            onClicked: {
                webSocket.connect();
                startPage.close();
            }
        }
        Separator {}

    }

    // Button exit
    MenuButton {
        id: exitButton
        text: qsTr("Exit");
        anchors.bottom: parent.bottom
        MouseArea {
            anchors.fill: parent
            onClicked: {
                confirmPage.visible = true;
            }
        }
    }

}
