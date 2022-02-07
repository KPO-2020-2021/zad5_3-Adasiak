#pragma once
#include "vector.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <string>
#include <vector>
#include "Przeszkody.hh"
using namespace std;

class BrylaGeometryczna:public Przeszkody, public std::enable_shared_from_this< BrylaGeometryczna >
{
protected:
    vector<Vector<3>> pkt1;
    Vector<3> Przesuniecie;
    Vector<3>  srodek;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;
    double katOZ; // obrot do okola osi Z
    double katOY; // kat wznoszenia i opadania
    double katOX; // kat rotacji np. wirnikow
    double bpromien;
public:
    Vector<3> operator[](int Ind) const { return pkt1[Ind]; } //wypisywanie
    Vector<3> &operator[](int Ind) { return pkt1[Ind]; } //wpisywanie


   

    void move(const Vector<3> &v);

    void obrotOZ(double kat);
    void obrotP(double kat, Vector<3> a);
    
    void obrotW(double kat);
    void obrotW1(double kat,Vector<3> b);

    std::string nazwa(){ return nazwa_pliku_do_zapisu;}

    std::string get_nazwa() const;



    void zapis();

    void set_katOX(double kat){katOX+=kat;}
    void set_katOZ(double kat){katOZ+=kat;}
    void set_katOY(double kat){katOY=kat;}

    void set_Przesuniecie(Vector<3> droga){
        Przesuniecie=Przesuniecie+macierzobrotZ(katOZ)*(macierzobrotX(katOX)* (macierzobrotY(katOY)*droga));
    }

    double promien(){return sqrt(pow(srodek[0]-pkt1[0][0],2) + pow(srodek[1]-pkt1[0][1],2)+pow(srodek[2]-pkt1[0][2],2));}

    Vector<3> wez_srodek() ;
    
    Vector<3> get_srodek() const ;
    
    bool czy_kolizja(std::shared_ptr <Przeszkody> &p);

    // bool czy_kolizja(std::shared_ptr <Przeszkody> p) const;
     double wez_promien(){return bpromien;}
     
    //  void obob(list<std::shared_ptr<Przeszkody> > &p);
     void obrotWW(/*std::shared_ptr <Przeszkody> &p*/);
     void obrotWWW(std::shared_ptr <Przeszkody> &p);

    void set_srodek(Vector<3> srodek);
        // string nazwa(){ return nazwa_pliku_do_zapisu;}

};
