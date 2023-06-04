#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RS.h"

extern int line, col;
extern Liste_TS1 TS1;
extern int nb_erreurs;


void Erreur_Lexicale(char* entity ,char* msg) {
    printf("erreur lexicale (Ln %d, Col %d): '%s' -> %s.\n",line, col, entity, msg);
    nb_erreurs++;
}


bool Double_Declaration_Entite(char* entity) {
    
    if(Idf_Existe_TS1(entity)) {     
        
        printf("erreur symantique (Ln %d, Col %d): double declaration de l'entite '%s'\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
}

bool Double_Declaration_Structure(char* entity) {
    
    if(Idf_Existe_TS2(entity)) {      
     
        printf("erreur symantique (Ln %d, Col %d): double declaration du type structure '%s'\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
}

bool Double_Declaration_Entite_Structure(Liste_Element_Struct L, char* entity) {
    
    if(Idf_Existe(L, entity)) {
        printf("erreur symantique (Ln %d, Col %d): double declaration de l'attribut '%s'\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Structure_Non_Declare(char* entity) {
    
    if(!Idf_Existe_TS2(entity)) {      
        printf("erreur symantique (Ln %d, Col %d): le type '%s' n'est pas declare\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Entite_Non_Declare(char* entity) {
    
    if(!Idf_Existe_TS1(entity)) {      
        printf("erreur symantique (Ln %d, Col %d): l'entite '%s' n'est pas declaree\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Taille_Negative(char* entity, int taille) {
    
    if(taille < 0) {
        printf("erreur symantique (Ln %d, Col %d): la taille du tableau '%s' est negative\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
} 


bool Est_Une_Constante(char* entity) {

    Liste_TS1 l = Look_Up(entity);
    if(l->nature == 0) {
        printf("erreur symantique (Ln %d, Col %d): l'entite '%s' est une constante\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Division_Par_Zero(bool check) {

    if(check) {
        printf("erreur symantique (Ln %d, Col %d): division par zero\n",line, col);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Est_Un_Tableau(char* entity) {
    Liste_TS1 l = Look_Up(entity);
    if(l->nature != 2) {
        printf("erreur symantique (Ln %d, Col %d): l'entite '%s' n'est pas un tableau\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return false;
    }
    return true;
}

//check
bool Out_Of_Bounds(char* entity, int i) {
    
    Liste_TS1 l = Look_Up(entity);
    int taille = atoi(l->valeur);
    if(i < 0 || i >= taille) {
        printf("erreur symantique (Ln %d, Col %d): '%s[%d]' est hors de l'interval\n",line, col, Traiter_Idf(entity), i);
        nb_erreurs++;
        return true;
    }
    return false;
}


bool Est_Un_Entier(char* entity) {
    
    Liste_TS1 l = Look_Up(entity);
    if(strcmp(l->type, "INTEGER") != 0) {
        printf("erreur symantique (Ln %d, Col %d): l'entite '%s' n'est pas un entier\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        return false;
    }
    return true;
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

//check 
bool Incompatibilite_Types(char* entity) {
   
    if(!compatibility) {
        printf("erreur symantique (Ln %d, Col %d): incompatibilite de type '%s = ........'\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        compatibility = true;
    }
    Depiler_Type();
}

//check 
bool Incompatibilite_Types_Tab(char* entity) {
   
    if(!compatibility) {
        printf("erreur symantique (Ln %d, Col %d): incompatibilite de type '%s[exp] = exp'\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        compatibility = true;
    }
    Depiler_Type();
}


bool Incompatibilite_Types_Index(char* entity) {

    if(!compatibility) {
        printf("erreur symantique (Ln %d, Col %d): indice non valide dans '%s[exp] -> indice doit etre de type entier\n",line, col, Traiter_Idf(entity));
        nb_erreurs++;
        compatibility = true;
    }
    Depiler_Type();

}


char* Traiter_Idf(char* idf) {

    char* s = Allouer_Char(strlen(idf) - 1);
    strncpy(s, idf + 1, strlen(idf));
    return s;
}