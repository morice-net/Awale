import QtQuick 2.3
import QtGraphicalEffects 1.0
import QtQuick.Particles 2.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: stone
    anchors.centerIn: parent
    height: parent.height - 0.35 * parent.height
    width: height
    property int numberOfStone
    property int textSize: stoneText.height - 5

    Image {
        id: stoneImage
        anchors.fill: parent
        source: "../Images/Stone.png"
    }
    InnerShadow {
        anchors.fill: stoneImage
        radius: 8.0
        samples: 16
        horizontalOffset: -3
        verticalOffset: 3
        color: "#b0000000"
        source: stoneImage
    }
    DropShadow {
        anchors.fill: stoneImage
        horizontalOffset: 2
        verticalOffset: 1
        radius: 8.0
        samples: 16
        color: "#80000000"
        source: stoneImage
    }
    Rectangle {
        id: textBack
        height: parent.height /2
        width: height
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        color: "#88FFFFBB"
        radius: 10

        Text {
            id: stoneText
            anchors.fill: parent
            text: stone.numberOfStone
            color: "black"
            font.family: "Droid Serif"
            font.pixelSize: textSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    }
    SequentialAnimation {
        id: winAnimation
        running: false
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height + 10; duration: 300 }
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height - 5; duration: 300 }
    }
    SequentialAnimation {
        id: takeAnimation
        running: false
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height - 10; duration: 300 }
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height + 5; duration: 300 }
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height - 5; duration: 300 }
    }
    onNumberOfStoneChanged: {
        if ( numberOfStone > 0 ) {
            winAnimation.start();
            particles.pulse(stone);
        } else {
            takeAnimation.start();
        }
    }

}