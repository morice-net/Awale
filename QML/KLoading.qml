import QtQuick 2.0

Rectangle {
    id: load
    anchors.fill: parent
    color: "#0068c6"
    visible: opacity != 0


    Image {
        id: gears
        anchors.centerIn: parent
        source: "../Images/KGears.png"

    }
    Image {
        id: icone
        anchors.centerIn: parent
        source: "../Images/KIco.png"
    }
    Text {
        id: loading
        text: qsTr("Loading...")
        anchors.top: icone.bottom
        anchors.margins: 25
        anchors.horizontalCenter: parent.horizontalCenter
        color: "white"
        font.bold: true
    }

    SequentialAnimation {
        id: blinking
        running: true
        loops: Animation.Infinite
        NumberAnimation { target: loading; property: "opacity"; from: 0.8; to: 0.2;duration: 900; easing.type: Easing.InQuad; }
        NumberAnimation { target: loading; property: "opacity"; from: 0.2; to: 0.8;duration: 900; easing.type: Easing.OutQuad; }

    }

    SequentialAnimation {
        id: closing
        ParallelAnimation {
            NumberAnimation { target: gears; property: "opacity"; to: 0; duration: 1500; easing.type: Easing.OutQuad }
            NumberAnimation { target: icone; property: "opacity"; to: 0; duration: 1500; easing.type: Easing.OutQuad }
            NumberAnimation { target: loading; property: "opacity"; to: 0; duration: 1600; easing.type: Easing.OutQuad }
        }
        NumberAnimation { target: load; property: "opacity"; to: 0; duration: 1000; easing.type: Easing.OutQuad }
    }

    NumberAnimation { target: gears; property: "rotation"; from: 0; to: 360; duration: 2000; running: true; loops: Animation.Infinite }


    function close() {
        blinking.stop();
        closing.start();
    }
}
