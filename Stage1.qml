import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

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
    Column{
        width: parent.width
        //height: parent.height - 150
        //anchors.fill: root
        spacing: 20
        id: column
        Rectangle {
            id:topButtons
            width: parent.width
            height: 100
            color: "#1a465f"
            Row{
                width: parent.width
                height: parent.height
                spacing: 2
                TopBtn{
                    labelText: "Pos"
                    imgSrc: "qrc:/assets/images/icons/soicon_pos.png"
                    width: parent.width/5.1
                    height: parent.height
                    state: dataModel.navigation.boat.speedOverGround.isValid ? "" : "disabled"
                }
                TopBtn{
                    labelText: "Hdg"
                    imgSrc: "qrc:/assets/images/icons/soicon_heading.png"
                    width: parent.width/5.1
                    height: parent.height
                    state: dataModel.navigation.boat.heading.isValid ? "" : "disabled"

                }
                TopBtn{
                    labelText: "Wind"
                    imgSrc: "qrc:/assets/images/icons/soicon_wind.png"
                    width: parent.width/5.1
                    height: parent.height
                    state: dataModel.environment.trueWind.speed.isValid ? "" : "disabled"
                }
                TopBtn{
                    labelText: "STW"
                    imgSrc: "qrc:/assets/images/icons/soicon_stw.png"
                    width: parent.width/5.1
                    height: parent.height
                    state: "disabled"
                }

                TopBtn{
                    labelText: "Depth"
                    imgSrc: "qrc:/assets/images/icons/soicon_depth.png"
                    width: parent.width/5.1
                    height: parent.height
                    state: "disabled"
                }
            }
        }



        Compass{
            id: compass
            width: parent.width
            height: parent.width
            Image{
                id: settingsIcon
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                source: "qrc:/assets/images/icons/icon_settings.png"
                fillMode: Image.PreserveAspectFit
                width: 35
                height: 39
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        root.stackView.push(mainMenu)
                    }
                }
            }
        }


    }
    BottomGraph{
        anchors.top: column.bottom
        anchors.topMargin: 10
        anchors.bottom: root.bottom
        width: root.width
        baseModel: dataModel.navigation.boat.headingTrue
    }

    MainMenu {
        id: mainMenu
        visible:false
        stackView: root.stackView


    }

}

