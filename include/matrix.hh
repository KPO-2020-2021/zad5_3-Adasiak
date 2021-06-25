#pragma once
// #ifndef Matrix<   SIZE>_HH
// #define Matrix<   SIZE>_HH

#include "size.hh"

// #include "Prostopadloscian.hh"
// #include "Graniastoslup6.hh"
// #include "BrylaGeometryczna.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "../include/lacze_do_gnuplota.hh"
// #include <stdlib.h>
// #include <fstream>
// #include <string>

using namespace std;

template <int SIZE>
class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy


public:
    Matrix(double[SIZE][SIZE]); // Konstruktor klasy

    Matrix();
    // Konstruktor klasy
    /*!       
    \brief
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
    Vector<SIZE> operator*(Vector<SIZE> tmp)
    {
        Vector<SIZE> result;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                result[i] += value[i][j] * tmp[j];
            }
        }
        return result;
    }
    /*!       
    \brief
 |  Realizuje rotacje dwoch wektorow.                                           |
 |  Argumenty:                                                                  |
 |      this - pierwszy skladnik                                                |
 |      transformation - macierz tymczasowa                                     |                                            |
 |                                                                              |
 |  Zwraca:                                                                     |
 |      Wektor rotacji o odpowiednia funkcje geometryczna                       |                                                         |
 */

    Vector<SIZE> rotacja(const double &kat) const
    {
        Vector<SIZE> rot;

        double rad_kat = (kat * PI) / 180;
        if (SIZE == 2)
        {
            double tmp[][SIZE] = {{cos(rad_kat), -sin(rad_kat)}, {sin(rad_kat), cos(rad_kat)}};
            Matrix<SIZE> transformation(tmp);
            rot = transformation * *this;
        }
        if (SIZE == 3)
        {
            double tmp[][SIZE] = {{cos(rad_kat), -sin(rad_kat), 0}, {sin(rad_kat), cos(rad_kat), 0}, {0, 0, 1}};
            Matrix transformation(tmp);
            rot = transformation * *this;
        }
        else
        {
            std::cerr << "Blad: Marcierz obrotu rozna od 2 lub 3  wymiarow" << std::endl;
        }
        return rot;
    }
    // BrylaGeometryczna operator*(BrylaGeometryczna tmp);

    // Graniastoslup operator*(Graniastoslup tmp);

    Matrix<SIZE> operator+(Matrix<SIZE> tmp);
    Matrix<SIZE> operator*(Matrix<SIZE> tmp);
    Matrix(double kat); // przelicznik kata na radiany

    // void macierzobrotu(double kat, Prostopadloscian &tmp); //macierz zawierajaca funkcje trygonometryczne niezbedne do obrotu Prostopadlosciana


    void Gaus();

    double &operator()(int row, int column);

    const double &operator()(int row, int column) const;
};
/*!       
    \brief
 |  Konstruktor klasy Matrix<   SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <int SIZE>
Matrix<SIZE>::Matrix()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
                value[i][j] = 1;
            else
                value[i][j] = 0;
        }
    }
}

/*!       
    \brief
 |  Konstruktor parametryczny klasy Matrix<   SIZE>.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu  double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            value[i][j] = tmp[i][j];
        }
    }
}

/*!      
    \brief
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int SIZE>
double &Matrix<SIZE>::operator()(int row, int column)
{

    if (row >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/*!       
    \brief
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int SIZE>
const double &Matrix<SIZE>::operator()(int row, int column) const
{

    if (row >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/*!       
    \brief
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator+(Matrix<SIZE> tmp)
{
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator*(Matrix<SIZE> tmp)
{
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result(i, j) = 0;
            for (int k = 0; k < SIZE; k++)
                result(i, j) += this->value[i][k] + tmp(k, j);
        }
    }
    return result;
}

/*!       
    \brief
 |  Pzrelicznik kata na radiany                           |
 |  Argumenty:                                            |
 |      kat                                               |
 |  Zwraca:                                               |
 |      rad (kat przeliczony na radiany)                  |
 */

// Matrix<   SIZE>::Matrix<   SIZE>( double kat)
// {
//     rad = kat * PI /180;
// }


// template <int SIZE>
// Prostopadloscian Matrix<SIZE>::operator*(Prostopadloscian tmp)
// {
//     Prostopadloscian wynik;
//     for (int i = 0; i < 8; ++i)
//     {

//         wynik[i] = *this * tmp[i];
//     }
//     return wynik;
// }





/*!       
    \brief
 |  Zwraca Prostopadlosciana pomnorzony przez ofpowiednie funkcje trygonometrzyczne konieczne do rotacji   |
 |  Argumenty:                                                                                      |
 |      Poszczegolne wierzcholki Prostopadlosciana                                                         |
 |       Macierz obrotu                                                                             |
 |  Zwraca:                                                                                         |
 |      Wizrcholki przemnozone przez odpowiednie funkcje trygonometrczne                            |
 */

// Prostopadloscian Matrix<   SIZE>::operator*(Prostopadloscian prost)
// {
//     Prostopadloscian wynik;
//     for(int i=0; i < 4 ; i++)
//     {
//         wynik[i] = (*this) * prost[i];
//     }
//     return wynik;
// }

/*!      
    \brief
 |  Wyznacznik macierzy metoda gaussa                                                               |
 |  Argumenty:                                                                                      |                                                         |
 |       Macierz                                                                                    |
 |  Zwraca:                                                                                         |
 |      Wyznacznik macierzy                                                                         |
 */
template <int SIZE>
void Matrix<SIZE>::Gaus()
{
    double ratio;
    for (int i = 0; i < 2; i++)
    {
        if (value[1][1] == 0.0)
        {
            std::cout << "Matematycznty blad" << std::endl;
            exit(0);
        }
        for (int j = 0; j < 2; j++)
        {
            ratio = value[j][i] / value[i][i];
            for (int k = 0; k < 2; k++)
            {
                value[j][k] = value[j][k] - ratio * value[i][k];
            }
        }
    }
}

/*!       
    \brief
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

/*!       
    \brief
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
