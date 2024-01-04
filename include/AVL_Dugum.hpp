/**
* @file AVL_Dugum.hpp
* @description Avl Ağaçlarının düğümlerinin metotlarının tanımlandığı başlık dosyası
* @course 2. Öğretim B grubu
* @assignment 2
* @date 23.12.2023
* @author Dilara Çetin  dilara.cetin2@ogr.sakarya.edu.tr
*/
#ifndef AVL_Dugum_hpp
#define AVL_Dugum_hpp

class AVL_Dugum
{
public:
    AVL_Dugum(int veri);
    int veri;
    AVL_Dugum* sol;
    AVL_Dugum* sag;
};

#endif