import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import "scripts/Utils.js" as Utils
Rectangle {
    property real contentScaleFactor : screenDpi / 163
    property var stackView
    property double scaleRatio: 1.0
    id: root
    color: "#ffffff"
    anchors.fill: parent
    width: 320 * scaleRatio
    height: 568 * scaleRatio
    signal loginClicked
    signal startEdoClicked

    Image {
        id: bg
        sourceSize.height: 2208
        sourceSize.width: 1242
        anchors.fill: parent
        //fillMode: Image.PreserveAspectFit
        source: "qrc:/assets/images/bg.png"
    }

    Column {
        id: column1
        anchors.topMargin: 60 * scaleRatio
        antialiasing: true
        anchors.fill: parent
       //Todo swipe tooltips

        Image{
            id:logo
            sourceSize.height: 325
            sourceSize.width: 760
            fillMode: Image.PreserveAspectFit
            source: "qrc:/assets/images/edo logo.png"
            width: 253 * scaleRatio
            height: 108 * scaleRatio
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Rectangle{
            id: tooltipRect
            height: 130
            color: "#00000000"

            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
        }

        Rectangle {
            id: loginBtnBox
            height: 63 * scaleRatio
            color: "#00000000"

            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0

            Button {
                id: loginBtn
                x: 122 * scaleRatio
                width: 292 * scaleRatio
                height: 48 * scaleRatio
                text: "Log In"
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    root.loginClicked()
                }
                style: ButtonStyle {
                    background: Image {
                        sourceSize.height: 144
                        sourceSize.width: 878
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/assets/images/btn_blue.png"
                    }
                    label: Text {
                        renderType: Text.NativeRendering
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 20 * scaleRatio
                        color: "white"
                        text: control.text
                    }
                }

            }
        }



            Rectangle {
                id: signUpBtnBox
                height: 63 * scaleRatio
                color: "#00000000"

                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0

                Button {
                    id: signUpBt
                    x: 122 * scaleRatio
                    y: 0
                    width: 292 * scaleRatio
                    height: 48 * scaleRatio
                    text: "Sign Up"
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter

                    style: ButtonStyle {
                        background: Image {
                            sourceSize.height: 144
                            sourceSize.width: 878
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: "qrc:/assets/images/btn_green.png"
                        }
                        label: Text {
                            renderType: Text.NativeRendering
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 20 * scaleRatio
                            color: "black"
                            text: control.text
                        }
                    }

                }
            }

            Rectangle {
                id: orLabel
                height: 70 * scaleRatio
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                color: "#00000000"

                Label {
                    id: label1
                    x: 171 * scaleRatio
                    y: 40 * scaleRatio
                    color: "#ffffff"
                    text: qsTr("Or")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Rectangle {
                id: startEdoAsGuestBtnBox
                height: 60 * scaleRatio
                color: "#00000000"

                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0

                Button {
                    id: startEdoAsGuestBtn
                    x: 122 * scaleRatio
                    width: 292 * scaleRatio
                    height: 48 * scaleRatio
                    text: "Start EDO as guest"
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter

                    onClicked: {
                        root.startEdoClicked()
                    }
                    style: ButtonStyle {
                        background: Image {
                            sourceSize.height: 144
                            sourceSize.width: 878
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: "qrc:/assets/images/btn_blue.png"
                        }
                        label: Text {
                            renderType: Text.NativeRendering
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 20 * scaleRatio
                            color: "white"
                            text: control.text
                        }
                    }

                }
            }

    }

}


