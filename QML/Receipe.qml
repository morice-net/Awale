import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    id: halve
    color: player == main.playerTurn ? "#a03b01" : "#641f00"
    radius: 15
    height: halve1.height / 2
    width: halve1.width / 3
    anchors.horizontalCenter:  parent.horizontalCenter
    border.color: "#ffffff"
    border.width: 2

    property int player
    property int animRotation: 0
    Text {
        anchors.fill: parent
        text: player == 1 ? main.playerScore1 : main.playerScore2
        color: "white"
        font.family: candyFont.name
        font.pixelSize: parent.height/2
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    transform: Rotation { origin.x: width/2 ; origin.y: height/2; angle: player == 1 ? 0 + animRotation : 180 + animRotation }

    SequentialAnimation {
        running: player == main.playerTurn
        loops: Animation.Infinite
        PauseAnimation { duration: 3000 }
        NumberAnimation { target: halve; property: "animRotation"; from: 0; to: -4; easing.type: Easing.InElastic; duration: 700 }
        NumberAnimation { target: halve; property: "animRotation"; from: -4; to: 5; duration: 100 }
        NumberAnimation { target: halve; property: "animRotation"; from: 5; to: 0; easing.type: Easing.OutElastic; duration: 600 }
    }
}
