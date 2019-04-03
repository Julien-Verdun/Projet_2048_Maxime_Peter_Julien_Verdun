#include "Damier.h"
//#include "exceptiondamier.h"
#include<vector>

template<class G>
Damier<G>::Damier(int l, int c, int borne, G vd)
{
    Borne = borne;
    Alloc(l, c);
    Alloc1(l,c);
    Init(vd);
}

template<class G>
Damier<G>::Damier(const Damier<G> &D)
{
    Alloc(D.L, D.C);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] = D.T[i][j];
}

template<class G>
Damier<G>::~Damier(){
    if (T != NULL) {
        Free();
        T = NULL;
    }
}

template<class G>
int Damier<G>::get_C(){
    return C;
}

template<class G>
int Damier<G>::get_L(){
    return L;
}


template<class G>
G** Damier<G>::get_T()
{
    return T;
}


//void Damier::Init_Jeu()

template<class G>
void Damier<G>::Free(){
    for (int i=0; i<L; i++)
        delete [] T[i];
    delete [] T;
}

template<class G>
void Damier<G>::Alloc(int l, int c){
    L = l;
    C = c;
    T = new G*[L];
    for(int i=0; i<L; i++)
        T[i] = new G[C];
}

template<class G>
void Damier<G>::Alloc1(int l, int c){
    L = l;
    C = c;
    T1 = new G*[L];
    for(int i=0; i<L; i++)
        T1[i] = new G[C];
}


template<class G>
void Damier<G>::Print(){
    cout << endl;
    for(int i=0; i<L; i++) {
        cout << endl;
        for(int j=0; j<C; j++)
            cout << T[i][j] << " ";
    }
}

template<class G>
void Damier<G>::Init(G value){
//    if ((value <0)||(value>=Borne))
//    {
//        string file(__FILE__);
//        string fonction(__PRETTY_FUNCTION__);
//        ExceptionDamier e(Borne, value, file, fonction);
//        throw(e);
//    }


    for(int i=0; i<L; i++)
    {
        for(int j=0; j<C; j++)
        {
            T[i][j]=value;
            T1[i][j] = value;
        }
    }
}



template<class G>
G Damier<G>::Get(int x, int y) {
    //if (x < 0 || x > L || y < 0 || y > C)
    //    throw(1);
    return T[x][y];
}




template<class G>
void Damier<G>::Set(int x, int y, G value) {
//    if (x < 0 || x > L || y < 0 || y > C)
//        throw(1);
//    if ((value <0)||(value>=Borne))
//    {
//        string file(__FILE__);
//        string fonction(__PRETTY_FUNCTION__);
//        ExceptionDamier e(Borne, value, file, fonction);
//        throw(e);
//    }
    T[x][y]=value;
}



template<class G>
G Damier<G>::Get_T1(int x, int y) {
    return T1[x][y];
}
template<class G>
void Damier<G>::Set_T1(int x, int y, G value) {
    T1[x][y]=value;
}


template<class G>
G** Damier<G>::get_last_compo()
{
    //return Liste_T[Liste_T.size()-i];//Liste_T.back();
    return T1;
}



template<class G>
void Damier<G>::append_new_compo(G** t)
{
    //Liste_T.push_back(t);
    for (int i = 0;i<get_L();i++)
        for (int j = 0;j < get_C();j++)
            Set_T1(i,j,t[i][j]);
}



template<class G>
void Damier<G>::delete_last_compo()
{
    //Liste_T.pop_back();
}













template<class G>
void Damier<G>::ReDim(int l, int c, G vd) {
    Free();
    Alloc(l, c);
    Init(vd);
}

template<class G>
Damier<G>& Damier<G>::operator= (const Damier<G> &D){
    if ( this != &D ) { // protection autoréférence
        Free();
        Alloc(D.L, D.C);
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++)
                T[i][j] = D.T[i][j];
    }
    return *this;
}

template<class G>
bool Damier<G>::sameDimensions (const Damier<G> &D) {
    if ((L == D.L) && (C == D.C))
        return true;
    return false;
}

template<class G>
Damier<G>& Damier<G>::operator+= (G c)
{
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += c;
    return *this;
}

template<class G>
Damier<G>& Damier<G>::operator+= (const Damier<G> &D)
{
    if (!sameDimensions(D)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            T[i][j] += D.T[i][j];
    return *this;
}

template<class G>
Damier<G> Damier<G>::operator+ (const Damier<G> &D1)
{
    if (!sameDimensions(D1)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }

    Damier<G> D(D1.L, D1.C,D1.Borne);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            D.T[i][j] = T[i][j]+D1.T[i][j];

    return D;
}

template<>
Damier<bool> Damier<bool>::operator+ (const Damier<bool> &D1)
{
    cout << endl << "Opérateur + spécifique au type bool" << endl;
    if (!sameDimensions(D1)){
        cerr << endl << __PRETTY_FUNCTION__ << " - Dimensions différentes !\n";
        exit(1);
    }

    Damier<bool> D(D1.L, D1.C,D1.Borne);
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            D.T[i][j] = T[i][j]||D1.T[i][j];

    return D;
}


template <class G>
ostream& operator<< (ostream& sortie, Damier<G>& V)
{
    for(int i=0; i<V.L; i++) {
        for(int j=0; j<V.C; j++)
            sortie << V.T[i][j] << " ";
        sortie << endl;
    }

    return sortie;
}



//Instantiating the class Damier
template class Damier<float>;
template class Damier<int>;
template class Damier<char>;
template class Damier<bool>;


//Instantiating friend function operator<<

template ostream& operator<<(ostream& sortie, Damier<float>& V);
template ostream& operator<<(ostream& sortie, Damier<int>&   V);
template ostream& operator<<(ostream& sortie, Damier<char>&  V);
template ostream& operator<<(ostream& sortie, Damier<bool>&  V);
