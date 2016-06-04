import QtQuick 2.4

import "../Elements"

MenuText {
    id: login
    text: main.login
    
    anchors.margins: 100
    anchors.top: face.bottom
    anchors.horizontalCenter: parent.horizontalCenter
    
    color: "#935925"
    font.family: candyFont.name
    font.pointSize: parent.height * 0.06
    
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter
}
