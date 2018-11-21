import QtQuick 2.2
import QtQuick.Controls 2.2
import qt.capbar.event 1.0
Item {
    objectName: "rootObject"
    width: 640
    height: 36
    Rectangle {
        objectName: "rectObject"
        id: rectangle
        color: "#4d4d4d"
        anchors.fill: parent

        Rectangle {
            id: close_bk
            x: 590
            y: 0
            width: 36
            height: 36
            color: "#00000000"
            anchors.right: parent.right
            anchors.rightMargin: 14
            visible: true
            border.color: "#00000000"

            Image {
                id: image_close
                x: 10
                y: 10
                width: 16
                height: 16
                source: "res/close.png"

                MouseArea {
                    id: mouseArea_close
                    x: -10
                    y: -9
                    width: 36
                    height: 36
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
            x: 1
            y: 2
            width: 235
            height: 36
            source: "res/logo.png"
        }

        Rectangle {
            id: max_bk
            x: 549
            y: 0
            width: 36
            height: 36
            color: "#00000000"
            anchors.right: parent.right
            anchors.rightMargin: 55
            Image {
                id: image_maxi
                x: 10
                y: 10
                width: 16
                height: 16
                MouseArea {
                    id: mouseArea_maxi
                    x: -10
                    y: -10
                    width: 36
                    height: 36
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
            y: 0
            width: 36
            height: 36
            color: "#00000000"
            anchors.right: parent.right
            anchors.rightMargin: 96
            Image {
                id: image_mini
                x: 10
                y: 9
                width: 16
                height: 16
                MouseArea {
                    id: mouseArea_mini
                    x: -10
                    y: -9
                    width: 36
                    height: 36
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
