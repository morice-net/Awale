import QtQuick 2.4
import Qt.WebSockets 1.0

Item {

    anchors.fill: parent
    property string serverAddres: "localhost:1234" // "81.56.85.184:1234"

    WebSocket {
        id: socket
        url: "ws://" + serverAddres
        onTextMessageReceived: messageBox.showMessage("Received message:\n" + message)
        onStatusChanged: if (socket.status == WebSocket.Error) {
                             messageBox.showError("Error: " + socket.errorString)
                         } else if (socket.status == WebSocket.Open) {
                             messageBox.showMessage("Connection succeeded");
                         } else if (socket.status == WebSocket.Closed) {
                             messageBox.showError("Socket closed");
                         }
        active: false
    }

    function connect() {
        socket.active = true;
    }

    function sendMessage(message) {
        socket.sendTextMessage(message);
    }
}

