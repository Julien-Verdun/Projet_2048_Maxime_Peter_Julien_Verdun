#include "jeu2048.h"
#include "damier.h"
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;


jeu2048::jeu2048(QObject *parent) : QObject(parent), Damier<int>(4,4,2048,0)
/*
Constructeur de la classe jeu2048, hérite des classes QObject,
Damier<int> et gestion_scores.
*/
{
    Init2048();
}




void jeu2048::Init2048()
/*
Initialise le jeu en modifiant aléatoirement une des cases du damier en un 2,
initialise et met à jour le score, le meilleur score et le nom du joueur.
*/
{
    Set(rand()%4,rand()%4,2);


    //mise à jour du score
    set_score(0);
    init_meilleur_score();
    set_meilleur_score(meilleur_score);

    rules = 1;
    set_is_rules();


    //mise à jour de l'interface graphique
    tuileChanged();
    scoreChanged();
    meilleurScoreChanged();
}





int jeu2048::recup_sens(int S)
/*
Modifie la variable sens donnant le sens dans lequel le joueur veut se
déplacer (1 gauche 4 bas 2 droite 3 haut).
*/
{
    sens = S;
}



int jeu2048::get_sens()
/*
Renvoie la variable sens.
*/
{
    return sens;
}


int jeu2048::get_score()
/*
Renvoie la variable score (indique le score actuelle du joueur).
*/
{
    return score;
}


void jeu2048::set_score(int new_score)
/*
Modifie la variable score et la remplace par le nouveau score new_score passé en argument.
*/
{
    score = new_score;
}

int jeu2048::get_meilleur_score()
/*
Renvoie la variable meilleur_score (indique le meilleur score du joueur).
*/
{
    return meilleur_score;
}

void jeu2048::set_meilleur_score(int new_score)
/*
Modifie la variable meilleur_score et la remplace par le nouveau score new_score passé en argument,
met également à jour le fichier texte contenant le meilleur score.
*/
{
    meilleur_score = new_score;
    ofstream file(adresse_meilleur_score,ios::out | ios::trunc);
    if(file.is_open())
    {
        file<<new_score;
        file.close();
    }
    else
    {
        cout<<"Erreur dans l'ouverture du fichier " << adresse_meilleur_score << ", pensez à bien changer le chemin d'accès."<<endl;
    }
}


string jeu2048::get_victoire_defaite()
/*
Renvoie la variable txt_vict_def.
*/
{
    return txt_vict_def;
}


void jeu2048::set_victoire_defaite(string vd)
/*
Modifie la variable txt_vict_def et la remplace par vd passée en argument.
*/
{
    txt_vict_def = vd;
}


int jeu2048::comput_score()
/*
Renvoie le score calculé en fonction des données/cases du damier.
*/
{
    int score = 0;
    for (int i = 0;i<get_L();i++)
        for (int j = 0;j < get_C();j++)
            score += number2score(Get(i,j));
    return score;
}





QString jeu2048::readTuileValue1()
/*
Modifie la case de coordonnées (0,0) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(0,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,0));
}
QString jeu2048::readTuileValue2()
/*
Modifie la case de coordonnées (0,1) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(0,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,1));
}
QString jeu2048::readTuileValue3()
/*
Modifie la case de coordonnées (0,2) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(0,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,2));
}
QString jeu2048::readTuileValue4()
/*
Modifie la case de coordonnées (0,3) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(0,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(0,3));
}
QString jeu2048::readTuileValue5()
/*
Modifie la case de coordonnées (1,0) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(1,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,0));
}
QString jeu2048::readTuileValue6()
/*
Modifie la case de coordonnées (1,1) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(1,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,1));
}
QString jeu2048::readTuileValue7()
/*
Modifie la case de coordonnées (1,2) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(1,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,2));
}
QString jeu2048::readTuileValue8()
/*
Modifie la case de coordonnées (1,3) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(1,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(1,3));
}
QString jeu2048::readTuileValue9()
/*
Modifie la case de coordonnées (2,0) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(2,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,0));
}
QString jeu2048::readTuileValue10()
/*
Modifie la case de coordonnées (2,1) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(2,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,1));
}
QString jeu2048::readTuileValue11()
/*
Modifie la case de coordonnées (2,2) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(2,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,2));
}
QString jeu2048::readTuileValue12()
/*
Modifie la case de coordonnées (2,3) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(2,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(2,3));
}
QString jeu2048::readTuileValue13()
/*
Modifie la case de coordonnées (3,0) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(3,0) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,0));
}
QString jeu2048::readTuileValue14()
/*
Modifie la case de coordonnées (3,1) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(3,1) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,1));
}
QString jeu2048::readTuileValue15()
/*
Modifie la case de coordonnées (3,2) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(3,2) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,2));
}
QString jeu2048::readTuileValue16()
/*
Modifie la case de coordonnées (3,3) de l'interface graphique et la remplace
par la valeur contenue dans le damier.
*/
{
    if (Get(3,3) == 0)
    {
        return QString(" ");
    }
    return QString::number(Get(3,3));
}



