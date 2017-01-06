import QtQuick 2.0

Item {
    width: parent.width * 0.9
    height: parent.height * 0.5
    anchors.margins: parent.height * 0.1
    anchors.horizontalCenter: parent.horizontalCenter
    Text {
        y: parent.height * 0.075
        text: "Game list"
        color: "#935925"
        font.family: africanFont.name
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: parent.height * 0.03

    }

    Rectangle {
        anchors.fill: parent
        anchors.topMargin: parent.height * 0.15
        anchors.leftMargin: parent.height * 0.03
        anchors.rightMargin: parent.height * 0.03

        color: "#88000000"
        radius: 10
        border.width: 1
        border.color: "white"
    }
}
