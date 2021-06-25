#include "Prostopadloscian.hh"
#include "../include/lacze_do_gnuplota.hh"
#include <iomanip>


/*!
    \brief
    *Konstruktor Prostopadlosciana. 
    *Tworzymy Prostopadlosciana wzgledem 1 wierzcholak (jego wspolrzednych ), 
    * a nastepnie kolejne wierzcholki dodajac do 1 wierzcholka szerokosc i wysokosc w zaleznosci od kolejnego wierzcholka
    * 
    * a nastepnie zapisujemy je kolejno  do odpowiedniego pliku 
    *
    *  

*/

Prostopadloscian::Prostopadloscian(Vector<3> pkt, double h, double w, double d, string nazwa_pliku, string nazwa_pliku_do_zapisu)
{
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    
    pkt1.resize(8);
    for (int i = 0; i < 8; i++)
    {
        pkt1[i] = pkt;
    }
    
    pkt1[1][0] += w;

    pkt1[2][1] += h;

    pkt1[3][0] += w;
    pkt1[3][1] += h;

    pkt1[4][1] += h;
    pkt1[4][2] += d;

    pkt1[5][0] += w;
    pkt1[5][1] += h;
    pkt1[5][2] += d;

    pkt1[6][2] += d;

    pkt1[7][0] += w;
    pkt1[7][2] += d;

    srodek_prostopadloscianu[0]=(pkt1[3][0]-pkt1[0][0])/2;
    srodek_prostopadloscianu[1]=(pkt1[3][1]-pkt1[0][1])/2;
    srodek_prostopadloscianu[2]=pkt1[0][2];
    
/*-----------------------------------------------*/

//     pkt1[1][0] -= h/2;
//     pkt1[1][1] -= w/2;

//     pkt1[2][0] += h/2;
//     pkt1[2][1] -= w/2;


//     pkt1[3][0] += h/2;
//     pkt1[3][1] -= w/2;
//     pkt1[3][2] += d;

//     pkt1[4][0] -= h/2;
//     pkt1[4][1] -= w/2;
//     pkt1[4][2] += d;

// /*------------------------------------*/

//     pkt1[5][0] += h/2;
//     pkt1[5][1] -= w/2;


//     pkt1[6][0] += h/2;
//     pkt1[6][1] += w/2;

//     pkt1[7][0] += h/2;
//     pkt1[7][1] += w/2;
//     pkt1[7][1] += d;

//     pkt1[8][0] += h/2;
//     pkt1[8][1] -= w/2;
//     pkt1[8][2] += d;

// /*--------------------------------------*/

//     pkt1[9][0] += h/2;
//     pkt1[9][1] += w/2;


//     pkt1[10][0] -= h/2;
//     pkt1[10][1] += w/2;

//     pkt1[11][0] -= h/2;
//     pkt1[11][1] += w/2;
//     pkt1[11][1] += d;

//     pkt1[12][0] += h/2;
//     pkt1[12][1] += w/2;
//     pkt1[12][1] += d;

// /*-----------------------------------------*/


//     pkt1[13][0] -= h/2;
//     pkt1[13][1] += w/2;


//     pkt1[14][0] -= h/2;
//     pkt1[14][1] -= w/2;

//     pkt1[15][0] -= h/2;
//     pkt1[15][1] -= w/2;
//     pkt1[15][1] += d;


//     pkt1[16][0] -= h/2;
//     pkt1[16][1] += w/2;
//     pkt1[16][1] += d;

// /*----------------------------------*/


//     pkt1[17][0] -= h/2;
//     pkt1[17][1] -= w/2;

//     pkt1[18][0] += h/2;
//     pkt1[18][1] -= w/2;


//     pkt1[19][0] += h/2;
//     pkt1[19][1] -= w/2;
//     pkt1[19][2] += d;

//     pkt1[20][0] -= h/2;
//     pkt1[20][1] -= w/2;
//     pkt1[20][2] += d;

/*----------------------------------------------------*/
    // pkt1[2][1] += h;

    // pkt1[3][0] += w;
    // pkt1[3][1] += h;

    // pkt1[4][1] += h;
    // pkt1[4][2] += d;

    // pkt1[5][0] += w;
    // pkt1[5][1] += h;
    // pkt1[5][2] += d;

    // pkt1[6][2] += d;

    // pkt1[7][0] += w;
    // pkt1[7][2] += d;




    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)pkt1.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<pkt1[i]<<endl;
    }
    plik.close();
    zapis();
}

/*!
    \brief
    *Operator wyswietlania 
    dokonujemy wyswietlenia kolejnych punktow graniastoslupa
    *
    *  

*/

std::ostream &operator<<(std::ostream &Strm,
                         const Prostopadloscian &Pr)
{

    for (int i = 0; i < 8; i++)
    {
        Strm << Pr[i] << endl;
        if ((i + 1) % 2 == 0)
            Strm << endl;
    }

    return Strm;
}


/*!       
    \brief
    wez_srodek
    funkcja zwraca srodek prostopadloscianu 
 */
Vector<3> Prostopadloscian::wez_srodek() 
{
    return srodek;
}
