#include "jeu2048.h"
#include "damier.h"
#include <iostream>
using namespace std;
//#include <Windows.h>


/*
A FAIRE



Julien :

S'occuper de la gestion des parties, ajouter une case retour en arrière

Voir is_mouv qui fait tout planter
Gerer si il y a eu un mouv ou pas


Gerer le retour_en_arriere avec l'affichage de la page 2

Gerer


Plus tard :

Gerer les transitions
Ajout de profil joueur pour gestion du score


*/


jeu2048::jeu2048(QObject *parent) : QObject(parent), Damier<int>(4,4,2048,0)
{
    Init2048();
}

void jeu2048::Init2048(){
    Set(rand()%4,rand()%4,2);

    //mise à jour du score
    set_score(0);
    set_meilleur_score(20480);

    //ajout en memoire de la grille
    append_new_compo(get_T());

    //mise à jour de l'interface graphique
    tuileChanged();
    scoreChanged();
    meilleurScoreChanged();
}






int jeu2048::recup_sens(int S)//1 gauche 4 bas 2 droite 3 haut
{
    sens = S;
}

int jeu2048::get_sens()
{
    return sens;
}


int jeu2048::get_score()
{
    return score;
}


void jeu2048::set_score(int new_score)
{
    score = new_score;
}

int jeu2048::get_meilleur_score()
{
    return meilleur_score;
}

void jeu2048::set_meilleur_score(int new_score)
{
    meilleur_score = new_score;
}


string jeu2048::get_victoire_defaite()
{
    return txt_vict_def;
}


void jeu2048::set_victoire_defaite(string vd)
{
    txt_vict_def = vd;
}


int jeu2048::comput_score() // Calcule le score en fonction des données du damier
{
    int score = 0;
    for (int i = 0;i<get_L();i++)
        for (int j = 0;j < get_C();j++)
            score += number2score(Get(i,j));
    return score;
}



int jeu2048::number2score(int n)
{
    int score = 0;
    float i = 0.5;
    if (n==4)
        score = 4;
    else
    {
        while (n >= 4)
        {
            n /= 2;
            i*=2;
            score += floor(i)*n*2;
        }
    }
    return score;
}








void jeu2048::change(){

    //ajout en mémoire de la partie
    append_new_compo(get_T());

    if (Est_gagne() == 0 && Est_perdu() == 0)
    {
        //deplacement des cases
        Deplacer_all(get_sens());
        //ajout d'un 2 aléatoirement si possible
        Renouvellement();

        // mise à jour du score
        set_score(comput_score());
        if (get_meilleur_score() < get_score())
            set_meilleur_score(get_score());


        //mise à jour de l'interface graphique
        tuileChanged();
        scoreChanged();
        meilleurScoreChanged();
    }
    if (Est_gagne()==0 && Est_perdu() == 1)
        Defaite();
    if (Est_gagne()==1)
        Victoire();
}



void jeu2048::change_score()
{
    scoreChanged();
}


void jeu2048::change_meilleur_score()
{
    meilleurScoreChanged();
}




QString jeu2048::readTuileValue1(){
    if (Get(0,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,0));
}
QString jeu2048::readTuileValue2(){
    if (Get(0,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,1));
}
QString jeu2048::readTuileValue3(){
    if (Get(0,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,2));
}
QString jeu2048::readTuileValue4(){
    if (Get(0,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,3));
}
QString jeu2048::readTuileValue5(){
    if (Get(1,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,0));
}
QString jeu2048::readTuileValue6(){
    if (Get(1,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,1));
}
QString jeu2048::readTuileValue7(){
    if (Get(1,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,2));
}
QString jeu2048::readTuileValue8(){
    if (Get(1,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,3));
}
QString jeu2048::readTuileValue9(){
    if (Get(2,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,0));
}
QString jeu2048::readTuileValue10(){
    if (Get(2,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,1));
}
QString jeu2048::readTuileValue11(){
    if (Get(2,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,2));
}
QString jeu2048::readTuileValue12(){
    if (Get(2,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,3));
}
QString jeu2048::readTuileValue13(){
    if (Get(3,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,0));
}
QString jeu2048::readTuileValue14(){
    if (Get(3,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,1));
}
QString jeu2048::readTuileValue15(){
    if (Get(3,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,2));
}
QString jeu2048::readTuileValue16(){
    if (Get(3,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,3));
}




QString jeu2048::readScoreValue(){
    return QString::number(get_score());
}


QString jeu2048::readMeilleurScoreValue(){
    return QString::number(get_meilleur_score());
}



QString jeu2048::readVictDef(){
    string vd = get_victoire_defaite();
    return QString(vd.c_str());
}










int jeu2048::Is_mouv()
{
    int ** last_T = get_last_compo();
    for (int i = 0 ; i < get_L() ; i ++)
        for (int j = 0 ; j < get_C() ; j ++)
            if (last_T[i][j] != Get(i,j))
                return 1;
    return 0;

}






