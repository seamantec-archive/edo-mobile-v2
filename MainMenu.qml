import QtQuick 2.5
import QtQuick.Controls 1.4
Rectangle {
    property var stackView;
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
    }

    Header{
        id:header
        stackView: root.stackView
        labelText: "Menu"
    }

    Component {
        id: headerType
        Rectangle {
               width: list.width
               height: 60
               color:  "#00000000"
               border.color: "#00314d"
               border.width: 1
            Label {
                id: headerLabel
                color: "#ffffff"
                text: itemModel.label
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.bottom: parent.bottom
                font.pointSize: 14
            }
        }
    }

    Component {
        id: textInputType
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

            TextEdit{
                id: textEdit1
                 width: parent.width/2
                height: parent.height
                text: itemModel.bindingValue
                horizontalAlignment: Text.AlignRight
                verticalAlignment: TextEdit.AlignVCenter
                font.pixelSize: 20
                anchors.right: parent.right
                anchors.rightMargin: 10
                readOnly: false
                Binding {
                    target: itemModel.bindingTarget
                    property: itemModel.bindingProp
                    value: textEdit1.text
                }
            }

        }
    }


    Component {
        id: textLabelType
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
                id: textEdit1
                 width: parent.width/2
                height: parent.height
                text: itemModel.bindingValue
                horizontalAlignment: Text.AlignRight
                verticalAlignment: TextEdit.AlignVCenter
                font.pixelSize: 20
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

        }
    }

    Component {
        id: onOffType
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

            SwitchBtn {
                id: textEdit1
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 10
            }

        }
    }

    Component {
        id: selectType
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

            Image{
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



                ListView {
                    id: listView1
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    anchors.right: parent.right
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    anchors.top: header.bottom
                    delegate: Rectangle {
                        height: 60
                        width: listView1.width
                        color: "#b3c2ca"
                        border.color: "#00314d"
                        border.width: 1
                        Label {
                            color: "#000000"
                            text:  model.modelData.shortString
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            anchors.bottom: parent.bottom
                            font.pointSize: 14
                            height: parent.height
                            verticalAlignment: TextEdit.AlignVCenter
                        }

                        MouseArea{
                            anchors.fill: parent
                            onClicked:{
                              itemModel.clickFunction(model);
                                itemStackView.pop();
                            }
                        }

                    }
                    model: itemModel.listModel
                }


            }
        }
    }
    Component{
        id: connectionSettings
        ConnectionSettings{
        }
    }

    property list<QtObject> paramModel: [
        QtObject { property string type: "header"
                   property string label: "ACCOUNT"
                   },
        QtObject { property string type: "textInput"
                   property string label: "Email"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"

                },
        QtObject { property string type: "select"
                   property string label: "Upgrade"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },
        QtObject { property string type: "textLabel"
                   property string label: "Restore purchases"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },

        QtObject { property string type: "header"
                   property string label: "CONNETIONS"
                   },

        QtObject { property string type: "connection"
                   property string label: "Data source"
                },

        QtObject { property string type: "textLabel"
                   property string label: "Server Connection"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },

        QtObject { property string type: "header"
                   property string label: "ACTIVITES"
                   },

        QtObject { property string type: "onOff"
                   property string label: "Record NMEA data"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },


        QtObject { property string type: "onOff"
                   property string label: "Real time tracking"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },

        QtObject { property string type: "header"
                   property string label: "UNITS"
                   },

        QtObject { property string type: "select"
                   property string label: "Distance"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },
        QtObject { property string type: "select"
                   property string label: "Small Distance"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },
        QtObject { property string type: "select"
                   property string label: "Water Depth"
                   property var clickFunction: function(model){
                            unitHandler.changeDepthUnit(model.modelData.index);
                   }
                    property var listModel: unitHandler.depthUnitsList
                },
        QtObject { property string type: "select"
                   property string label: "Boat Speed"            
            property var clickFunction: function(model){
                     unitHandler.changeSpeedUnit(model.modelData.index);
            }
             property var listModel: unitHandler.speedUnitsList
                },

        QtObject { property string type: "select"
                   property string label: "Wind Speed"                  
                   property var clickFunction: function(model){
                            unitHandler.changeWindSpeedUnit(model.modelData.index);
                    }
                    property var listModel: unitHandler.windSpeedUnitsList
                },

        QtObject { property string type: "select"
                   property string label: "Temperature"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                },

        QtObject { property string type: "select"
                   property string label: "North Reference"
                   property var bindingValue:""// connectionHandler.tcpConnection.host
                   property var bindingTarget:"" //connectionHandler.tcpConnection
                    property string bindingProp: "host"
                }
    ]
    ListView{
        id: list
        clip: true
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: header.bottom
        model: paramModel

        delegate: Component{
            //property var type;

                Loader {
                    property var itemModel: model
                    property var itemStackView: root.stackView
                    property var connectionHandlerB: connectionHandler
                    sourceComponent: {
                        switch(type) {
                            case "header": return headerType
                            case "textInput": return textInputType
                            case "textLabel": return textLabelType
                            case "onOff": return onOffType
                            case "select": return selectType
                            case "connection": return connectionSettings
                        }
                    }
                }


        }
    }

}
