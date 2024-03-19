import QtQuick 2.15
import QtQuick.Window 2.15

import User.QmlPlugin 1.0


Window {
    QmlCxxComponent {
        id:a
        onNameChanged: {
            console.log(name)
        }
    }

    QmlCxxComponent2 {
        id: b
        onNameChanged: {
            console.log(name)
        }
    }

    ButtonWithIcon {
        anchors.centerIn: parent
        onClicked: {
            a.name += "a"
            b.name +=  "b"
        }
    }

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}
