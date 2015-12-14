import QtQuick 2.3
import QtGraphicalEffects 1.0
import QtQuick.Particles 2.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: stone
    anchors.fill: parent

    property int numberOfStone
    property int textSize: stoneText.height - 5
    Repeater {
        model: numberOfStone
        Image {
            id: stoneImage
            height: 0.25 * stone.height
            width: height
            x: { getRandomNumber(stone.height,width) }
            y: { getRandomNumber(stone.height,width) }
            source: "../Images/Stone.png"
        }
    }

    Rectangle {
        id: textBack
        height: parent.height /4
        width: height
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: -2
        border.color: "#FFFFFF"
        color: "#DDFFFFFF"
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
    function getRandomNumber(numberMax,width) {
        numberMax -= (20-numberOfStone);
        var randomNumber = 0;
        if (numberMax <= width) {
            return 0;
        }
        while (randomNumber < width/2 || randomNumber > (numberMax-width/2)) {
            randomNumber = Math.random()*(numberMax)+width/2;
            if (randomNumber <= 0) {
                return 0;
            }
        }
        return randomNumber;
    }

}
