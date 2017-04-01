import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import CopyFiles 1.0

ApplicationWindow {
    visible: true
    width: 640
    title: qsTr("Photo Synch")

    property bool isSourceSelection: true

    CopyFiles {
        id: files
    }

    ColumnLayout {
        width: parent.width
        GridLayout {
            columns: 3
            rows: 2
            width: parent.width
            Label {
                text: "Source:"
                width: destinationLb.contentWidth
            }
            TextField {
                id: sourceText
                Layout.fillWidth: true
                placeholderText: "folder containing the photos"
                text: files.sourceDirectory
            }
            Button {
                anchors.right: parent.right
                text: "Select"
                onClicked: {
                    isSourceSelection = true
                    fileSelection.open()
                }
            }
            Label {
                id: destinationLb
                text: "Destination:"
            }
            TextField {
                id: destinationText
                Layout.fillWidth: true
                placeholderText: "folder receiving the photos"
                text: files.destinationDirectory
            }
            Button {
                anchors.right: parent.right
                text: "Select"
                onClicked: {
                    isSourceSelection = false
                    fileSelection.open()
                }
            }
        }


        GridLayout {
            width: parent.width
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            columns: 2
            rows: 1
            Button {
                text: "Copy"
                onClicked: {files.synchronise()}
            }
            Button {
                anchors.right: parent.right
                text: "Cancel"
                onClicked: Qt.quit()
            }
        }
    }

    FileDialog {
        id: fileSelection
        title: "Select a folder"
        folder: shortcuts.home
        selectFolder: true
        onAccepted: {
            console.log("You choose: "+fileSelection.fileUrls)
            if (isSourceSelection){
                files.sourceDirectory = fileSelection.fileUrl.toString()

            } else {
                files.destinationDirectory = fileSelection.fileUrl.toString()
            }
        }

    }
}
