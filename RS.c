#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RS.h"

extern int line, col;
extern Liste_TS1 TS1;

int cpt_exp = 0; 
// 0 > 1 > 0
int exp_type[2] ;
// 0 => INTEGER  / 1 => FLOAT 
// 1 - 1 or 0 - 0 => same type
// 1 - 0 or 0 - 1 incompatibilité

bool Double_Declaration_Entite(char entity[]) {
    
    if(Idf_Existe_TS1(entity)) {      
        printf("semantic error : line %d, col %d  double declaration de l'entite '%s'\n",line, col, entity);
        return true;
    }
    return false;
}

bool Double_Declaration_Structure(char entity[]) {
    
    if(Idf_Existe_TS2(entity)) {      
        
        
        return true;
    }
    return false;
}

bool Double_Declaration_Entite_Structure(Liste_Element_Struct L, char entity[]) {
    if(Idf_Existe(L, entity)) {
        printf("semantic error : line %d, col %d  double declaration de l'attribut '%s'\n",line, col, entity);
        return true;
    }
    return false;
}


bool Structure_Non_Declare(char entity[]) {
    
    if(!Idf_Existe_TS2(entity)) {      
        printf("semantic error : line %d, col %d le type '%s' n'est pas declare\n",line, col, entity);
        return true;
    }
    return false;
}


bool Entite_Non_Declare(char entity[]) {
    
    if(!Idf_Existe_TS1(entity)) {      
        printf("semantic error : line %d, col %d l'entite '%s' n'est pas declare\n",line, col, entity);
        return true;
    }
    return false;
}


bool Taille_Negative(char entity[], int taille) {
    
    if(taille < 0) {
        printf("semantic error : line %d, col %d la taille du tableau '%s' est negative\n",line, col, entity);
        return true;
    }
    return false;
} 


bool Est_Une_Constante(char nom[]) {

    Liste_TS1 l = TS1;
    while (l != NULL)
    {
        if(strcmp(l->nom, nom) == 0) {
            if(l->nature == 0) {
                printf("semantic error : line %d, col %d l'entite '%s' est une constante\n",line, col, nom);
                return true;
            }
            return false;
        }
        l = l->suivant;
    }
    
}


bool Division_Par_Zero(bool check) {

    if(check) {
        printf("semantic error : line %d, col %d division par zero\n",line, col);
        return true;
    }
    return false;
}


