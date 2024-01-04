/**
* @file Yigit.hpp
* @description Yığıt metotlarının tanımlandığı başlık dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef Yigit_hpp
#define Yigit_hpp
#include<iostream>
using namespace std;

class Yigit
{
public:
	Yigit();
	~Yigit();
	void ekle(int veri);
	void cikar();
    bool bosmu();
    bool dolumu();
	int getir();
	void yazdir();
    friend ostream& operator<<(ostream& os,Yigit& yigit);
private:
	void genislet(int boyut);
	int kapasite;
    int tepe;
	int* veriler;
};

#endif