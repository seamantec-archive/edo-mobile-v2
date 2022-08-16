import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import "scripts/Utils.js" as Utils

ApplicationWindow {
    property double scaleRatio: 1.0//screenWidth / 414
    id: applicationWindow1
    visible: true
    width: 320 * scaleRatio
    height: 568 * scaleRatio
    title: qsTr("EDO Racing")

    property bool menu_visible: false

    StackView{
        id:stackView
        anchors.fill: parent
        focus: true
        initialItem: startupScreen

        delegate: StackViewDelegate {

               function transitionFinished(properties)
               {
                   properties.exitItem.opacity = 1
               }

              pushTransition: StackViewTransition {
                   PropertyAnimation {
                       target: enterItem
                       property: "opacity"
                       from: 0
                       to: 1
                       duration: 100
                   }
                   PropertyAnimation {
                       target: exitItem
                       property: "opacity"
                       from: 1
                       to: 0
                       duration: 100
                   }
               }
           }
    }

    StartupScreen {
        id: startupScreen
        stackView:  stackView
        scaleRatio: scaleRatio
        onLoginClicked: {
            stackView.push(loginScreen)
        }
        onStartEdoClicked: {
            stackView.push(stageContainer)
        }
    }


    LoginScreen {
        id: loginScreen
        stackView: stackView
        visible: false
    }

    StageContainer{
        id:stageContainer
        visible: false
        stackView: stackView
    }



}

