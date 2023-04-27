#ifndef TS_H
#define TS_H
#include "bool.h"

typedef struct Element_Simple
{
    char nom[20] ;
    int nature ;  // 0 => const; 1 => var_simple; 2 => var_tab;
    char type[20];     // INTEGER or FLOAT or Struct idf
    char valeur[20]; 
    struct Element_Simple* suivant;

}Element_Simple , *Liste_TS1;


Liste_TS1 Allouer_TS1();            //Allocation de la table des symbiles 1
bool Idf_Existe_TS1(char nom[]);    //check if idf exists in ts
void Inserer_Element_TS1(char nom[] , int nature, char type[], char valeur[]); //la valeur dans le cas d'un tableau c'est sa taille
void MAJ_TS1(char type[]);          //mis a jour types
void Afficher_TS1();
char* Get_Idf_Type(char nom[]);
char* Idf_Point_Idf(char idf1[], char idf2[]);

typedef struct Element_Struct
{
    char nom[10] ;
    char type[10];  
    struct Element_Struct* suivant;

}Element_Struct , *Liste_Element_Struct;

Liste_Element_Struct Allouer();
bool Idf_Existe(Liste_Element_Struct L, char nom[]);
void Inserer_Element(Liste_Element_Struct* L, char nom[], char type[]);
void MAJ_Liste_Element_Struct(Liste_Element_Struct L, char type[]);
void Afficher(Liste_Element_Struct P);



typedef struct Structure
{
    char nom[10] ;
    struct Element_Struct* Attributs_Struc; 
    struct Structure* suivant;

}Structure , *Liste_TS2;

Liste_TS2 Allouer_TS2();
bool Idf_Existe_TS2(char nom[]);
void Inserer_Element_TS2(char nom[]);
void Afficher_TS2();
void MAJ_TS2(char nom[], Liste_Element_Struct L);
Liste_Element_Struct Get_Table_Attributs_De_Type(char nom[]);

#endif