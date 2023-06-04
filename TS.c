#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"


/* --------------------------------------TABLES DES SYNMBOLE 1--------------------------------------- */
// ts1
Liste_TS1 TS1 = NULL;


char* Allouer_Char(int taille) {

    char* s = (char*) malloc(taille * sizeof(char));

    if(s == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return s;
}


Liste_TS1 Allouer_TS1()
{
 
    Liste_TS1 L = (Element_Simple*) malloc(sizeof(Element_Simple));

    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
}


bool Idf_Existe_TS1(char* nom)
{
    Liste_TS1 L = TS1;
    while(L != NULL)
    {
        if(strcmp(L->nom, nom) == 0)
        {
            return true ;
        }
        else
        {
            L = L->suivant ;
        }
    }
    return false ;
}


void Inserer_Element_TS1(char* nom, int nature, char* type, char* valeur)
{   
    if (TS1 == NULL)
    {
        TS1 = Allouer_TS1();
        TS1->nom = Allouer_Char(strlen(nom));
        TS1->type = Allouer_Char(strlen(type));
        TS1->valeur = Allouer_Char(strlen(valeur));
        
        strcpy(TS1->nom, nom);
        strcpy(TS1->type, type);
        strcpy(TS1->valeur, valeur);
        TS1->nature = nature;
    
        TS1->suivant = NULL ;
    }
    else
    {
        Liste_TS1 p = TS1;
        while(p->suivant != NULL)
        {
            p = p->suivant ;
        }

        p->suivant = Allouer_TS1() ;
        p = p->suivant ;

        p->nom = Allouer_Char(strlen(nom));
        p->type = Allouer_Char(strlen(type));
        p->valeur = Allouer_Char(strlen(valeur));
        
        strcpy(p->nom, nom);
        strcpy(p->type, type);
        strcpy(p->valeur, valeur);
        p->nature = nature;
        
        p->suivant = NULL ;
    }
}


void Supprimer_TS1(Liste_TS1 L) {

    if(L == TS1) {
        TS1 = TS1->suivant;
    }
    else {
        
        Liste_TS1 p = TS1;
        while (p->suivant != L)
        {
            p = p->suivant;
        }
        p->suivant = L->suivant;
    }
    free(L);
} 


void MAJ_TS1(char* type) {

    Liste_TS1 L = TS1;
    while (L != NULL)
    {
        if(strcmp(L->type, "#") == 0) {
            

            if(strcmp(type, "INTEGER") == 0 || strcmp(type, "FLOAT") == 0) {
                
                // un type simple: INTEGER  || FLOAT
                L->type = Allouer_Char(strlen(type));
                strcpy(L->type, type);
                L = L->suivant;
            }
            else {
                
                // un type structure
                char* str;
                Liste_Element_Struct E = Get_Table_Attributs_De_Type(type); 
                /*
                    "Liste_Element_Struct E = Get_Table_Attributs_De_Type(type);"

                    cette  instruction vas chercher la ts1 la structure dont le nom == type dans 
                    et retourner sa table d'attributs

                    ensuite pour chaque attribut on fait une concatenation idf_attribut et inserer le resultat dans ts1
                */ 
                while (E != NULL)
                {   
         
                    str = Idf_Point_Idf(L->nom, E->nom);                // concatenation nom_nom pour exprimer nom.nom
                    Inserer_Element_TS1(str, L->nature, E->type, "#");  // inserer nom_nom dans ts1
                    E = E->suivant;
                }
                
                Liste_TS1 p = L;
                L = L->suivant;
                Supprimer_TS1(p);                                       // supprimer l'element dans ts1 qui a une type != INTEGER  || FLOAT
            }        
        }
        else {
            L = L->suivant;
        }
    }
}


char* Get_Idf_Type(char* nom) {

    Liste_TS1 l = TS1;

    while (l != NULL)
    {   
        if (strcmp(l->nom, nom) == 0)
        {
            char* s = Allouer_Char(strlen(l->type));
            strcpy(s, l->type);
            return s;
        }
        l = l->suivant;
    }
}


Liste_TS1 Look_Up(char* nom) {
    
    Liste_TS1 l = TS1;
    while (l != NULL)
    {
        if(strcmp(l->nom, nom) == 0) {
            return l;
        }
        l = l->suivant;
    }
    return NULL;
}

void Afficher_TS1()
{   
    printf("----------------------------Table Des Symboles 1----------------------------\n");
    
    Liste_TS1 L = TS1;
    printf("%12s\t%12s\t%12s\t%s\n\n","IDF" , "NATURE", "TYPE", "VALEUR/TAILLE");
    if(L == NULL) {
        printf("\t\t\t     la ts1-globale est vide\n");
    }
    else {
        while(L != NULL)
        {   
            char* nature = Allouer_Char(10);
            if(L->nature == 0)
            {
                strcpy(nature,"CONSTANTE\0");
            }
            else
            {
                if(L->nature == 1) {
                    strcpy(nature,"VARIABLE\0");
                }
                else
                {
                    if(L->nature == 2) {
                        strcpy(nature,"TABLEAU\0");
                    }
                    else {
                         strcpy(nature,"PROGRAMME\0");
                    }
                }
            }

            printf("%12s\t%12s\t%12s\t%s\n",L->nom, nature, L->type, L->valeur);
            L = L->suivant;
        }
    }
    
    printf("\n");
}


char* Idf_Point_Idf(char* idf1, char* idf2) {
    
    char* nom = Allouer_Char(strlen(idf1) + strlen(idf2) + 2);
    strcpy(nom, idf1);
    strcat(nom, "_");
    strcat(nom, idf2);
    return nom;
}




/* --------------------------------------TABLES DES ATTRIBUTS POUR CHAQUE STRUCT :  --------------------------------------- */

Liste_Element_Struct Allouer() {
    
    Liste_Element_Struct L = (Element_Struct*) malloc(sizeof(Element_Struct)); 
    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
    
}

bool Idf_Existe(Liste_Element_Struct L, char* nom)
{

    while(L != NULL)
    {
        if(strcmp(L->nom, nom) == 0)
        {
            return true ;
        }
        else
        {
            L = L->suivant ;
        }
    }
    return false ;
}


void Inserer_Element(Liste_Element_Struct* L, char* nom, char* type)
{   

    if ((*L) == NULL)
    {
        (*L) = Allouer();
        (*L)->nom = Allouer_Char(strlen(nom));
        (*L)->type = Allouer_Char(strlen(type));

        strcpy((*L)->nom, nom) ;
        strcpy((*L)->type, type) ;
        (*L)->suivant = NULL ;
    }
    else
    {
        Liste_Element_Struct p = (*L);
        while(p->suivant != NULL)
        {
            p = p->suivant ;
        }

        p->suivant = Allouer() ;
        p = p->suivant ;
        p->nom = Allouer_Char(strlen(nom));
        p->type = Allouer_Char(strlen(type));
        strcpy(p->nom, nom) ;
        strcpy(p->type, type) ;
        p->suivant = NULL ;
    }
}


void MAJ_Liste_Element_Struct(Liste_Element_Struct L, char* type) 
{
    while (L != NULL)
    {
        if(strcmp(L->type, "#") == 0) {
            L->type = Allouer_Char(strlen(type)); 
            strcpy(L->type, type);
        }
        L = L->suivant;
    }
}


void Afficher(Liste_Element_Struct L)
{   
    printf("\t-------------- Table Attributs --------------\n");
    
    printf("%20s\t%20s\n\n","IDF" , "TYPE");
    if(L == NULL) {
        printf("\t\tla table des attributs est vide\n");
    }
    else {
        while(L != NULL)
        {   
            printf("%20s\t%20s\n",L->nom, L->type);
            L = L->suivant;
        }
    }
    
    printf("\n");
}



/* --------------------------------------TABLES DES SYNMBOLES 2: les structures --------------------------------------- */
Liste_TS2 TS2 = NULL;

Liste_TS2 Allouer_TS2()
{
 
    Liste_TS2 L = (Structure*) malloc(sizeof(Structure)); 
    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
}



bool Idf_Existe_TS2(char* nom)
{
    Liste_TS2 L = TS2;
    while(L != NULL)
    {
        if(strcmp(L->nom, nom) == 0)
        {
            return true ;
        }
        else
        {
            L = L->suivant ;
        }
    }
    return false ;
}


void Inserer_Element_TS2(char* nom)
{   
   
    if (TS2 == NULL)
    {
        TS2 = Allouer_TS2();
        TS2->nom = Allouer_Char(strlen(nom) + 1);
        strcpy(TS2->nom, nom) ;
        TS2->suivant = NULL ;
    }
    else
    {
        Liste_TS2 p = TS2;
        while(p->suivant != NULL)
        {
            p = p->suivant ;
        }

        p->suivant = Allouer_TS2() ;
        p = p->suivant ;
        p->nom = Allouer_Char(strlen(nom) + 1);
        strcpy(p->nom, nom) ;
        p->suivant = NULL ;
    }
  
}


void MAJ_TS2(char nom[], Liste_Element_Struct L) {

    Liste_TS2 p = TS2;
    while(p != NULL)
    {
        if(strcmp(p->nom, nom) == 0)
        {
            p->Attributs_Struc = L;
            break;
        }
        p = p->suivant;
    }
}



void Afficher_TS2()
{   
    printf("----------------------------Table Des Symboles 2----------------------------\n");
    
    Liste_TS2 L = TS2;
    printf("%12s\n\n","IDF");
    if(L == NULL) {
        printf("\t\t\t  la ts2-structures est vide\n");
    }
    else {
        while(L != NULL)
        {   
            printf("%12s\n\n",L->nom);
            Afficher(L->Attributs_Struc);
            L = L->suivant;
        }
    }
    printf("\n");
}


Liste_Element_Struct Get_Table_Attributs_De_Type(char* nom) {

    Liste_TS2 L = TS2;
    while (L != NULL)
    {
        if(strcmp(L->nom, nom) == 0) {
            return L->Attributs_Struc;
        }
        L = L->suivant;
    }
    return NULL;
}





