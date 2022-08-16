import QtQuick 2.5
import QtQuick.Controls 1.4

Rectangle{
    property var stackView;
    height: 30
    width: row1.width
    color: "#00000000"
    id: root
    signal clicked;
    Row{
        id: row1
        spacing: 6
        height: parent.height
        Image{
            width: 14
            source: "qrc:/assets/images/icons/arrow back.png"
            fillMode: Image.PreserveAspectFit
            height: 23
            anchors.verticalCenter: parent.verticalCenter

        }
        Label {
            color: "#ffffff"
            text: "Back"
            horizontalAlignment: Text.AlignLeft
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            font.pointSize: 15
            verticalAlignment: Text.AlignVCenter
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            stackView.pop()
        }
    }
}
