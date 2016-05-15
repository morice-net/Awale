import QtQuick 2.4
import QtGraphicalEffects 1.0
import QtQuick.XmlListModel 2.0

//import "QML/JavaScript/Palette.js" as Palette
import "Menu"
import "Game"
import "Elements"

Rectangle {
    id: main
    visible: true
    focus: true // For the keys listener

    // width: 600
    // height:800
    anchors.fill: parent

    property string login: accountXmlModel.get(0).login
    property string faceIcon: accountXmlModel.get(0).iconUrl
    property int wins: accountXmlModel.get(0).wins
    property int games: accountXmlModel.get(0).games
    property int elo: accountXmlModel.get(0).elo

    property int winner: 0
    property int playerScore1: 0
    property int playerScore2: 0
    property int takenHole: 0
    property int mode: 0
    property var playerHalve1: [0,0,0,0,0,0]
    property var playerHalve2: [0,0,0,0,0,0]
    property var playable: [0,0,0,0,0,0,0,0,0,0,0,0]
    property int playerTurn: 0 // 1 or 2 when initialized and playing

    signal start(int mode)
    signal takeHole(int player,int index)
    signal revert()

    XmlListModel {
        id: accountXmlModel
        query: "/Account"
        XmlRole { name: "login"; query: "login/string()" }
        XmlRole { name: "iconUrl"; query: "iconUrl/string()" }
        XmlRole { name: "wins"; query: "wins/number()" }
        XmlRole { name: "games"; query: "games/number()" }
        XmlRole { name: "elo"; query: "elo/number()" }
    }

    FontLoader {
        id: candyFont
        source: "../Ressources/CANDY.TTF"
    }

    Image {
        id: background
        source: "../Images/Background.png"
        anchors.fill: parent
    }

    Board {
        id: board
    }


    BoardMenu {
        id: boardMenu
    }

    MenuBackground {
        id: menu
    }

    BoardButton {
        id: settingsButton
        source: "../../Images/SettingsButton.png"
        anchors.bottom: parent.bottom
    }

    WinPage {
        id: winPage
        opacity: 0
        visible: false
    }

    ConfirmPage {
        id: confirmPage
    }

    MessageBox {
        id: messageBox
    }

    AwaleSocket {
        id: webSocket
    }

    Keys.onPressed: {
        if (event.key == Qt.Key_Escape || event.key == Qt.Key_Back) {
            if (menu.isStartPage()) {
                console.log("Confirm exit ?");
                if (confirmPage.visible) {
                    confirmPage.visible = false;
                } else {
                    confirmPage.visible = true;
                }
            } else {
                menu.setStartPage();
            }

            event.accepted = true;
        }
    }

    function rules() {
        console.log(" * Rules Called");
    }

    onWinnerChanged: {
        if (winner == -1) {
            return;
        } else {
            console.log(winner);
            winPage.start(winner);
        }
    }

    onPlayerTurnChanged: board.resetAnimation()

}
