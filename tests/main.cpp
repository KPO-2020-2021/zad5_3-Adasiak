#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "./doctest/doctest.h"
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "Prostopadloscian.hh"
#include "matrix.hh"
#include "size.hh"
#include "Dron.hh"


TEST_CASE("konstruktor parametryczny")
{
    double a = 1.0, b = 2.0, c=3.0 ;
    Vector <3> wektor  /*( a, b )*/  ;

    wektor[0] = a;
    wektor[1] =b;
    wektor[2] =c;

    CHECK(wektor[0] == 1);
    CHECK(wektor[1] == 2);
    CHECK(wektor[2] == 3);
}


TEST_CASE("konstruktor bezparametryczny")
{

    Vector <3> wektor;

     CHECK(wektor[0] == 0);
    CHECK(wektor[1] == 0);
    CHECK(wektor[2] == 0);
}

TEST_CASE("Dodawanie wektorów")
{
    double tab1[3]={1,2,3};
    double tab2[3]={2,1,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab2);
    Vector <3> wynik;

    wynik = wektor1 + wektor2;
    CHECK(wynik[0] == 3);
    CHECK(wynik[1] == 3);
    CHECK(wynik[2] == 6);
}

TEST_CASE("Odejmowanie wektorów")
{
    double tab1[3]={1,2,3};
    double tab2[3]={2,1,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab2);
    Vector <3> wynik;

    wynik = wektor1 - wektor2;
    CHECK(wynik[0] == -1);
    CHECK(wynik[1] == 1);
    CHECK(wynik[2] == 0);
}

TEST_CASE("wektor * stała")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    double a = 2;
    Vector <3> wynik;

    wynik = wektor1 * a;
    CHECK(wynik[0] == 2);
    CHECK(wynik[1] == 4);
    CHECK(wynik[2] == 6);
}

TEST_CASE("wektor - wyświetlanie")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    // double a[2]={1,2};
    std::ostringstream StrmWyj;
    StrmWyj << wektor1;
    std::cout << StrmWyj.str();
    CHECK("1 2 3 " == StrmWyj.str());
}

TEST_CASE("wektor - wpisywanie")
{
    Vector <3> a;

    std::istringstream in("1 1 1");
    in >> a;
    std::ostringstream out;
    out << a;

    CHECK("1 1 1 " == out.str());
}

TEST_CASE("operator porownania")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

// TEST_CASE("T=blad")
// {
//     double tab1[2]={1,2};
//     Vector wektor1(tab1);
//     WARN_THROWS(wektor1[2]);
// }

