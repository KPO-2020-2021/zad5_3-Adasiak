#pragma once 

#include <vector>
#include "vector.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <string>
#include <unistd.h>
#include <memory>
#include "Dron.hh"
#include "Ostroslup.hh"
#include "Gran.hh"
#include "PPlaskowyz.hh"
#include "Przeszkody.hh"
#include <list>
#include <iomanip>

using namespace std;

class Scena
{   
    protected:
    double katOZ; // obrot do okola osi Z
    double katOY; // kat wznoszenia i opadania
    double katOX; // kat rotacji np. wirnikow

    vector<Vector<3>> scr1;
    Vector<3> Przesuniecie;
    Vector<3> srodek;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;
    int k=0;// ilosc punktów na prostej
    int nr=0;
    // PzG::LaczeDoGNUPlota Lacze;
    public:

    Scena(double dlugosc, double szeroksc,double glebokosc,  string nazwa_pliku, string nazwa_pliku_do_zapisu);

    void zapis();

    void move(const Vector<3> &v);

    void set_katOX(double kat){katOX+=kat;}
    void set_katOZ(double kat){katOZ+=kat;}
    void set_katOY(double kat){katOY=kat;}
    Vector<3> &operator [](int i){return scr1[i];}
    Vector<3> operator [](int i)const {return scr1[i];}


    void add_basic_objects(list<std::shared_ptr<Przeszkody> > &p,PzG::LaczeDoGNUPlota &Lacze,Vector<3> place, double xwth, double ywth,int k,int rodzaj);

   
    // std::string get_nazwa() const;


};
