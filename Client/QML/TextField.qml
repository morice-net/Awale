import QtQuick 2.0

Rectangle {
    width: 100
    height: 62

    property string label

    Image {
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
        }

        TextEdit {
            anchors.fill: parent
            font.family: "Droid Serif"
        }
    }
}
