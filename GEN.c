#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GEN.h"
#include "TS.h"
#include "QUAD.h"

extern Liste_QUAD QUAD;
extern Liste_TS1 TS1;
FILE* Code = NULL;
Liste_Etiq ETIQ = NULL;
int etq_quad = 0;

char* Nom_Programme() {

    Liste_TS1 p = TS1;
    while (p != NULL)
    {
        if(p->nature == 99) {
            return p->nom;
        }
        p = p->suivant;
    }
    return "programme";
}

void Generer() {

    char* nom = Nom_Programme();
    char* nom_ext = Allouer_Char(strlen(nom) + 4);
    strcpy(nom_ext, nom);
    strcat(nom_ext, ".asm");

    Code = (FILE*) fopen(nom_ext, "w");
    fprintf(Code,"TITLE %s\n\n", nom_ext);

    Generer_Stack_Segment();
    Generer_Data_Segment();
    Generer_Code_Segment();

    fclose(Code);
}

void Generer_Stack_Segment() {
  
    fprintf(Code, "segment_pile SEGMENT stack\n");
    fprintf(Code, "DW   500 dup (?)\n");
    fprintf(Code, "base_pile EQU 500\n");
    fprintf(Code, "segment_pile ENDS\n\n");
}

void Generer_Data_Segment() {

    fprintf(Code, "DATA segment\n");

    Liste_TS1 p = TS1;
    while (p != NULL) {
        Declarer_Variable(p);
        p = p->suivant;
    }

    //declarer un tableau pour les temporaires
    fprintf(Code, "temporaires DW 500 DUP (?)\n");
    fprintf(Code, "DATA ends\n\n");
}

void Generer_Code_Segment() {

    fprintf(Code, "CODE segment\n");
    fprintf(Code, "start:\n");
    fprintf(Code, "ASSUME CS:CODE, DS:DATA, SS:segment_pile\n");

    fprintf(Code, "MOV AX, DATA\n");
    fprintf(Code, "MOV DS, AX\n");
    fprintf(Code, "MOV AX, segment_pile\n");
    fprintf(Code, "MOV SS, AX\n");
    fprintf(Code, "MOV SP, base_pile\n\n");


    //CODE
    Liste_QUAD q = QUAD;
    while (q != NULL)
    {
        
        fprintf(Code, "%s:\n", Generer_Etiq(etq_quad));
        etq_quad++;

        switch (q->operateur[0])
        {
        case ':': //:=
            Generer_Affectation(q->operande1, q->temporaire);
            break;
        case '+': //+
            Generer_Addition(q->operande1, q->operande2, q->temporaire);
            break;
        case '*': //*
            Generer_Multiplication(q->operande1, q->operande2, q->temporaire);
            break;
        case '/': // /
            Generer_Division(q->operande1, q->operande2, q->temporaire);
            break;
        default:
            //BL || BG || BLE || BGE || BE || BNE || BNZ || BZ || BR
            if(strcmp(q->operateur, "BLE") == 0) {

            }
            break;
        }
        
        q = q->suivant;
    }
    
    fprintf(Code, "\n");
    fprintf(Code, "MOV AH, 4Ch\n");
    fprintf(Code, "INT 21h\n");
    fprintf(Code, "CODE ends\n");
    fprintf(Code, "END start\n\n");

}

void Declarer_Variable(Liste_TS1 l) {


    switch (l->nature)
    {
    case 0: //CONST
        fprintf(Code, "%s EQU %s\n", l->nom, l->valeur);
        break;
    case 1: //VAR SIMPLE
        fprintf(Code, "%s DW ?\n", l->nom);
        break;
    case 2: //TABLEAU
        fprintf(Code, "%s DW %s dup (?)\n", l->nom, l->valeur);
        break;
    default:
        break;
    }
}


