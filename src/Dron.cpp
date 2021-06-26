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

Vector<3> Dron::wspolrzedne()
{
  Vector<3> pom;
  if (iddrona == 1)
  {
    pom = Dron::droga;
    std::cout << pom << std::endl;
    // return droga;
  }
  if (iddrona == 2)
  {
    pom = Dron::dwojka;
    std::cout << pom << std::endl;
    // return dwojka;
  }
  return pom;
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

void Dron::DodajTrasePrzelotu(double x1, double y1)
{
    // Wektor3D nastepny = kopia.get_srodek();
    Vector<3> nastepny = get_srodek();
    nastepny[2] = 0;
    // if(iddrona==1){
    pkk.resize(3);
    for (int i = 0; i < 3; i++)
    {
        pkk[i] = nastepny;
    }
    
    pkk[1][2]+=120;

    pkk[2][0]+=x1;
    pkk[2][1]+=y1;

    pkk[3][2]=0;

    // nastepny[2] = 0;
    
    // droga_drona.push_back(nastepny);
    // nastepny[2] = 100;
    // droga_drona.push_back(nastepny);
    // nastepny[0] += droga * cos(kat * M_PI / 180);
    // nastepny[1] += droga * sin(kat * M_PI / 180);
    // droga_drona.push_back(nastepny);
    // nastepny[2] = 0;
    // droga_drona.push_back(nastepny);
    // }
    // if(iddrona==2){
    // dwojka.push_back(nastepny);
    // nastepny[2] = 100;
    // droga_drona.push_back(nastepny);
    // nastepny[0] += droga * cos(kat * M_PI / 180);
    // nastepny[1] += droga * sin(kat * M_PI / 180);
    // droga_drona.push_back(nastepny);
    // nastepny[2] = 0;
    // droga_drona.push_back(nastepny);
    // }
    std::fstream plik;

    plik.open("../datasets/droga.dat", std::ios::out);
    for (int i = 0; i < (int)pkk.size(); i++)
    {

        plik << pkk[i] << std::endl;
    }
    plik.close();
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
  srodek_Drona=get_srodek();

  Vector<3> srodek_Obiektu ;
  srodek_Obiektu = p->wez_srodek();


  double l = sqrt(pow(srodek_Drona[0] - srodek_Obiektu[0], 2) + pow(srodek_Drona[1] - srodek_Obiektu[1], 2) + pow(srodek_Drona[2] - srodek_Obiektu[2], 2));

  // std::cout << "l" << srodek_Drona << std::endl;
  // std::cout << "pppppp" << p->wez_promien() << std::endl;

  if (promien + p->wez_promien() >= l)
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
  // DodajTrasePrzelotu(x1,y1);
  double x_dron = 20, y_dron = 20, z_dron = 0;
  int k=1;
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
      for (; z_dron <= 120; z_dron += 2)
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
      bool mpower=false;
for(int i=0;i<k;i++){
      //-------------------------------------
      // Lot do przodu ...
    if(i<1){
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
    else{
          x_dron=20;
          y_dron=20;
          if(iddrona==1){
                z_dron=Dron::droga[2];
          }
          if(iddrona==2){
                z_dron=Dron::dwojka[2];
          }
      int qq;
      std::cout<< "opcje dalszego sterowania dronem po kolizji"<<std::endl;
      std::cout<< "Podaje nowe wspolzedne docelowe  - wybierz 1 "<<std::endl;
      std::cout<< "Autopilot - wybierz 2 "<<std::endl;
      std::cin>>qq;
          
              if(qq==1)
              {
                  double x, y;
                  double q, w;

                  std::cout<< "Podaj nowe wspolrzedne"<<std::endl;
                    double xx, yy;
                    std::cin>>xx;
                    std::cin>>yy;
                    if(iddrona==1){
                      z_dron=Dron::droga[2];
                    }
                    if(iddrona==2){
                      z_dron=Dron::dwojka[2];
                    }

                    Vector<3> wznoszenie;
                    wznoszenie[2] = 2;
                    cout << endl
                        << "Wznoszenie ... " << endl;
                    for (; z_dron <= 120; z_dron += 2)
                    {
                      ruch(wznoszenie, 0, 0);
                      // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron))
                      //     return false;
                      usleep(100000); // 0.1 ms
                      Lacze.Rysuj();
                    }

                    z_dron -= 2;

                                double cc, dd;
                    cc = atan2(yy, xx);
                    // std::cout << c  <<std::endl;
                    dd = cc * 180 / M_PI;
                    // std::cout << d  <<std::endl;

                    cout << "Zmiana orientacji ... " << endl;
                    if (dd > 0)
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
                        dd = dd * (-1);
                        for (int i = 0; i <= d; i += 5)
                        {

                          obrot(-5);

                          usleep(100000);
                          Lacze.Rysuj();
                        }
                    }

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

                  x = (xx - q) / 50;
                  y = (yy - w) / 50;
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
            if(qq==2)
            {
                  double pomz;
                   if(iddrona==1){
                      pomz=Dron::droga[2];
                    }
                    if(iddrona==2){
                      pomz=Dron::dwojka[2];
                    }
                while(pomz>2) 
                {
                      if(iddrona==1){
                          z_dron=Dron::droga[2];
                        }
                        if(iddrona==2){
                          z_dron=Dron::dwojka[2];
                        }

                        x_dron=y_dron=20;

                      Vector<3> wznoszenie;
                      wznoszenie[2] = 2;
                      cout << endl
                          << "Autpilot pracuje ...." << endl;
                      for (; z_dron <= 120; z_dron += 2)
                      {
                        ruch(wznoszenie, 0, 0);
                        // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron))
                        //     return false;
                        usleep(100000); // 0.1 ms
                        Lacze.Rysuj();
                      }

                      z_dron -= 2;

                      double x, y;
                      double q, w;
                      if (iddrona == 1)
                      {
                        q = rand() % -20 + 20;
                        w = rand() % -20 + 20;
                      }
                      if (iddrona == 2)
                      {
                        q = rand() % -20 + 20;
                        w = rand() % -20 + 20;
                      }

                      x =  q / 50;
                      y = w / 50;
                      Vector<3> lot;
                      lot[0] = x;
                      lot[1] = y;
                      // cout << "Lot do przodu ... " << endl;
                      for (; (y_dron <= 50); x_dron += 1, y_dron += 1)
                      {

                        ruch(lot, 0, 0);

                        usleep(100000);
                        Lacze.Rysuj();
                      }
                      x_dron -= 1, y_dron -= 1;

                                    //-------------------------------------
                        // Opadanie ...
                        //
                        Vector<3> opadanie;
                        opadanie[2] = -2;
                        // std::cout << "Opadanie ... " << endl;

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
                              // std::cout << kolizja << std::endl;
                            }
                            a++;
                          }

                          if (kolizja == true)
                          {
                            std::cout << "kolizja " << std::endl;
                            k=k+1;
                            break;
                          }
                          if(kolizja==false){
                          ruch(opadanie, 0, 0);
                          }
                          kolizja = false;

                          usleep(100000); // 0.1 ms
                          Lacze.Rysuj();
                        }
                         if(iddrona==1){
                          pomz=Dron::droga[2];
                        }
                        if(iddrona==2){
                          pomz=Dron::dwojka[2];
                        }
                        
                }
                std::cout<<"Udalo sie wyladowac"<<std::endl;
                mpower=true;
                 if(mpower==true){
                   break;
                 }
            }
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
          // std::cout << kolizja << std::endl;
        }
        a++;
      }

      if (kolizja == true)
      {
        std::cout << "kolizja " << std::endl;
        k=k+1;
        break;
      }
      if(kolizja==false){
      ruch(opadanie, 0, 0);
      }
      kolizja = false;

      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    }
    
    }

    std::cout << "srodekD"<< std::endl;
          }
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
  for (; z_dron <= 120; z_dron += 2)
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



/*!       
    \brief
    get_srodek
    funkcja ustala srodek korpusu drona
*/

Vector<3> Dron::get_srodek()
{
  Vector<3> pom;
  if(iddrona==1){
    pom=korpus->wez_srodek()+Dron::droga;
  }
  if(iddrona==2){
    pom=korpus1->wez_srodek()+Dron::dwojka;
  }
  return pom;
}