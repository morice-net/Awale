import QtQuick 2.0

Item{

    anchors.fill: parent
    opacity: 0
    visible: opacity > 0

    function init() {
        appearFadeEffect.start();
    }

    function close() {
        leaveFadeEffect.start();
    }

    NumberAnimation on opacity { id: appearFadeEffect; running: false; to: 1; duration: 900; easing.type: "OutCurve"  }
    NumberAnimation on opacity { id: leaveFadeEffect; running: false; to: 0; duration: 900; easing.type: "InCurve"  }
}
