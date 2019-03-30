import QtQuick 2.9
import QtQuick.Window 2.2

Window {
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
                valeurTuile1.recup_sens(3);
                valeurTuile1.change();//le faire pour 1 active tuileChanged et le fait pour tous
                break;
            case Qt.Key_Down:
                valeurTuile1.recup_sens(4);
                valeurTuile1.change();
                break;
            case Qt.Key_Left:
                valeurTuile1.recup_sens(1);
                valeurTuile1.change();
                break;
            case Qt.Key_Right:
                 valeurTuile1.recup_sens(2);
                valeurTuile1.change();
                break;
            case Qt.Key_A:
                valeurTuile1.recup_sens(5);
                valeurTuile1.terminer();
            }
        Tuile{
            id: case1
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: valeurTuile1.valQML1
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile1.change();
                        //
//                }
//            }
        }

        Tuile{
            id: case2
            anchors.left: case1.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: valeurTuile2.valQML2
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile2.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case3
            anchors.left: case2.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: valeurTuile3.valQML3
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile3.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case4
            anchors.left: case3.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            texteAEditer: valeurTuile4.valQML4
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile4.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case5
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: case1.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile5.valQML5
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile5.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case6
            anchors.left: case5.right
            anchors.leftMargin: 10
            anchors.top: case2.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile6.valQML6
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile6.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case7
            anchors.left: case6.right
            anchors.leftMargin: 10
            anchors.top: case3.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile7.valQML7
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile7.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case8
            anchors.left: case7.right
            anchors.leftMargin: 10
            anchors.top: case4.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile8.valQML8
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile8.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case9
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: case5.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile9.valQML9
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile9.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case10
            anchors.left: case9.right
            anchors.leftMargin: 10
            anchors.top: case6.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile10.valQML10
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile10.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case11
            anchors.left: case10.right
            anchors.leftMargin: 10
            anchors.top: case7.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile11.valQML11
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile11.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case12
            anchors.left: case11.right
            anchors.leftMargin: 10
            anchors.top: case8.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile12.valQML12
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile12.change();
//                    break;
//                }
//            }
        }


        Tuile{
            id: case13
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: case9.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile13.valQML13
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile13.change();
//                    break;
//                }
//            }

        }

        Tuile{
            id: case14
            anchors.left: case13.right
            anchors.leftMargin: 10
            anchors.top: case10.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile14.valQML14
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile14.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case15
            anchors.left: case14.right
            anchors.leftMargin: 10
            anchors.top: case11.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile15.valQML15
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile15.change();
//                    break;
//                }
//            }
        }

        Tuile{
            id: case16
            anchors.left: case15.right
            anchors.leftMargin: 10
            anchors.top: case12.bottom
            anchors.topMargin: 10
            texteAEditer: valeurTuile16.valQML16
//            Keys.onPressed: {
//                switch (event.key) {
//                case Qt.Key_up:
//                    valeurTuile16.change();
//                    break;
//                }
//            }
        }









    }
        Rectangle {
        id: nom_jeu
        width: 100
        height: 30
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
        height: 30
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 160
        Text {
            id: text_current_score
            color: "#221111"
            text: valeurCurrentScore.sQML
            lineHeight: 1
            elide: Text.ElideMiddle
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            anchors.fill: parent
            font.pixelSize: 15
            verticalAlignment: Text.AlignVCenter
            renderType: Text.QtRendering
        }
    }




    Rectangle {
        id: best_score
        x: 35
        width: 120
        height: 30
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.rightMargin: 50
        anchors.right: parent.right
        Text {
            id: text_best_score
            color: "#221111"
            text: valeurMeilleurScore.bsQML
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1
            font.bold: true
            anchors.fill: parent
            elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 15
            renderType: Text.QtRendering
        }
    }
}
