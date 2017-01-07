import QtQuick 2.0

import QtQuick.XmlListModel 2.0

Item {
    id: pictChooser
    width: 110
    height: 110
    anchors.horizontalCenter: parent.horizontalCenter
    clip: true

    Rectangle {
        id: faceBorder
        anchors.fill: parent
        color: "#935925"
        radius: height/6

        Rectangle {
            color: "#f8e8b0"
            anchors.fill: parent
            anchors.margins: 5
            radius: height/5
        }
    }

    XmlListModel {
        id: faces
        source: "http://artaud.g.free.fr/Awale/Faces/Faces.xml"
        query: "/FacesList/Face"

        XmlRole { name: "sourceUrl"; query: "@name/string()" }
    }

    ListView {
        id: list
        anchors.fill: faceBorder
        anchors.margins: 10
        spacing: 60
        model: faces
        orientation: ListView.Horizontal
        delegate: Item {
            property string source: { "http://artaud.g.free.fr/Awale/Faces/" + sourceUrl }
            height: pictChooser.height - 20
            width: height

            Image {
                anchors.fill: parent
                source: parent.source
            }

            MouseArea {
                anchors.fill: parent
                onClicked: list.currentIndex = index;
            }
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
