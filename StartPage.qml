import QtQuick 2.3

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

Rectangle {
    color: "#000000"
    anchors.fill: parent
    visible: opacity > 0
    
    Rectangle
    {
        color: "#b3f14e"
        border.color: "#ffffffCC"
        width: 100
        height: 70
        anchors.centerIn: parent
        radius: 20
        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "Start now !"
            font.family: "Droid Serif"
            font.bold: true
            font.pointSize: 12
        }
        
        MouseArea {
            anchors.fill: parent
            onClicked: {
                main.start();
                fadeEffect.start()
            }
        }
    }
    
    NumberAnimation on opacity { id: fadeEffect; running: false; to: 0; duration: 600; easing.type: "OutCurve"  }
}
