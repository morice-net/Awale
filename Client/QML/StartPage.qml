import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"
Page  {
    // Play button
    MenuButton {
        id: playButton
        text: qsTr("Play !");
        anchors.centerIn: parent
        font.family: candyFont.name
        font.pointSize: parent.height * 0.1
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(1);
                fadeEffect.start()
            }
        }
        Separator {}

    }

    // Button exit
    MenuButton {
        id: exitButton
        text: qsTr("Exit");
        anchors.top: playButton.bottom
        font.family: candyFont.name
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start(2);
                fadeEffect.start()
            }
        }
    }

}
