import QtQuick 2.0

import QtQuick.XmlListModel 2.0

Item {
    width: 363
    height: 105
    anchors.horizontalCenter: parent.horizontalCenter

    XmlListModel {
        id: faces
        source: "http://artaud.g.free.fr/Awale/Faces/Faces.xml"
        query: "/FacesList/Face"

        XmlRole { name: "sourceUrl"; query: "@name/string()" }
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
            property string source: { "http://artaud.g.free.fr/Awale/Faces/" + sourceUrl }
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
        if (list.currentItem == null) {
            return "NoPicture";
        }
        return list.currentItem.source;
    }
}
