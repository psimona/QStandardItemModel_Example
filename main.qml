import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    TableView {

        anchors.fill: parent

        TableViewColumn {title: "1"; role: "one"; width: 150 }
        TableViewColumn {title: "2"; role: "two"; width: 150   }
        TableViewColumn {title: "3"; role: "three"; width: 150 }

        model: myModel

    }
}
