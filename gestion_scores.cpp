#include <gestion_scores.h>
using namespace std;

gestion_scores::gestion_scores(string nom_du_fichier)
/*
Constructeur de la classe gestion_scores (un paramètre, le nom du fichier texte à
utiliser).
*/
{
    set_nom_fichier(nom_du_fichier);
    //recherche_scores_joueurs();
}


string gestion_scores::get_nom_fichier()
/*
Retourne le nom du fichier qui contient les infos joueur et score.
*/
{
    return nom_du_fichier;
}

void gestion_scores::set_nom_fichier(string new_name)
/*
Modifie la variable contenant le nom du fichier qui contient les infos joueur
et score et le remplace par la chaîne de caractère new_name.
*/
{
    nom_du_fichier = new_name;
}

string gestion_scores::lecture_fichier()
/*
Cette fonction lit le fichier contenant le nom et le score des joueurs et
retourne son contenu sous forme d'une chaine de caractères.
La chaîne de caractères est de la forme "nom joueur" "score".
*/
{
    string texte_lu = "";
    ifstream file(get_nom_fichier(),ios::in);
    if(file.is_open())
    {
        string line;
        while (getline(file,line))
        {
            texte_lu += line;
            texte_lu += " ";
        }
        file.close();
    }
    else
    {
        cout<<"Error in opening file !! Function lecture_fichier"<<endl;
        texte_lu = "Probleme";
    }
    return texte_lu;
}




void gestion_scores::recherche_scores_joueurs()
/*
Lit le fichier texte contenant nom et score des joueurs et
remplit la liste des noms et la liste des joueurs avec les
informations contenues dans le fichier texte.
*/
{
    string texte_lu = lecture_fichier();
    //on les remplit
    unsigned long i = 0;
    while (i <= texte_lu.size())
    {
        while(texte_lu[i] == ' ') i ++;
        unsigned long cpt = i;
        while (texte_lu[cpt] != ' ') cpt++;
        noms_joueurs.push_back(texte_lu.substr(i,cpt));
        i = cpt+1;
        cpt ++;
        while(texte_lu[cpt] == ' ') {
            i ++;
            cpt ++;
        }
        while(texte_lu[cpt] != ' ') cpt++;
        scores_joueurs.push_back(stoi(texte_lu.substr(i,cpt)));
        i = cpt+1;
    }
}




vector<int> gestion_scores::get_vecteur_scores()
/*
Renvoie le vecteur contenant le nom des joueurs contenus dans le fichier texte.
*/
{
    return scores_joueurs;
}

vector<string> gestion_scores::get_vecteur_noms()
/*
Renvoie le vecteur contenant les scores contenus dans le fichier texte.
*/
{
    return noms_joueurs;
}





void gestion_scores::ecriture_fichier(string nom_joueur, int score_joueur)
/*
Permet d'ajouter au fichier une ligne contenant le nom et le score d'un joueur passés en paramètre.
*/
{
    string texte_a_ajouter = nom_joueur + " " + to_string(score_joueur) + " ";
    ofstream file (get_nom_fichier(),ios::out | ios::app);
    if(file.is_open())
    {
        file<<texte_a_ajouter;
        file<<"\n";
        file.close();
    }
    else
    {
        cout<<"Error in opening file !!"<<endl;
    }
}



int gestion_scores::get_score_joueur(string nom_joueur)
/*
Cette fonction lit le document contenant la liste des joueurs et leur score
à la recherche du joueur renseigné en argument et renvoie son score lorsqu'elle l'a
trouvé ou -1 si il n'est pas dans la liste.
*/
{
    string texte_lu = lecture_fichier();
    size_t pos_nom = texte_lu.find(nom_joueur);
    if (pos_nom!=string::npos)
    {
        //le faire sous forme de parcours d'une liste
        //ce sera plus simple pour trouver le score une fois qu'on a acces a l'element
    }
    else {
        return -1;
    }
}



void gestion_scores::modification_score(string nom_joueur, int new_score)
/*
Cette fonction lit le document contenant la liste des joueurs et leur score
à la recherche du joueur renseigné en argument et modifie son score avec
le nouveau score renseigné en argument.
*/
{
    string texte_lu = lecture_fichier();
    string new_texte;
    int joueur_modif = 0;
    for (unsigned long i = 0;i <= texte_lu.size()-nom_joueur.size()+1;i++)
    {
        if (texte_lu[i] == nom_joueur[0])
        {
            //cout << "Premiere lettre detectee " << i << endl;
            int is_joueur = 1;
            for (unsigned long j = 1; j <= nom_joueur.size(); j++)
            {
                if (!(texte_lu[i+j] == nom_joueur[j]))
                    is_joueur = 0;
            }
            if (is_joueur == 1)
            {
                unsigned long cpt = i+nom_joueur.size()+1;
//                cout << texte_lu.substr(i,cpt) << endl;
//                cout << "Est ce que c est un espace" << texte_lu[cpt] << endl;
                while (texte_lu[cpt] == ' ')
                {
                    cpt++;
                }
                new_texte = texte_lu.substr(0,i+nom_joueur.size()) + " " + to_string(new_score) + texte_lu.substr(cpt+1,texte_lu.size());
                rewrite(new_texte);
                joueur_modif = 1;
            }
        }
    }
    if (joueur_modif == 0)
    {
        ecriture_fichier(nom_joueur,new_score);
    }
}


void gestion_scores::rewrite(string new_text)
/*
Ouvre le fichier texte et remplace son contenu par le texte passé en argument.
*/
{
    ofstream file (get_nom_fichier(),ios::out | ios::trunc);
    if(file.is_open())
    {
        file<<new_text;
        file.close();
    }
    else
    {
        cout<<"Error in opening file !! Function rewrite "<<endl;
    }
}
