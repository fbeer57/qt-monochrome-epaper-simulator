import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3
import myextension 1.0

Window
{
    visible: true
    width: 640
    height: 480
    RowLayout {
        anchors.fill: parent
        GroupBox{
            Layout.minimumWidth: 402
            Layout.minimumHeight: 302
            Layout.fillWidth: true
            Layout.fillHeight: true
            title: "Display"
            Rectangle {
                anchors.fill: parent
                color: "steelblue"
                ImageItem {
                    anchors.fill: parent
                    id: display
                    width: 400
                    height: 300
                }
            }
        }
        GroupBox {
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            title: "Actions"
            ColumnLayout {
                Layout.fillWidth: true
                Button{
                    id: demo
                    text: "Demo"
                    onClicked: {
                        display.demo()
                    }
                }
                Button{
                    id: hLines
                    text: "hLines"
                    onClicked: {
                        display.hLines()
                    }
                }
                Button{
                    id: vLines
                    text: "vLines"
                    onClicked: {
                        display.vLines()
                    }
                }
                Button{
                    id: fonts
                    text: "Fonts"
                    onClicked: {
                        display.fonts()
                    }
                }
            }
        }
    }
}
