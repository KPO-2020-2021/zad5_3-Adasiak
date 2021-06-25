#pragma once

#include "BrylaGeometryczna.hh"
#include "Dron.hh"
#include "Przeszkody.hh"
#include <iostream>

class Gran : public BrylaGeometryczna
{
    protected:
    int nrprzeszkody;
    double gpromien;
    public:
    Gran(Vector<3> pkt,double dlugosc ,double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    // ~Ostroslup();
        Vector<3> wez_srodek();
         double wez_promien(){return gpromien;}

};

std::ostream &operator<<(std::ostream &Strm,
                         const Gran &Pr);