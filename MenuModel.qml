import QtQuick 2.5

ListModel {
    ListElement {
        type: "header"
        label: "Account"
    }

    ListElement {
        type: "textInput"
        label: "Email"
        bindingValue: "connectionHandler.tcpConnection.host"
    }
    ListElement {
        type: "content"
        label: "Upgrade"
    }
    ListElement {
        type: "content"
        label: "Restore purchase"
    }

    ListElement {
        type: "content"
        name: "John Brown"
        number: "555 8426"
    }
    ListElement {
        type: "content"
        name: "Sam Wise"
        number: "555 0473"
    }
}
