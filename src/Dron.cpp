#include "Dron.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h>
#define PLIK_TRASY_PRZELOTU "..datasets/trasa_przelotu.dat"

/*!       
    \brief
    konstruktor drona
    za jego pomoca mozliwe jest stworzenie 2 roznych dronow 
    tworzenie 1 drona zacznie sie od punktu (0,0,0)
    a 2 od punktu (-100,-100,0)
    do tworzenia konstruncji drona uzyjemy Prostopadlosciana oraz Graniastoslupa6

*/
Dron::Dron(int id)
{
  if (id == 1)
  {
    iddrona = id; 
   // Lacze.ZmienKolor(2);
    korpus = new Prostopadloscian(droga, 30, 30, 20, "../datasets/korp.dat", "../datasets/korp2.dat");
    wirniki[0] = new Graniastoslup((*korpus)[4], 12, 12, 10, "../datasets/wirnik1.dat", "../datasets/wirnik1_2.dat");
    wirniki[1] = new Graniastoslup((*korpus)[5], 12, 12, 10, "../datasets/wirnik2.dat", "../datasets/wirnik2_2.dat");
    wirniki[2] = new Graniastoslup((*korpus)[6], 12, 12, 10, "../datasets/wirnik3.dat", "../datasets/wirnik3_2.dat");
    wirniki[3] = new Graniastoslup((*korpus)[7], 12, 12, 10, "../datasets/wirnik4.dat", "../datasets/wirnik4_2.dat");
    // korpus->ZmienKolor(5);
    // double x,y,z;
    // Vector<3> jeden,dwa,trzy;
    // jeden=(*korpus)[0];
    // dwa=(*korpus)[3];

    // trzy=dwa-jeden;
    // trzy[2]=trzy[2]*2;
    srodekD = ((*korpus)[3] - (*korpus)[0]) / 2;
    // srodekD=srodekD+(korpus[3][1]-korpus[0][1])/2;
    // srodekD=srodekD+korpus[0][2];

    // srodekD=trzy;
  }
  if (id == 2)
  {
    iddrona = id;
    double a = -100, b = -100;
    Dron::dwojka[0] = a;
    Dron::dwojka[1] = b;

    korpus1 = new Prostopadloscian(dwojka, 30, 30, 20, "../datasets/korp3.dat", "../datasets/korp4.dat");
    wirniki1[0] = new Graniastoslup((*korpus1)[4], 12, 12, 10, "../datasets/wirnik1_3.dat", "../datasets/wirnik1_4.dat");
    wirniki1[1] = new Graniastoslup((*korpus1)[5], 12, 12, 10, "../datasets/wirnik2_3.dat", "../datasets/wirnik2_4.dat");
    wirniki1[2] = new Graniastoslup((*korpus1)[6], 12, 12, 10, "../datasets/wirnik3_3.dat", "../datasets/wirnik3_4.dat");
    wirniki1[3] = new Graniastoslup((*korpus1)[7], 12, 12, 10, "../datasets/wirnik4_3.dat", "../datasets/wirnik4_4.dat");
  }
}

/*!       
    \brief
    Funckaj sluzaca do wyswietlania wspolrzednych punktu od ktorego zacynalismy tworzenie drona
*/

void Dron::wspolrzedne()
{
  Vector<3> pom;
  if (iddrona == 1)
  {
    pom = Dron::droga;
    std::cout << pom << std::endl;
  }
  if (iddrona == 2)
  {
    pom = Dron::dwojka;
    std::cout << pom << std::endl;
  }
}

/*!       
    \brief
    Ruch
    funkcja odpowiadajaca za poruszanie sie drona 
    przemieszcza ona wszytskie jego skladowe (korpus oraz wszytskie wirniki)
    w wersji podstawowej oferuje ona jedynie poruszanie sie drona jednakzde jezeli ustawimy odpowiednie katy bedzie ona jednoczenie wykonywala jego obrot

    przy jednoczesnym obrocie rotorow wolol wlasnej osi


*/

