import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import "scripts/Utils.js" as Utils
Rectangle {
    property var scaleFactor:1
    property var originalWidth:1242
    FontLoader { id: digitalFont; source: "qrc:/assets/fonts/digital_edo_pr.ttf" }
    id: root
    height: originalWidth
    width: originalWidth
    clip: false
    color: "#00000000"
    onWidthChanged: {
        scaleFactor = width/originalWidth;
        console.log("SCALE FACTOR", scaleFactor)
    }
    Image{
        id: bg
        sourceSize: {width: 1242; height: 1252}
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "qrc:/assets/instruments/new_compass/compass_bg.png"

        Image{
            id: rotate
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            sourceSize: {width: 1219; height: 1219}
            fillMode: Image.PreserveAspectFit
            source:  "qrc:/assets/instruments/new_compass/compass_rotate.png"
            scale: scaleFactor
            rotation:360-dataModel.navigation.boat.headingTrue.value//-180
            Behavior on rotation{
                RotationAnimation {
                   easing:{type: Easing.InCurve}
                   direction: RotationAnimation.Shortest
                }
            }

        }

        Image{
            id: digi_bg
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            scale: scaleFactor
            sourceSize: {width: 817; height: 817}
            fillMode: Image.PreserveAspectFit
            source:  "qrc:/assets/instruments/new_compass/digi_bg.png"

            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter:  parent.verticalCenter

                width: parent.width
                Rectangle {
                    id: speed_rect
                    width: parent.width
                   height: digi_bg.height*0.4
                    color: "#00000000"

                    Column{
                                anchors.fill: parent
                                spacing: 5/scaleFactor
                                Label {
                                    id: speedLabel
                                    color: "#fddc9e"
                                    text: qsTr("SPEED")
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignHCenter
                                    font.pointSize: 20/scaleFactor
                                }

                                Row{
                                    id: speedFields
                                    height: 60
                                    antialiasing: true
                                    enabled: false
                                    spacing: 10/scaleFactor
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Column {
                                        width: 50
                                        height: 60
                                        spacing: 10/scaleFactor                                       
                                        Text {
                                            id: speedMax
                                            text: Utils.pad(dataModel.navigation.boat.speedOverGround.minMax.max, 3)
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 15/scaleFactor}
                                            anchors.right: parent.right
                                        }
                                        Text {
                                            id: speedMin
                                            text: Utils.pad(dataModel.navigation.boat.speedOverGround.minMax.min, 3)
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 15/scaleFactor}
                                            anchors.right: parent.right
                                        }
                                    }

                                    Row {
                                        id: row1
                                        Text{
                                            id: speedText
                                            //dataModel.environment.apparentWind.speed.whole
                                            text: Utils.pad(dataModel.navigation.boat.speedOverGround.whole, 3)
                                            verticalAlignment: Text.AlignBottom
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 40/scaleFactor}
                                        }
                                        Label {
                                            id: label2
                                            text: "."
                                            font {family: digitalFont.name; pointSize: 34/scaleFactor}
                                            color: "#ffffff"
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0
                                        }
                                        Text{
                                            id:windSpeedDecimal
                                            text: Utils.pad(dataModel.navigation.boat.speedOverGround.decimal,1)
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0//dataModel.environment.apparentWind.speed.decimal
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 34/scaleFactor}
                                        }


                                        Text{
                                            id:windSpeedUnit
                                            text:dataModel.navigation.boat.speedOverGround.shortUnit
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0//dataModel.environment.apparentWind.speed.decimal
                                            color: "#ffffff"
                                            font { pointSize: 14/scaleFactor}
                                        }


                                    }
                                }

                        }

                }

                Rectangle {
                    id: heading_rect
                    width: parent.width
                  height: digi_bg.height*0.4
                    color: "#00000000"

                    Column{
                                anchors.fill: parent
                                spacing: 5/scaleFactor
                                Label {
                                    id: headingLabel
                                    color: "#fddc9e"
                                    text: qsTr("HEADING")
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignHCenter
                                    font.pointSize: 20/scaleFactor
                                }

                                Row{
                                    id: headingFields
                                    height: 60
                                    antialiasing: true
                                    enabled: false
                                    spacing: 10/scaleFactor
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    Column {
                                        width: 50
                                        height: 60
                                        spacing: 10/scaleFactor
                                        Text {
                                            id: headingMax
                                            text: Utils.pad(dataModel.navigation.boat.headingTrue.minMax.max, 3)
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 15/scaleFactor}
                                            anchors.right: parent.right
                                        }
                                        Text {
                                            id: headingMin
                                            text: Utils.pad(dataModel.navigation.boat.headingTrue.minMax.min, 3)
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 15/scaleFactor}
                                            anchors.right: parent.right
                                        }
                                    }

                                    Row {
                                        id: headingBig
                                        Text{
                                            id: headingText
                                            //dataModel.environment.apparentWind.speed.whole
                                            text: Utils.pad(dataModel.navigation.boat.headingTrue.whole, 3)
                                            verticalAlignment: Text.AlignBottom
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 40/scaleFactor}
                                        }
                                        Label {
                                            id: headingDot
                                            text: "."
                                            font {family: digitalFont.name; pointSize: 34/scaleFactor}
                                            color: "#ffffff"
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0
                                        }
                                        Text{
                                            id:headingDecimal
                                            text: Utils.pad(dataModel.navigation.boat.headingTrue.decimal,1)
                                            anchors.bottom: parent.bottom
                                            anchors.bottomMargin: 0//dataModel.environment.apparentWind.speed.decimal
                                            color: "#ffffff"
                                            font {family: digitalFont.name; pointSize: 34/scaleFactor}
                                        }


                                        Text{
                                            id:headingUnit
                                            text:dataModel.navigation.boat.headingTrue.shortUnit
                                            anchors.top: parent.top
                                            anchors.bottomMargin: 0//dataModel.environment.apparentWind.speed.decimal
                                            color: "#ffffff"
                                            font { pointSize: 14/scaleFactor}
                                        }


                                    }
                                }

                        }

                }
            }




        }
    }
}

