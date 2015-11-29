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
        onClicked: deactivate()
    }

    onVisibleChanged: {
        if (opacity > 0) {
            deactivate()
        } else {
            activate.start();
        }
    }

    function deactivate() {
        confirmPage.opacity = 0;
        box.y = -box.height;
        visible = false;
        main.forceActiveFocus();
    }
}
