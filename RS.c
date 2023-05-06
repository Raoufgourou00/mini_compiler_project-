#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RS.h"

extern int line, col;
extern Liste_TS1 TS1;
extern int nb_erreurs;


bool Double_Declaration_Entite(char* entity) {
    
    if(Idf_Existe_TS1(entity)) {      
        printf("semantic error : line %d, col %d  double declaration de l'entite '%s'\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
}

bool Double_Declaration_Structure(char* entity) {
    
    if(Idf_Existe_TS2(entity)) {      
     
        printf("semantic error : line %d, col %d  double declaration du type structure '%s'\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
}

bool Double_Declaration_Entite_Structure(Liste_Element_Struct L, char* entity) {
    
    if(Idf_Existe(L, entity)) {
        printf("semantic error : line %d, col %d  double declaration de l'attribut '%s'\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Structure_Non_Declare(char* entity) {
    
    if(!Idf_Existe_TS2(entity)) {      
        printf("semantic error : line %d, col %d le type '%s' n'est pas declare\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Entite_Non_Declare(char* entity) {
    
    if(!Idf_Existe_TS1(entity)) {      
        printf("semantic error : line %d, col %d l'entite '%s' n'est pas declare\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Taille_Negative(char* entity, int taille) {
    
    if(taille < 0) {
        printf("semantic error : line %d, col %d la taille du tableau '%s' est negative\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
} 


bool Est_Une_Constante(char* entity) {

    Liste_TS1 l = Look_Up(entity);
    if(l->nature == 0) {
        printf("semantic error : line %d, col %d l'entite '%s' est une constante\n",line, col, entity);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Division_Par_Zero(bool check) {

    if(check) {
        printf("semantic error : line %d, col %d division par zero\n",line, col);
        nb_erreurs++;
        return true;
    }
    return false;
}

bool Est_Un_Tableau(char* entity) {
    Liste_TS1 l = Look_Up(entity);
    if(l->nature != 2) {
        printf("semantic error : line %d, col %d l'entite '%s' n'est pas un tableau\n",line, col, entity);
        nb_erreurs++;
        return false;
    }
    return true;
}

bool Out_Of_Bounds(char* entity, int i) {
    
    Liste_TS1 l = Look_Up(entity);
    int taille = atoi(l->valeur);
    if(i < 0 || i >= taille) {
        printf("semantic error : line %d, col %d '%s[%d]' est hors de l'interval\n",line, col, entity, i);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool compatibility = true;
int cpt_exp = 0; 
// 0 > 1 > 0
int exp_type[2] ;
// 0 => INTEGER  / 1 => FLOAT 
// 1 - 1 or 0 - 0 => same type
// 1 - 0 or 0 - 1 incompatibilité

int Depiler_Type() {
    
    int type = exp_type[cpt_exp - 1];
    cpt_exp--;
    return type;
}

void Empiler_Type(int type) {  
    
    exp_type[cpt_exp] = type;
    cpt_exp = (cpt_exp + 1); 
}

void Traitement_Types() {

    if(cpt_exp == 2) {
        int x1 = Depiler_Type();
        int x2 = Depiler_Type();
        if(x1 != x2) {
            compatibility = false;
        }
        Empiler_Type(x1);
    }
}


bool Incompatibilite_Types(char* entity) {
   
    if(!compatibility) {
        printf("semantic error : line %d, col %d incompatibilite de type '%s = ........'\n",line, col, entity);
        nb_erreurs++;
        compatibility = true;
    }
    Depiler_Type();
}


bool Incompatibilite_Types_Tab(char* entity, char* i) {
   
    if(!compatibility) {
        printf("semantic error : line %d, col %d incompatibilite de type '%s[%s] = ........'\n",line, col, entity, i);
        nb_erreurs++;
        compatibility = true;
    }
    Depiler_Type();
}
