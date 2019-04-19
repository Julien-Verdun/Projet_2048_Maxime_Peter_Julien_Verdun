#include "Damier.h"
//#include "exceptiondamier.h"
#include<vector>

template<class G>
Damier<G>::Damier(int l, int c, int borne, G vd)
/*
Constructeur de la classe Damier (4 paramètres, les dimensions du damier l et c,
la valeur  maximale du damier borne et la valeur initiale prise par les cases du damier vd.
*/
{
    Borne = borne;
    Alloc(l, c);
    Alloc1(l,c);
    Init(vd);
}

template<class G>
Damier<G>::Damier(const Damier<G> &D)
/*
Constructeur par copie de la classe Damier (un paramètre, un damier à recopier).
*/
{
    Alloc(D.L, D.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] = D.T[i][j];
}

template<class G>
Damier<G>::~Damier()
/*
Destructeur de la classe Damier (libération des espaces en mémoir utilisées par
le damier T et la liste des damiers Liste_T).
*/
{
    if (T != NULL) {
        Free();
        T = NULL;
        for(int i = 0; i< Liste_T.size()-1 ; i++)
        {
            Liste_T.pop_back();
        }
    }
}

template<class G>
int Damier<G>::get_C()
/*
Renvoie le nombre de colonne du Damier : C.
*/
{
    return C;
}

template<class G>
int Damier<G>::get_L()
/*
Renvoie le nombre de ligne du Damier : L.
*/
{
    return L;
}


template<class G>
G** Damier<G>::get_T()
/*
Renvoie le Dmier T (tableau à 2 dimensions).
*/
{
    return T;
}



template<class G>
void Damier<G>::Free()
/*
Libère l'espace mémoire occupé par le tableau T.
*/
{
    for (int i=0; i<L; i++)
        delete [] T[i];
    delete [] T;
}

template<class G>
void Damier<G>::Alloc(int l, int c)
/*
Allocation dynamique des espaces mémoires nécessaires pour le tableau T.
*/
{
    L = l;
    C = c;
    T = new G*[L];
    for(int i=0; i<L; i++)
        T[i] = new G[C];
}

template<class G>
void Damier<G>::Alloc1(int l, int c)
/*
Allocation dynamique des espaces mémoires nécessaires pour le vecteur de tableau Liste_T.
*/
{
    L = l;
    C = c;
    G** T1;
    T1 = new G*[L];
    for(int i=0; i<L; i++)
        T1[i] = new G[C];
    Liste_T.push_back(T1);
}


template<class G>
void Damier<G>::Init(G value)
/*
Initialisation des valeurs du tableau T avec la valeur donnée en paramètre : value.
*/
{
    for(int i=0; i<L; i++)
    {
        for(int j=0; j<C; j++)
        {
            T[i][j]=value;
            Liste_T[0][i][j] = value;
        }
    }
    pos_vec = 0;
}



template<class G>
G Damier<G>::Get(int x, int y)
/*
Renvoie la valeur du tableau placé à la ligne x et à la colonne y.
*/
{
    return T[x][y];
}




template<class G>
void Damier<G>::Set(int x, int y, G value)
/*
Modifie la valeur du tableau placée à la ligne x et à la colonne y avec la valeur
value donnée en paramètre.
*/
{
    T[x][y]=value;
}



template<class G>
G** Damier<G>::get_last_compo()
/*
Renvoie le dernier damier contenu dans la liste des damiers Liste_T.
*/
{
    G** A;
    A = new G*[L];
    for(int i=0; i<L; i++)
        A[i] = new G[C];
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            A[i][j] = Liste_T[pos_vec][i][j];
    return A;
}



template<class G>
void Damier<G>::append_new_compo(G** t)
/*
Ajoute un damier t à la liste des damiers Liste_T si
le damier précédent n'est pas le même.
*/
{
    int is_same = 1;
    for (int i = 0 ; i< L; i++)
    {
        for(int j = 0; j<C ; j++)
        {
            if (Liste_T[pos_vec][i][j] != t[i][j])
            {
                is_same = 0;
            }
        }
    }
    if (is_same == 0)
    {
        pos_vec++;
        Liste_T.push_back(t);
    }
}



template<class G>
void Damier<G>::delete_last_compo()
/*
Supprime le dernier damier contenu dans la liste des damiers Liste_T.
*/
{
    Liste_T.erase(Liste_T.begin()+pos_vec);
    pos_vec --;
}





template<class G>
int Damier<G>::get_pos_vec()
/*
Renvoie la variable pos_vec.
*/
{
    return pos_vec;
}


template<class G>
void Damier<G>::set_pos_vec(int i)
/*
Modifier la variable pos_vec par la variable donnée en paramètre i.
*/
{
    pos_vec = i;
}


//Instantiating the class Damier
template class Damier<float>;
template class Damier<int>;
template class Damier<char>;
template class Damier<bool>;
