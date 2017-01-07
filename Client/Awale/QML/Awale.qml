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

    property string login
    property string faceIcon
    property int wins
    property int games
    property int gameId
    property int elo

    property int winner: 0
    property int playerScore1: 0
    property int playerScore2: 0
    property int takenHole: 0
    property int mode: 0
    property var playerHalve1: [0,0,0,0,0,0]
    property var playerHalve2: [0,0,0,0,0,0]
    property var playable: [0,0,0,0,0,0,0,0,0,0,0,0]
    property int playerTurn: 0 // 1 or 2 when initialized and playing
    property int lastPlayed: -1

    property string xmlText
    property bool connected: false


    signal revert()

    XmlListModel {
        id: xmlAccountModel
        query: "/State/Account"
        xml: xmlText
        XmlRole { name: "login"; query: "login/string()" }
        XmlRole { name: "iconUrl"; query: "iconUrl/string()" }
        XmlRole { name: "wins"; query: "wins/number()" }
        XmlRole { name: "games"; query: "games/number()" }
        XmlRole { name: "elo"; query: "elo/number()" }

        onStatusChanged: {
            if (status == XmlListModel.Ready) {
                if (!connected) {
                    connected = true;
                    main.login = get(0).login;
                    main.faceIcon = get(0).iconUrl;
                    main.wins = get(0).wins;
                    main.games = get(0).games;
                    main.elo = get(0).elo;
                } else {
                    board.loginPlayer1 = get(0).login;
                    board.faceIconPlayer1 = get(0).iconUrl;
                    board.loginPlayer2 = get(1).login;
                    board.faceIconPlayer2 = get(1).iconUrl;
                }
            }
        }
    }

    XmlListModel {
        id: xmlGameModel
        query: "/State/Game"
        xml: xmlText
        XmlRole { name: "playerScore1"; query: "Awale/playerScore1/number()" }
        XmlRole { name: "playerScore2"; query: "Awale/playerScore2/number()" }
        XmlRole { name: "playerHalve1"; query: "Awale/playerHalve1/string()" }
        XmlRole { name: "playerHalve2"; query: "Awale/playerHalve2/string()" }
        XmlRole { name: "takenHole"; query: "Awale/takenHole/number()" }
        XmlRole { name: "playerTurn"; query: "Awale/playerTurn/number()" }
        XmlRole { name: "playables"; query: "Awale/playables/string()" }
        XmlRole { name: "lastPlayed"; query: "Awale/lastPlayed/number()" }
        XmlRole { name: "gameId"; query: "@id/number()" }

        onStatusChanged: {
            if (status == XmlListModel.Ready) {
                main.playerScore1 = get(0).playerScore1;
                main.playerScore2 = get(0).playerScore2;
                main.playerHalve1 = getArrayFromString(get(0).playerHalve1);
                main.playerHalve2 = getArrayFromString(get(0).playerHalve2);
                main.takenHole = get(0).takenHole;
                main.playerTurn = get(0).playerTurn;
                main.playable = getArrayFromString(get(0).playables);
                main.lastPlayed = get(0).lastPlayed;
                main.gameId = get(0).gameId;
            }
        }
    }

    FontLoader {
        id: candyFont
        source: "../Ressources/CANDY.TTF"
    }

    FontLoader {
        id: africanFont
        source: "../Ressources/TribecaRegular.ttf"
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

    function start(mode) {
        main.mode = mode
        if (mode == 1) {
            webSocket.sendMessage("launchGame|"+login);
        }
        if (mode == 2) {
            webSocket.sendMessage("createGame|"+login);
        }
    }

    function rules() {
        console.log(" * Rules Called");
    }

    function getArrayFromString(myString) {
        return myString.split(",");
    }

    function takeHole(index) {
        webSocket.sendMessage("takeHole|"+main.gameId+"|"+main.login+"|"+index);
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
    onLoginChanged: console.log(login)
}
