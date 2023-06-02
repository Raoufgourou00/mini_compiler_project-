#ifndef GEN_H
#define GEN_H
#include "TS.h"

char* Nom_Programme();
void Generer();
void Generer_Data_Segment();
void Generer_Code_Segment();
void Generer_Stack_Segment();

void Declarer_Variable(Liste_TS1 l);

void Get_In_Acc(char** op1, char** op2);
void Generer_Affectation(char* op, char* temp);
void Generer_Addition(char* op1, char* op2, char* temp);
void Generer_Soustraction(char* op1, char* op2, char* temp);
void Generer_Multiplication(char* op1, char* op2, char* temp);
void Generer_Division(char* op1, char* op2, char* temp);

char* Get_Num_Temp(char* temp);
void Transformer_Float(char* op);
char* Get_Nom_Tableau(char* op);
char* Get_Index_Tableau(char* op);

typedef struct Element_Etiq
{
    int num_etiq;
    struct Element_Etiq* suivant;
    
}Element_Etiq, *Liste_Etiq;

Liste_Etiq Allouer_Etiq();
void Ajouter_Etiq(int etiq);
int Chercher_Etiq(int etiq);

char* Generer_Etiq(int num_etiq);


#endif