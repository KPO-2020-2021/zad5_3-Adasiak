#include "Ostroslup.hh"

Ostroslup::Ostroslup(Vector<3> pkt, double dlugosc ,double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu)
{
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;

    pkt1.resize(16);
    for (int i = 0; i < 16; i++)
    {
        pkt1[i] = pkt;
    }

    pkt1[1][0] -=dlugosc; 
    pkt1[1][1] -=szerokosc;

    pkt1[2][0] +=dlugosc; 
    pkt1[2][1] -=szerokosc;

    pkt1[3][2] += wysokosc;
/*---------------------------------------*/

    pkt1[4][0] +=dlugosc; 
    pkt1[4][1] -=szerokosc;

    pkt1[5][0] +=dlugosc; 
    pkt1[5][1] +=szerokosc;

    pkt1[6][2] +=wysokosc;
/*--------------------------------------------*/

    pkt1[7][0] +=dlugosc; 
    pkt1[7][1] +=szerokosc;

    pkt1[8][0] -=dlugosc; 
    pkt1[8][1] +=szerokosc;

    pkt1[9][2] +=wysokosc;

/*--------------------------------------------*/
    pkt1[10][0] -=dlugosc; 
    pkt1[10][1] +=szerokosc;


    pkt1[11][0] -=dlugosc; 
    pkt1[11][1] -=szerokosc;

    pkt1[12][2] +=wysokosc;

/*------------------------------------------*/

    pkt1[13][0] -=dlugosc; 
    pkt1[13][1] -=szerokosc;

    pkt1[14][0] +=dlugosc; 
    pkt1[14][1] -=szerokosc;

    pkt1[15][2] += wysokosc;
/*------------------------------------------*/
    this->srodek=this->srodek+pkt;
    set_srodek(pkt);
    
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



std::ostream &operator<<(std::ostream &Strm,
                         const Ostroslup &Pr)
{

    for (int i = 1; i < 13; i++)
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
    funkcja zwraca srodek ostroslupa 
 */
Vector<3> Ostroslup::wez_srodek() 
{
    return srodek;
}