void Generer_Affectation(char* op, char* temp) {


    Transformer_Float(op);

    if(strchr(op, '#') != NULL) {
        fprintf(Code, "MOV AX, temporaires[%d]\n", atoi(Get_Num_Temp(op)) * 2);
    }
    else {
        if(strchr(op, '[') != NULL) {
            fprintf(Code, "MOV AX, %s[%d]\n", Get_Nom_Tableau(op), atoi(Get_Index_Tableau(op)) * 2);
        }
        else {
            fprintf(Code, "MOV AX, %s\n", op);
        }
    }


    if(strchr(temp, '#') != NULL) {
        fprintf(Code, "MOV temporaires[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV %s[%d], AX\n", Get_Nom_Tableau(temp), atoi(Get_Index_Tableau(temp)) * 2);
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }
  
}

void Generer_Addition(char* op1, char* op2, char* temp) {

    Transformer_Float(op1);
    Transformer_Float(op2);

    if(strchr(op1, '#') != NULL) {
        fprintf(Code, "MOV AX, temporaires[%d]\n", atoi(Get_Num_Temp(op1)) * 2);
    }
    else {
        if(strchr(op1, '[') != NULL) {
            fprintf(Code, "MOV AX, %s[%d]\n", Get_Nom_Tableau(op1), atoi(Get_Index_Tableau(op1)) * 2);
        }
        else {
            fprintf(Code, "MOV AX, %s\n", op1);
        }
    }

    if(strchr(op2, '#') != NULL) {
        fprintf(Code, "ADD AX, temporaires[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "ADD AX, %s[%d]\n", Get_Nom_Tableau(op2), atoi(Get_Index_Tableau(op2)) * 2);
        }
        else {
            fprintf(Code, "ADD AX, %s\n", op2);
        }
    }

    if(strchr(temp, '#') != NULL) {
        fprintf(Code, "MOV temporaires[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV %s[%d], AX\n", Get_Nom_Tableau(temp), atoi(Get_Index_Tableau(temp)) * 2);
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }
}


void Generer_Soustraction(char* op1, char* op2, char* temp) {

    Transformer_Float(op1);
    Transformer_Float(op2);

    if(strchr(op1, '#') != NULL) {
        fprintf(Code, "MOV AX, temporaires[%d]\n", atoi(Get_Num_Temp(op1)) * 2);
    }
    else {
        if(strchr(op1, '[') != NULL) {
            fprintf(Code, "MOV AX, %s[%d]\n", Get_Nom_Tableau(op1), atoi(Get_Index_Tableau(op1)) * 2);
        }
        else {
            fprintf(Code, "MOV AX, %s\n", op1);
        }
    }

    if(strchr(op2, '#') != NULL) {
        fprintf(Code, "SUB AX, temporaires[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "SUB AX, %s[%d]\n", Get_Nom_Tableau(op2), atoi(Get_Index_Tableau(op2)) * 2);
        }
        else {
            fprintf(Code, "SUB AX, %s\n", op2);
        }
    }

    if(strchr(temp, '#') != NULL) {
        fprintf(Code, "MOV temporaires[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV %s[%d], AX\n", Get_Nom_Tableau(temp), atoi(Get_Index_Tableau(temp)) * 2);
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }
}


void Generer_Multiplication(char* op1, char* op2, char* temp) {

    Transformer_Float(op1);
    Transformer_Float(op2);

    if(strchr(op1, '#') != NULL) {
        fprintf(Code, "MOV AX, temporaires[%d]\n", atoi(Get_Num_Temp(op1)) * 2);
    }
    else {
        if(strchr(op1, '[') != NULL) {
            fprintf(Code, "MOV AX, %s[%d]\n", Get_Nom_Tableau(op1), atoi(Get_Index_Tableau(op1)) * 2);
        }
        else {
            fprintf(Code, "MOV AX, %s\n", op1);
        }
    }

    if(strchr(op2, '#') != NULL) {
        fprintf(Code, "MUL temporaires[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "MUL %s[%d]\n", Get_Nom_Tableau(op2), atoi(Get_Index_Tableau(op2)) * 2);
        }
        else {
            fprintf(Code, "MUL %s\n", op2);
        }
    }

    if(strchr(temp, '#') != NULL) {
        fprintf(Code, "MOV temporaires[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV %s[%d], AX\n", Get_Nom_Tableau(temp), atoi(Get_Index_Tableau(temp)) * 2);
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }
}


