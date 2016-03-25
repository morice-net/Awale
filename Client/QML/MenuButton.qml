import QtQuick 2.0

Text {
    anchors.margins: parent.height * 0.1
    anchors.horizontalCenter: parent.horizontalCenter

    color: "#935925"
    font.family: "Droid Serif"
    font.bold: true
    font.pointSize: parent.height * 0.03

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter


    // Should be opacity 1 but animation rules
    opacity: 0
    NumberAnimation on opacity { id: appearEffect; running: false; to: 1; duration: 1500; easing.type: "InCurve"  }
    Component.onCompleted: {
        appearEffect.start();
    }
}