void Dron::ruch(Vector<3> droga, double katOZ, double katOY)
{
  if (iddrona == 1)
  {
    wirniki[0]->set_katOZ(katOZ);
    wirniki[0]->obrotW(90);
    wirniki[0]->move(droga);

    wirniki[1]->set_katOZ(katOZ);
    wirniki[1]->obrotW(90);
    wirniki[1]->move(droga);

    wirniki[2]->set_katOZ(katOZ);
    wirniki[2]->obrotW(90);
    wirniki[2]->move(droga);

    wirniki[3]->set_katOZ(katOZ);
    ;
    wirniki[3]->obrotW(90);
    wirniki[3]->move(droga);

    korpus->set_katOZ(katOZ);
    korpus->set_katOY(katOY);
    // korpus->obrotP(1);
    korpus->move(droga);

    wirniki[0]->zapis();
    wirniki[1]->zapis();
    wirniki[2]->zapis();
    wirniki[3]->zapis();

    korpus->zapis();

    Dron::droga = droga + Dron::droga;

    // srodekD=srodekD+droga;

  }

  if (iddrona == 2)
  {
    wirniki1[0]->set_katOZ(katOZ);
    wirniki1[0]->obrotW(90);
    wirniki1[0]->move(droga);

    wirniki1[1]->set_katOZ(katOZ);
    wirniki1[1]->obrotW(90);
    wirniki1[1]->move(droga);

    wirniki1[2]->set_katOZ(katOZ);
    wirniki1[2]->obrotW(90);
    wirniki1[2]->move(droga);

    wirniki1[3]->set_katOZ(katOZ);
    ;
    wirniki1[3]->obrotW(90);
    wirniki1[3]->move(droga);

    korpus1->set_katOZ(katOZ);
    korpus1->set_katOY(katOY);
    // korpus->obrotP(1);
    korpus1->move(droga);

    wirniki1[0]->zapis();
    wirniki1[1]->zapis();
    wirniki1[2]->zapis();
    wirniki1[3]->zapis();

    korpus1->zapis();

    Dron::dwojka = droga + Dron::dwojka;
  }
}

/*!       
    \brief
    Funkcja obrotu drona wokol jego srodka 
    obraca ona rotory wzgledem srodka drona oraz korpus przez co caly dron kreci sie wokol wlasnej osi o zadany kat

    przy jednoczesnym obrocie rotorow wolol wlasnej osi
*/
void Dron::obrot(double kat)
{
  Vector<3> tmp;
  if (iddrona == 1)
  {
    wirniki[0]->obrotW(90);
    wirniki[0]->obrotW1(kat, droga);

    wirniki[1]->obrotW(90);
    wirniki[1]->obrotW1(kat, droga);

    wirniki[2]->obrotW(90);
    wirniki[2]->obrotW1(kat, droga);

    wirniki[3]->obrotW(90);
    wirniki[3]->obrotW1(kat, droga);

    korpus->obrotP(kat, droga);

    wirniki[0]->zapis();
    wirniki[1]->zapis();
    wirniki[2]->zapis();
    wirniki[3]->zapis();

    korpus->zapis();
  }
  if (iddrona == 2)
  {
    wirniki1[0]->obrotW(90);
    wirniki1[0]->obrotW1(kat, dwojka);

    wirniki1[1]->obrotW(90);
    wirniki1[1]->obrotW1(kat, dwojka);

    wirniki1[2]->obrotW(90);
    wirniki1[2]->obrotW1(kat, dwojka);

    wirniki1[3]->obrotW(90);
    wirniki1[3]->obrotW1(kat, dwojka);

    korpus1->obrotP(kat, dwojka);

    wirniki1[0]->zapis();
    wirniki1[1]->zapis();
    wirniki1[2]->zapis();
    wirniki1[3]->zapis();

    korpus1->zapis();
  }
}


std::ostream &operator<<(std::ostream &Strm,
                         /*const*/ Dron &P)
{
  Strm << P << endl;
  return Strm;
}

bool Dron::DodajTrasePrzelotu(PzG::LaczeDoGNUPlota &Lacze, double x2, double y2)
{

  // this->nazwa_pliku = nazwa_pliku;
  // this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;

  ofstream StrmWy(PLIK_TRASY_PRZELOTU);

  if (!StrmWy.is_open())
  {
    cerr << endl
         << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << endl
         << endl;
    return false;
  }

  double a, b;
  if (iddrona == 1)
  {
    a = droga[0] + 15;
    b = droga[1] + 15;
  }
  if (iddrona == 2)
  {
    a = droga[0] + 15;
    b = droga[1] + 15;
  }
  Vector<3> s, d, f, g;
  s[0] = a;
  s[1] = b;

  d = s;
  d[2] = 80;

  f = d;
  f[0] += x2;
  f[1] += y2;

  g = f;
  g[2] = 0;
  StrmWy << s << endl
         << d << endl
         << f << endl
         << g << endl;
  Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU, 1);
  return !StrmWy.fail();
}


