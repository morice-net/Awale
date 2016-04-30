import QtQuick 2.4
import Qt.WebSockets 1.0

Item {

    anchors.fill: parent
    property string serverAddres: "localhost:1234" // "81.56.85.184:80"

    WebSocket {
        id: socket
        url: "ws://" + serverAddres
        onTextMessageReceived: messageBox.showMessage("Received message:\n" + message)
        onStatusChanged: if (socket.status == WebSocket.Error) {
                             errorReceived(socket.errorString);
                         } else if (socket.status == WebSocket.Open) {
                             messageBox.showMessage("Connection succeeded");
                             menu.setLoginPage();
                         } else if (socket.status == WebSocket.Closed) {
                             errorReceived("Socket closed");
                         }
        active: false
    }

    function connect() {
        socket.active = false;
        socket.active = true;
    }

    function sendMessage(message) {
        socket.sendTextMessage(message);
    }

    function errorReceived(message) {

        if (message == "Host unreachable" || message == "Connection refused" || message == "Socket closed") {
            menu.setStartPage();
        }

        messageBox.showError("Error: " + message)

    }
}

