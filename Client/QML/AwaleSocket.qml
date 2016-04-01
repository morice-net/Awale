import QtQuick 2.4
import Qt.WebSockets 1.0

Item {

    anchors.fill: parent
    property string serverAddres: "localhost:1234"

    WebSocket {
        id: socket
        url: "ws://" + serverAddres
        onTextMessageReceived: {
            messageBox.text = messageBox.text + "\nReceived message: " + message
        }
        onStatusChanged: if (socket.status == WebSocket.Error) {
                             console.log("Error: " + socket.errorString)
                         } else if (socket.status == WebSocket.Open) {
                             socket.sendTextMessage("Socket2")
                         } else if (socket.status == WebSocket.Closed) {
                             messageBox.text += "\nSocket closed"
                         }
        active: false
    }

    WebSocket {
        id: secureWebSocket
        url: "wss://" + serverAddres
        onTextMessageReceived: {
            messageBox.text = messageBox.text + "\nReceived secure message: " + message
        }
        onStatusChanged: if (secureWebSocket.status == WebSocket.Error) {
                             console.log("Error: " + secureWebSocket.errorString)
                         } else if (secureWebSocket.status == WebSocket.Open) {
                             secureWebSocket.sendTextMessage("Hello Secure World")
                         } else if (secureWebSocket.status == WebSocket.Closed) {
                             messageBox.text += "\nSecure socket closed"
                         }
        active: false
    }
}

