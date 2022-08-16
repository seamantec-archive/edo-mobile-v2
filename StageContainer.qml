import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Rectangle {
    id: stage
    color: "#ffffff"
    width: parent.width
    height: parent.height
    property var stackView;

    Flickable {
        id: flickable1
        y: 0
        width: parent.width
        height: parent.height
        boundsBehavior: Flickable.DragAndOvershootBounds
        flickableDirection: Flickable.HorizontalFlick
        contentWidth:stage1.width + messageList.width
        contentHeight: this.height
        clip: true

        property int currentViewIndex: 0
        property int startX:0
        property int newX:0

        NumberAnimation{
            id: xAnimation
            target: flickable1
            properties: "contentX"
            easing {type: Easing.OutCurve; overshoot: 100}
        }

        onContentXChanged: {
          if(Math.abs(startX-contentX) > this.width){
              cancelFlick();
          }
        }

        onMovementEnded: {
            var tempIndex = Math.floor(contentX/this.width),
            modulus = contentX % this.width;
            newX = 0;
            if(startX >= contentX){
                if(modulus < this.width * 0.8){
                    newX = (tempIndex) * this.width;
                }else{
                    newX= (tempIndex+1)*this.width;
                }
            }else{
                if(modulus > this.width * 0.2){
                    newX = (tempIndex+1) * this.width;
                }else{
                    newX = tempIndex*this.width;
                }
            }
            if(newX <0){
                newX = 0;
            }else if(newX > contentWidth-this.width){
                newX = contentWidth-this.width;
            }
            //contentX = newX;
            xAnimation.from = contentX;
            xAnimation.to = newX;
            xAnimation.start();


        }
        onMovementStarted: {
            if(contentX != newX){
                xAnimation.stop();
                contentX = newX;
            }

            startX = contentX;
        }




        Stage1{
            id:stage1
            width: applicationWindow1.width
            height: flickable1.height
            stackView: stage.stackView
        }


         MessagesList{
             id: messageList
             width: applicationWindow1.width
            height: flickable1.height
            anchors.left: stage1.right

         }

       // Rectangle{
       //     id: stage2
       //     width: applicationWindow1.width
       //     height: flickable1.height
       //     color: "#ce2c86"
       //     anchors.left: stage1.right
       // }



    }


}
