#ifndef DAMIER_H
#define DAMIER_H

#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <vector>

template <class G>
class Damier
{
public:
    Damier(int l, int c, int borne, G vd=0);
    Damier(const Damier &D);
    ~Damier();

    Damier<G>& operator=  (const Damier<G> &D); // opérateur d'affectation
    Damier<G>& operator+= (const Damier<G> &D);
    Damier<G>& operator+= (G c);
    Damier<G>  operator+  (const Damier<G> &D);
    template <class B> friend ostream& operator<< (ostream& sortie, Damier<B>& V);



    void Print();
    void Init(G value);
    G Get(int x, int y);
    void Set(int x, int y, G value);
    void ReDim(int l, int c, G vd = 0);

    int get_C();
    int get_L();

    G** get_last_compo();
    void append_new_compo(G** t);

private:
    int L;
    int C;
    int Borne;
    G** T;
    vector<G**> Liste_T;
    // Méthode privée (factorisation  de code)
    void Alloc(int l, int c);
    void Free();
    bool sameDimensions (const Damier<G> &D);
};

#endif // DAMIER_H
