/**
* @file Yigit.cpp
* @description yigit metotlarının yazıldığı kaynak dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/
#include "Yigit.hpp"
#include <iomanip>
Yigit::Yigit()
{
    tepe = -1;
    veriler=0;
    kapasite = 5;
    genislet(kapasite);
}
Yigit::~Yigit()
{
    delete[] veriler;
}
bool Yigit::bosmu()
{
    if(tepe==-1)
        return true;
    return false;
}
bool Yigit::dolumu()
{
    if(tepe==kapasite-1)
        return true;
    return false;
}
void Yigit::ekle(int veri)
{
    if(tepe==kapasite-1)
        genislet(kapasite);

    tepe++;
    veriler[tepe]=veri;
}
void Yigit::cikar()
{
    if(tepe!=-1)
    {
        tepe--;
    }
}
int Yigit::getir()
{
    if(tepe!=-1)
        return veriler[tepe];
    throw std::out_of_range("Yigit Bos");
}
void Yigit::yazdir()
{
    if(bosmu())
    {
        cout<<"Yigit bos"<<endl;
        return;
    }

    cout<<"Yigit Uyeleri:";
    while(!bosmu())
    {
        cout<<getir()<<" ";
        cikar();
    }
    cout<<endl;
}

void Yigit::genislet(int boyut)
{
    int *yeniAlan = new int[boyut+kapasite];
    for(int i=0;i<=tepe;i++)
    {
        
         yeniAlan[i] = veriler[i];   
        
    }
    if(veriler)
        delete[] veriler;
    veriler = yeniAlan;
    kapasite += boyut;
   
}
/*
ostream& operator<<(ostream& os,Yigit& yigit)
{
    os<<setw(5)<<"---->";
    for(int i=0;i<=yigit.tepe;i++)
    {
        os<<yigit.veriler[yigit.tepe-i]<<endl;
        os<<setw(5)<<"    ";     
    }
    cout<<endl;
    return os;
}
*/
