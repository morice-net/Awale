import QtQuick 2.0

Text {
    anchors.margins: parent.height * 0.08
    anchors.horizontalCenter: parent.horizontalCenter
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.family: "Droid Serif"
    font.bold: true
    font.pointSize: parent.height * 0.03
    color: "#935925"
    MouseArea {
        anchors.fill: parent
        onClicked: {
            main.start();
            blurEffect.start()
            fadeEffect.start()
        }
    }
}
