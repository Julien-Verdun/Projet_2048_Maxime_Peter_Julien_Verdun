#include "gestion_scores.h"
using namespace std;

gestion_scores::gestion_scores()
{
    set_nom_fichier("gestion_des_scores.txt");
}


string gestion_scores::get_nom_fichier()
//Retourne le nom du fichier qui contient les infos joueur et score.
{
    return nom_du_fichier;
}

void gestion_scores::set_nom_fichier(string new_name)
//Modifie la variable contenant le nom du fichier qui contient les infos joueur et score.
{
    nom_du_fichier = new_name;
}


void gestion_scores::ecriture_fichier(string nom_joueur, int score_joueur)
//Permet d'ajouter au fichier une ligne contenant le nom et le score d'un joueur.
{
    string texte_a_ajouter = nom_joueur + " " + to_string(score_joueur) + " ";
    fstream file;
    file.open(get_nom_fichier(),ios::out);
    if(!file)
    {
        cout<<"Error in creating file !!"<<endl;
    }
    else
    {
        cout<<"File created successfully"<<endl;
        file<<texte_a_ajouter;
    }
    file.close();
}

string gestion_scores::lecture_fichier()
//Cette fonction lit le fichier contenant le nom et le score des joueurs et
//retourne son contenu sous forme d'une chaine de caractères.
{
    string texte_lu;
    fstream file;
    file.open(get_nom_fichier(),ios::in);
    if(!file)
    {
        cout<<"Error in opening file !!"<<endl;
    }
    else
    {
        char ch;
        cout<<"File content: ";

        while(!file.eof())
        {
            file>>ch;
            cout<<ch;
            texte_lu += ch;
        }
    }
    file.close();
    return texte_lu;
}

int gestion_scores::get_score_joueur(string nom_joueur)
//Cette fonction lit le document contenant la liste des joueurs et leur score
//à la recherche du joueur renseigné en argument et renvoie son score lorsqu'elle l'a
//trouvé ou -1 si il n'est pas dans la liste.
{
    string texte_lu = lecture_fichier();
    for (int i = 0;i <= texte_lu.size();i++)
    {
        if (texte_lu[i] == nom_joueur[0])
        {
            int is_joueur = 1;
            for (int j = 1; j <= nom_joueur.size(); j++)
            {
                if (!(texte_lu[i+j] == nom_joueur[j]))
                    is_joueur = 0;
            }
            if (is_joueur == 1)
            {
                string string_score = "";
                int cpt = i+nom_joueur.size()+1;
                while (&texte_lu[cpt] != " ")
                {
                    string_score += texte_lu[cpt];
                    cpt++;
                }
                return *string_score.c_str();
            }
        }
    }
    return -1;
}

void gestion_scores::modification_score(string nom_joueur, int new_score)
//Cette fonction lit le document contenant la liste des joueurs et leur score
//à la recherche du joueur renseigné en argument et modifie son score avec
//le nouveau score renseigné en argument
{
    // BESOIn d'une fonction qui supprime le contenu du fichier et ensuite remplace par autre chose
    string texte_lu = lecture_fichier();
    string new_texte;
    for (int i = 0;i <= texte_lu.size();i++)
    {
        if (texte_lu[i] == nom_joueur[0])
        {
            int is_joueur = 1;
            for (int j = 1; j <= nom_joueur.size(); j++)
            {
                if (!(texte_lu[i+j] == nom_joueur[j]))
                    is_joueur = 0;
            }
            if (is_joueur == 1)
            {
                int cpt = i+nom_joueur.size()+1;
                while (&texte_lu[cpt] != " ")
                {
                    cpt++;
                }
                new_texte = texte_lu.substr(0,i+nom_joueur.size()) + to_string(new_score) + texte_lu.substr(cpt+1,texte_lu.size());
                rewrite(new_texte);
            }
        }
    }
}


void gestion_scores::rewrite(string new_text)
{

}
