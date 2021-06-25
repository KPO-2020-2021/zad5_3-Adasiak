#include "Gran.hh"

Gran::Gran(Vector<3> pkt, double dlugosc ,double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu)
{
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;

    pkt1.resize(20);
    for (int i = 0; i < 20; i++)
    {
        pkt1[i] = pkt;
    }

    pkt1[1][0] -=dlugosc; 
    pkt1[1][1] -=szerokosc;

    pkt1[2][0] +=dlugosc; 
    pkt1[2][1] -=szerokosc;

    pkt1[3][0] +=dlugosc; 
    pkt1[3][1] -=szerokosc;
    pkt1[3][2] += wysokosc;

    pkt1[4][0] -=dlugosc; 
    pkt1[4][1] -=szerokosc;
    pkt1[4][2] += wysokosc;


/*---------------------------------------*/

    pkt1[5][0] +=dlugosc; 
    pkt1[5][1] +=szerokosc;

    pkt1[6][0] +=dlugosc; 
    pkt1[6][1] -=szerokosc;

    pkt1[7][0] +=dlugosc; 
    pkt1[7][1] -=szerokosc;
    pkt1[7][2] +=wysokosc;
/*--------------------------------------------*/

    pkt1[8][0] -=dlugosc; 
    pkt1[8][1] +=szerokosc;

    pkt1[9][0] +=dlugosc; 
    pkt1[9][1] +=szerokosc;


    pkt1[10][0] +=dlugosc; 
    pkt1[10][1] -=szerokosc;
    pkt1[10][2] +=wysokosc;


    pkt1[11][0] -=dlugosc; 
    pkt1[11][1] -=szerokosc;
    pkt1[11][2] +=wysokosc;

/*--------------------------------------------*/

    pkt1[12][0] -=dlugosc; 
    pkt1[12][1] -=szerokosc;

    pkt1[13][0] -=dlugosc; 
    pkt1[13][1] +=szerokosc;

    pkt1[14][0] -=dlugosc; 
    pkt1[14][1] -=szerokosc;
    pkt1[14][2] +=wysokosc;

/*------------------------------------------*/

    pkt1[15][0] -=dlugosc; 
    pkt1[15][1] -=szerokosc;

    pkt1[16][0] +=dlugosc; 
    pkt1[16][1] -=szerokosc;

    pkt1[17][0] +=dlugosc; 
    pkt1[17][1] -=szerokosc;
    pkt1[17][2] += wysokosc;

    pkt1[18][0] -=dlugosc; 
    pkt1[18][1] -=szerokosc;
    pkt1[18][2] += wysokosc;
/*------------------------------------------*/

     BrylaGeometryczna::srodek=pkt;


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
                         const Gran &Pr)
{

    for (int i = 1; i < 18; i++)
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
    funkcja zwraca srodek grani 
 */
Vector<3> Gran::wez_srodek() 
{
    return srodek;
}

