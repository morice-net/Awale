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

    x: state == "in" ? -440 : 0
    y: 0
    width: 600
    height: 1000
    color: x == 0 ? "#33000000" : "#00000000"

    Image {
        x: 435
        y: 90
        width: 65
        height: 70
        source: "../../Images/BoardBackButton.png"
    }

    Image {
        x: 435
        y: 160
        width: 65
        height: 70
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
        x: 435
        y: 90
        width: 65
        height: 70
        source: "../../Images/BoardBackButton.png"
        visible: parent.state != 'gamelist'
    }

    Image {
        id: gamesBack
        x: 435
        y: 160
        width: 65
        height: 70
        source: "../../Images/BoardBackButton.png"
        visible: parent.state != 'home'
    }

    Image {
        anchors.centerIn: homeBack
        width: main.width/11
        height: width
        source: "../../Images/HomeButton.png"

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.state = 'home'
        }
    }

    Image {
        anchors.centerIn: gamesBack
        width: main.width/11
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

