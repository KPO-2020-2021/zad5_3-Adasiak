#pragma once

// #include "BrylaGeometryczna.hh"
#include "Przeszkody.hh"
#include "Dron.hh"
// #include "matrix3x3.hh"
// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>

using namespace std;
class PPlaskowyz : public BrylaGeometryczna
{
  

public:
    PPlaskowyz(){};

    PPlaskowyz(Vector<3> pkt, double h, double w, double d, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    
      Vector<3> wez_srodek();
};


std::ostream &operator<<(std::ostream &Strm, const PPlaskowyz &Pr);


