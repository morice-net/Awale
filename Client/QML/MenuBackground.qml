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

        StartPage {
            id: startPage
        }

        LoginPage {
            id: loginPage
        }

        AccountCreationPage {
            id: accountCreationPage
        }

        LaunchGamePage {
            id: launchGamePage
        }

        OpponentListPage {
            id: opponentListPage
        }
    }

    function isStartPage() {
        return (startPage.visible > 0);
    }

    function setStartPage() {
        loginPage.close();
        accountCreationPage.close();
        launchGamePage.close();
        opponentListPage.close();
        startPage.init();
    }

    function init() {
        opacity = 1;
    }

    NumberAnimation on opacity { id: fadeEffect; running: false; to: 0; duration: 1000; easing.type: "InCurve"  }

    Component.onCompleted: {
        setStartPage();
    }

}
