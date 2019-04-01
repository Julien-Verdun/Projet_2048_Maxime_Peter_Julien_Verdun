import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 400
    height: 600
    title: qsTr("Jeu du 2048")

    Rectangle {
        id: grille
        x: 122
        y: 179
        width: 360
        height: 360
        color: "#00555500"
        radius: 10
        border.width: 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenter: parent.horizontalCenter
        focus: true
        //1 gauche 2 droite 3 haut 4 bas
        Keys.onPressed:
            switch (event.key) {
            case Qt.Key_Up:
                jeu.recup_sens(3);
                jeu.change();//le faire pour 1 active tuileChanged et le fait pour tous
                break;
            case Qt.Key_Down:
                jeu.recup_sens(4);
                jeu.change();
                break;
            case Qt.Key_Left:
                jeu.recup_sens(1);
                jeu.change();
                break;
            case Qt.Key_Right:
                 jeu.recup_sens(2);
                jeu.change();
                break;
            case Qt.Key_A:
                jeu.recup_sens(5);
                jeu.terminer();
            }
        Tuile{
            id: case1
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: jeu.valQML1
        }

        Tuile{
            id: case2
            anchors.left: case1.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: jeu.valQML2
        }

        Tuile{
            id: case3
            anchors.left: case2.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: jeu.valQML3
        }

        Tuile{
            id: case4
            anchors.left: case3.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: jeu.valQML4
        }

        Tuile{
            id: case5
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: case1.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML5
        }

        Tuile{
            id: case6
            anchors.left: case5.right
            anchors.leftMargin: 10
            anchors.top: case2.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML6
        }

        Tuile{
            id: case7
            anchors.left: case6.right
            anchors.leftMargin: 10
            anchors.top: case3.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML7
        }

        Tuile{
            id: case8
            anchors.left: case7.right
            anchors.leftMargin: 10
            anchors.top: case4.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML8
        }

        Tuile{
            id: case9
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: case5.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML9
        }

        Tuile{
            id: case10
            anchors.left: case9.right
            anchors.leftMargin: 10
            anchors.top: case6.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML10
        }

        Tuile{
            id: case11
            anchors.left: case10.right
            anchors.leftMargin: 10
            anchors.top: case7.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML11
        }

        Tuile{
            id: case12
            anchors.left: case11.right
            anchors.leftMargin: 10
            anchors.top: case8.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML12
        }


        Tuile{
            id: case13
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: case9.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML13

        }

        Tuile{
            id: case14
            anchors.left: case13.right
            anchors.leftMargin: 10
            anchors.top: case10.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML14
        }

        Tuile{
            id: case15
            anchors.left: case14.right
            anchors.leftMargin: 10
            anchors.top: case11.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML15
        }

        Tuile{
            id: case16
            anchors.left: case15.right
            anchors.leftMargin: 10
            anchors.top: case12.bottom
            anchors.topMargin: 10
            texteAEditer: jeu.valQML16
        }









    }
        Rectangle {
        id: nom_jeu
        width: 100
        height: 60
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 30

        Text {
            id: text2048
            color: "#FFEE11"
            text: qsTr("2048")
            renderType: Text.QtRendering
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 25
        }
    }





    Rectangle {
        id: current_score
        x: 40
        width: 120
        height: 60
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 160
        Text {
            id: text_current_score1
            height: 30
            color: "#221111"
            text: qsTr("Score")
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            lineHeight: 1
            elide: Text.ElideMiddle
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.pixelSize: 15
            verticalAlignment: Text.AlignVCenter
            renderType: Text.QtRendering
        }
        Text {
            id: text_current_score
            height: 30
            color: "#221111"
            text: valeurCurrentScore.sQML
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            lineHeight: 1
            elide: Text.ElideMiddle
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.pixelSize: 15
            verticalAlignment: Text.AlignVCenter
            renderType: Text.QtRendering
        }
    }




    Rectangle {
        id: best_score
        x: 35
        width: 120
        height: 60
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.rightMargin: 50
        anchors.right: parent.right
        Text {
            id: text_best_score1
            height: 30
            color: "#221111"
            text: qsTr("Meilleur score")
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1
            font.bold: true
            elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 15
            renderType: Text.QtRendering
        }
        Text {
            id: text_best_score
            height: 30
            color: "#221111"
            text: valeurMeilleurScore.bsQML
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1
            font.bold: true
            elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 15
            renderType: Text.QtRendering
        }
    }

    Rectangle {
        id: retour_arriere
        width: 30
        height: 30
        color: "#ffffff"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 0

        Image {
            id: image_retour_arriere
            anchors.fill: parent
            source: "image_retour_arriere.PNG"
        }

        MouseArea {
            id: mouseArea_retour_arriere
            anchors.fill: parent
            hoverEnabled: true
            onClicked: jeu.retour_en_arriere()
        }
    }
}



/*##^## Designer {
    D{i:21;anchors_width:80}D{i:22;anchors_width:40}D{i:24;anchors_width:80}D{i:25;anchors_width:40}
D{i:27;anchors_height:100;anchors_width:100}
}
 ##^##*/