QString jeu2048::readScoreValue()
/*
Modifie le score actuel de l'interface graphique et la remplace
par la valeur de la variable score.
*/
{
    return QString::number(get_score());
}


QString jeu2048::readMeilleurScoreValue()
/*
Modifie le meilleur score actuel de l'interface graphique et la remplace
par la valeur de la variable meilleur score.
*/
{
    return QString::number(get_meilleur_score());
}



QString jeu2048::readVictDef()
/*
*/
{
    string vd = get_victoire_defaite();
    return QString(vd.c_str());
}



QString jeu2048::readrulesColor()
{
    string color = "";
    if (is_rules() == 1) color = "#FFFFFFFF";
    else color = "#00FFFFFF";
    return QString(color.c_str());
}


QString jeu2048::readtextRules()
{
    string texte = "";
    if (is_rules() == 1)
    {
        texte = "Les règles du jeu 2048 sont les suivantes : \n ";
        texte += "- le but du jeu fusionner des cases afin \n d'atteindre le score de 2048 \n";
        texte += "- seul 2 cases de même valeur peuvent \nêtre fusionnées \n";
        texte += "- les déplacements se font avec les 4 flèches \n du clavier (haut bas droite et gauche) \n";
        texte += "- une touche retour en arrière est disponible en \n dessous de la grille afin de rattraper ses mauvais coups \n";
        texte += "Bon courage !!";
    }
    else
    texte = "";
    return QString(texte.c_str());
}