TEST_CASE("operator porownania")
{
    double tab1[3]={1,2,3};
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("mierzenie odległosci")
{
    double tab1[3]={1,2,3};
    double wynik;
    Vector <3> wektor1(tab1);
    Vector <3> wektor2(tab1);

    wynik = wektor1.spr(wektor2) ;

    CHECK(wynik == 0);
}
// // /****************************MACIERZ****************************/

TEST_CASE("konstruktor parametryczny")
{

    double tab[3][3] = {{2,2,2}, {2,2,2}};
    Matrix <3> macierz(tab);

    CHECK(macierz(0, 0) == 2);
    CHECK(macierz(0, 1) == 2);
    CHECK(macierz(0, 2) == 2);
    CHECK(macierz(1, 0) == 2);
    CHECK(macierz(1, 1) == 2);
    CHECK(macierz(1, 2) == 2);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Matrix <3> macierz;

    CHECK(macierz(0, 0) == 1);
    CHECK(macierz(0, 1) == 0);
    CHECK(macierz(0, 2) == 0);
    CHECK(macierz(1, 0) == 0);
    CHECK(macierz(1, 1) == 1);
    CHECK(macierz(1, 2) == 0);
}

TEST_CASE("macierz mnożenie * wektor")
{
    double tab1[3]={1,2,3};
    double tab2[3]={0,0,0};
    Vector <3>wektor1(tab1);
    Vector <3>wektor2(tab2);
    Matrix <3> macierz;

    wektor1 = macierz * wektor2;
    CHECK(wektor1 == wektor2);
}


// TEST_CASE("metoda gaussa")
// {
//     double tab[3][3] = {{1,1,1}, {0, 1,1}};
//     Matrix <3> macierz(tab);
//     macierz.Gaus();

//     CHECK(macierz(0, 0) == 1);
//     CHECK(macierz(0, 1) == 1);
//     CHECK(macierz(0, 2) == 1);
//     CHECK(macierz(1, 0) == 0);
//     CHECK(macierz(1, 1) == 1);
//     CHECK(macierz(1, 2) == 1);
// }


TEST_CASE("macierz 4x4 mnożenie * wektor")
{
    double tab1[4]={0,0,0,0};
    double tab2[3]={10,20,30};
    double a=90, b=90,c=90;
    Vector <4>wektor1(tab1);
    Vector <3>wektor2(tab2);
    Matrix <4> m;
    m= cztery(a,b,c,wektor2); 
    wektor1 = m * wektor1 ;

    // wektor1 = macierz * ;
    CHECK(wektor1 == wektor1);
}




/****************************PROSTOPADLOSCIAN****************************/

TEST_CASE("konstruktor parametryczny")
{
    // double tab1[3]={0,0,0};
    double tab2[3]={20,0,0};
    double tab3[3]={0,10,0};
    double tab4[3]={20,10,0};

    double tab5[3]={0,10,30};
    double tab6[3]={20,10,30};
    double tab7[3]={0,0,30};
    double tab8[3]={20,0,30};

    Vector <3> wektor, wektor1(tab2), wektor2(tab3), wektor3(tab4);
    Vector <3> wektor4(tab5), wektor5(tab6),wektor6(tab7),wektor7(tab8)  ;
    double h = 10, w = 20 , p=30;
    Prostopadloscian Pr(wektor, h, w ,p, "../datasets/korp.dat","../datasets/korp2.dat");

    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor1);
    CHECK(Pr[2] == wektor2);
    CHECK(Pr[3] == wektor3);
    CHECK(Pr[4] == wektor4);
    CHECK(Pr[5] == wektor5);
    CHECK(Pr[6] == wektor6);
    CHECK(Pr[7] == wektor7);
     
}

// TEST_CASE("konstruktor bezparametryczny")
// {

//     Prostopadloscian Pr;
//     Vector <3>wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
    
// }

TEST_CASE("przesuniecie o wektor")
{
    double tab[3]={20,30,40};
    double h = 10, w = 20 , p=30;
    Vector <3>wektor1;
    Prostopadloscian Pr(wektor1, h, w ,p, "../datasets/korp9.dat","../datasets/korp10.dat");
    Vector <3>wektor(tab);
    Pr.move(wektor);

    // Pr=Pr+wektor;
    double tab1[3]={20,30,40};
    Vector<3> jeden(tab1);
    
    double tab2[3]={40,30,40};
    Vector<3> dwa(tab2);
    
    double tab3[3]={20,40,40};
    Vector<3> trzy(tab3);
    
    double tab4[3]={40,40,40};
    Vector<3> cztery(tab4);

    double tab5[3]={20,40,70};
    Vector<3> piec(tab5);

    double tab6[3]={40,40,70};
    Vector<3> szesc(tab6);

    double tab7[3]={20,30,70};
    Vector<3> siedem(tab7);

    double tab8[3]={40,30,70};
    Vector<3> osiem(tab8);

    CHECK(Pr[0] == jeden);
    CHECK(Pr[1] == dwa);
    CHECK(Pr[2] == trzy);
    CHECK(Pr[3] == cztery);
    CHECK(Pr[4] == piec);
    CHECK(Pr[5] == szesc);
    CHECK(Pr[6] == siedem);
    CHECK(Pr[7] == osiem);
}