/*!       
    \brief
    czy_kolizja 
    Funkcja sprawdza odleglosc miedzy punktem bazowym drona a srodkiem przeszkody 
    jesli dana odlegosc jest mniejsza od pomieni drona oraz przeszkody nastepuje kolizja i zwracana jest wartosc true 
    w przeciwnym razie zwracana jest wartosc false
*/
bool Dron::czy_kolizja(std::shared_ptr<Przeszkody> p)
{

  Vector<3> srodek_Drona;

  if (iddrona == 1)
  {
    srodek_Drona = /*korpus->srodek_prostopadloscianu*/ droga;
  }
  if (iddrona == 2)
  {
    srodek_Drona = /*korpus->srodek_prostopadloscianu*/ dwojka;
  }
  // if()
  Vector<3> srodek_Obiektu ;
  srodek_Obiektu = p->wez_srodek();


  double l = sqrt(pow(srodek_Drona[0] - srodek_Obiektu[0], 2) + pow(srodek_Drona[1] - srodek_Obiektu[1], 2) + pow(srodek_Drona[2] - srodek_Obiektu[2], 2));

  std::cout << "l" << srodek_Obiektu << std::endl;

  if (promien + p->promien() >= l)
  {
    return true;
  }
  return false;
}

/*!       
    \brief
    Animacja lotu drona Ftunkcja odpowiada za powolne wyswietlanie ruchu drona przez co mozemy sledzic na ekranie jego ruch 
    funckja bazuje na operacjach ruchu drona oraz obrotu
    w momecie odadanie drona sprawdzana jest lista na ktorej umieszczone sa przeszkody czy aby nie wystepuje kolizja 

*/