void jeu2048::change()
/*
Réalise tout les modifications nécessaires dès l'appui du joueur sur une des
4 touches, modification des valeurs du damier et apparition aléatoire d'un 2,
mise à jour sur l'écran des scores et annonce d'une victoire ou d'une défaite
si tel est le cas.
*/
{
    if (Est_gagne() == 0 && Est_perdu() == 0 && Is_mouv() == 1)
    {
        //ajout en mémoire de la partie actuelle (qui deviendra la precedente juste apres l'ajout
        int** A;
        A = new int*[4];
        for(int i=0; i<4; i++)
            A[i] = new int[4];
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                A[i][j] = Get(i,j);

        append_new_compo(A);

        //deplacement des cases
        Deplacer_all(get_sens());


        //Vérification que le dernier mouvement a bougé quelque chose et qu'il n'a pas juste ajouté une cellule
        //Permet de ne pas freezer le jeu quand la grille est pleine.
        int** B;
        B = new int*[4];
        for(int i=0; i<4; i++)
            B[i] = new int[4];
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                B[i][j] = Get(i,j);

        append_new_compo(B);

        if (Is_mouv() == 1)
        {
            delete_last_compo();
            delete_last_compo();
        }
        else delete_last_compo();



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
    if (Est_gagne()==0 && Est_perdu() == 1) Defaite();
    if (Est_gagne()==1) Victoire();
}



void jeu2048::change_score()
/*
Active la fonction signal scoreChanged pour mettre à jour le score.
*/
{
    scoreChanged();
}


void jeu2048::change_meilleur_score()
/*
Active la fonction signal meilleurScoreChanged pour mettre à jour le meilleur score.
*/
{
    meilleurScoreChanged();
}






int jeu2048::number2score(int n)
/*
Renvoie le score correspondant à une case possédant la valeur n.
Rappel : score calculé tel que : dès que 2 cases fusionnent pour
n'en donné qu'une portant la valeur double, le score est incrémenté
de la somme des 2 cases initiales. Ainsi le score total se calcul par
le score cumulé sur chaque case (ce que fait cette fonction).
*/
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





void jeu2048::Deplacer_all(int sens)
/*
Suivant le sens de déplacement donné en argument, cette fonction
modifie le damier afin d'obtenir le damier résultant de la
modification.
Pour cela, on déplace d'abord toutes les cases non vides dans la direction
de déplacement, puis, une fois qu'aucun 0 ne s'interpose entre les cases
non nulles, on réalise les fusions si cela est possible.
*/
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




void jeu2048::Renouvellement()
/*
Ajout d'un 2 dans le damier sur une place restante de manière aléatoire.
*/
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


int jeu2048::Estoccupee(int i, int j)
/*
Renvoie 1 si la case du damier de coordonnées (i,j) est occupée (non nulle)
et 0 dans le cas contraire
*/
{
    if (Get(i,j)!=0) return 1;
    else return 0;
}





int jeu2048::Is_mouv()
/*
Compare le damier actuel et le dernier en mémoire et renvoie 1
si il y a eu un changement (un mouvement) entre les deux et 0
sinon.
*/
{
    int ** last_T = get_last_compo();

    for (int i = 0 ; i < get_L() ; i ++)
        for (int j = 0 ; j < get_C() ; j ++)
            if (last_T[i][j] != Get(i,j))
                return 1;
    return 0;

}



int jeu2048::Is_only_zero(vector<int> liste,unsigned int indice, int g_d)
/*
Lit les valeurs du vecteur liste  et renvoie 1 si il n'est composé
que de 0 et 0 si il possède au moins un élèment différent de 0.
La lecture est fait de manière différente (0 de gauche à droite)
et 1 (de droite à gauche) afin d'optimiser l'algorithme (plus de chance
de trouver une case non nulle, et donc d'arrêter le parcours de la liste
précocemment, en début de liste, si on a "pousser" toutes les cases à gauche
et de même en fin de liste si on a "pousser" les cases à droite.
*/
{
    if (g_d == 0)
        for (unsigned int i = indice ; i< sizeof(liste) ; i++)
            if (liste[i] != 0)
                return 0;
    if (g_d == 1)
        for (unsigned int i = sizeof(liste)-1;i >= indice;i--)
            if (liste[i] != 0)
                return 0;
    return 1;
}






int jeu2048::Est_vide(int l_c,int num)
/*
Teste si la ligne ou la colonne (déterminé par la variable l_c) numéro num
du damier est vide (toutes les cases sont nulles).
*/
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






vector<int> jeu2048::Decaler(int sens, int num_l_c)
/*
Prend en argument le sens de déplacement, le numéro de la ligne ou
de la colonne (défini par le sens de déplacement) et renvoie la nouvelle
ligne ou colonne après le déplacement.
*/
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
             else{i+=1;}
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
             else{i-=1;}
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




void jeu2048::retour_en_arriere()
/*
Lit le damier précédent dans le vecteur des damiers et modifie l'ensemble
des cases pour revenir à l'étape précédente.
*/
 {
     if (Is_mouv()==1 && get_pos_vec() >= 1)
     {
     int** last_compo = get_last_compo();

     for (int i = 0;i<get_L();i++)
         for (int j = 0;j < get_C();j++)
             Set(i,j,last_compo[i][j]);
     delete_last_compo();
     // mise à jour du score
     set_score(comput_score());
     if (get_meilleur_score() < get_score())
         set_meilleur_score(get_score());
     //mise à jour de l'interface graphique
     tuileChanged();
     scoreChanged();

     //si c'etait une victoire ou une défaite on remet la chaîne de
     //caractère à "" pour ne plus afficher le message de fin.
     if(get_victoire_defaite().size() > 0)
     {
        set_victoire_defaite("");
        victoire_defaiteChanged();
     }
     }
 }





int jeu2048::Est_gagne()
/*
Renvoie 1 si la partie est gagnée (i-e si une des cases vaut 2048)
et 0 sinon.
*/
 {
     for (int i = 0;i<get_L();i++)
         for (int j = 0;j < get_C();j++)
             if (Get(i,j) >= 2048)
                 return 1;
     return 0;
 }


int jeu2048::Est_perdu()
/*
Renvoie 1 si on a perdu (i-e que plus aucun mouvement n'est possible dans
le damier, plus aucunes fusions possibles et plus aucunes cases libres) ou 0 sinon.
*/
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
/*
Cette fonction gère les cas de victoire.
*/
 {
     set_victoire_defaite("Bravo, c'est gagné !!!");
     victoire_defaiteChanged();
     //decaler vers la fenetre 2
 }

void jeu2048::Defaite()
/*
Cette fonction gère les cas de défaite.
*/
 {
     set_victoire_defaite("Dommage, tu as perdu !!!");
     victoire_defaiteChanged();
     //decaler vers la fenetre 2
 }

int jeu2048::is_rules()
{
    return rules;
}

void jeu2048::set_is_rules()
{
    if (rules == 0)
    {
        rules = 1;
    }
    else rules = 0;
    rulesChanged();
}

void jeu2048::init_meilleur_score()
/*
Lit le fichier texte contenant le meilleur score et initialise la variable meilleur_score
*/
{
    string texte_lu = "";
    ifstream file(adresse_meilleur_score,ios::in);
    if(file.is_open())
    {
        string line;
        while (getline(file,line))
        {
            texte_lu += line;
        }
        file.close();
        meilleur_score = stoi(texte_lu);
    }
    else
    {
        cout<<"Erreur dans l'ouverture du fichier " << adresse_meilleur_score << ", pensez à bien changer le chemin d'accès."<<endl;
        meilleur_score = 0;
    }
}