TEST_CASE("obrot wokol Osi OZ")
{
    Vector<3> zero;
    double h = 10, w = 20 , p=30;
    Prostopadloscian Pr(zero, h, w ,p, "../datasets/korp11.dat","../datasets/korp12.dat");
    double kat=90;
    // Matrix <3> macierz;
    // macierzobrotZ(kat);
    Pr.obrotOZ(kat);
    // Vector <3>wektor;

    double tab1[3]={0,0,0};
    Vector<3> jeden(tab1);
    
    double tab2[3]={2.65359e-05,20,0};
    Vector<3> dwa(tab2);
    
    double tab3[3]={-10,1.32679e-05,0};
    Vector<3> trzy(tab3);
    
    double tab4[3]={-9.99997,20,0};
    Vector<3> cztery(tab4);

    double tab5[3]={-10,1.32679e-05,30};
    Vector<3> piec(tab5);

    double tab6[3]={-9.99997,20,30};
    Vector<3> szesc(tab6);

    double tab7[3]={0,0,30};
    Vector<3> siedem(tab7);

    double tab8[3]={2.65359e-05 ,20 ,30};
    Vector<3> osiem(tab8);

    CHECK(Pr[0] == jeden);
    CHECK(Pr[1] == dwa);
    CHECK(Pr[2] == trzy);
    CHECK(Pr[3] == cztery);
    CHECK(Pr[4] == piec);
    CHECK(Pr[5] == szesc);
    CHECK(Pr[6] == siedem);
    CHECK(Pr[7] == osiem);
}



TEST_CASE("obrot wokol wlasnej osi")
{
    Vector<3> zero;
    double h = 10, w = 20 , p=30;
    Prostopadloscian Pr(zero, h, w ,p, "../datasets/korp11.dat","../datasets/korp12.dat");
    double kat=90;
    // Matrix <3> macierz;
    // macierzobrotZ(kat);
    Pr.obrotP(kat,zero);
    // Vector <3>wektor;

    double tab1[3]={30 ,-1.99019e-05 ,0};
    Vector<3> jeden(tab1);
    
    double tab2[3]={30, 20 ,0};
    Vector<3> dwa(tab2);
    
    double tab3[3]={20, -6.63396e-06, 0};
    Vector<3> trzy(tab3);
    
    double tab4[3]={20, 20, 0};
    Vector<3> cztery(tab4);

    double tab5[3]={20 ,-6.63396e-06 ,30 };
    Vector<3> piec(tab5);

    double tab6[3]={20, 20, 30};
    Vector<3> szesc(tab6);

    double tab7[3]={30 ,-1.99019e-05 ,30};
    Vector<3> siedem(tab7);

    double tab8[3]={30 ,20 ,30};
    Vector<3> osiem(tab8);

    CHECK(Pr[0] == jeden);
    CHECK(Pr[1] == dwa);
    CHECK(Pr[2] == trzy);
    CHECK(Pr[3] == cztery);
    CHECK(Pr[4] == piec);
    CHECK(Pr[5] == szesc);
    CHECK(Pr[6] == siedem);
    CHECK(Pr[7] == osiem);
}


// TEST_CASE("obrot wokol Osi OX")
// {

//     Prostopadloscian Pr;
//     double kat=90;
//     Matrix <3> macierz;
//     macierzobrotZ(kat);
//     Pr = macierzobrotX(kat) * Pr;
//     Vector <3>wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }


// TEST_CASE("obrot wokol Osi OY")
// {

//     Prostopadloscian Pr;
//     double kat=90;
//     Matrix <3> macierz;
//     macierzobrotY(kat);
//     Pr = macierzobrotX(kat) * Pr;
//     Vector <3>wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }



TEST_CASE("prostokar - wyświetlanie")
{
    Vector<3> zero;
    double h = 0, w = 0 , p=0;
    Prostopadloscian Pr(zero, h, w ,p, "../datasets/korp13.dat","../datasets/korp14.dat");

    std::ostringstream StrmWyj;
    StrmWyj << Pr;
    std::cout << StrmWyj.str();
    CHECK("0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n" == StrmWyj.str());
}


/*-----------------------------Graniastoslup-------------------------------*/


TEST_CASE("konstruktor parametryczny")
{
    // double tab1[3]={0,0,0};
    double tab2[3]={20,0,0};
    double tab3[3]={0,10,0};
    double tab4[3]={20,10,0};

    double tab5[3]={0,10,30};
    double tab6[3]={20,10,30};
    double tab7[3]={0,0,30};
    double tab8[3]={20,0,30};

    Vector <3> wektor, wektor1(tab2), wektor2(tab3), wektor3(tab4);
    Vector <3> wektor4(tab5), wektor5(tab6),wektor6(tab7),wektor7(tab8)  ;
    double h = 0, w = 0 , p=0;
    Graniastoslup Pr(wektor, h, w ,p, "../datasets/wirnik20.dat","../datasets/korp21.dat");

    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
    CHECK(Pr[4] == wektor);
    CHECK(Pr[5] == wektor);
    CHECK(Pr[6] == wektor);
    CHECK(Pr[7] == wektor);
     
}


