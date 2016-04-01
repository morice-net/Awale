import QtQuick 2.4

Item {
    width: 363
    height: 85
    anchors.horizontalCenter: parent.horizontalCenter

    property string label
    property bool hideText: false

    Image {
        anchors.fill: parent
        source: "../Images/TextBackground.png"

        TextInput {
            anchors.fill: parent
            anchors.margins: 25
            font.family: candyFont.name
            font.pointSize: 25
            color: "#ded7bd"
            text: label
            echoMode: hideText ? TextInput.Password : TextInput.Normal

            onTextChanged: {
                var suffix = '\n';
                if (text.indexOf(suffix, text.length - suffix.length) !== -1) {
                    text = text.substring(0, text.length - suffix.length);
                }

                if (text == label) {
                    color = "#ded7bd";
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
}