void Dron::AnimacjaLotuDrona(list<std::shared_ptr<Przeszkody>> &p, PzG::LaczeDoGNUPlota &Lacze, double x1, double y1)
{

  double x_dron = 20, y_dron = 20, z_dron = 0;
  // double KatOr_st = 0;

  //-------------------------------------
  // Wznoszenie ...
  //
  // DodajTrasePrzelotu(Lacze,x1,y1);
  // int k=1;
  // int z=0;
  // while(k==1)
  {

    // if(z==0)
    {
      Vector<3> wznoszenie;
      wznoszenie[2] = 2;
      cout << endl
           << "Wznoszenie ... " << endl;
      for (; z_dron <= 100; z_dron += 2)
      {
        ruch(wznoszenie, 0, 0);
        // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron))
        //     return false;
        usleep(100000); // 0.1 ms
        Lacze.Rysuj();
      }

      z_dron -= 2;

      double c, d;
      c = atan2(y1, x1);
      // std::cout << c  <<std::endl;
      d = c * 180 / M_PI;
      // std::cout << d  <<std::endl;

      cout << "Zmiana orientacji ... " << endl;
      if (d > 0)
      {
        for (int i = 0; i <= d; i += 5)
        {

          obrot(5);

          usleep(100000);
          Lacze.Rysuj();
        }
      }
      else
      {
        d = d * (-1);
        for (int i = 0; i <= d; i += 5)
        {

          obrot(-5);

          usleep(100000);
          Lacze.Rysuj();
        }
      }

      // KatOr_st -= 5;

      //-------------------------------------
      // Lot do przodu ...
      //
      double x, y;
      double q, w;
      if (iddrona == 1)
      {
        q = (droga[0] - 15.0);
        w = (droga[1] - 15.0);
      }
      if (iddrona == 2)
      {
        q = (dwojka[0] - 15.0);
        w = (dwojka[1] - 15.0);
      }

      x = (x1 - q) / 50;
      y = (y1 - w) / 50;
      Vector<3> lot;
      lot[0] = x;
      lot[1] = y;
      cout << "Lot do przodu ... " << endl;
      for (; (y_dron <= 50); x_dron += 1, y_dron += 1)
      {

        ruch(lot, 0, 0);

        usleep(100000);
        Lacze.Rysuj();
      }
      x_dron -= 1, y_dron -= 1;
    }

    //-------------------------------------
    // Opadanie ...
    //
    Vector<3> opadanie;
    opadanie[2] = -2;
    std::cout << "Opadanie ... " << endl;

    bool kolizja = false;

    for (; z_dron >= 0; z_dron -= 2)
    {
      auto a = p.cbegin();

      for (unsigned int i = 0; i < p.size(); i++)
      {

        if (czy_kolizja(*a))
        {
          // std::cout << a <<std::endl;
          // std::cout << (*a)->get_nazwa() << endl;
          kolizja = true;
          std::cout << kolizja << std::endl;
        }
        a++;
      }

      if (kolizja == true)
      {
        std::cout << "kolizja " << std::endl;
        break;
      }
      ruch(opadanie, 0, 0);
      kolizja = false;

      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    }
    // srodekD=srodekD+droga;

    // std::cout << "srodekD"<< Dron::srodekD<< std::endl;

    // k=k-1;
    // z-=1;
    // std::cout<< "maselko" <<std::endl;
    //     std::cout<<z<<std::endl;
    // //   return true;
    //       while(z==1)
    //       {
    //                 double zpomocniczy;
    //                 zpomocniczy=z_dron;
    //                   if(z==1){
    //                       Vector<3> wznoszenie;
    //                 wznoszenie[2]=2;
    //                 cout << endl << "Wznoszenie ... " << endl;
    //                 for (; zpomocniczy <= 120; zpomocniczy += 2)
    //                 {
    //                     ruch(wznoszenie,0,0);
    //                   // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron))
    //                   //     return false;
    //                   usleep(100000); // 0.1 ms
    //                   Lacze.Rysuj();
    //                 }
    //                 z_dron=zpomocniczy;
    //                 z_dron -= 2;

    //                 // double c,d;
    //                 // c=atan2(y1,x1);
    //                 // // std::cout << c  <<std::endl;
    //                 // d =c*180/M_PI ;
    //                 // // std::cout << d  <<std::endl;

    //                 // cout << "Zmiana orientacji ... " << endl;
    //                 // if(d>0)
    //                 // {
    //                 //     for ( int i=0; i <= d; i += 5)
    //                 //     {

    //                 //       obrot(5);

    //                 //       usleep(100000);
    //                 //       Lacze.Rysuj();
    //                 //     }
    //                 // }
    //                 // else
    //                 // {
    //                 //   d=d*(-1);
    //                 //   for ( int i=0; i <= d; i += 5)
    //                 //     {

    //                 //       obrot(-5);

    //                 //       usleep(100000);
    //                 //       Lacze.Rysuj();
    //                 //     }
    //                 // }

    //                 // KatOr_st -= 5;

    //                 //-------------------------------------
    //                 // Lot do przodu ...
    //                 //
    //                 double x,y;
    //                 double q,w;
    //                 if(iddrona==1){
    //                   q=20;
    //                   w=20;
    //                 }
    //                 if(iddrona==2)
    //                 {
    //                   q=15;
    //                   w=15;
    //                 }

    //                 x=q/50;
    //                 y=w/50;
    //                 Vector<3> lot;
    //                 lot[0]=x;
    //                 lot[1]=y;
    //                 cout << "Lot do przodu ... " << endl;
    //                 for (int ypom; (ypom<=50) ; x_dron += 1, ypom += 1) {

    //                   ruch(lot,0,0);

    //                   usleep(100000);
    //                   Lacze.Rysuj();
    //                 }
    //                 x_dron -= 1, y_dron -= 1;
    //             }

    //               //-------------------------------------
    //               // Opadanie ...
    //               //
    //                 Vector<3> opadanie;
    //                 opadanie[2]=-2;
    //               cout << "Opadanie ... " << endl;

    //               bool kolizja = false;
    //               for (; z_dron >= 0; z_dron -= 2) {

    //                           for (std::list<std::shared_ptr<Przeszkody>>::const_iterator a = p.begin(); a != p.end(); a++);
    //                         {
    //                           ruch(opadanie,0,0);
    //                           if (!kolizja)
    //                           {
    //                               std::cout << "kolizja " << std::endl;
    //                               // k=k+1;
    //                               z=z+ 1;
    //                               break;
    //                           }
    //                     }

    //                 usleep(100000); // 0.1 ms
    //                 Lacze.Rysuj();
    //               }
    //                 z=z
    //                 -1;

    //       }
  }
}

