import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: main
    visible: true
    focus: true // For the keys listener

    //anchors.fill: parent
    width: 600
    height:800

    property int playerScore1: 0
    property int playerScore2: 0
    property int takenHole: 0
    property var playerHalve1: [0,0,0,0,0,0]
    property var playerHalve2: [0,0,0,0,0,0]
    property int playerTurn: 0 // 1 or 2 when initialized and playing

    signal start(int mode)
    signal takeHole(int player,int index)

    Image {
        id: background
        source: "../Images/Background.png"
        width: Math.max(main.width,main.height)
        height: width
        anchors.centerIn: parent
    }

    Board {
        id: board
    }

    StartPage {
        id: startPage
    }

    Image {
        id: settingsButton
        source: "../Images/SettingsButton.png"
        width: Math.max(main.width/11.5,main.height/11.5)
        height: width
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5
    }

    ConfirmPage {
        id: confirmPage
    }

    Keys.onPressed: {
        if (event.key == Qt.Key_Escape) {
            console.log("Confirm exit ?");
            if (confirmPage.visible) {
                confirmPage.visible = false;
            } else {
                confirmPage.visible = true;
            }

        }
    }

    function settings() {
        console.log(" Settings Called !!!");
    }
}
