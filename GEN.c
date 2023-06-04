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
char acc[] = "";



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
  
    fprintf(Code, "PILE SEGMENT STACK\n");
    fprintf(Code, "DW 1000 dup (?)\n");
    fprintf(Code, "base_pile dw ?\n");
    fprintf(Code, "PILE ENDS\n\n");
}

void Generer_Data_Segment() {

    fprintf(Code, "DATA segment\n");

    Liste_TS1 p = TS1;
    while (p != NULL) {
        Declarer_Variable(p);
        p = p->suivant;
    }

    
    fprintf(Code, "DATA ends\n\n");
}

void Generer_Code_Segment() {

    fprintf(Code, "CODE segment\n");
    fprintf(Code, "start:\n");
    fprintf(Code, "ASSUME CS:CODE, DS:DATA, SS:segment_pile\n");

    fprintf(Code, "MOV AX, DATA\n");
    fprintf(Code, "MOV DS, AX\n");
    fprintf(Code, "MOV AX, PILE\n");
    fprintf(Code, "MOV SS, AX\n");
    fprintf(Code, "MOV SP, base_pile\n");
    fprintf(Code, "mov BP, base_pile\n\n");


    //CODE
    char* num_etiq_br = NULL;
    int last_etiq;
    Liste_QUAD q = QUAD;
    while (q != NULL)
    {
        
        fprintf(Code, "%s:\n", Generer_Etiq(q->num));
        switch (q->operateur[0])
        {
        case ':': //:=
            Generer_Affectation(q->operande1, q->temporaire);
            break;
        case '+': //+
            Generer_Addition(q->operande1, q->operande2, q->temporaire);
            break;
        case '-': //-
            Generer_Soustraction(q->operande1, q->operande2, q->temporaire);
            break;
        case '*': //*
            Generer_Multiplication(q->operande1, q->operande2, q->temporaire);
            break;
        case '/': // /
            Generer_Division(q->operande1, q->operande2, q->temporaire);
            break;
        default:
            //BL || BG || BLE || BGE || BE || BNE || BNZ || BZ || BR
            num_etiq_br = Generer_Etiq(atoi(q->operande1)); 

            Transformer_Float(q->operande2);
            Transformer_Float(q->temporaire);

            
            if(strcmp(q->operande2, "") != 0) {
                
                char* vide = Allouer_Char(1);
                strcpy(vide, "\0");
                Get_In_Acc(&q->operande2, &vide);
            }
            if(strcmp(q->operateur, "BR") == 0) {
                fprintf(Code, "JMP %s\n", num_etiq_br);
            }
            else {

                if(strcmp(q->operateur, "BZ") == 0) {

                    fprintf(Code, "AND AX, 1\n" );
                    fprintf(Code, "JZ %s\n", num_etiq_br);
                }
                else
                {
                    if(strcmp(q->operateur, "BNZ") == 0) {
                        fprintf(Code, "OR AX, 0\n");
                        fprintf(Code, "JNZ %s\n", num_etiq_br);
                    }
                    else 
                    {

                        if(q->temporaire[0] == '#') {
                                fprintf(Code, "CMP AX, BP[%d]\n", atoi(Get_Num_Temp(q->temporaire)) * 2);
                        }
                        else {

                            if(strchr(q->temporaire, '[') != NULL) {
                                fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(q->temporaire))) * 2);
                                fprintf(Code, "ADD BX, BX\n");
                                fprintf(Code, "CMP AX, %s[BX]\n", Get_Nom_Tableau(q->temporaire));
                            }
                            else {
                                fprintf(Code, "CMP AX, %s\n", q->temporaire);
                            }
                        }

                        if(strcmp(q->operateur, "BLE") == 0) {

                            fprintf(Code, "JLE %s\n", num_etiq_br);
                        }
                        else {

                            if(strcmp(q->operateur, "BL") == 0) {
                                
                                fprintf(Code, "JL %s\n", num_etiq_br);
                            }
                            else {
                                
                                if(strcmp(q->operateur, "BG") == 0) {
                    
                                    fprintf(Code, "JG %s\n", num_etiq_br);
                                }
                                else {

                                    if(strcmp(q->operateur, "BGE") == 0) {
                                        
                                        fprintf(Code, "JGE %s\n", num_etiq_br);
                                    }
                                    else {
                                        if(strcmp(q->operateur, "BE") == 0) {
                                    
                                            fprintf(Code, "JE %s\n", num_etiq_br);
                                        }
                                        else 
                                        {
                                            fprintf(Code, "JNE %s\n", num_etiq_br);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
            strcpy(acc, "");
            break;
        }
        
        if(q->suivant == NULL) {
            last_etiq = q->num;
        }
        q = q->suivant;
    }
    
    fprintf(Code, "\n");
    fprintf(Code, "etiq_%d:\n", last_etiq + 1);
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


void Get_In_Acc(char** op1, char** op2) {

    Transformer_Float(*op1);
    Transformer_Float(*op2);

    if(strcmp(acc, "") == 0) {

        if(*op1[0] == '#') {
            fprintf(Code, "MOV AX, BP[%d]\n", atoi(Get_Num_Temp(*op1)) * 2);
        }
        else {
            if(strchr(*op1, '[') != NULL) {
                fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(*op1))) * 2);
                fprintf(Code, "ADD BX, BX\n");
                fprintf(Code, "MOV AX, %s[BX]\n", Get_Nom_Tableau(*op1));
            }
            else {
                fprintf(Code, "MOV AX, %s\n", *op1);
            }
        }

        strcpy(acc, *op1);
    }

    if(strcmp(acc, *op2) == 0) {
        //permutation dans le quad
        char* x = *op1;
        *op1 = *op2;
        *op2 = x;
    }
    else 
    {
        if(strcmp(acc, *op1) != 0) {

            if(*op1[0] == '#') {
                fprintf(Code, "MOV AX, BP[%d]\n", atoi(Get_Num_Temp(*op1)) * 2);
            }
            else {
                if(strchr(*op1, '[') != NULL) {
                    fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(*op1))) * 2);
                    fprintf(Code, "ADD BX, BX\n");
                    fprintf(Code, "MOV AX, %s[BX]\n", Get_Nom_Tableau(*op1));
                }
                else {
                    fprintf(Code, "MOV AX, %s\n", *op1);
                }
            }

            strcpy(acc, *op1);
        }
    }
}

