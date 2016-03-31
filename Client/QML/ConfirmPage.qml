import QtQuick 2.0

Rectangle {
    id: confirmPage
    anchors.fill: parent
    color: "#AA000000"
    visible: false
    opacity: 0

    Image {
        id: box
        source: "../Images/ConfirmBox.png"
        y: -height
        anchors.horizontalCenter: parent.horizontalCenter
    }

    SequentialAnimation {
        id: activate
        running: false
        NumberAnimation {
            target: confirmPage
            property: "opacity"
            to: 1
            duration: 450
        }
        NumberAnimation {
            target: box
            property: "y"
            to: confirmPage.height/3
            duration: 450
            easing.type: "OutElastic"
        }

    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.visible = false
    }

    Image {
        id: validateButton
        source: "../Images/ValidateButton.png"
        y: box.y + box.height - height
        x: box.x + box.width/2  + box.width / 20
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (menu.visible) {
                    Qt.quit();
                } else {
                    menu.init();
                }
                confirmPage.visible = false;
            }
        }
    }

    onVisibleChanged: {
        if (opacity > 0) {
            confirmPage.opacity = 0;
            box.y = -box.height;
        } else {
            activate.start();
        }
    }
}
