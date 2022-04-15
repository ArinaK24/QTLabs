import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal
    title: qsTr("Результат подсчёта")
    width: 220
    height: 50

    property int currentIndex: -1

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Количество квартир:")
        }
        TextField {
            id: textCount
            Layout.fillWidth: true
        }

    }

    function countApartments(space){
        textCount.text = count(space);
        root.show()
    }
 }
