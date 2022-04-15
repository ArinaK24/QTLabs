import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0 // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление информации о квартире")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Район города:")
        }
        TextField {
            id: textArea
            Layout.fillWidth: true
            placeholderText: qsTr("Введите район")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Площать, м^2:")
        }
        TextField {
            id: textSpace
            Layout.fillWidth: true
            placeholderText: qsTr("Введите площадь")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Количество комнат:")
        }
        TextField {
            id: textRooms
            Layout.fillWidth: true
            placeholderText: qsTr("Введите количество комнат")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Этаж:")
        }
        TextField {
            id: textFloor
            Layout.fillWidth: true
            placeholderText: qsTr("Введите этаж")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Материал стен:")
        }
        TextField {
            id: textMaterial
            Layout.fillWidth: true
            placeholderText: qsTr("Введите материал стен")
        }
    }

    Button {
        visible: {textArea.length>0 && textSpace.length>0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()
            add(textArea.text, textSpace.text, textRooms.text, textFloor.text, textMaterial.text)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible) {
          textArea.text = ""
          textSpace.text = ""
          textRooms.text = ""
          textFloor.text = ""
          textMaterial.text = ""
      }
    }
 }
