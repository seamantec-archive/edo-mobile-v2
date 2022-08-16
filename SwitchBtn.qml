import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    id:root
    property bool isOn: false
    signal statusChanged;
   width: 57
   height: 37
   MouseArea{
       anchors.fill: parent
       onReleased: {
           isOn = !isOn;
           statusChanged();
       }
   }

   Image{
       id: offImg
       width: 57
       height: 37
       source: "qrc:/assets/images/switch_off.png"
       fillMode: Image.PreserveAspectFit
       visible: !isOn
   }

   Image{
       id: onImg
       width: 57
       height: 37
       source: "qrc:/assets/images/switch_on.png"
       fillMode: Image.PreserveAspectFit
       visible: isOn
   }
}

