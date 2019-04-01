import QtQuick 2.0

Item {
    property alias texteAEditer: texte.text
    id: tuile
    width: 77.5
    height: 77.5

    Rectangle {
        id: rectangle
        color: "#ffffaa"
        radius: 6
        border.color: "#bbaa66"
        border.width: 2
        anchors.fill: parent

        Text {
            id: texte
            font.weight: Font.Normal
            font.bold: true
            lineHeight: 0.7
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 22
            onTextChanged: {
                if (text === " ") {rectangle.color = "#ffffee" ; return;}
                if (text === "2") {rectangle.color = "#ffffaa" ; return;}
                if (text === "4") {rectangle.color = "#ffff66" ; return;}
                if (text === "8") {rectangle.color = "#ffff00" ; return;}
                if (text === "16") {rectangle.color = "#ffee00" ; return;}
                if (text === "32") {rectangle.color = "#ffcc00" ; return;}
                if (text === "64") {rectangle.color = "#ffaa00" ; return;}
                if (text === "128") {rectangle.color = "#ff8800" ; return;}
                if (text === "256") {rectangle.color = "#ff6600" ; return;}
                if (text === "512") {rectangle.color = "#ff4400" ; return;}
                if (text === "1024") {rectangle.color = "#ff2200" ; return;}
                if (text === "2048") {rectangle.color = "#ff0000" ; return;}
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onEntered: rectangle.border.width=4, texte.font.pixelSize = 30
        onExited: rectangle.border.width=2, texte.font.pixelSize = 22
    }
}
