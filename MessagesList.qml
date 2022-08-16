import QtQuick 2.0

ListView {
    id: lView   
    spacing: 3

    contentWidth: 0
    orientation: ListView.Vertical
    flickableDirection: Flickable.VerticalFlick
    model: dataModel.listModel.model

    delegate: Item{
        id: delegateItem
        property var propertyList: model.modelData.propertyList
        width: lView.width
        height: headerItem.height + (listDetail.visible ? propertyList.length * 20 : 0)
        Rectangle{
            id: headerItem
            x: 0
            y: 0
            width: parent.width
            height: 20
            color: "#00ff00"
            Text {
                text: model.modelData.displayName
            }

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onClicked: {
                    listDetail.visible = !listDetail.visible;
                }
            }
        }

        Rectangle{
            id: listDetail
            visible: false
            anchors.top: headerItem.bottom
            Column {
                Repeater {
                    id: repeaterItem
                    model: propertyList
                    Rectangle{
                        height: 20
                        width: lView.width
                        color: "#ff0000"
                        Text {
                            x: 0
                            y: 0
                            text: model.modelData.displayName + " " + model.modelData.fullValueString + " " + model.modelData.shortUnit
                        }
                    }
                }
            }
        }

    }
}
