import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 800
    height: 550
    title: qsTr("Каталог квартир риелтора")

    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: butAdd.top
        anchors.bottomMargin: 8
        border.color: "SteelBlue"


    ScrollView {
        anchors.fill: parent
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15

        ListView {
            id: apList
            anchors.fill: parent
            model: apartmentModel
            delegate: DelegateForApartment{}
            clip: true
            activeFocusOnTab: true
            focus: true
        }
    }
    }

    Button {
        id: butAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:butEdit.left
        text: "Добавить"
        width: 100
        onClicked: windowAdd.show()
    }

    Button {
        id: butEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: butDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100
        onClicked: {
            var areaAp = apList.currentItem.apartmentData.areaOfApartment
            var spaceAp = apList.currentItem.apartmentData.spaceOfApartment
            var roomsAp = apList.currentItem.apartmentData.roomsOfApartment
            var floorAp = apList.currentItem.apartmentData.floorOfApartment
            var materialAp = apList.currentItem.apartmentData.materialOfApartment

            windowEdit.execute(areaAp, spaceAp, roomsAp, floorAp, materialAp, apList.currentIndex)
        }
    }

    Button {
        id: butDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: apList.currentIndex >= 0
        onClicked: del(apList.currentIndex)
    }

        Label {
            id: labelSpace
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.left: parent.left
            //anchors.right: butAdd.left
            anchors.rightMargin: 8
            anchors.leftMargin: 8
            Layout.alignment: Qt.AlignRight
            text: qsTr("Введите нужную площадь квартиры:")
        }
        TextField {
            id: textSpace
            Layout.fillWidth: true
            placeholderText: qsTr("")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 8
            anchors.left: labelSpace.right
            anchors.rightMargin: 8
        }
        Button {
            id: butCount
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            //anchors.right:parent.right
            anchors.left: textSpace.right
            anchors.leftMargin: 8
            text: "Подсчитать"
            width: 100
            enabled: textSpace.text != ""
            onClicked: windowAnswer.countApartments(textSpace.text)
        }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit {
        id: windowEdit
    }
    DialogForAnswer {
        id: windowAnswer
    }
}

