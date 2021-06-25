#pragma once

// #include "BrylaGeometryczna.hh"
#include "Przeszkody.hh"
#include "Dron.hh"
#include <iostream>

class Ostroslup : public BrylaGeometryczna
{
    protected:
    int nrprzeszkody;
    Vector<3> srodek;
    public:
    Ostroslup(Vector<3> pkt,double dlugosc ,double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    // ~Ostroslup();
        Vector<3> wez_srodek() ;
    
};

std::ostream &operator<<(std::ostream &Strm,
                         const Ostroslup &Pr);