void Generer_Division(char* op1, char* op2, char* temp) {

    Transformer_Float(op1);
    Transformer_Float(op2);

    if(strchr(op1, '#') != NULL) {
        fprintf(Code, "MOV AX, temporaires[%d]\n", atoi(Get_Num_Temp(op1)) * 2);
    }
    else {
        if(strchr(op1, '[') != NULL) {
            fprintf(Code, "MOV AX, %s[%d]\n", Get_Nom_Tableau(op1), atoi(Get_Index_Tableau(op1)) * 2);
        }
        else {
            fprintf(Code, "MOV AX, %s\n", op1);
        }
    }

    if(strchr(op2, '#') != NULL) {
        fprintf(Code, "DIV temporaires[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "DIV %s[%d]\n", Get_Nom_Tableau(op2), atoi(Get_Index_Tableau(op2)) * 2);
        }
        else {
            fprintf(Code, "DIV %s\n", op2);
        }
    }

    if(strchr(temp, '#') != NULL) {
        fprintf(Code, "MOV temporaires[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV %s[%d], AX\n", Get_Nom_Tableau(temp), atoi(Get_Index_Tableau(temp)) * 2);
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }
}

char* Get_Num_Temp(char* temp) {
    
    char* num_temp = Allouer_Char(strlen(temp) - 6);
    strncpy(num_temp, temp + 6, strlen(temp) - 1);
    return num_temp;
}

void Transformer_Float(char* op) {
    
    if(strchr(op, '.') != NULL) {
        //is a float number
        float f = atof(op);
        f *= 100; 
        //on prend seulement les 2 premiers chiffres avant la virgule
        int i = (int) f;
        sprintf(op, "%d", i);
    }

}

char* Get_Nom_Tableau(char* op) {

    char* s = op;
    int i = 0;
    while (s[i] != '[') {
        i++;
    }

    char* nom_tab = Allouer_Char(i);
    for (int j = 0; j < i; j++)
    {
        nom_tab[j] = s[j];
    }
    return nom_tab;
}


char* Get_Index_Tableau(char* op) {

    char* s = op;
    int i = 0;
    while (s[i] != '[') {
        i++;
    }

    i++;

    int j = i;
    int cpt = 0;

    while (s[i] != ']')
    {
        cpt++;
        i++;
    }

    char* index_tab = Allouer_Char(cpt);
    for (int k = 0; k < cpt; k++)
    {
        index_tab[k] = s[j + k];
    }
    return index_tab;
}


Liste_Etiq Allouer_Etiq() {

    Liste_Etiq etiq = (Element_Etiq*) malloc(sizeof(Element_Etiq));
    if(etiq == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return etiq;
}
void Ajouter_Etiq(int etiq) {

    if(ETIQ == NULL) {
        ETIQ = Allouer_Etiq();
        ETIQ->num_etiq = etiq;
        ETIQ->suivant = NULL;
    }
    else 
    {
        Liste_Etiq e = ETIQ;
        while (e->suivant != NULL)
        {
            e = e->suivant;
        }
        
        e->suivant = Allouer_Etiq();
        e = e->suivant;
        e->num_etiq = etiq;
        e->suivant = NULL;
    }
}
int Chercher_Etiq(int etiq) {

    Liste_Etiq e = ETIQ;
    while (e != NULL)
    {
        if(e->num_etiq == etiq) {
            return e->num_etiq;
        }
        e = e->suivant;
    }

    return -1;
}

char* Generer_Etiq(int num_etiq) {

    char* etiq = Allouer_Char(10);
    sprintf(etiq, "etiq_%d", num_etiq);
    return etiq;
}