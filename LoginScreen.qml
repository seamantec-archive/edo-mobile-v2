import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import "scripts/Utils.js" as Utils
Rectangle {
    property real contentScaleFactor : screenDpi / 163
    property var stackView;
    color: "#ffffff"
    anchors.fill: parent
    width: 414
    height: 736
    id: root
    Image {
        id: bg
        sourceSize.height: 2208
        sourceSize.width: 1242
        anchors.fill: parent
        //fillMode: Image.PreserveAspectFit
        source: "qrc:/assets/images/bg.png"
        Header{
         stackView: root.stackView
         labelText: "Log In"
        }

        Column {
            id: column1
            anchors.topMargin: 60
            antialiasing: true
            anchors.fill: parent
            Rectangle {
                id: facebookLoginBox
                height: 100
                color: "#00000000"
                antialiasing: true

                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0

                Button {
                    id: button1
                    x: 122
                    y: 0
                    width: 292
                    height: 48
                    text: "Log In with Facebook"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    style: ButtonStyle {
                        background: Image {
                            sourceSize.height: 144
                            sourceSize.width: 878
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            source: "qrc:/assets/images/btn_facebook.png"
                        }
                        label: Text {
                            renderType: Text.NativeRendering
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.pointSize: 20
                            color: "white"
                            text: control.text
                        }
                    }

                }
            }

            Rectangle {
                id: orLabel
                height: 40
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                color: "#00000000"

                Label {
                    id: label1
                    x: 171
                    y: 40
                    color: "#ffffff"
                    text: qsTr("Or")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Column {
                id: regularLogin
                height: 400
                spacing: 2
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0


                TextField {
                    id: emailText
                    height: 40
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    placeholderText: qsTr("Email")
                    style: TextFieldStyle {
                            background: Rectangle {
                                implicitWidth: 100
                                implicitHeight: 24
                                color:"#f2f2f2"
                                opacity: 0.5
                            }
                     }
                }

                TextField {
                    id: passwordText
                    height: 40
                    echoMode: 2
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    placeholderText: qsTr("Password")
                    style: TextFieldStyle {
                            background: Rectangle {
                                implicitWidth: 100
                                implicitHeight: 24
                                color:"#f2f2f2"
                                opacity: 0.5
                            }
                        }
                }


                Rectangle {
                    id: loginBtnBox
                    height: 120
                    color: "#00000000"

                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 0

                    Button {
                        id: loginBtn
                        x: 122
                        y: 0
                        width: 292
                        height: 48
                        text: "Log In"
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
                                font.pointSize: 20
                                color: "black"
                                text: control.text
                            }
                        }

                    }
                }
            }

        }


    }

}

