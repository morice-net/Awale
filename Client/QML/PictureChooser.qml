import QtQuick 2.0

Item {
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


    Component {
        id: iconFaces
        Rectangle {
            width: 85
            height: 85
            border.width: 1
            border.color: "#FFFFFF99"
            Image {
                anchors.fill: parent
                source: source
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(index);
                    list.currentIndex = index;
                }
            }
        }
    }

    ListView {
        id: list
        height: parent.height
        width: height
        anchors.centerIn: parent
        spacing: 100
        model: faces
        orientation: ListView.Horizontal
        delegate: iconFaces
        highlightFollowsCurrentItem: true
        focus: true
    }


}
