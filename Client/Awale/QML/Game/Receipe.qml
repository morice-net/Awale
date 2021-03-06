import QtQuick 2.4

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    id: receipe
    color: player == main.playerTurn ? "#a03b01" : "#641f00"
    radius: 15
    height: halve1.height / 2
    width: halve1.width / 3
    anchors.horizontalCenter:  parent.horizontalCenter
    border.color: "#ffffff"
    border.width: 2

    property int player
    property int animRotation: 0
    Image {
        source: player == 1 ? faceIconPlayer1 : faceIconPlayer2
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
    }

    Text {
        anchors.fill: parent
        text: player == 1 ? main.playerScore1 : main.playerScore2
        color: "white"
        font.family: candyFont.name
        font.pixelSize: parent.height/2
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    SequentialAnimation {
        running: player == main.playerTurn
        loops: Animation.Infinite
        PauseAnimation { duration: 3000 }
        NumberAnimation { target: receipe; property: "animRotation"; from: 0; to: -4; easing.type: Easing.InElastic; duration: 700 }
        NumberAnimation { target: receipe; property: "animRotation"; from: -4; to: 5; duration: 100 }
        NumberAnimation { target: receipe; property: "animRotation"; from: 5; to: 0; easing.type: Easing.OutElastic; duration: 600 }
    }
}
