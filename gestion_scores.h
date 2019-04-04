#ifndef GESTION_SCORES_H
#define GESTION_SCORES_H

using namespace std;
#include <cmath>
#include <iostream>
#include <fstream>

class gestion_scores
{

// reecrire en utilisant find chainedecaractere.find("abs") trouve ou se trouve
    // abs dans la cdc et renvoie l'indice de début
public:
    gestion_scores();
    string get_nom_fichier();
    void set_nom_fichier(string new_name);
    string lecture_fichier();
    void ecriture_fichier(string nom_joueur, int score_joueur);
    int get_score_joueur(string nom_joueur);
    void modification_score(string nom_joueur, int new_score);
    void rewrite(string new_text);
private:
    string nom_du_fichier;
};

#endif // GESTION_SCORES_H
