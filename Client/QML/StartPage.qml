import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"
Item  {
    anchors.fill: parent
    visible: opacity > 0

    Image {
        anchors.fill: parent

        source: "../Images/Background.png"
        width: Math.max(main.width,main.height)
        height: width
        anchors.centerIn: parent

        Image {
            id: title
            source: "../Images/Title.png"
            anchors.horizontalCenter: parent.horizontalCenter
            y: parent.height * 0.12
            width: parent.width * 0.7
            fillMode: Image.PreserveAspectFit
        }

        DropShadow {
            anchors.fill: title
            horizontalOffset: 2
            verticalOffset: 1
            radius: 8.0
            samples: 16
            color: "#ffffff"
            source: title
        }

        // Button 1 player
        MenuButton {
            id: button1player
            text: qsTr("1 player");
            anchors.bottom: button2players.top
            font.family: candyFont.name
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    main.start(1);
                    fadeEffect.start()
                }
            }
            Separator {}

        }

        // Button 2 players
        MenuButton {
            id: button2players
            text: qsTr("2 players");
            anchors.bottom: buttonRules.top
            font.family: candyFont.name
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    main.start(2);
                    fadeEffect.start()
                }
            }
            Separator {}
        }

        // Button Rules
        MenuButton {
            id: buttonRules
            text: qsTr("Rules");
            y: parent.height * 0.8
            font.family: candyFont.name
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    main.rules();
                }
            }
            Separator {}
        }

        // Button Learning
        MenuButton {
            id: buttonLearning
            text: qsTr("Learning");
            anchors.top: buttonRules.bottom
            font.family: candyFont.name
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    main.start(3);
                }
            }
        }
    }

    function init() {
        opacity = 1;
    }

    NumberAnimation on opacity { id: fadeEffect; running: false; to: 0; duration: 1000; easing.type: "InCurve"  }

}