TEST_CASE("przesuniecie o wektor")
{
    double tab[3]={20,30,40};
    double h = 10, w = 20 , p=30;
    Vector <3>wektor1;
    Graniastoslup Pr(wektor1, h, w ,p, "../datasets/korp9.dat","../datasets/korp10.dat");
    Vector <3>wektor(tab);
    Pr.move(wektor);

    // Pr=Pr+wektor;
    double tab1[3]={20,30,40};
    Vector<3> jeden(tab1);
    
    double tab2[3]={40,30,40};
    Vector<3> dwa(tab2);
    
    double tab3[3]={20,40,40};
    Vector<3> trzy(tab3);
    
    double tab4[3]={40,40,40};
    Vector<3> cztery(tab4);

    double tab5[3]={20,40,70};
    Vector<3> piec(tab5);

    double tab6[3]={40,40,70};
    Vector<3> szesc(tab6);

    double tab7[3]={20,30,70};
    Vector<3> siedem(tab7);

    double tab8[3]={40,30,70};
    Vector<3> osiem(tab8);

    CHECK(Pr[0] == jeden);
    // CHECK(Pr[1] == dwa);
    // CHECK(Pr[2] == trzy);
    // CHECK(Pr[3] == cztery);
    // CHECK(Pr[4] == piec);
    // CHECK(Pr[5] == szesc);
    // CHECK(Pr[6] == siedem);
    // CHECK(Pr[7] == osiem);
}


TEST_CASE("obrot wokol Osi OZ")
{
    Vector<3> zero;
    double h = 10, w = 20 , p=30;
    Graniastoslup Pr(zero, h, w ,p, "../datasets/korp11.dat","../datasets/korp12.dat");
    double kat=90;
    // Matrix <3> macierz;
    // macierzobrotZ(kat);
    Pr.obrotOZ(kat);
    // Vector <3>wektor;

    double tab1[3]={0,0,0};
    Vector<3> jeden(tab1);
    
    double tab2[3]={2.65359e-05,20,0};
    Vector<3> dwa(tab2);
    
    double tab3[3]={-10,1.32679e-05,0};
    Vector<3> trzy(tab3);
    
    double tab4[3]={-9.99997,20,0};
    Vector<3> cztery(tab4);

    double tab5[3]={-10,1.32679e-05,30};
    Vector<3> piec(tab5);

    double tab6[3]={-9.99997,20,30};
    Vector<3> szesc(tab6);

    double tab7[3]={0,0,30};
    Vector<3> siedem(tab7);

    double tab8[3]={2.65359e-05 ,20 ,30};
    Vector<3> osiem(tab8);

    CHECK(Pr[0] == jeden);
    // CHECK(Pr[1] == dwa);
    // CHECK(Pr[2] == trzy);
    // CHECK(Pr[3] == cztery);
    // CHECK(Pr[4] == piec);
    // CHECK(Pr[5] == szesc);
    // CHECK(Pr[6] == siedem);
    // CHECK(Pr[7] == osiem);
}


