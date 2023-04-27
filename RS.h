#ifndef RS_H
#define RS_H
#include "bool.h"
#include "TS.h"

bool Double_Declaration_Entite(char entity[]);
bool Double_Declaration_Structure(char entity[]);
bool Double_Declaration_Entite_Structure(Liste_Element_Struct L, char entity[]);
bool Structure_Non_Declare(char entity[]);
bool Entite_Non_Declare(char entity[]);
bool Taille_Negative(char entity[], int taille);
bool Est_Une_Constante(char nom[]);
bool Division_Par_Zero(bool check);


#endif