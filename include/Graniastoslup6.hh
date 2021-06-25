#pragma once

#include "vector.hh"
#include "BrylaGeometryczna.hh"

// #include "matrix.hh"
#include "size.hh"
// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
class Graniastoslup : public BrylaGeometryczna
{

public:
    Graniastoslup(){};
    
    Graniastoslup(Vector<3> pkt, double h, double w, double d, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    
    Vector<3> wez_srodek();
 
};

std::ostream &operator<<(std::ostream &Strm, const Graniastoslup &Pr);