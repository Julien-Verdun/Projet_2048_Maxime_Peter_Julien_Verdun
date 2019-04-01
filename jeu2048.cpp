#include "jeu2048.h"
#include "damier.h"
#include <iostream>
using namespace std;
#include <Windows.h>


/*
A FAIRE

Separer score et score change en 2 rectangles pour avoir du texte au dessus du score

Gerer la defaite et la vicoire
Faire une meilleur fonction est_perdu

Gerer la fermeture de la fenetre sur demande avec touche a

Verifier la logique de jeu

S'occuper de la gestion des parties, ajouter une case retour en arrière

Gérer les couleurs en fonction du score dans les tuiles en passant la couleur de la tuile comme un argument
et en modifiant cette valeur en fonction de la valeur de la case
2048 jaunee
64 rouge
16 rouge orange
2 blanc


Gerer les transitions

*/


jeu2048::jeu2048(QObject *parent) : QObject(parent), Damier<int>(4,4,2048,0)
{
    Init2048();
}

void jeu2048::Init2048(){
    Set(rand()%4,rand()%4,2);
    set_score(0);
    set_meilleur_score(0);
    tuileChanged();
    scoreChanged();
    meilleurScoreChanged();
    //chnger la valeur de la case
    // comment acceder au contenue texte de la case ?
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




int jeu2048::comput_score() // Calcule le score en fonction des données du damier
{
    int score = 0;
    for (int i = 0;i<get_L();i++)
        for (int j = 0;j < get_C();j++)
            if (Get(i,j) > 2)
                score += Get(i,j);
    return score;
}





































void jeu2048::change(){                          //Récupère le sens, applique la logique du jeu et actualise l'affichage de l'interface
    if (Est_gagne() == 0)// && Est_perdu() == 0)
    {
        Deplacer_all(get_sens());
        Renouvellement();
    }
//    else if (Est_gagne() == 0 && Est_perdu() == 1)
//    {
//        Defaite();
//    }
    else
    {
        Victoire();
    }
    set_score(comput_score());
    if (get_meilleur_score() < get_score())
        set_meilleur_score(get_score());
    tuileChanged();
    scoreChanged();
    meilleurScoreChanged();
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
         for (int i = indice;i<sizeof(liste);i++)
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
     if (sens == 1 || sens == 3) // Décalage à gauche et en haut symétrique
     {
         int i = 0;
         int cmpt = 0;
         int non_nuls=0;
         while(i<4 && cmpt ==0)
         {
             if (Is_only_zero(old_one,i,0)==1)
                 cmpt = 1;
             if(old_one[i] == 0)
             {
                 int c = i-non_nuls;
                 for(int j = i;j<4;j++)
                 {
                     if (old_one[j] ==0) c+=1;
                     else
                     {
                           old_one[j-c] = old_one[j];
                           old_one[j]=0;
                     }
                  }
             }
             non_nuls+=1;
             i+=1;//i+=1;
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
         int non_nuls=0;
         while(i>-1 && cmpt ==0)
             {
                 if (Is_only_zero(old_one,i,0)==1)
                     cmpt = 1;
                 if(old_one[i] == 0)
                 {
                     int c = i-non_nuls;
                     for(int j = i;j>-1;j--)
                     {
                         if (old_one[j] ==0) c-=1;
                         else
                         {
                               old_one[3-(j-c)] = old_one[j];
                               old_one[j]=0;
                         }
                      }
                 }
                 non_nuls+=1;
                 i-=1;
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
     int x = rand()%get_L();
     int y = rand()%get_C();
     while (Estoccupee(x,y)==1)
     {
         x = rand()%get_L();
         y = rand()%get_C();
     }
     Set(x,y,2);
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
     int sortie = 0;
     int test_zeros = 1;
     int test_adjacents = 0;
     for (int i = 0;i<get_L();i++)
         for (int j = 0;j < get_C();j++)
             if (Get(i,j) == 0)
                test_zeros = 0;



     for (int i = 1;i<get_L()-1;i++)
         for (int j = 1;j < get_C()-1;j++)
             if (test_adjacents =0){
                if (Get(i,j) == Get(i-1,j) ||Get(i,j) == Get(i+1,j) ||Get(i,j) == Get(i,j-1) || Get(i,j) == Get(i,j+1)) test_adjacents = 1;
             }
     for (int i = 0;i<get_L();i++)
         if (Get(i,0)==Get(i,1)) test_adjacents = 1;
     for (int i = 0;i<get_L();i++)
         if (Get(i,2)==Get(i,3)) test_adjacents = 1;

     for (int j = 0;j<get_C();j++)
         if (Get(0,j)==Get(1,j)) test_adjacents = 1;
     for (int j = 0;j<get_C();j++)
         if (Get(2,j)==Get(3,j)) test_adjacents = 1;

     if (test_zeros == 0 && test_adjacents == 1) sortie = 1;

     return sortie;
 }



 void jeu2048::Victoire()
 {
     cout << "Victoire !!" << endl;
     terminer();
 }

 void jeu2048::Defaite()
 {
     cout << "Defaite !!" << endl;
     terminer();
 }


void jeu2048::terminer()
{

}



void jeu2048::retour_en_arriere()
{
    int** last_compo = get_last_compo();
    for (int i = 0;i<get_L();i++)
        for (int j = 0;j < get_C();j++)
            Set(i,j,last_compo[i][j]);
}






