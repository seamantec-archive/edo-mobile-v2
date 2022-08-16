import QtQuick 2.5
import QtQuick.Controls 1.4

Rectangle {
    property var stackView;
    property string labelText;
    id: root
    color: "#00000000"
    anchors.top: parent.top
    anchors.topMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.right: parent.right
    anchors.rightMargin: 0
    height: 60

    Label {
        id: loginLabel
        color: "#ffffff"
        text: labelText;
        font.bold: false
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignTop
    }

    BackBtn {
        id: button2
        y: 0
        height: 26
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        stackView: root.stackView
    }
}

