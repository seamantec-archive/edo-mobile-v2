import QtQuick 2.5
import QtQuick.Controls 1.4
Rectangle {
    id:root
    color:"#80000000"
    property var baseModel
    Label{
        text: root.baseModel.minMax.max
        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: row.top
        color: "#ffffff"
    }

    Row{
        id: row
        anchors.topMargin: 18
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        layoutDirection: Qt.RightToLeft
        anchors.fill: root
        spacing: 3
        clip: true
       Repeater{
          id: repeaterItem
          model: root.baseModel.history
          property int columnWidth: (row.width-15*row.spacing)/root.baseModel.max_history
          Rectangle{
              anchors.bottom: row.bottom
              width: repeaterItem.columnWidth
              height: {
                  var canvasHeight = row.height;
                  var columnHeight = canvasHeight*(model.modelData.value/root.baseModel.minMax.max);
                  return model.modelData.isValid ? columnHeight : 0;
              }
              color: "#68bfef"
              /*Text{
                  text: model.modelData.value
                  rotation: 90
                  color: "#ffffff"
              }*/
          }
       }

    }
}