/*!       
    \brief
    Zwiadu drona Funkcja odpowiada za powolne wyswietlanie ruchu drona przez co mozemy sledzic na ekranie jego ruch 
    funckja bazuje na operacjach ruchu drona oraz obrotu

    przy podaniu promienia lotu dron wzbija sie w powietrze a nastepnie wykonuje lot o zadany promien. 
    kolejno obraca sie wokol wlasnej osi o 90 stopni i zaczyna lot po obwodzie kola.
    Po powrocie drona do miejsca skad zaczynal przelot po okregu nastpeuje kolejny obrot o 90 stopni wolku jego wlasnej osi a nastepnie powrot do punktu skad zaczynal przelot.
    

*/
void Dron::zwiad2(PzG::LaczeDoGNUPlota &Lacze, double promien)
{

  Vector<3> kolejnypom;
  if (iddrona == 1)
  {
    kolejnypom = droga;
  }
  if (iddrona == 2)
  {
    kolejnypom = dwojka;
  }

  double x_dron = 20, y_dron = 20, z_dron = 0;
  double KatOr_st = 0;

  //-------------------------------------
  // Wznoszenie ...
  //
  Vector<3> wznoszenie;
  wznoszenie[2] = 2;
  cout << endl
       << "Wznoszenie ... " << endl;
  for (; z_dron <= 80; z_dron += 2)
  {
    ruch(wznoszenie, 0, 0);

    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }

  z_dron -= 2;

  // double katobr;
  // katobr = atan2(y1,x1) ;
  cout << "Zmiana orientacji ... " << endl;
  for (; KatOr_st <= 45; KatOr_st += 5)
  {

    obrot(5);

    usleep(100000);
    Lacze.Rysuj();
  }
  KatOr_st -= 5;

  //-------------------------------------
  // Lot do przodu ...
  //
  double x, y;
  double a, b;
  if (iddrona == 1)
  {
    a = (droga[0] - 15.0);
    b = (droga[1] - 15.0);
  }
  if (iddrona == 2)
  {
    a = (droga[0] - 15.0);
    b = (droga[1] - 15.0);
  }
  x = (promien - a) / 50;
  y = (promien - b) / 50;
  Vector<3> lot;
  lot[0] = x;
  lot[1] = y;
  cout << "Lot do przodu ... " << endl;
  for (; /*(x_dron <= 100)&&*/ (y_dron <= 50); x_dron += 1, y_dron += 1)
  {

    ruch(lot, 0, 0);

    usleep(100000);
    Lacze.Rysuj();
  }
  x_dron -= 1, y_dron -= 1;

  // Dron::droga[0]=promien;
  // Dron::droga[1]=promien;

  cout << droga << endl;
  cout << "Zmiana orientacji ... 1 " << endl;
  for (int j = 0; j <= 90; j += 5)
  {

    obrot(5);

    usleep(100000);
    Lacze.Rysuj();
  }

  Vector<3> pomocniczy;
  if (iddrona == 1)
  {
    pomocniczy = droga;
  }
  if (iddrona == 2)
  {
    pomocniczy = dwojka;
  }

  // KatOr_st -= 5;

  cout << "Zwiad...." << endl;

  if (iddrona == 1)
  {
    Dron::droga[0] = kolejnypom[0] - 10;
    Dron::droga[1] = kolejnypom[1] - 10;
    // cout<<droga<<endl;
  }
  if (iddrona == 2)
  {
    // cout<<kolejnypom<<endl;
    dwojka[0] = kolejnypom[0] - 10;
    dwojka[1] = kolejnypom[1] - 10;
    // cout<<dwojka<<endl;
  }

  for (int i = 0; i <= 180; i++)
  {
    obrot(2);

    usleep(100000);
    Lacze.Rysuj();
  }

  if (iddrona == 1)
  {
    Dron::droga[0] = pomocniczy[0];
    Dron::droga[1] = pomocniczy[1];
  }
  if (iddrona == 2)
  {
    Dron::dwojka[0] = pomocniczy[0];
    Dron::dwojka[1] = pomocniczy[1];
  }

  cout << droga << endl;
  cout << "Zmiana orientacji ... 1 " << endl;
  for (int k = 0; k <= 90; k += 5)
  {

    obrot(5);

    usleep(100000);
    Lacze.Rysuj();
  }

  // KatOr_st -= 5;

  cout << "Powrót...." << endl;
  Vector<3> powrot;
  powrot[0] = -(promien - 10) / 50;
  powrot[1] = -(promien - 10) / 50;
  for (int l = 0; l <= 50; l++)
  {

    ruch(powrot, 0, 0);

    usleep(100000);
    Lacze.Rysuj();
  }
  // x_dron -= 1, y_dron -= 1;

  //-------------------------------------
  // Opadanie ...
  //
  Vector<3> opadanie;
  opadanie[2] = -2;
  cout << "Opadanie ... " << endl;
  for (; z_dron >= 0; z_dron -= 2)
  {

    ruch(opadanie, 0, 0);

    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }

  //   return true;
}