// fonction gerant la logique du jeu



 int jeu2048::Est_vide(int l_c,int num) // Teste si une ligne ou une colonne du damier est vide
 {
     if (l_c == 0)
     {
         for (int j = 0 ; j < get_C() ; j ++)
         {
             if (Get(num,j) != 0) return 0;
         }
     }
     if (l_c == 1)
     {
         for (int i = 0 ; i < get_L() ; i ++)
         {
             if (Get(i,num) != 0) return 0;
         }
     }
     return 1;
 }





 int jeu2048::Is_only_zero(vector<int> liste,int indice, int g_d)  // Teste si les éléments d'une liste à droite ou à gauche d'un élément donné sont nul ou non
 {
     if (g_d == 0)
         for (int i = indice ; i< sizeof(liste) ; i++)
             if (liste[i] != 0)
                 return 0;
     if (g_d == 1)
         for (int i = sizeof(liste)-1;i >= indice;i--)
             if (liste[i] != 0)
                 return 0;
     return 1;
 }


 vector<int> jeu2048::Decaler(int sens, int num_l_c)
 {
     vector<int> old_one(4);
     //Construction de la liste
     if (sens == 1 || sens == 2)
     {
         for(int j = 0;j<get_C();j++) old_one[j] = Get(num_l_c,j);
     }
     if (sens == 3 || sens == 4)
     {
         for(int i = 0;i<get_L();i++) old_one[i] = Get(i,num_l_c);
     }


     //Decalage et addition si possible
     if (sens == 1 || sens == 3)
     {
         int i = 0;
         int cmpt = 0;
         while(i<3 && cmpt < 10)
         {
             if (Is_only_zero(old_one,i,0)==1)
                 i = 3;
             else if(old_one[i] == 0)
             {
                 for(int j = i;j<3;j++)
                     old_one[j] = old_one[j+1];
                 old_one[3] = 0;
             }
             else{i+=1;}//i+=1;
             cmpt += 1;
         }
         for (int i = 0;i<3;i++)
         {
             if (old_one[i] != 0 && old_one[i] == old_one[i+1])
             {
                 old_one[i] += old_one[i+1];
                 for(int j = i+1;j<3;j++)
                     old_one[j] = old_one[j+1];
                 old_one[3] = 0;
             }
         }
     }
     if (sens == 2 || sens == 4)
     {
         int i = 3;
         int cmpt = 0;
         while (i>0 && cmpt < 10)
         {
             if (Is_only_zero(old_one,i,1)==1)
                 i = 0;
             else if(old_one[i] == 0)
             {
                 for(int j = i;j>0;j--)
                     old_one[j] = old_one[j-1];
                 old_one[0] = 0;
             }
             else{i-=1;}//i -= 1;
             cmpt += 1;
         }
         for (int i = 3;i>0;i--)
         {
             if (old_one[i] != 0 && old_one[i] == old_one[i-1])
             {
                 old_one[i] += old_one[i-1];
                 for(int j = i-1;j>0;j--)
                     old_one[j] = old_one[j-1];
                 old_one[0] = 0;
             }
         }
     }
     return old_one;
 }



// vector<int> jeu2048::Decaler(int sens, int num_l_c)
// {
//     vector<int> old_one(4);
//     //Construction de la liste
//     if (sens == 1 || sens == 2)
//     {
//         for(int j = 0;j<get_C();j++) old_one[j] = Get(num_l_c,j);
//     }
//     if (sens == 3 || sens == 4)
//     {
//         for(int i = 0;i<get_L();i++) old_one[i] = Get(i,num_l_c);
//     }


//     //Decalage et addition si possible
//     if (sens == 1 || sens == 3) // Décalage à gauche et en haut symétrique
//     {
//         int i = 0;
//         int cmpt = 0;
//         int non_nuls=0;
//         while(i<4 && cmpt ==0)
//         {
//             if (Is_only_zero(old_one,i,0)==1)
//                 cmpt = 1;
//             if(old_one[i] == 0)
//             {
//                 int c = i-non_nuls;
//                 for(int j = i;j<4;j++)
//                 {
//                     if (old_one[j] ==0) c+=1;
//                     else
//                     {
//                           old_one[j-c] = old_one[j];
//                           old_one[j]=0;
//                     }
//                  }
//             }
//             non_nuls+=1;
//             i+=1;//i+=1;
//         }
//         for (int i = 0;i<3;i++)
//         {
//             if (old_one[i] != 0 && old_one[i] == old_one[i+1])
//             {
//                 old_one[i] += old_one[i+1];
//                 for(int j = i+1;j<3;j++)
//                     old_one[j] = old_one[j+1];
//                 old_one[3] = 0;
//             }
//         }
//     }
//     if (sens == 2 || sens == 4)
//     {
//         int i = 3;
//         int cmpt = 0;
//         int non_nuls=0;
//         while(i>-1 && cmpt ==0)
//             {
//                 if (Is_only_zero(old_one,i,0)==1)
//                     cmpt = 1;
//                 if(old_one[i] == 0)
//                 {
//                     int c = i-non_nuls;
//                     for(int j = i;j>-1;j--)
//                     {
//                         if (old_one[j] ==0) c-=1;
//                         else
//                         {
//                               old_one[3-(j-c)] = old_one[j];
//                               old_one[j]=0;
//                         }
//                      }
//                 }
//                 non_nuls+=1;
//                 i-=1;
//             }


