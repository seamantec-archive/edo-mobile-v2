import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Rectangle{
    id: rectangle1
    property string labelText: "Label"
    property string imgSrc: "qrc:/qtquickplugin/images/template_image.png"

    color: "#002c45"
    width: 200
    height: 300

    Label{
        id: label
        height: 40
        color: "#ffffff"
        text: labelText
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        styleColor: "#ffffff"
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }

    Image {
        id: image1
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: label.top
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        fillMode: Image.PreserveAspectFit
        source: imgSrc
    }
    states: [
        State {
            name: "disabled"

            PropertyChanges {
                target: image1
                opacity: 0.5
            }
        }
    ]
}

