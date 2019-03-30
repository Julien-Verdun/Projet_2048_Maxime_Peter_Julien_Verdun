import QtQuick 2.0

Item {
    property alias texteAEditer: texte.text
    id: tuile
    width: 77.5
    height: 77.5

    Rectangle {
        id: rectangle
        color: "#bbaa11"
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
            //text:valeurTuile.vleQML

//            focus true
//            text: valeurTuile.vleQML
//            Keys.onPressed: {
//                switch (event.key){
//                case Qt.Key_Up:
//                    valeurTuile.move_up();
//                    break;
//                case Qt.Key_Down:
//                    valeurTuile.move_down();
//                    break;
//                case Qt.Key_Left:
//                    valeurTuile.move_left()
//                    break;
//                case Qt.Key_Right:
//                    valeurTuile.move_right();
//                    break;
//                }
//            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        //acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MiddleButton
        onEntered: rectangle.color = "#aaaaaa", texte.font.pixelSize = 30
        onExited: rectangle.color = "#bbaa11", texte.font.pixelSize = 22
    }
}