//         for (int i = 3;i>0;i--)
//         {
//             if (old_one[i] != 0 && old_one[i] == old_one[i-1])
//             {
//                 old_one[i] += old_one[i-1];
//                 for(int j = i-1;j>0;j--)
//                     old_one[j] = old_one[j-1];
//                 old_one[0] = 0;
//             }
//         }
//     }
//     return old_one;
// }


 void jeu2048::Deplacer_all(int sens)//deplacer_all(3et4) ne fonctionne pas et deplacer_all(1) s'arrete un cran avant colonne 3
 {
     if(sens == 1 || sens == 2)// gauche ou droite
     {
         for(int i = 0 ; i<get_L() ; i++)
         {
             if (Est_vide(0,i)==0)
             {
                 vector<int> new_ligne = Decaler(sens,i);
                 for (int j = 0;j<get_C();j++)
                 {
                     Set(i,j,new_ligne[j]);
                 }
             }
         }
     }
     if(sens == 3 || sens == 4)// haut ou bas
     {
         for(int j = 0 ; j<get_C() ; j++)
         {
             if (Est_vide(1,j)==0)
             {
                 vector<int> new_colonne = Decaler(sens,j);
                 for (int i = 0;i<get_L();i++)
                 {
                     Set(i,j,new_colonne[i]);
                 }
             }
         }
     }
 }



 int jeu2048::Estoccupee(int i, int j)
 {
     if (Get(i,j)!=0) return 1;
     else return 0;
 }



 void jeu2048::Renouvellement()
 {
    vector<int> liste_place_dispo;
    for(int i = 0 ; i<get_L() ; i++)
        for(int j = 0 ; j<get_C() ; j++)
            if (Get(i,j) == 0)
            {
                liste_place_dispo.push_back(i);
                liste_place_dispo.push_back(j);
            }
    if (!(liste_place_dispo.size() == 0))
    {
        int i = rand()%liste_place_dispo.size();
        if (i%2 == 0)
            Set(liste_place_dispo[i],liste_place_dispo[i+1],2);
        else
            Set(liste_place_dispo[i-1],liste_place_dispo[i],2);
    }
 }

 int jeu2048::Est_gagne()
 {
     for (int i = 0;i<get_L();i++)
         for (int j = 0;j < get_C();j++)
             if (Get(i,j) >= 2048)
                 return 1;
     return 0;
 }


 int jeu2048::Est_perdu()
 // a revoir car plus complexe que ca
 //besoin d'étudier si un mouvement peut-être fait ou non
 {
     int sortie = 1;//on considere que l'on a perdu sauf si..
     //verification a l'interieur
     //si case vide on a pas perdu
     for (int i = 0;i<get_L();i++)
         for (int j = 0;j < get_C();j++)
             if (Get(i,j) == 0)
                sortie = 0;
     //verification à l'interieur
     //si 2 cases a proximite ont meme valeur on a pas perdu
     for (int i = 1;i<get_L()-1;i++)
         for (int j = 1;j < get_C()-1;j++)
             if (Get(i,j)==Get(i+1,j) || Get(i,j)==Get(i-1,j) || Get(i,j)==Get(i,j-1) || Get(i,j)==Get(i,j+1))
                sortie = 0;
     //verification sur les bords-colonnes
     //si 2 cases ont meme valeur, pas perdu
     if (Get(1,0) == Get(2,0) || Get(1,3) == Get(2,3))
         sortie = 0;
     //verification sur les bords-lignes
     //si 2 cases ont meme valeur, pas perdu
     if (Get(0,1) == Get(0,2) || Get(3,1) == Get(3,2))
         sortie = 0;
     //verification sur les 4 bords
     //si 2 cases ont meme valeur, pas perdu
     if (Get(0,0)==Get(0,1) || Get(0,0)==Get(1,0) || Get(3,0) == Get(3,1) || Get(3,0) == Get(2,0) || Get(0,3) == Get(1,3) || Get(0,3) == Get(0,2) || Get(3,3)==Get(2,3) || Get(3,3) == Get(3,2))
         sortie = 0;
     return sortie;
 }



 void jeu2048::Victoire()
 {
     set_victoire_defaite("Bravo, c'est gagné !!!");
     victoire_defaiteChanged();
     //decaler vers la fenetre 2
 }

 void jeu2048::Defaite()
 {
     set_victoire_defaite("Dommage, tu as perdu !!!");
     victoire_defaiteChanged();
     //decaler vers la fenetre 2
 }



void jeu2048::retour_en_arriere()
{
    //if (Is_mouv()==1)
    //{
    int** last_compo = get_last_compo();
    for (int i = 0;i<get_L();i++)
    {
        for (int j = 0;j < get_C();j++)
        {
            Set(i,j,last_compo[i][j]);
            cout << last_compo[i][j] << "  ";
        }
        cout << endl;
    }
    maj();
    //}
}


void jeu2048::maj()
{//pourquoi ça ne fonctionne pas ? Je ne comprends pas, c'est pourtant transparent
    tuileChanged();
    scoreChanged();
}





