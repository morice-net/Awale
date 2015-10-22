import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    color:"black"
    radius: 15
    opacity: 0.7
    height: halve1.height / 2
    width: halve1.width / 2
    anchors.horizontalCenter:  parent.horizontalCenter

    property int player
    Image {
        id: hole
        height: parent.height - 0.2 * parent.height
        width: height
        source: "Stone.png"
        anchors.centerIn: parent
        Rectangle {
            id: textBack
            height: parent.height /2
            width: height
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            color: "#88FFFFBB"
            radius: 10
            Text {
                anchors.fill: parent
                text: player == 1 ? main.playerScore1 : main.playerScore2
                color: "black"
                font.pixelSize: height - 2
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

    }

}
