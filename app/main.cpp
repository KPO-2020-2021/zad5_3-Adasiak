// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <list>
#include <memory>

#include "matrix3x3.hh"
#include "exampleConfig.h"
// #include "vector.hh"
// #include "Graniastoslup6.hh"
#include "Ostroslup.hh"
#include "Gran.hh"

#include "Dron.hh"
#include "Scena.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i Prostopadlosciana
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

// void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream &StrmWy, Graniastoslup Pr)
// {
//        StrmWy << Pr;
// }


// bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku,
//                                         Graniastoslup Pr /*, Vector<  2> Przesuniecie*/)
// {
//        std::ofstream StrmPlikowy;

//        StrmPlikowy.open(sNazwaPliku);
//        if (!StrmPlikowy.is_open())
//        {
//               std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
//                         << ":(  nie powiodla sie." << std::endl;
//               return false;
//        }

//        PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, Pr /*, Przesuniecie*/);
//        StrmPlikowy << Pr[0] << endl;
//        StrmPlikowy << Pr[1];
//        StrmPlikowy.close();
//        return !StrmPlikowy.fail();
// }



// void PrzykladZapisuWspolrzednychDoStrumienia1(std::ostream &StrmWy, Prostopadloscian Pr)
// {
//        StrmWy << Pr;
// }


// bool PrzykladZapisuWspolrzednychDoPliku1(const char *sNazwaPliku,
//                                         Prostopadloscian Pr /*, Vector<  2> Przesuniecie*/)
// {
//        std::ofstream StrmPlikowy;

//        StrmPlikowy.open(sNazwaPliku);
//        if (!StrmPlikowy.is_open())
//        {
//               std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
//                         << ":(  nie powiodla sie." << std::endl;
//               return false;
//        }

//        PrzykladZapisuWspolrzednychDoStrumienia1(StrmPlikowy, Pr /*, Przesuniecie*/);
//        StrmPlikowy << Pr[0] << endl;
//        StrmPlikowy << Pr[1];
//        StrmPlikowy.close();
//        return !StrmPlikowy.fail();
// }


using namespace std;

