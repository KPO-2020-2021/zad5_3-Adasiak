#pragma once

#include "matrix.hh"
#include <cmath>

typedef Matrix<3> Macierz3x3;

Macierz3x3 macierzobrotZ(double kat);
Macierz3x3 macierzobrotZ1(double kat);
Macierz3x3 macierzobrotY(double kat);
Macierz3x3 macierzobrotX(double kat);
Matrix<4> cztery(double alfa, double beta, double gamma, Vector<3> size);

