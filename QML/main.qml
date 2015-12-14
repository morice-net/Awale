import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    id: main
    visible: true
    focus: true // For the keys listener

    anchors.fill: parent
    //width: 600
    //height:800

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
        anchors.fill: parent
    }

    Board {
        id: board
    }

    StartPage {
        id: startPage
    }

    ConfirmPage {
        id: confirmPage
    }

    Keys.onPressed: {
        if (event.key == Qt.Key_Escape || event.key == Qt.Key_Back) {
            console.log("Confirm exit ?");
            if (confirmPage.visible) {
                confirmPage.visible = false;
            } else {
                confirmPage.visible = true;
            }
            event.accepted = true;
        }
    }

    function rules() {
        console.log(" Settings Called !!!");
    }
}
