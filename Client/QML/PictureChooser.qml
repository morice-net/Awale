import QtQuick 2.0

Rectangle {
    width: 363
    height: 85
    anchors.horizontalCenter: parent.horizontalCenter

    ListModel {
        id: faces
        ListElement {
            source: "http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Female-Face-FE-4-blonde-icon.png"
        }
        ListElement {
            source: "http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Male-Face-E1-icon.png"
        }
        ListElement {
            source: "http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Male-Face-F5-icon.png"
        }
    }

    ListView {
        anchors.fill: parent
        model: faces
        layoutDirection: Qt.Horizontal
        delegate: Image {
            source: source
        }
    }


}