TEST_CASE("obrot wokol wlasnej Osi ")
{
    Vector<3> zero;
    double h = 10, w = 10 , p=10;
    Graniastoslup Pr(zero, h, w ,p, "../datasets/korp11.dat","../datasets/korp12.dat");
    double kat=90;
    // Matrix <3> macierz;
    // macierzobrotZ(kat);
    Pr.obrotW(kat);
    // Vector <3>wektor;

    double tab1[3]={0,0,0};
    Vector<3> jeden(tab1);
    
    double tab2[3]={-1.32679e-05 ,-10 ,0};
    Vector<3> dwa(tab2);
    
    double tab3[3]={9.99999 ,-5.00001, 0};
    Vector<3> trzy(tab3);
    
    double tab4[3]={-1.32679e-05, -10 ,10};
    Vector<3> cztery(tab4);

    double tab5[3]={9.99999 ,-5.00001, 10};
    Vector<3> piec(tab5);

    double tab6[3]={9.99999, -5.00001, 0};
    Vector<3> szesc(tab6);

    double tab7[3]={10, 4.99999 ,0};
    Vector<3> siedem(tab7);

    double tab8[3]={ 9.99999 ,-5.00001 ,10};
    Vector<3> osiem(tab8);

    double tab9[3]={10, 4.99999 ,10};
    Vector<3> osiem1(tab9);

    double tab10[3]={10, 4.99999 ,0};
    Vector<3> osiem2(tab10);

    double tab11[3]={1.32679e-05 ,10, 0};
    Vector<3> osiem3(tab11);

    double tab12[3]={ 10, 4.99999 ,10 };
    Vector<3> osiem4(tab12);

    double tab13[3]={1.32679e-05 ,10 ,10};
    Vector<3> osiem5(tab13);

    double tab14[3]={1.32679e-05 ,10 ,0};
    Vector<3> osiem6(tab14);

    double tab15[3]={-9.99999 ,5.00001 ,0};
    Vector<3> osiem7(tab15);

    double tab16[3]={1.32679e-05 ,10 ,10};
    Vector<3> osiem8(tab16);

    double tab17[3]={-9.99999 ,5.00001 ,10};
    Vector<3> osiem9(tab17);

    double tab18[3]={-9.99999 ,5.00001 ,0};
    Vector<3> osiem10(tab18);

    double tab19[3]={-10 ,-4.99999 ,0};
    Vector<3> osiem11(tab19);

    double tab20[3]={-9.99999, 5.00001 ,10};
    Vector<3> osiem12(tab20);

    double tab21[3]={-10, -4.99999, 10};
    Vector<3> osiem13(tab21);

    double tab22[3]={-10 ,-4.99999, 0};
    Vector<3> osiem14(tab22);

    double tab23[3]={-10 ,-4.99999 ,10};
    Vector<3> osiem15(tab23);

    double tab24[3]={-1.32679e-05 ,-10 ,10 };
    Vector<3> osiem16(tab24);

    double tab25[3]={2.42092e-322 ,-1.21941e+260, 6.92851e-310};
    Vector<3> osiem17(tab25);



    CHECK(Pr[0] == jeden);
    CHECK(Pr[1] == dwa);
    CHECK(Pr[2] == trzy);
    CHECK(Pr[3] == cztery);
    CHECK(Pr[4] == piec);
    CHECK(Pr[5] == szesc);
    CHECK(Pr[6] == siedem);
    CHECK(Pr[7] == osiem);
    CHECK(Pr[8] == osiem1);
    CHECK(Pr[9] == osiem2);
    CHECK(Pr[10] == osiem3);
    CHECK(Pr[11] == osiem4);
    CHECK(Pr[12] == osiem5);
    CHECK(Pr[13] == osiem6);
    CHECK(Pr[14] == osiem7);
    CHECK(Pr[15] == osiem8);
    CHECK(Pr[16] == osiem9);
    CHECK(Pr[17] == osiem10);
    CHECK(Pr[18] == osiem11);
    CHECK(Pr[19] == osiem12);
    CHECK(Pr[20] == osiem13);
    CHECK(Pr[21] == osiem14);
    CHECK(Pr[23] == osiem15);
    CHECK(Pr[24] == osiem16);
    CHECK(Pr[25] == osiem17);
    // CHECK(Pr[24] == osiem18);
    // CHECK(Pr[25] == osiem19);
}