int main()
{
       
       char menu;
       // double kat=1;
       // char os;
       int powierzchnia;
       // Matrix<3> m;
       Vector<3> zero;
       zero[0]=0;
       zero[1]=0;
       zero[2]=0;
       Vector<3> wektor_trans;
       wektor_trans[0]=50;
       wektor_trans[1]=50;
       wektor_trans[2]=30;
       Vector<3>  skala;
       // Vector<3> wektor;
       // wektor[0] = 100;
       // wektor[1] = 100;
       // wektor[2] = 10;
       
       int nr=1;
       Dron Predator(nr);
       int Mariusz = 2;
       Dron Pudzianowski(Mariusz);
       list<shared_ptr<Przeszkody> > p;

       // int plicznik;
       // plicznik=0;
       // Pudzianowski.ruch(wektor_trans,0,0);
       
       double a=-90,b=90,c,d;
       c=atan2(b,a);
       std::cout << c  <<std::endl;
       d =c*180/M_PI ;
       std::cout << d  <<std::endl;

       std::cout << "Project Dron based on C++ Boiler Plate v"
                 << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
                 << "."
                 << PROJECT_VERSION_MINOR /* istotne zmiany */
                 << "."
                 << PROJECT_VERSION_PATCH /* naprawianie bugów */
                 << "."
                 << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
                 << std::endl;

       PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                                   // rysunku Prostopadlosciana

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "Prostopadloscian.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       


       Scena dno(500,500,0,"../datasets/dno.dat","../datasets/dno2.dat");
       // dno.menu();
       Vector<3> place1;
       place1[0]=50;
       place1[1]=50;
       double xwth1=20,ywth1=20;
       dno.zapis();

       Vector<3> wektor;
       wektor[0] = 100;
       wektor[1] = 100;
       dno.add_basic_objects(p,Lacze,wektor,xwth1,ywth1,0,1);

       Vector<3> kotek;
       kotek[0]=-100;
       kotek[1]=100;
       dno.add_basic_objects(p,Lacze,kotek,xwth1,ywth1,0,2);

       Vector<3> zaba;
       zaba[0] = 100;
       zaba[1] = -100;
       dno.add_basic_objects(p,Lacze,zaba,xwth1,ywth1,0,1);


       Vector<3> bocian;
       bocian[0] = 100;
       bocian[1] = -70;
       dno.add_basic_objects(p,Lacze,bocian,xwth1,ywth1,0,3);

       //
       //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy x,y,z.
       //
       Lacze.ZmienTrybRys(PzG::TR_3D);

       // Ustawienie zakresow poszczegolnych osi
       Lacze.UstawZakresY(-155, 155);
       Lacze.UstawZakresX(-155, 155);
       Lacze.UstawZakresZ(-155, 155);

       Lacze.DodajNazwePliku("../datasets/dno2.dat",1 );
       // Lacze.DodajNazwePliku("../datasets/trasa_przelotu.dat" );
      


       // Lacze.DodajNazwePliku("../datasets/gora"+to_string(glicznik)+".dat" );

       // AtrybutyRysowania kaczka;

       // Lacze.ZmienKolor();
       Lacze.DodajNazwePliku("../datasets/korp2.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik1_2.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik2_2.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik3_2.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik4_2.dat",2);

       Lacze.DodajNazwePliku("../datasets/korp4.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik1_4.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik2_4.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik3_4.dat",2);
       Lacze.DodajNazwePliku("../datasets/wirnik4_4.dat",2);

       
       // double marcin=45;
       // Predator.obrot(marcin);
       Lacze.Rysuj();
       // std::cout << p.size() << std::endl;
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

       //----------------------------------------------------------
       // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       //
 

       
       // Predator.obrot(90);
       // Pudzianowski.obrot(90);
       double q,w;
       q=w=10;
       
       Predator.AnimacjaLotuDrona(p,Lacze,q,w);
       // Pudzianowski.AnimacjaLotuDrona(Lacze,a,b);

       // double kitek=50;
       // Predator.zwiad2(Lacze,kitek);
       // Pudzianowski.zwiad2(Lacze,kitek); 


       // Vector<3> place2;
       // place2[0]=-50;
       // place2[1]=-50;
       // dno.add_basic_objects(Lacze,place2, xwth1, ywth1,1,3);
       // dno.zapis();

       
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

       Vector<3> place3;
       place3[0]=-110;
       place3[1]=100;
       dno.add_basic_objects(p,Lacze,place3, xwth1, ywth1,0,3);

       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // // }
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

              

       // Predator.ruch(kasia,0,0);
       // // Predator.obrot(1);
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
       // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       // std::cin.ignore(100000, '\n');

       while (menu != 'k')
       {

              std::cout << "Wybierz jedna z dostepnych opcji: " << std::endl;
              std::cout << "a - wybierz aktywnego drona" << std::endl;
              std::cout << "p - zadaj parametry przelotu" << std::endl;
              std::cout << "d - dodaj element powierzchni" << std::endl;
              std::cout << "u - usun element powierzchni" << std::endl;
              std::cout << "m - wyswietl menu" << std::endl;
              std::cout << "k - koniec dzialania programu" << std::endl;
              std::cin >> menu;

              int aktywny;
              switch (menu)
              {
              case 'a':
              {
                     std::cout << "1 - Polozenie (x,y):  " ;
                     Predator.wspolrzedne();
                     std::cout << "2 - Polozenie (x,y):  " ;
                     Pudzianowski.wspolrzedne();
                     std::cout<<"Podaj numer drona: ";
                     std::cin>>aktywny;

              }
              break;
              case 'p':
              {
                     std::cout<<"Podaj wspolzedne jakie ma osiagnac dron::";
                     double w1,w2;
                     std::cin>>w1;
                     std::cout<<" ";
                     std::cin>>w2;

                     if(aktywny==1){
                     Predator.AnimacjaLotuDrona(p,Lacze,w1,w2);
                     }
                     if(aktywny==2){
                     Pudzianowski.AnimacjaLotuDrona(p,Lacze,w1,w2);
                     }


              }
              break;
              case 'd':
              {

                     std::cout<<"Podaj miejsce pojawiania sie przeszkody" << std::endl;
                     Vector<3> tmpppp;
                     std::cin >> place1;
                     std::cout << "Podaj dlugosc przeszkody" << std::endl;
                     std::cin >> xwth1;
                     std::cout << "Podaj szerkosc przeszkody" << std::endl;
                     std::cin >> ywth1;
                     std::cout << "Wybierz rodzaj powierzchniowego elementu " << std::endl;
                     std::cout << "1 - Gora z ostrym sztytem" << std::endl;
                     std::cout << "2 - Gora z grania" << std::endl;
                     std::cout << "3 - Plaskowyz" << std::endl;
                     std::cin >> powierzchnia;

                     // double t1,t2,t3;

                     if (powierzchnia == 1)
                     {
                            dno.add_basic_objects(p,Lacze,place1, xwth1, ywth1,0,1);
                     } 
                     
                     if (powierzchnia == 2)
                     {
                            dno.add_basic_objects(p,Lacze,tmpppp, xwth1, ywth1,0,2);
                     }
                     
                     if (powierzchnia == 3)
                     {
                            // std::cout << "Podaj scale wzdluz kolejnych osi OX, OY, OZ." << std::endl;
                            // std::cin >> skala;

                            dno.add_basic_objects(p,Lacze,tmpppp, xwth1, ywth1,0,3);
                     }
                     
                     Lacze.Rysuj();
              }
              break;
              case 'u':
              {
                     dno.add_basic_objects(p,Lacze,place3, xwth1, ywth1,1,3);
                     Lacze.Rysuj();
              }
              break;
              
              case 'm':
              {

              }
              break;
              case 'k':
              {
                     std::cout << "Koniec dzialania programu." << std::endl;
              }
              break;
              
              // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // // }
       //        // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       //        std::cin.ignore(100000, '\n');
              
              default:
                     std::cout << "Bledna opcja" << std::endl;
                     break;
               Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
              // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
              std::cin.ignore(100000, '\n');
              
              
              }
       }
       return 0;

}
