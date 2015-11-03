import QtQuick 2.3
import QtGraphicalEffects 1.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"
Item  {
    anchors.fill: parent
    visible: opacity > 0

    Image {
        id: backgrd
        anchors.fill: parent

        source: "Background.png"
        width: Math.max(main.width,main.height)
        height: width
        anchors.centerIn: parent

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
                blurEffect.start()
                fadeEffect.start()
            }
        }

    }

    FastBlur {
        id: blurGraphics
        anchors.fill: backgrd
        source: backgrd
        radius: 0

        NumberAnimation on radius { id: blurEffect; running: false; to: 32; duration: 550 }
    }
    NumberAnimation on opacity { id: fadeEffect; running: false; to: 0; duration: 600; easing.type: "InCurve"  }
}
