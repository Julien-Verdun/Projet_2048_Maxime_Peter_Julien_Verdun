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


    void Print();
    void Init(G value);

    G Get(int x, int y);
    void Set(int x, int y, G value);

    void ReDim(int l, int c, G vd = 0);

    int get_C();
    int get_L();

    G** get_T();

    G** get_last_compo();
    void append_new_compo(G** t);
    void delete_last_compo();

    int get_pos_vec();
    void set_pos_vec(int i);


private:
    int pos_vec;
    int L;
    int C;
    int Borne;
    G** T;
    vector<G**> Liste_T;

    void Alloc(int l, int c);
    void Alloc1(int l, int c);
    void Free();

};

#endif // DAMIER_H
