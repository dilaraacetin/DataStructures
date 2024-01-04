/**
* @file AVL_Agaci.hpp
* @description Avl Ağaçlarının metotlarının yazıldığı başlık dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef AVL_Agaci_hpp
#define AVL_Agaci_hpp
#include<iostream>
#include "AVL_Dugum.hpp"
#include "Yigit.hpp"
using namespace std;

class AVL_Agaci
{
public:
	int yaprakOlmayanDugumler;
	AVL_Agaci();

	~AVL_Agaci();
	bool varmi(int veri);
	void ekle(int veri);
	void sil(int veri);
	//friend ostream& operator<<(ostream& os,AVLAgaci& kuyruk);
	int yukseklik();
	void postOrder();
	void boslukBirak(int adet);
	void yazdir();
	void yigitaEkle(Yigit& yigit);
	int yaprakOlmayanDugumlerToplami();
	void avlSil();
	bool bosmu();
private:
	void avlSil(AVL_Dugum* aktif);
	int dengesizlikYonu(AVL_Dugum* aktif);
	AVL_Dugum* solaDondur(AVL_Dugum* dugum);
	AVL_Dugum* sagaDondur(AVL_Dugum* dugum);
	int minDeger(AVL_Dugum* aktif);
	//void levelOrder();
	void postOrder(AVL_Dugum* index);
	int yukseklik(AVL_Dugum* aktifDugum);
	AVL_Dugum* ekle(int veri, AVL_Dugum* aktifDugum);
	bool varmi(int aranan, AVL_Dugum* aktif);
	AVL_Dugum* sil(int veri, AVL_Dugum* aktif);
	int maxDeger(AVL_Dugum* aktif);
	void yigitaEkle(AVL_Dugum* aktif, Yigit& yigit);
	void yaprakOlmayanDugumlerToplami(AVL_Dugum* aktif);
	bool bosmu(AVL_Dugum* aktif);
	AVL_Dugum* kok;


};

#endif