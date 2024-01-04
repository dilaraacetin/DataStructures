/**
* @file AVL_Dugum.cpp
* @description Avl Ağaçlarının düğümlerinin metotlarının yazıldığı kaynak dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/
#include "AVL_Dugum.hpp"

AVL_Dugum::AVL_Dugum(int veri)
{
    this->veri = veri;
    sol=sag=0;
}