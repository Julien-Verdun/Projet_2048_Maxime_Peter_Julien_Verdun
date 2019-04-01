#ifndef JEU2048_H
#define JEU2048_H

#include <QObject>
using namespace std;
#include "damier.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iostream>

class jeu2048 : public QObject, public Damier<int>
{
    Q_OBJECT
    Q_PROPERTY(QString valQML1 READ readTuileValue1() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML2 READ readTuileValue2() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML3 READ readTuileValue3() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML4 READ readTuileValue4() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML5 READ readTuileValue5() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML6 READ readTuileValue6() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML7 READ readTuileValue7() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML8 READ readTuileValue8() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML9 READ readTuileValue9() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML10 READ readTuileValue10() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML11 READ readTuileValue11() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML12 READ readTuileValue12() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML13 READ readTuileValue13() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML14 READ readTuileValue14() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML15 READ readTuileValue15() NOTIFY tuileChanged)
    Q_PROPERTY(QString valQML16 READ readTuileValue16() NOTIFY tuileChanged)

    Q_PROPERTY(QString sQML READ readScoreValue() NOTIFY scoreChanged)
    Q_PROPERTY(QString bsQML READ readMeilleurScoreValue() NOTIFY meilleurScoreChanged)

    //Q_PROPERTY(int pos1 READ read_new_position() NOTIFY positionChanged )

public:
    explicit jeu2048(QObject *parent = nullptr);
//    Q_INVOKABLE void move_up();
//    Q_INVOKABLE void move_down();
//    Q_INVOKABLE void move_left();
//    Q_INVOKABLE void move_right();

    Q_INVOKABLE int recup_sens(int sens);
    QString readTuileValue1();
    QString readTuileValue2();
    QString readTuileValue3();
    QString readTuileValue4();
    QString readTuileValue5();
    QString readTuileValue6();
    QString readTuileValue7();
    QString readTuileValue8();
    QString readTuileValue9();
    QString readTuileValue10();
    QString readTuileValue11();
    QString readTuileValue12();
    QString readTuileValue13();
    QString readTuileValue14();
    QString readTuileValue15();
    QString readTuileValue16();
    QString readScoreValue();
    QString readMeilleurScoreValue();

    Q_INVOKABLE void change();
    Q_INVOKABLE void change_score();
    Q_INVOKABLE void change_meilleur_score();

    Q_INVOKABLE void terminer();

    void Deplacer_all(int sens);
    void Renouvellement();
    int Estoccupee(int i, int j);
    // void Save_places(); // matrice contenant l'ensemble des positions des parties précédentes
    // void Retour_en_arriere(); // permet le retour en arrière de 1 à N fois
    void Defaite();//lorsque toutes les cases sont pleines et que plus aucun mouvement n'est possible
    // void Is_mouv(); detecte si il y a eu un mouvement d'un coup à l'autre, sinon pas de renouvellement
    int Is_only_zero(vector<int> liste, int indice, int g_d);// g_d == 0 si sens normal et 1 si de droite à gauche
    int Est_vide(int l_c,int num);//0 pour ligne 1 pour colonne; 1 si est_vide 0 sinon
    int Est_gagne();//1 si gagne 0 sinon
    int Est_perdu();//1si perdu 0 sinon
    void Victoire();// lorsqu'une case vaut 2048.
    vector<int> Decaler(int sens,int num_l_c);
    //fonction qui change les valeurs de chaque case en les valeurs de la matrice damier


    int get_sens();

    int get_score();
    void set_score(int new_score);

    int get_meilleur_score();
    void set_meilleur_score(int new_score);

    int comput_score();

    void retour_en_arriere();


protected :
    void Init2048();
private:
    int sens;
    int score;
    int meilleur_score;
signals:
    void tuileChanged();
    void scoreChanged();
    void meilleurScoreChanged();
public slots:
};

#endif // JEU2048_H
