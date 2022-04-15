import QtQuick 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Rectangle {
    id: apItem
    readonly property color evenBackgroundColor: "#E0FFFF"  // цвет для четных пунктов списка
    readonly property color oddBackgroundColor: "#B0C4DE"   // цвет для нечетных пунктов списка
    readonly property color selectedBackgroundColor: "#00FFFF"  // цвет выделенного элемента списка

    property bool isCurrent: apItem.ListView.view.currentIndex === index
    property bool selected: apItemMouseArea.containsMouse || isCurrent
    property variant apartmentData: model

    width: parent ? parent.width : apartmentList.width
    height: 160

    states: [
        State {
            when: selected           
            PropertyChanges { target: apItem;
                color: isCurrent ? palette.highlight : selectedBackgroundColor
            }
        },
        State {
            when: !selected
            PropertyChanges { target: apItem;  color: isCurrent ? palette.highlight : index % 2 == 0 ? evenBackgroundColor : oddBackgroundColor }
        }
    ]

    MouseArea {
        id: apItemMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            apItem.ListView.view.currentIndex = index
            apItem.forceActiveFocus()
        }
    }
    Item {
        id: itemOfApartments
        width: parent.width
        height: 160
        Column{
            id: t2
            anchors.left: parent.left
            anchors.leftMargin: 10
            width: 240
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: t1
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Район города:"
                color: "DarkBlue"
                font.pointSize: 12
            }
            Text {
                id: textName
                anchors.horizontalCenter: parent.horizontalCenter
                text: areaOfApartment
                color: "DarkBlue"
                font.pointSize: 18
                font.bold: true
            }
        }
        Column{
            anchors.left: t2.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            Text {
                text: "Площадь, м^2:"
                color: "DarkBlue"
                font.pointSize: 10
            }
            Text {
                id: textLenght
                text: spaceOfApartment
                color: "DarkBlue"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Количество комнат:"
                color: "DarkBlue"
                font.pointSize: 10
            }
            Text {
                id: textFlow
                color: "DarkBlue"
                text: roomsOfApartment
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Этаж:"
                color: "DarkBlue"
                font.pointSize: 10
            }
            Text {
                id: textRunoff
                text: floorOfApartment
                color: "DarkBlue"
                font.pointSize: 12
                font.bold: true
            }
            Text {
                text: "Материал стен:"
                color: "DarkBlue"
                font.pointSize: 10
            }
            Text {
                id: textArea
                color: "DarkBlue"
                text: materialOfApartment
                font.pointSize: 12
                font.bold: true
            }
        }

    }
}
