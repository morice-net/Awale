import QtQuick 2.3
import QtGraphicalEffects 1.0
import QtQuick.Particles 2.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Item {
    id: stone
    anchors.centerIn: parent
    width: parent.width/2
    height: width
    property int numberOfStone
    property int oldNumberOfStone
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
            font.family: candyFont.name
            font.pixelSize: textSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    }

    Text {
        id: takenStonesText
        anchors.fill: parent
        text: "+" + stone.oldNumberOfStone
        font.family: candyFont.name
        font.pixelSize: parent.height*0.4
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        opacity: 0

        LinearGradient {
            anchors.fill: parent
            source: takenStonesText
            start: Qt.point(0, 0)
            end: Qt.point(0, parent.height)
            gradient: Gradient {
                        GradientStop { position: 0.0; color: "#FF0000" }
                        GradientStop { position: 1.0; color: "#333333" }
                    }

        }
    }

    DropShadow {
        anchors.fill: takenStonesText
        opacity: takenStonesText.opacity
        color: "#80ffffff"
        source: takenStonesText
        horizontalOffset: 2
        verticalOffset: 2
        radius: 4
        samples: 8
    }


    SequentialAnimation {
        id: winAnimation
        running: false
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height + 10; duration: 300 }
        NumberAnimation { target: stone; property: "textSize"; to: stoneText.height - 5; duration: 300 }
    }

    SequentialAnimation{
        id: takeAnimation
        running: false

        NumberAnimation { target: takenStonesText; property: "opacity"; to: 1; duration: 300 }
        NumberAnimation { target: takenStonesText; property: "font.pixelSize"; to: stone.height; duration: 500 }
        NumberAnimation { target: takenStonesText; property: "font.pixelSize"; to: stone.height*0.7; duration: 300 }
        NumberAnimation { target: takenStonesText; property: "opacity"; to: 0; duration: 300 }

        onRunningChanged: if (!running) oldNumberOfStone = numberOfStone
    }

    onNumberOfStoneChanged: {
        if ( numberOfStone > 0 ) {
            winAnimation.start();
            particles.pulse(stone);
            oldNumberOfStone = numberOfStone;
        } else if (halve.alreadyPlayed) {
            takeAnimation.start();
        } else {
            if (player == 1) {
                halve1.alreadyPlayed = true;
            } else if (player == 2) {
                halve2.alreadyPlayed = true;
            }
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

    Component.onCompleted: {
        oldNumberOfStone = numberOfStone;
    }

}
