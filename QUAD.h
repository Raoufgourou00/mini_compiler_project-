#ifndef QUAD_H
#define QUAD_H
#include "bool.h"

typedef struct Element_Q
{   
    int num;
    char operateur[10];
    char operande1[20];
    char operande2[20];    
    char temporaire[20]; 
    struct Element_Q* suivant;

}Element_Q , *Liste_QUAD;





Liste_QUAD Allouer_QUAD(); 
void Inserer_Element_QUAD(char operateur[], char operande1[], char operande2[], char temporaire[]);
char* Generer_Temp();
//char* Get_Dernier_Temp();
void Afficher_QUAD();

void Affectation_QUAD(char operande1[], char operande2[]);
void Addition_QUAD(char operande1[], char operande2[]);
void Soustraction_QUAD(char operande1[], char operande2[]);
void Division_QUAD(char operande1[], char operande2[]);
void Multiplication_QUAD(char operande1[], char operande2[]);
void Moins_QUAD(char operande[]);
void Plus_QUAD(char operande[]);
void Sup_QUAD();
void Inf_QUAD();
void Sup_Egal_QUAD();
void Inf_Egal_QUAD();
void Egal_Egal_QUAD();
void Non_Egal_QUAD();

void And_QUAD();
void Or_QUAD();
void Not_Quad();

void Routine_If_Apres_Cond();
void Routine_If_Apres_Inst1();
void Routine_If_Apres_Inst2();

void Routine_While_Apres_Inst();
void Routine_While_Apres_Cond();
void Routine_While_Avant_Cond();

void Routine_For_Apres_Init(char* i, char* pas);
void Routine_For_Apres_Cond();
void Routine_For_Apres_Inst();
char* Case_Tab(char* entity, char* i);


typedef struct Element_Pile_Temp
{
    char temp[20];
    struct Element_Pile_Temp* suivant;
    
}Element_Pile_Temp, *PILE_TEMP;


PILE_TEMP Allouer_Pile();
char* Tete_Pile();
void Empiler(char temp[]);
void Depiler(char* temp);
void Afficher_Pile();




typedef struct Element_Pile_QUAD
{
    Liste_QUAD quad;
    struct Element_Pile_QUAD* suivant;
    
}Element_Pile_QUAD, *PILE_QUAD;


PILE_QUAD Allouer_Pile_QUAD();
Liste_QUAD Tete_Pile_QUAD();
void Empiler_QUAD(Liste_QUAD q);
void Depiler_QUAD(Liste_QUAD* q);
void Afficher_Pile_QUAD();


#endif