import QtQuick 2.4

Item {
    width: 363
    height: 85
    anchors.horizontalCenter: parent.horizontalCenter

    property string label
    property bool hideText: false

    Rectangle {
        anchors.fill: parent
        color: "#935925"
        radius: height/6
        Rectangle {
            color: "#f8e8b0"
            anchors.fill: parent
            anchors.margins: 5
            radius: height/5
        }

        TextInput {
            id: inputValue
            anchors.fill: parent
            anchors.margins: 25
            font.family: candyFont.name
            font.pointSize: 25
            color: "#d5a771"
            text: label
            echoMode: hideText ? TextInput.Password : TextInput.Normal

            onTextChanged: {
                var suffix = '\n';
                if (text.indexOf(suffix, text.length - suffix.length) !== -1) {
                    text = text.substring(0, text.length - suffix.length);
                }

                if (text == label) {
                    color = "#d5a771";
                }
            }

            onFocusChanged: {
                if (focus && text == label) {
                    text = "";
                    color = "white";
                } else if (text == "") {
                    text = label;
                }
            }        
        }
    }

    SequentialAnimation {
        running: inputValue.text == label
        loops: Animation.Infinite
        NumberAnimation { target: inputValue; property: "opacity"; to: 0.3; duration: 800 }
        NumberAnimation { target: inputValue; property: "opacity"; to: 1; duration: 700 }
        PauseAnimation { duration: 2500 }
    }

    function value() {
        return inputValue.getText(0,inputValue.displayText.length);
    }
}
