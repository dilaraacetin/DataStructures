/**
* @file AVL_Agaci.cpp
* @description Avl Ağaçlarının metotlarının yazıldığı kaynak dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/
#include "AVL_Agaci.hpp"
#include "Yigit.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

AVL_Agaci::AVL_Agaci()
{
    kok = 0;
    yaprakOlmayanDugumler = 0;
}
AVL_Agaci::~AVL_Agaci()
{
}
void AVL_Agaci::avlSil()
{
    avlSil(kok);
}
bool AVL_Agaci::varmi(int veri)
{
    return varmi(veri, kok);
}
void AVL_Agaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek, kok);
}
void AVL_Agaci::sil(int veri)
{
    kok = sil(veri, kok);
}
int AVL_Agaci::yukseklik()
{
    return yukseklik(kok);
}
void AVL_Agaci::postOrder()
{
    postOrder(0);
}
void AVL_Agaci::yazdir()
{
    postOrder(kok);
    cout << endl;
}
bool AVL_Agaci::bosmu()
{
    return bosmu(kok);
}
void AVL_Agaci::yigitaEkle(Yigit& yigit)
{
    yigitaEkle(kok, yigit);
}

int AVL_Agaci::yaprakOlmayanDugumlerToplami()
{
    yaprakOlmayanDugumlerToplami(kok);
    return yaprakOlmayanDugumler;
}

void AVL_Agaci::postOrder(AVL_Dugum* aktif)
{
    if (aktif)
    {

        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout << aktif->veri << "  ";
    }
}

int AVL_Agaci::yukseklik(AVL_Dugum* aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + max(yukseklik(aktifDugum->sol),
            yukseklik(aktifDugum->sag));
    }
    return -1;
}
void AVL_Agaci::avlSil(AVL_Dugum* aktif)
{
    if (aktif != 0)
    {
        avlSil(aktif->sol);
        avlSil(aktif->sag);
        aktif = NULL;
    }
}
bool AVL_Agaci::bosmu(AVL_Dugum* aktif)
{
    if (aktif == NULL)
        return true;
    else
        return false;
}

AVL_Dugum* AVL_Agaci::ekle(int veri, AVL_Dugum* aktifDugum)
{
    if (aktifDugum == 0)
        return new AVL_Dugum(veri);

    else if (aktifDugum->veri < veri)
    {
        aktifDugum->sag = ekle(veri, aktifDugum->sag);
        if (yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 1)
        {
            if (veri > aktifDugum->sag->veri)
                aktifDugum = sagaDondur(aktifDugum);

            else
            {
                aktifDugum->sag = solaDondur(aktifDugum->sag);
                aktifDugum = sagaDondur(aktifDugum);
            }
        }
    }
    else if (aktifDugum->veri > veri)
    {
        aktifDugum->sol = ekle(veri, aktifDugum->sol);
        if (yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1)
        {

            if (veri < aktifDugum->sol->veri)
                aktifDugum = solaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = sagaDondur(aktifDugum->sol);
                aktifDugum = solaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}

AVL_Dugum* AVL_Agaci::solaDondur(AVL_Dugum* buyukEbeveyn)
{
    AVL_Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
AVL_Dugum* AVL_Agaci::sagaDondur(AVL_Dugum* buyukEbeveyn)
{
    AVL_Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
int AVL_Agaci::maxDeger(AVL_Dugum* aktif)
{
    if (aktif->sag)
        return maxDeger(aktif->sag);

    return aktif->veri;
}
bool AVL_Agaci::varmi(int aranan, AVL_Dugum* aktif)
{
    if (!aktif)
        return false;

    if (aktif->veri < aranan)
    {
        return varmi(aranan, aktif->sag);
    }
    else if (aktif->veri > aranan)
    {
        return varmi(aranan, aktif->sol);
    }
    else
    {
        return true;  
    }
}
AVL_Dugum* AVL_Agaci::sil(int veri, AVL_Dugum* aktif)
{
    if (aktif == 0)
        return 0;

    if (veri < aktif->veri)
    {
        aktif->sol = sil(veri, aktif->sol);
    }
    else if (veri > aktif->veri)
    {
        aktif->sag = sil(veri, aktif->sag);
    }
    else//aradığımız düğümü bulduk
    {
        if (aktif->sol == 0 && aktif->sag == 0)
        {
            delete aktif;
            aktif = 0;
        }
        else if (aktif->sol == 0)
        {
            AVL_Dugum* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }
        else if (aktif->sag == 0)
        {
            AVL_Dugum* sil = aktif->sol;
            *aktif = *aktif->sol;
            delete sil;
        }
        else
        {
            aktif->veri = minDeger(aktif->sag);
            sil(aktif->veri, aktif->sag);
        }


    }

    int denge = dengesizlikYonu(aktif);

    if (denge > 1) //sol tarafta dengesizlik
    {
        //sol sol dengesizliği
        if (dengesizlikYonu(aktif->sol) >= 0)
        {
            return sagaDondur(aktif);
        }
        //sol sag durumu
        if (dengesizlikYonu(aktif->sol) < 0)
        {
            aktif->sol = solaDondur(aktif->sol);
            return sagaDondur(aktif);
        }
    }
    else if (denge < -1)//sag tarafta dengesizlik
    {
        //sağ sağ durumu
        if (dengesizlikYonu(aktif->sag) <= 0)
        {
            return solaDondur(aktif);
        }
        //sağ sol durumu
        if (dengesizlikYonu(aktif->sag) > 0)
        {
            aktif->sag = sagaDondur(aktif->sag);
            return solaDondur(aktif);
        }
    }
    return aktif;
}
int AVL_Agaci::minDeger(AVL_Dugum* aktif)
{
    if (aktif->sol)
        return maxDeger(aktif->sol);

    return aktif->veri;
}
void AVL_Agaci::boslukBirak(int adet) {
    int baslangicBosluk = pow(2, adet) - 1;
    for (int i = 0; i < baslangicBosluk; i++)
        cout << "  ";
}
int AVL_Agaci::dengesizlikYonu(AVL_Dugum* aktif)
{
    if (aktif == 0)
        return 0;
    return yukseklik(aktif->sol) - yukseklik(aktif->sag);
}
void AVL_Agaci::yigitaEkle(AVL_Dugum* aktif, Yigit& yigit)
{
    if (aktif == nullptr) return;

    yigitaEkle(aktif->sol, yigit);
    yigitaEkle(aktif->sag, yigit);

    if (aktif->sol == nullptr && aktif->sag == nullptr)
    {
        yigit.ekle(aktif->veri);


    }

}
void AVL_Agaci::yaprakOlmayanDugumlerToplami(AVL_Dugum* aktif)
{
    if (aktif == nullptr) return;

    yaprakOlmayanDugumlerToplami(aktif->sol);
    yaprakOlmayanDugumlerToplami(aktif->sag);

    if (aktif->sol != 0 || aktif->sag != 0)
    {
        yaprakOlmayanDugumler += aktif->veri;
    }

}


