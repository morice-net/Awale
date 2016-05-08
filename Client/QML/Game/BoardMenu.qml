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

    x: state == "in" ? -435 : 0
    y: 0
    width: 600
    height: 1000
    color: state == "in" ? "#00000000" : "#33000000"

    Image {
        x: 435
        y: 90
        width: 85
        height: 85
        source: "../../Images/BoardBackButton.png"
    }

    Image {
        x: 435
        y: 180
        width: 85
        height: 85
        source: "../../Images/BoardBackButton.png"
    }

    Rectangle {
        id: internShadow
        anchors.fill: parent
        color: "#33000000"
        visible: parent.state != "in"

        MouseArea {
            anchors.fill: parent
            onClicked: parent.parent.state = 'in'
        }
    }

    Image {
        source: "../../Images/BoardBackMenu.png"
        anchors.fill: parent
    }

    Image {
        id: homeBack
        x: 435
        y: 90
        width: 85
        height: 85
        source: "../../Images/BoardBackButton.png"
        visible: parent.state != 'gamelist'
    }

    Image {
        id: gamesBack
        x: 435
        y: 180
        width: 85
        height: 85
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
}

