#ifndef OPTIM_H
#define OPTIM_H
#include "QUAD.h"
#include "bool.h"

typedef struct Element_Temp
{   
    int num;
    char temp[20];  
    char valeur[20]; 
    char operateur[20];
    struct Element_Temp* suivant;

}Element_Temp , *Liste_Temp;

Liste_Temp Allouer_TEMP();
void Inserer_Element_TEMP(char temp[], char valeur[], int num, char operateur[]);
extern Liste_QUAD QUAD;

void Optim();
void EliminExpRed();
void VerifExpRed(Liste_QUAD c, Liste_QUAD p);
void PropagCopies();
void PropagExpress();
void SimplAlg();



#endif