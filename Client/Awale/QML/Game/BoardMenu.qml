import QtQuick 2.4

Rectangle {

    states: [
        State {
            name: "home"
        },
        State {
            name: "gamelist"
        },
        State {
            name: "in"
        }
    ]

    state: "in"

    x: state == "in" ? -width*0.75 : 0
    y: 0
    width: main.width
    height: main.height
    color: x == 0 ? "#33000000" : "#00000000"

    Image {
        x: parent.width * 437 / 600
        y: 90
        width: Math.min(main.width, main.height)/9
        height: width
        source: "../../Images/BoardBackButton.png"
    }

    Image {
        x: parent.width * 437 / 600
        y: 170
        width: Math.min(main.width, main.height)/9
        height: width
        source: "../../Images/BoardBackButton.png"
    }

    Rectangle {
        id: internShadow
        anchors.fill: parent
        color: "#33000000"
        visible: parent.x == 0

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.state = 'in'
        }
    }

    Image {
        source: "../../Images/BoardBackMenu.png"
        anchors.fill: parent

        LaunchGamePage {
            id: launchGamePage
            visible: parent.parent.state == 'gamelist'
        }

        AccountPage {
            id: accountPage
            visible: parent.parent.state == 'home'
        }
    }

    Image {
        id: homeBack
        x: parent.width * 437 / 600
        y: 90
        width: Math.min(main.width, main.height)/9
        height: width
        source: "../../Images/BoardBackButton.png"
        visible: parent.state != 'gamelist'
    }

    Image {
        id: gamesBack
        x: parent.width * 437 / 600
        y: 170
        width: Math.min(main.width, main.height)/9
        height: width
        source: "../../Images/BoardBackButton.png"
        visible: parent.state != 'home'
    }

    Image {
        anchors.centerIn: homeBack
        width: Math.min(main.width, main.height)/11
        height: width
        source: "../../Images/HomeButton.png"

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.state = 'home'
        }
    }

    Image {
        anchors.centerIn: gamesBack
        width: Math.min(main.width, main.height)/11
        height: width
        source: "../../Images/GamesListButton.png"

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.state = 'gamelist'
        }
    }

    Behavior on x {
        NumberAnimation { duration: 400 }
    }
}