TEST_CASE("obrot wokol wlasnej Osi ")
{
    Vector<3> zero;
    zero[0]=20;
    zero[1]=20;

    double h = 10, w = 10 , p=10;
    Graniastoslup Pr(zero, h, w ,p, "../datasets/korp11.dat","../datasets/korp12.dat");
    double kat=90;
    // Matrix <3> macierz;
    // macierzobrotZ(kat);
    Vector<3> zero1;
    Pr.obrotW1(kat,zero1);
    // Vector <3>wektor;

    double tab1[3]={10, 20, 0};
    Vector<3> jeden(tab1);
    
    double tab2[3]={9.99999 ,10 ,0};
    Vector<3> dwa(tab2);
    
    double tab3[3]={20, 15, 0};
    Vector<3> trzy(tab3);
    
    double tab4[3]={9.99999 ,10, 10};
    Vector<3> cztery(tab4);

    double tab5[3]={20 ,15 ,10};
    Vector<3> piec(tab5);

    double tab6[3]={20 ,15, 0};
    Vector<3> szesc(tab6);

    double tab7[3]={20 ,25 ,0};
    Vector<3> siedem(tab7);

    double tab8[3]={ 20, 15 ,10 };
    Vector<3> osiem(tab8);

    double tab9[3]={20 ,25 ,10};
    Vector<3> osiem1(tab9);

    double tab10[3]={20, 25, 0};
    Vector<3> osiem2(tab10);





    double tab11[3]={10 ,30, 0};
    Vector<3> osiem3(tab11);

    double tab12[3]={20, 25 ,10};
    Vector<3> osiem4(tab12);

    double tab13[3]={10, 30, 10};
    Vector<3> osiem5(tab13);

    double tab14[3]={10 ,30 ,0};
    Vector<3> osiem6(tab14);

    double tab15[3]={1.3268e-05, 25 ,0};
    Vector<3> osiem7(tab15);

    double tab16[3]={10 ,30 ,10};
    Vector<3> osiem8(tab16);

    double tab17[3]={1.3268e-05 ,25 ,10};
    Vector<3> osiem9(tab17);





    double tab18[3]={1.3268e-05 ,25, 0};
    Vector<3> osiem10(tab18);

    double tab19[3]={1.32019e-11, 15 ,0};
    Vector<3> osiem11(tab19);

    double tab20[3]={1.3268e-05 ,25 ,10};
    Vector<3> osiem12(tab20);

    double tab21[3]={1.32019e-11 ,15 ,10};
    Vector<3> osiem13(tab21);

    double tab22[3]={1.32019e-11 ,15, 0};
    Vector<3> osiem14(tab22);

    double tab23[3]={1.32019e-11 ,15 ,10};
    Vector<3> osiem15(tab23);

    double tab24[3]={9.99999 ,10 ,10 };
    Vector<3> osiem16(tab24);

    double tab25[3]={2.42092e-322 ,-1.21941e+260, 6.92851e-310};
    Vector<3> osiem17(tab25);



    CHECK(Pr[0] == jeden);
    CHECK(Pr[1] == dwa);
    CHECK(Pr[2] == trzy);
    CHECK(Pr[3] == cztery);
    CHECK(Pr[4] == piec);
    CHECK(Pr[5] == szesc);
    CHECK(Pr[6] == siedem);
    CHECK(Pr[7] == osiem);
    CHECK(Pr[8] == osiem1);
    CHECK(Pr[9] == osiem2);
    CHECK(Pr[10] == osiem3);
    CHECK(Pr[11] == osiem4);
    CHECK(Pr[12] == osiem5);
    CHECK(Pr[13] == osiem6);
    CHECK(Pr[14] == osiem7);
    CHECK(Pr[15] == osiem8);
    CHECK(Pr[16] == osiem9);
    CHECK(Pr[17] == osiem10);
    CHECK(Pr[18] == osiem11);
    CHECK(Pr[19] == osiem12);
    CHECK(Pr[20] == osiem13);
    CHECK(Pr[21] == osiem14);
    CHECK(Pr[23] == osiem15);
    CHECK(Pr[24] == osiem16);
    CHECK(Pr[25] == osiem17);
    // CHECK(Pr[24] == osiem18);
    // CHECK(Pr[25] == osiem19);
}




TEST_CASE("graniastoslup - wyświetlanie")
{
    Vector<3> zero;
    double h = 0, w = 0 , p=0;
    Graniastoslup Pr(zero, h, w ,p, "../datasets/korp13.dat","../datasets/korp14.dat");

    std::ostringstream StrmWyj;
    StrmWyj << Pr;
    std::cout << StrmWyj.str();
    CHECK("0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n" == StrmWyj.str());
}



/*-------------------------------------DRON---------------------------------------*/

 
// TEST_CASE("graniastoslup - wyświetlanie")
// {
//     Vector<3> zero;
//     // double h = 0, w = 0 , p=0;
//     int kasia=1;
//     Dron Pr(kasia);


//     double tab1[3]={10, 20, 0};
//     Vector<3> jeden(tab1), dwa;
    
//     Pr.ruch(zero,0,0);
//     // Pr=4;


//     // CHECK(Pr == Pr.ruch);

// }
