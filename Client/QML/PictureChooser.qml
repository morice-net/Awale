import QtQuick 2.0

Item {
    width: 363
    height: 105
    anchors.horizontalCenter: parent.horizontalCenter

    ListModel {
        id: faces
        ListElement {
            sourceUrl: "http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Female-Face-FE-4-blonde-icon.png"
        }
        ListElement {
            sourceUrl: "http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Male-Face-E1-icon.png"
        }
        ListElement {
            sourceUrl: "http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Male-Face-F5-icon.png"
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
        delegate: Rectangle {
            property string source: sourceUrl
            width: 105
            height: 105
            border.width: 1
            border.color: "#FFFFFF99"
            Image {
                anchors.fill: parent
                source: parent.source
                fillMode: Image.PreserveAspectFit

            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(index);
                    list.currentIndex = index;
                }
            }

            Component.onCompleted: console.log(source)
        }
        highlightFollowsCurrentItem: true
        focus: true
    }

    function value() {
        console.log(list.currentItem.source);
        return list.currentItem.source;
    }
}
