import QtQuick 2.0

Item{

    anchors.fill: parent
    opacity: 0
    visible: opacity > 0

    function init() {
        opacity = 1;
    }

    function close() {
        opacity = 0;
    }

    NumberAnimation on opacity { id: fadeEffect; running: false; to: 0; duration: 1000; easing.type: "InCurve"  }
}
