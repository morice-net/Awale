import QtQuick 2.4
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    id: winPage
    anchors.fill: parent
    color: "#AA000000"
    visible: false
    opacity: 0

    property int winnerNumber: 0

    Image {
        id: box
        source: "../Images/MessageBox.png"
        anchors.centerIn: parent
    }

    Text {
        text: "Player <b>" + winnerNumber + "</b> wins !"
        font.pointSize: 32
        font.family: candyFont.name
        color: "white"
        anchors.fill: box
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.bottomMargin: 25
    }

    Image {
        id: validateButton
        source: "../Images/ValidateButton.png"
        y: box.y + box.height - height
        x: box.x + box.width/2
        MouseArea {
            anchors.fill: parent
            onClicked: {
                startPage.init();
                winDone.start();
            }
        }
    }

    NumberAnimation on opacity { id: winStart; duration: 10000; to: 1; easing.type: Easing.InOutQuad }
    NumberAnimation on opacity { id: winDone; duration: 1000; to: 0; easing.type: Easing.InOutQuad }

    function start(winner) {
        winnerNumber = winner;
        winPage.visible = true;
        winStart.start();
    }

}
