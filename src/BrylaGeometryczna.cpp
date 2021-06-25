#include "BrylaGeometryczna.hh"



/*!       
    \brief
    set_srodek
    funkcja odpowiada za pobranie srodka byryly geometrycznej i zapisanie jej w odpowiedniej zmiennej 
 */
void BrylaGeometryczna::set_srodek(Vector<3> srodek)
{
    this->srodek = srodek;
}


/*!       
    \brief
    wez_srodek
    funkcja zwraca srodek bryly geometryczneij 
 */
Vector<3> BrylaGeometryczna::wez_srodek() 
{
    return srodek;
}


/*!       
    \brief
    get_nazwa
    funkcja zwraca nazwe pliku bryly geometryczneij 
 */
std::string BrylaGeometryczna::get_nazwa() const
{
    return nazwa_pliku;
}
/*!       
    \brief
    czy_kolizja
    funkcja sprawdza odleglosc pomiedzy srodkiem bryly geometrycznej oraz srodkiem przeszkody
    jesli odleglosc miedzy bryla a przeszkoda jest mniejsza od promieni bryly oraz przeszkody nastepuje kolizja a funkcja zwraca wartosc prawdziwa
    w przeciwnym przypadku zwraca wartosc false 
 */
bool BrylaGeometryczna::czy_kolizja(std::shared_ptr<Przeszkody> &ob)
{
    std::shared_ptr<BrylaGeometryczna> self = shared_from_this();

    if (ob != self)
    {

        Vector<3> srodek_Bryla= wez_srodek();
        Vector<3> srodek_Obiektu = ob->wez_srodek();
        double l = sqrt(pow(srodek_Bryla[0] - srodek_Obiektu[0], 2) + pow(srodek_Bryla[1] - srodek_Obiektu[1], 2) + pow(srodek_Bryla[2] - srodek_Obiektu[2], 2));
        if (promien() + ob->promien() >= l)
        {
            return true;
        }
    }
    return false;
}


/*!       
    \brief
    move
    opdopwiada za translacje poszczegolnych punktow o zadany wektor
    w przypadku ustawienia wczesnijszego katow dla bryly posiada mozliwosc jednoczesnego obrotu
 */
void BrylaGeometryczna::move(const Vector<3> &v)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = macierzobrotZ(katOZ)*(macierzobrotX(katOX)*(pkt1[i]))+v;
    }
}

/*!       
    \brief
    Funkcja sluzy do obrotu bryly wzgledem srodka ukladu wsplrzednych
 */

void BrylaGeometryczna::obrotOZ(double kat)
{
    
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] ))) ;
    }
}



/*!       
    \brief
    Funkcja sluzy do obrotu Prostopadloscianu wzgledem jego srodka

        kazdy punkt przesuwamy tak aby srodek prostopadloscian znajdowal sie w srodku ukladu wspolrzednych a nastepnie wykoujemy rotacje przez co otrzymujemy obrocona obyle wzgledem jej srodka 
 */

void BrylaGeometryczna::obrotP(double kat, Vector<3> a)
{
    Vector<3> tmp;
    tmp[0]=0;
    tmp[1]=0;
    tmp[2]=0;
    double q=15,w=15;
    // q = 
    tmp[0] = (q + a[0]) /*+tmp*/ ;
    tmp[1] = (w + a[1]) /*+tmp*/; 
    

    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}



/*!       
    \brief
    Funkcja sluzy do obrotu Graniastoslupa wzgledem jego srodka

    kazdy punkt przesuwamy tak aby srodek graniastoslupa znajdowal sie w srodku ukladu wspolrzednych a nastepnie wykoujemy rotacje przez co otrzymujemy obrocona obyle wzgledem jej srodka 
 */

void BrylaGeometryczna::obrotW(double kat)
{
    Vector<3> tmp;
    tmp= pkt1[0];
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}


void BrylaGeometryczna::obrotW1(double kat,Vector<3> b)
{
    
    double z=15;
    Vector<3> tmp;
    tmp[0]=0;
    tmp[1]=0;
    tmp[2]=0;
    tmp[0] = (z + b[0]) /*+tmp*/ ;
    tmp[1] = (z + b[1]) /*+tmp*/; 
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}



/*!       
    \brief
    Funkcja sluzy do zapisu bryly geometrycznej
    zapisujemy kolejno wspolzedne kazdego z jej punktow
    
*/
void BrylaGeometryczna::zapis(){
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)pkt1.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<pkt1[i]<<endl;//robie enter co 2 linie
    }
    plik.close();
}
