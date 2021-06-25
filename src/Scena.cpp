#include "Scena.hh"


/*!       
    \brief
    konstryktor sceny 
    tworzymy ja za pomoca bazowego punktu tymczasowego wzgledem ktorego dodajemy dlugosc i szerokosc
*/
Scena::Scena(double dlugosc, double szeroksc,double glebokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu){
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    katOX = 0;
    katOY = 0;
    katOZ = 0;
    Vector<3> tmp;
    int m=0;
    k=0;
    for(int i=-dlugosc/2; i<=dlugosc/2; i+=10){
       for(int j=-szeroksc/2; j<=szeroksc/2; j+=10){
                tmp[0]=i;
                tmp[1]=j;
                tmp[2]=glebokosc;
                scr1.push_back(tmp);
                m++;
        }
        k++;
    }
    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)scr1.size(); i++){
        if(i%k==0)
        plik<<endl;
        plik<<scr1[i]<<endl;
    }
    plik.close();
}



/*!       
    \brief
    Funkcja sluzy do zapisu poszczegolnych punktow sceny do pliku
 */
void Scena::zapis()
{
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)scr1.size(); i++)
    {
        if(i%k==0)
        plik<<endl;
        plik<<scr1[i]<<endl;
    }
    plik.close();
}



/*!       
    \brief
    move
    funkcja sluzy do poruszania scena o zadany wektor
 */   
void Scena::move(const Vector<3> &v)
{
    for (int i = 0; i < (int)scr1.size(); i++)
    {
        scr1[i] = macierzobrotZ(katOZ)*(macierzobrotX(katOX)*(scr1[i]))+v;
    }
}


// std::string Scena::get_nazwa() const
// {
//     return nazwa_pliku;
// }


/*!       
    \brief
    add_basic_objects
    funkcja sluzy do dodawania na powierzchnie sceny przeszkody
 */   
void Scena::add_basic_objects(list<std::shared_ptr<Przeszkody> > &p,PzG::LaczeDoGNUPlota &Lacze, Vector<3> place, double xwth, double ywth,int k,int rodzaj)
{   
    Vector<3> pomocniczyprzeszkoda;
       pomocniczyprzeszkoda[0]=-50;
       pomocniczyprzeszkoda[1]=-50;
    if(k==1)
    {
        std::cout<<"madam"<<std::endl;

        // Scena::nr = Scena::nr - 1;
        //  int i = 0;
        // for (std::list<std::shared_ptr<Przeszkody>>::const_iterator a = p.begin(); a != p.end(); a++)
        // {
        //     cout << i << ": " << (*a)->get_nazwa() << endl;
        //     i++;
        // }
        // cout << "podaj numer" << endl;

        // int nr;
        // cin >> nr;
        // std::list<std::shared_ptr<Przeszkody>>::const_iterator a = p.begin();
        // for (int j = 0; j < nr; j++)
        // {

        //     a++;
        // }

        //  std::cout<<"las"<<std::endl;
        //  //Tutaj wywala seg
        // //  int z;
        // //  z=a;
        // //  std::cout<<z<<std::endl;

        // // std::cout<<"maja"<<std::endl;

        // //  std::cout<<(*a)->nazwa()<<std::endl;
        // Lacze.UsunNazwePliku((*a)->nazwa());
        // //  std::cout<<"koleos"<<std::endl;

//najpierw zwolnic pamiec frreeee
        // // Lacze.UsunNazwePliku((*a)->get_nazwa());

        // // std::cout<<"nie wiem"<<std::endl;
        // //Tutaj wywala seg
        // p.erase(a);
        // // std::cout<<"kociak"<<std::endl;





        // std::cout<<"madam"<<std::endl;

        // Scena::nr = Scena::nr - 1;
        // //  int i = 0;
        // cout << "podaj numer" << endl;

        // int nr;
        // cin >> nr;
        // for (std::list<std::shared_ptr<Przeszkody>>::const_iterator a = p.begin(); a != p.end(); a++)
        // {
        //     if(*a < nr)
        //     {
        //         Lacze.UsunNazwePliku((*a)->nazwa());
        //         p.erase(a);       
        //     }
        //     // cout << i << ": " << (*a)->get_nazwa() << endl;
        //     // i++;

        // }
        // cout << "podaj numer" << endl;

        // int nr;
        // cin >> nr;
        // std::list<std::shared_ptr<Przeszkody>>::const_iterator a = p.begin();
        // for (int j = 0; j < nr; j++)
        // {

        //     a++;
        // }

        //  std::cout<<"las"<<std::endl;
        //  std::cout<<(*a)->nazwa()<<std::endl;
        // Lacze.UsunNazwePliku((*a)->nazwa());
    
        // Lacze.UsunNazwePliku((*a)->get_nazwa());

        // std::cout<<"nie wiem"<<std::endl;
        //Tutaj wywala seg
        // p.erase(a);
        

    }
    else
    {
        if(rodzaj==1){
        /*(*p) =*/ p.push_back(make_shared<Ostroslup>(place, xwth,ywth,100,  "../datasets/pyramid_default_sample"+to_string(Scena::nr)+".dat", "../datasets/pyramid_default_final"+to_string(Scena::nr)+".dat"));
        }
        if(rodzaj==2){
        /*(*p) =*/ p.push_back(make_shared<Gran>(place, xwth,ywth,100,  "../datasets/gran_default_sample"+to_string(Scena::nr)+".dat", "../datasets/gran_default_final"+to_string(Scena::nr)+".dat"));
        }
        if(rodzaj==3){
        /*(*p) =*/ p.push_back(make_shared<PPlaskowyz>(place, xwth,ywth,50,  "../datasets/pplaskowyz_default_sample"+to_string(Scena::nr)+".dat", "../datasets/pplaskowyz_default_final"+to_string(Scena::nr)+".dat"));
        }

        Scena::nr = Scena::nr + 1;
        
        for(list<shared_ptr<Przeszkody> >::const_iterator i=p.begin(); i!= p.end(); i++)
        {
                
                (*i)->zapis();
                        Lacze.DodajNazwePliku((*i)->get_nazwa().c_str());
                        
        }
    }
}

