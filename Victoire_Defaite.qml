import QtQuick 2.0

Item {
    property alias texteAEditer: txt_vict_def.text
    width: 400
    height: 600
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Text {
            id: txt_vict_def
            width: 150
            height: 40
            text: texte_victoire_defaire.valVD_QML
            font.family: "Tahoma"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
        }
    }

}
