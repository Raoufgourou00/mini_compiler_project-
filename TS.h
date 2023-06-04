#ifndef TS_H
#define TS_H
#include "bool.h"

// table des symboles 1: pour sauvegarder les cst, les var, les tab, et les variables declarés structure
/*

    exp pour les variables declarés structure:
    si on a la structure 

    STRUCT {

            INTEGER t1;
            FLOAT t2;
        } S;

    et on a cette declaration 

    STRUCT S s1;

    alors on sauvegarde dans la ts1

    s1_t1, et s1_t2

*/
typedef struct Element_Simple
{
    char* nom;      // nom de l'idf
    int nature;     // nature de l'idf:  0 => const; 1 => var_simple; 2 => var_tab;  (99 => nom programme);
    char* type;     // type de l'idf:  INTEGER || FLOAT
    char* valeur;   // pour les cst valeur = valeur, pour les variable = #(vide), pour les tab valeur = taille tab
    struct Element_Simple* suivant;

}Element_Simple , *Liste_TS1;


char* Allouer_Char(int taille);     // allouer un string
Liste_TS1 Allouer_TS1();            // allouer un element dans la ts1
bool Idf_Existe_TS1(char* nom);     // check si un idf exist dans la ts1
void Inserer_Element_TS1(char* nom, int nature, char* type, char* valeur); 
                                    // inserer un element dans la ts1
                                    // la valeur dans le cas d'un tableau c'est sa taille
void Supprimer_TS1(Liste_TS1 L);    // supprimer un element de la ts1
void MAJ_TS1(char* type);           // pour chaque element dans la ts1 tq element.type == '#' faire element.type = type 
char* Get_Idf_Type(char* nom);                  // retourner le type d'un nom idf donné
Liste_TS1 Look_Up(char* nom);                   // chercher un element dans ts1 par son nom: return null si l'element n'existe pas
void Afficher_TS1();                            // afficher la ts1
char* Idf_Point_Idf(char* idf1, char* idf2);    // entrées: idf1, idf2 -> sortie: idf1_idf2 : pour exprimer idf.idf


// la table des attributs d'une structure: chaque structure a une table d'attributs
typedef struct Element_Struct
{
    char* nom;
    char* type;  
    struct Element_Struct* suivant;

}Element_Struct , *Liste_Element_Struct;

Liste_Element_Struct Allouer();                                         // allouer un element attribut
bool Idf_Existe(Liste_Element_Struct L, char* nom);                     // chercher un attribut par son nom dans une liste d'attributs
void Inserer_Element(Liste_Element_Struct* L, char* nom, char* type);   // inserer un attribut dans une liste d'attributs
void MAJ_Liste_Element_Struct(Liste_Element_Struct L, char* type);      // pour chaque attribut d'une liste d'attributs dont attribut.type == "#" faire attribut.type = type
void Afficher(Liste_Element_Struct P);                                  // afficher une liste d'attributs



// table des structures
typedef struct Structure
{
    char* nom;                                    // nom de la structure
    struct Element_Struct* Attributs_Struc;       // un pointeur vers sa table d'attributs (table imbriquée)
    struct Structure* suivant;

}Structure , *Liste_TS2;

Liste_TS2 Allouer_TS2();                           // allouer un element structure 
bool Idf_Existe_TS2(char* nom);                    // chercher un element par son nom dans la ts2
void Inserer_Element_TS2(char* nom);               // ajouter un element dans la ts2
void Afficher_TS2();                               // afficher la ts2
void MAJ_TS2(char* nom, Liste_Element_Struct L);   // associer a chaque structure dont structure.nom == nom sa table d'attributs
Liste_Element_Struct Get_Table_Attributs_De_Type(char* nom);
                                                   // retourner la table des attribut de la structure: structure.nom == nom 

#endif