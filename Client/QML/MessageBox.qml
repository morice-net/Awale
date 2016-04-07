import QtQuick 2.4

Rectangle {
    id: messageBox
    anchors.fill: parent
    color: "#AA000000"
    visible: opacity > 0
    opacity: 0

    property string message: ""
    property bool error: false

    Image {
        id: box
        source: "../Images/MessageBox.png"
        anchors.centerIn: parent
    }

    Text {
        text: message
        font.pointSize: 18
        font.family: candyFont.name
        color: "white"
        anchors.fill: box
        anchors.topMargin: 24
        anchors.leftMargin: 24
        anchors.rightMargin: 24
        anchors.bottomMargin: 60
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
    }

    Image {
        id: validateButton
        source: if (messageBox.error)
                    "../Images/CancelButton.png"
                else
                    "../Images/ValidateButton.png"
        y: box.y + box.height - height
        x: box.x + box.width/2
        MouseArea {
            anchors.fill: parent
            onClicked: {
                messageBox.opacity = 0;
            }
        }
    }
/*
    NumberAnimation on opacity { id: winStart; duration: 10000; to: 1; easing.type: Easing.InOutQuad }
    NumberAnimation on opacity { id: winDone; duration: 1000; to: 0; easing.type: Easing.InOutQuad }
*/
    function showError(message) {
        messageBox.error = true;
        messageBox.message = message;
        messageBox.opacity = 1;
    }

    function showMessage(message) {
        messageBox.error = false;
        messageBox.message = message;
        messageBox.opacity = 1;
    }

}

