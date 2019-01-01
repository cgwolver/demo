import QtQuick 2.2
import QtQuick.Controls 2.2
import qt.capbar.event 1.0
Item {
    objectName: "rootObject"
    width: 640
    height: 50
    visible: true
    Rectangle {
        objectName: "rectObject"
        id: rectangle
        height: 50
        color: "#ffffff"
        anchors.fill: parent

        Rectangle {
            id: close_bk
            x: 590
            width: 50
            height: 50
            color: "#00000000"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 2
            visible: true
            border.color: "#00000000"


            Image {
                id: image_close
                x: 18
                y: 18
                width: 16
                height: 16
                source: "res/close.png"

                MouseArea {
                    id: mouseArea_close
                    x: -10
                    y: -18
                    width: 36
                    height: 50
                    hoverEnabled: true
                    onEntered:
                    {
                        close_bk.color = "#ff0909"
                    }
                    onExited:
                    {
                        close_bk.color = "#00000000"
                    }
                    onClicked:
                    {
                        capEvent.onClose()
                    }
                }
            }
        }
        Image {
            id: logo
            x: 0
            y: 0
            width: 235
            height: 60
            visible: false
            source: "res/logo.png"
        }

        Rectangle {
            id: max_bk
            x: 549
            width: 50
            height: 50
            color: "#00000000"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: close_bk.left
            anchors.rightMargin: 0
            Image {
                id: image_maxi
                x: 18
                y: 18
                width: 16
                height: 16
                MouseArea {
                    id: mouseArea_maxi
                    x: -10
                    y: -18
                    width: 36
                    height: 50
                    hoverEnabled: true
                    onEntered:
                    {
                        max_bk.color = "#ff0909"
                    }
                    onExited:
                    {
                        max_bk.color = "#00000000"
                    }
                    onClicked:
                    {
                        capEvent.onMaxi()
                    }
                }
                source: "res/maxi.png"
            }
            border.color: "#00000000"
            visible: true
        }

        Rectangle {
            id: mini_bk
            x: 508
            width: 50
            color: "#00000000"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: max_bk.left
            anchors.rightMargin: 0
            Image {
                id: image_mini
                x: 18
                y: 18
                width: 16
                height: 16
                MouseArea {
                    id: mouseArea_mini
                    x: -10
                    y: -18
                    width: 36
                    height: 50
                    hoverEnabled: true
                    onEntered:
                    {
                        mini_bk.color = "#ff0909"
                    }
                    onExited:
                    {
                        mini_bk.color = "#00000000"
                    }
                    onClicked:
                    {
                        capEvent.onMini()
                    }
                }

                source: "res/mini.png"
            }
            border.color: "#00000000"
            visible: true
        }
    }


    CapbarEvent {
        id:capEvent
        objectName: "capEventObject"

    }


}









































/*##^## Designer {
    D{i:2;anchors_height:60;anchors_width:36;anchors_x:590;anchors_y:0}D{i:9;anchors_height:60;anchors_y:0}
}
 ##^##*/
