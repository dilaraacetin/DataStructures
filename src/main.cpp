/**
* @file main.cpp
* @description Programın ana işlemlerinin yapıldığı main dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "AVL_Agaci.hpp"
#include "Yigit.hpp"

using namespace std;

int main()
{
    ifstream dosya("Veri.txt");
    const int agacSayisi = 500;
    int yigitSayisi = 0;
    int sayi = 0;
    string satir;

    Yigit yigitlar[agacSayisi];
    AVL_Agaci* avlAgaclar[agacSayisi];


    if (dosya.is_open())
    {

        while (getline(dosya, satir))
        {
            avlAgaclar[yigitSayisi] = new AVL_Agaci();

            string sayiStr;
            for (char c : satir)
            {
                if (c == ' ' || c == '\t')
                {
                    if (!sayiStr.empty())
                    {
                        //if(avlAgaclar[satirSayisi]->varmi(sayiStr))
                        avlAgaclar[yigitSayisi]->ekle(stoi(sayiStr));


                        sayiStr.clear();
                    }
                }
                else
                {
                    sayiStr += c;
                }
            }
            if (!sayiStr.empty()) {
                avlAgaclar[yigitSayisi]->ekle(stoi(sayiStr));

            }
            yigitSayisi++;

        }
    }
    else
    {
        cout << "Dosya acilamadi" << endl;
    }

    int ascii[agacSayisi];
    int toplamlar[agacSayisi];
    Yigit geciciler[agacSayisi];
    int enkucuk;
    int enbuyuk;
    int enKucukYigitId = 0;
    int enBuyukYigitId = 0;
    int asciiSayisi=agacSayisi;


    for (int i = 0; i < yigitSayisi; i++)
    {
        avlAgaclar[i]->yigitaEkle(yigitlar[i]);
        avlAgaclar[i]->yigitaEkle(geciciler[i]);

        toplamlar[i] = avlAgaclar[i]->yaprakOlmayanDugumlerToplami();
        ascii[i] = (toplamlar[i] % (26)) + 65;
        cout << char(ascii[i]);

    }

    
while (true) //Yığıtlar üzerinde silme işlemleri yaptığımız döngü
{
    if (yigitSayisi == 1)
    break;

    while (true)
    {

        for (int i = 0; i < yigitSayisi; i++) //En küçük değerin olduğu yığıtı bulma işlemi
        {
            if (i == 0)
            {
                enkucuk = yigitlar[i].getir();
            }
            else
            {
                if (yigitlar[i].getir() < enkucuk)
                {
                    enkucuk = yigitlar[i].getir();
                    enKucukYigitId = i;
                }
            }
        }

        yigitlar[enKucukYigitId].cikar();

        if (yigitlar[enKucukYigitId].bosmu() == true)
        {

            for (int i = enKucukYigitId; i < yigitSayisi - 1; i++)
            {
                while (geciciler[i].bosmu() == false)
                {
                    geciciler[i].cikar();
                }
                    geciciler[i] = geciciler[i+1];
                if(i==yigitSayisi-2)
                {
                    while(geciciler[yigitSayisi-1].bosmu()==false)
                    geciciler[yigitSayisi-1].cikar();
                }
        
            }
            for (int i = enKucukYigitId; i < asciiSayisi - 1; i++) {
                ascii[i] = ascii[i + 1];
            }
            asciiSayisi--;
            for(int i=0;i<asciiSayisi;i++)
            cout<<char(ascii[i]);
            system("cls");
            asciiSayisi--;
            yigitSayisi--;

            for (int i = 0; i < yigitSayisi; i++)
            {
                yigitlar[i] = geciciler[i];
            }
            
            break;   

        }
    
        for (int i = 0; i < yigitSayisi; i++) //En büyük değerin olduğu yığıtı bulma işlemleri
        {
            if (i == 0)
            {
                enbuyuk = yigitlar[i].getir();
            }
            else
            {
                if (yigitlar[i].getir() > enbuyuk)
                {
                    enbuyuk = yigitlar[i].getir();
                    enBuyukYigitId = i;
                }
            }
        }


        yigitlar[enBuyukYigitId].cikar();

        if (yigitlar[enBuyukYigitId].bosmu() == true)
        {
 
            for (int i = enBuyukYigitId; i < yigitSayisi - 1; i++)
            {
                while (geciciler[i].bosmu() == false)
                {
                    geciciler[i].cikar();
                }
                    geciciler[i] = geciciler[i+1];
                if(i==yigitSayisi-2)
                {
                    while(geciciler[yigitSayisi-1].bosmu()==false)
                    geciciler[yigitSayisi-1].cikar();
                }
            }
            for (int i = enKucukYigitId; i < asciiSayisi - 1; i++) {
                ascii[i] = ascii[i + 1];
            }
            asciiSayisi--;
            for(int i=0;i<asciiSayisi;i++)
            cout<<char(ascii[i]);
            system("cls");
            yigitSayisi--;
            for (int i = 0; i < yigitSayisi; i++)
            {
                yigitlar[i] = geciciler[i];
            }
            break;
        }
        
       
    }
    if(asciiSayisi==1)
        break;

}   
   
    dosya.close();
}
   