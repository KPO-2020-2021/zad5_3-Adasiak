#include "Graniastoslup6.hh"
#include "../include/lacze_do_gnuplota.hh"
#include <iomanip>

/*!
    \brief
    *Konstruktor Graniastoslupa. 
    *Tworzymy Graniastoslupa wzgledem 1 wierzcholak (jego wspolrzednych ), 
    * a nastepnie kolejne pkt1 dodajac do 1 wierzcholka szerokosc i wysokosc w zaleznosci od kolejnego wierzcholka
    * 
    * a nastepnie zapisujemy je kolejno  do odpowiedniego pliku
    *
    *  

*/

Graniastoslup::Graniastoslup(Vector<3> pkt, double h, double w, double d,string nazwa_pliku, string nazwa_pliku_do_zapisu)
{
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;

    pkt1.resize(25);
    for (int i = 0; i < 25; i++)
    {
        pkt1[i] = pkt;
    }
    pkt1[1][0] -= w;

    pkt1[2][0] -= w/2;
    pkt1[2][1] -= h;

    pkt1[3][0] -= w;
    pkt1[3][2] += d;

    pkt1[4][0] -= w/2;
    pkt1[4][1] -= h;
    pkt1[4][2] += d;

    pkt1[5][0] -= w/2;
    pkt1[5][1] -= h;

    pkt1[6][0] += w/2;
    pkt1[6][1] -= h;

    pkt1[7][0] -= w/2;
    pkt1[7][1] -= h;
    pkt1[7][2] += d;

    pkt1[8][0] += w/2;
    pkt1[8][1] -= h;
    pkt1[8][2] += d;
    

    pkt1[9][0] += w/2;
    pkt1[9][1] -= h;

    pkt1[10][0] += w;


    pkt1[11][0] += w/2;
    pkt1[11][1] -= h;
    pkt1[11][2] += d;

    pkt1[12][0] += w;
    pkt1[12][2] += d;


    pkt1[13][0] += w;

    pkt1[14][0] += w/2;
    pkt1[14][1] += h;

    pkt1[15][0] += w;
    pkt1[15][2] += d;

    pkt1[16][0] += w/2;
    pkt1[16][1] += h;
    pkt1[16][2] += d;


    pkt1[17][0] += w/2;
    pkt1[17][1] += h;

    pkt1[18][0] -= w/2;
    pkt1[18][1] += h;

    pkt1[19][0] += w/2;
    pkt1[19][1] += h;
    pkt1[19][2] += d;

    pkt1[20][0] -= w/2;
    pkt1[20][1] += h;
    pkt1[20][2] += d;


    pkt1[21][0] -= w/2;
    pkt1[21][1] += h;

    pkt1[22][0] -= w;

    pkt1[23][0] -= w/2;
    pkt1[23][1] += h;    
    pkt1[23][2] += d;    

    pkt1[24][0] -= w;
    pkt1[24][2] += d;

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
                         const Graniastoslup &Pr)
{

    for (int i = 1; i < 25; i++)
    {
        Strm << Pr[i] << endl;
        if ((i) % 2 == 0)
            Strm << endl;
    }

    return Strm;
}


/*!       
    \brief
    wez_srodek
    funkcja zwraca srodek graniastoslupa 
 */
Vector<3> Graniastoslup::wez_srodek() 
{
    return srodek;
}
