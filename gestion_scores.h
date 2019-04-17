#ifndef GESTION_SCORES_H
#define GESTION_SCORES_H

using namespace std;
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class gestion_scores
{

// reecrire en utilisant find chainedecaractere.find("abs") trouve ou se trouve
    // abs dans la cdc et renvoie l'indice de début

    //lors de l'ajout verifier que le joueur n'est pas deja prsent dans le fichier
    //faire modification
public:
    gestion_scores(string nom_du_fichier);
    string get_nom_fichier();
    void set_nom_fichier(string new_name);
    string lecture_fichier();// type int
    void recherche_scores_joueurs();
    vector<int> get_vecteur_scores();
    vector<string> get_vecteur_noms();
    void ecriture_fichier(string nom_joueur, int score_joueur);
    int get_score_joueur(string nom_joueur);
    void modification_score(string nom_joueur, int new_score);
    void rewrite(string new_text);
private:
    string nom_du_fichier;
    vector<string> noms_joueurs;
    vector<int> scores_joueurs;
};

#endif // GESTION_SCORES_H
