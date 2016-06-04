import QtQuick 2.4
import Qt.WebSockets 1.0

Item {

    anchors.fill: parent
    property string serverAddres: "localhost:1234" // "81.56.85.184:80"

    WebSocket {
        id: socket
        url: "ws://" + serverAddres
        onTextMessageReceived: processMessage(message)
        onStatusChanged: if (socket.status == WebSocket.Error) {
                             errorReceived(socket.errorString);
                         } else if (socket.status == WebSocket.Open) {
                             //messageBox.showMessage("Connection succeeded");
                             menu.setLoginPage();
                         } else if (socket.status == WebSocket.Closed) {
                             errorReceived("Socket closed");
                         }
        active: false
    }

    function beginsWith(stringMessage, stringBegin) {
        var beginsOrNot = true;
        for (var i = 0; i < stringBegin.length; i++) {
            if (stringMessage.charAt(i) != stringBegin.charAt(i)) {
                beginsOrNot = false;
            }
        }
        return beginsOrNot;
    }


    function removeFirstLetters(stringMessage, lengthToRemove) {
        var returnedString = "";
        for (var i = lengthToRemove; i < stringMessage.length; i++) {
            returnedString += stringMessage.charAt(i);
        }
        return returnedString;
    }

    function connect() {
        socket.active = false;
        socket.active = true;
    }

    function sendMessage(message) {
        socket.sendTextMessage(message);
    }

    function processMessage(message) {
        console.log(message);
        if (beginsWith(message,"Error|")) {
            errorReceived(removeFirstLetters(message, 6));
        } else if (beginsWith(message,"<?xml")) {
            accountXmlModel.xml = message;
        } else {
            messageBox.showMessage("Received message:\n" + message)
        }
    }

    function errorReceived(message) {
        menu.init();
        if (message == "Host unreachable" || message == "Connection refused" || message == "Socket closed") {
            menu.setStartPage();
        }

        messageBox.showError("Error: " + message)
    }
}

