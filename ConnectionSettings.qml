import QtQuick 2.5
import QtQuick.Controls 1.4

import com.seamantec.handlers.ConnectionHandler 1.0

Rectangle {
    height: 60
    width: list.width
    color: "#b3c2ca"
    border.color: "#00314d"
    border.width: 1
    Label {
        color: "#000000"
        text: itemModel.label
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        font.pointSize: 14
        height: parent.height
        verticalAlignment: TextEdit.AlignVCenter
    }

    Label{
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: moreImg.left
        anchors.rightMargin: 10
        text: connectionHandler.connectionStatus
        color: connectionHandler.isConnected ? "#009100" : "#ff0000"
    }

    Image{
        id: moreImg
        width: 14
        source: "qrc:/assets/images/arrow more.png"
        fillMode: Image.PreserveAspectFit
        height: 23
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 10
    }



    MouseArea{
        anchors.fill: parent
        onClicked: {
            itemStackView.push(innerList);
        }
    }

    Rectangle {
        id: innerList
        visible:false
        Image {
            id: bg
            sourceSize.height: 2208
            sourceSize.width: 1242
            anchors.fill: parent
            //fillMode: Image.PreserveAspectFit
            source: "qrc:/assets/images/bg.png"
        }
        Header{
            id:header
            stackView: root.stackView
            labelText: itemModel.label
        }

        Column {
            id: column1
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.top: header.bottom


            Rectangle {
                height: 60
                width: list.width
                color: "#b3c2ca"
                border.color: "#00314d"
                border.width: 1
                Row {
                    id: connectionSelector
                    anchors.fill: parent
                    ExclusiveGroup {
                        id: connectionTypeGroup
                            onCurrentChanged: {
                               if(current == udpRadio){
                                   connectionHandler.selectConnection(ConnectionHandler.UDP)
                               }else if(current == tcpRadio){
                                   connectionHandler.selectConnection(ConnectionHandler.TCP)
                               }else if(current == simulationRadio){
                                   connectionHandler.selectConnection(ConnectionHandler.SIMULATION)
                               }
                            }
                    }
                    RadioButton {
                        id: tcpRadio
                        text: qsTr("TCP socket")
                        exclusiveGroup: connectionTypeGroup
                        checked: connectionHandler.isTCPConnection
                    }

                    RadioButton {
                        id: udpRadio
                        text: qsTr("UDP socket")
                        exclusiveGroup: connectionTypeGroup
                        checked: connectionHandler.isUDPConnection
                    }

                    RadioButton {
                        id: simulationRadio
                        text: qsTr("Simulation")
                        exclusiveGroup: connectionTypeGroup
                        checked: connectionHandler.isSimulation
                    }


                }
           }


            Column {
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                id: tcpConnection
                visible:connectionHandler.isTCPConnection
                Rectangle {
                    height: 60
                    width: list.width
                    color: "#b3c2ca"
                    border.color: "#00314d"
                    border.width: 1
                    Label {
                        color: "#000000"
                        text: "Host"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.bottom: parent.bottom
                        font.pointSize: 14
                        height: parent.height
                        verticalAlignment: TextEdit.AlignVCenter
                    }

                    TextEdit{
                        id: hostInput
                         width: parent.width/2
                        height: parent.height
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: TextEdit.AlignVCenter
                        font.pixelSize: 20
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        text: connectionHandler.tcpConnection.host
                        readOnly: false

                        Binding {
                                target: connectionHandler.tcpConnection
                                property: "host"
                                value: hostInput.text
                            }
                    }

                }
                Rectangle {
                    height: 60
                    width: list.width
                    color: "#b3c2ca"
                    border.color: "#00314d"
                    border.width: 1
                    Label {
                        color: "#000000"
                        text: "Port"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.bottom: parent.bottom
                        font.pointSize: 14
                        height: parent.height
                        verticalAlignment: TextEdit.AlignVCenter
                    }

                    TextEdit{
                        id: portEdit
                         width: parent.width/2
                        height: parent.height
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: TextEdit.AlignVCenter
                        font.pixelSize: 20
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        text: connectionHandler.tcpConnection.port
                        readOnly: false

                        Binding {
                                target: connectionHandler.tcpConnection
                                property: "port"
                                value: portEdit.text
                            }
                    }

                }

            }



            Column {
                id: udpConnectionSettings
                visible:connectionHandler.isUDPConnection
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                Rectangle {
                    height: 60
                    width: list.width
                    color: "#b3c2ca"
                    border.color: "#00314d"
                    border.width: 1
                    Label {
                        color: "#000000"
                        text: "Port"
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.bottom: parent.bottom
                        font.pointSize: 14
                        height: parent.height
                        verticalAlignment: TextEdit.AlignVCenter
                    }

                    TextEdit{
                        id: portUdpEdit
                         width: parent.width/2
                        height: parent.height
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: TextEdit.AlignVCenter
                        font.pixelSize: 20
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        text: connectionHandler.udpConnection.port
                        readOnly: false

                        Binding {
                                target: connectionHandler.udpConnection
                                property: "port"
                                value: portUdpEdit.text
                            }
                    }

                }

            }



        Rectangle {
            height: 60
            width: list.width
            color: "#b3c2ca"
            border.color: "#00314d"
            border.width: 1
            Row {
                id: rowLayout1
                height: 25
                spacing: 10
                anchors.right: parent.right
                anchors.left: parent.left

                Button {
                    id: connectionButton
                    text: "Connect"
                    anchors.verticalCenter: parent.verticalCenter
                    onClicked: {
                        connectionHandler.connectDisconnect();
                    }
                    Component.onCompleted: {
                       connectionHandler.connectionStatusChanged.connect(connectionChanged)
                    }
                    function connectionChanged(){
                        if(connectionHandler.isConnected){
                            connectionButton.text = "Disconnect"
                        }else{
                            connectionButton.text = "Connect"
                        }
                    }
                }

                Label {
                    id: label1
                    text: connectionHandler.connectionStatus
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

        }
 }


    }
}


