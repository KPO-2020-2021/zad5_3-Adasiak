#include "matrix3x3.hh"

/*!       
    \brief
 |  Macierz zawierajaca funkcje trygonometryczne potrzebne do rotacji wzgledem osi OZ                              |
 |  Argumenty:                                                                                      |
 |      Poszczegolne elemety macierzy                                                               |
 |  Zwraca:                                                                                         |
 |      Odpowiednie funkcje trygonometryczne uzaleznione od kata w radianach(rad)                   |
 */

Macierz3x3 macierzobrotZ(double kat)
{
    Macierz3x3 Wynik;
    double rad;
    rad = kat * PI / 180;
    Wynik(0, 0) = cos(rad);
    Wynik(0, 1) = -sin(rad);
    Wynik(0, 2) = 0;

    Wynik(1, 0) = sin(rad);
    Wynik(1, 1) = cos(rad);
    Wynik(1, 2) = 0;

    Wynik(2, 0) = 0;
    Wynik(2, 1) = 0;
    Wynik(2, 2) = 1;

    return Wynik;
}


Macierz3x3 macierzobrotZ1(double kat)
{
    Macierz3x3 Wynik;
    double rad;
    rad = kat * PI / 180;
    Wynik(0, 0) = -cos(rad);
    Wynik(0, 1) = sin(rad);
    Wynik(0, 2) = 0;

    Wynik(1, 0) = -sin(rad);
    Wynik(1, 1) = -cos(rad);
    Wynik(1, 2) = 0;

    Wynik(2, 0) = 0;
    Wynik(2, 1) = 0;
    Wynik(2, 2) = -1;

    return Wynik;
}


/*!       
    \brief
 |  Macierz zawierajaca funkcje trygonometryczne potrzebne do rotacji  wzgledem osi OY                              |
 |  Argumenty:                                                                                      |
 |      Poszczegolne elemety macierzy                                                               |
 |  Zwraca:                                                                                         |
 |      Odpowiednie funkcje trygonometryczne uzaleznione od kata w radianach(rad)                   |
 */

Macierz3x3 macierzobrotY(double kat)
{
    Macierz3x3 Wynik;
    double rad;
    rad = kat * PI / 180;
    Wynik(0, 0) = cos(rad);
    Wynik(0, 1) = 0;
    Wynik(0, 2) = sin(rad);

    Wynik(1, 0) = 0;
    Wynik(1, 1) = 1;
    Wynik(1, 2) = 0;

    Wynik(2, 0) = -sin(rad);
    Wynik(2, 1) = 0;
    Wynik(2, 2) = cos(rad);

    return Wynik;
}

/*!       
    \brief
 |  Macierz zawierajaca funkcje trygonometryczne potrzebne do rotacji  wzgledem osi OX                             |
 |  Argumenty:                                                                                      |
 |      Poszczegolne elemety macierzy                                                               |
 |  Zwraca:                                                                                         |
 |      Odpowiednie funkcje trygonometryczne uzaleznione od kata w radianach(rad)                   |
 */

Macierz3x3 macierzobrotX(double kat)
{
    Macierz3x3 Wynik;
    double rad;
    rad = kat * PI / 180;
    Wynik(0, 0) = 1;
    Wynik(0, 1) = 0;
    Wynik(0, 2) = 0;

    Wynik(1, 0) = 0;
    Wynik(1, 1) = cos(rad);
    Wynik(1, 2) = -sin(rad);

    Wynik(2, 0) = 0;
    Wynik(2, 1) = sin(rad);
    Wynik(2, 2) = cos(rad);

    return Wynik;
}


/*!       
    \brief
 |  Macierz zawierajaca funkcje trygonometryczne                               |
 |  Argumenty:                                                                                      |
 |      Poszczegolne elemety macierzy                                                               |
 |  Zwraca:                                                                                         |
 |      Odpowiednie funkcje trygonometryczne uzaleznione od kata w radianach(rad) oraz wartosci wektora bazowego                   |
 */

Matrix<4> cztery(double alfa, double beta, double gamma, Vector<3> size)
{
    Matrix<4> Wynik;
    // double a, b, c;
    double x,y,z ;
    alfa = alfa * PI / 180;
    beta = beta * PI / 180;
    gamma = gamma * PI / 180;
    // Vector<3>  size;
    // size[0]=2;
    // size[1]=2;
    // size[2]=2;
    x= size[0];
    y= size[1];
    z= size[2];

    Wynik(0, 0) = cos(alfa)*cos(beta);
    Wynik(0, 1) = (cos(alfa)*sin(beta)*sin(gamma))-(sin(alfa)*cos(gamma))  ;
    Wynik(0, 2) = (cos(alfa)*sin(beta)*cos(gamma))+(sin(alfa)*sin(gamma));
    Wynik(0, 3) = x;

    Wynik(1, 0) = sin(alfa)*cos(beta);
    Wynik(1, 1) = (sin(alfa)*sin(beta)*sin(gamma))+(cos(alfa)*cos(gamma));
    Wynik(1, 2) = (sin(alfa)*sin(beta)*cos(gamma))+(cos(alfa)*sin(gamma));
    Wynik(1, 3) = y;

    Wynik(2, 0) = -sin(beta);
    Wynik(2, 1) = cos(beta)*sin(gamma);
    Wynik(2, 2) = cos(beta)*cos(gamma);
    Wynik(2, 3) = z;

    Wynik(3, 0) = 0;
    Wynik(3, 1) = 0;
    Wynik(3, 2) = 0;
    Wynik(3, 3) = 1;

    return Wynik;
}
