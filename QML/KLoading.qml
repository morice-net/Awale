import QtQuick 2.0

Rectangle {
    id: load
    anchors.fill: parent
    color: "#0068c6"
    visible: opacity != 0

    Text {
        id: loading
        text: qsTr("Loading...")
        anchors.centerIn: parent
        color: "white"
        font.bold: true
    }

    Image {
        id: gears
        anchors.margins: 40
        anchors.bottomMargin: 35
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        source: "../Images/KGears.png"
        NumberAnimation on opacity { id:closingGears; to: 0;duration: 2000 }

    }
    Image {
        id: icone
        anchors.margins: 20
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        source: "../Images/KIco.png"
        NumberAnimation on opacity { id:closingIco; to: 0;duration: 2000 }
    }

    NumberAnimation { target: loading; property: "opacity"; from: 0.9; to: 0;duration: 1300; easing.type: Easing.InQuad; running: true; loops: Animation.Infinite }
    NumberAnimation { target: gears; property: "rotation"; from: 0; to: 360; duration: 2000; running: true; loops: Animation.Infinite }
    NumberAnimation on opacity { id:closing; to: 0;duration: 4000 }

    function close() {
        closingGears.start();
        closingIco.start();
        closing.start();
    }
}