void Generer_Affectation(char* op, char* temp) {

    char* vide = Allouer_Char(1);
    strcpy(vide, "\0");
    Get_In_Acc(&op, &vide);
    if(temp[0] == '#') {
        fprintf(Code, "MOV BP[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(temp))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "MOV %s[BX], AX\n", Get_Nom_Tableau(temp));
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }
    
    strcpy(acc, temp);
}


void Generer_Addition(char* op1, char* op2, char* temp) {


    Get_In_Acc(&op1, &op2);

 
    if(op2[0] == '#') {
        fprintf(Code, "ADD AX, BP[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(op2))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "ADD AX, %s[BX]\n", Get_Nom_Tableau(op2));
        }
        else {
            fprintf(Code, "ADD AX, %s\n", op2);
        }
    }

    if(temp[0] == '#') {
        fprintf(Code, "MOV BP[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(temp))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "MOV %s[BX], AX\n", Get_Nom_Tableau(temp));
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }

    strcpy(acc, temp);
}


void Generer_Soustraction(char* op1, char* op2, char* temp) {

    char* vide = Allouer_Char(1);
    strcpy(vide, "\0");
    Get_In_Acc(&op1, &vide);

    if(op2[0] == '#') {
        fprintf(Code, "SUB AX, BP[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(op2))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "SUB AX, %s[BX]\n", Get_Nom_Tableau(op2));
        }
        else {
            fprintf(Code, "SUB AX, %s\n", op2);
        }
    }

    if(temp[0] == '#') {
        fprintf(Code, "MOV BP[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(temp))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "MOV %s[BX], AX\n", Get_Nom_Tableau(temp));
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }

    strcpy(acc, temp);
}


void Generer_Multiplication(char* op1, char* op2, char* temp) {

    Get_In_Acc(&op1, &op2);

    if(op2[0] == '#') {
        fprintf(Code, "MUL BP[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(op2))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "MUL %s[BX]\n", Get_Nom_Tableau(op2));
        }
        else {
            fprintf(Code, "MUL %s\n", op2);
        }
    }

    if(temp[0] == '#') {
        fprintf(Code, "MOV BP[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(temp))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "MOV %s[BX], AX\n", Get_Nom_Tableau(temp));
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }

    strcpy(acc, temp);
}


void Generer_Division(char* op1, char* op2, char* temp) {

    char* vide = Allouer_Char(1);
    strcpy(vide, "\0");
    Get_In_Acc(&op1, &vide);

    if(op2[0] == '#') {
        fprintf(Code, "DIV BP[%d]\n", atoi(Get_Num_Temp(op2)) * 2);
    }
    else {
        if(strchr(op2, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(op2))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "DIV %s[BX]\n", Get_Nom_Tableau(op2));
        }
        else {
            fprintf(Code, "DIV %s\n", op2);
        }
    }

    if(temp[0] == '#') {
        fprintf(Code, "MOV BP[%d], AX\n", atoi(Get_Num_Temp(temp)) * 2);
    }
    else {
        if(strchr(temp, '[') != NULL) {
            fprintf(Code, "MOV BX, BP[%d]\n", atoi(Get_Num_Temp(Get_Index_Tableau(temp))) * 2);
            fprintf(Code, "ADD BX, BX\n");
            fprintf(Code, "MOV %s[BX], AX\n", Get_Nom_Tableau(temp));
        }
        else {
            fprintf(Code, "MOV %s, AX\n", temp);
        }
    }

    strcpy(acc, temp);
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