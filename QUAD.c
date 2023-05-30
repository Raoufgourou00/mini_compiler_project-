#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QUAD.h"
#include "TS.h"
#include "RS.h"

int num_temp = 0;
int num_quad = 0;
Liste_QUAD QUAD = NULL;
Liste_QUAD dernier_quad = NULL;
PILE_TEMP PILE = NULL;
PILE_QUAD PILE_Q = NULL;

Liste_QUAD Allouer_QUAD() {
    
    Liste_QUAD L = (Element_Q*) malloc(sizeof(Element_Q));

    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
}


void Inserer_Element_QUAD(char operateur[], char operande1[], char operande2[], char temporaire[]) {

    if (QUAD == NULL)
    {
        QUAD = Allouer_QUAD();
        QUAD->num = num_quad;
        strcpy(QUAD->operateur, operateur);
        strcpy(QUAD->operande1, operande1);
        strcpy(QUAD->operande2, operande2);
        strcpy(QUAD->temporaire, temporaire);
        QUAD->suivant = NULL ;
        dernier_quad = QUAD;
    }
    else
    {
        Liste_QUAD p = dernier_quad;

        p->suivant = Allouer_QUAD() ;
        p = p->suivant ;
        p->num = num_quad;
        strcpy(p->operateur, operateur);
        strcpy(p->operande1, operande1);
        strcpy(p->operande2, operande2);
        strcpy(p->temporaire, temporaire);
        p->suivant = NULL ;
        dernier_quad = p;
    }
    num_quad++;
}


char* Generer_Temp() {

    char* temp = (char*) malloc(sizeof(char) * 50);
    sprintf(temp, "temp_%d", num_temp);
    num_temp++;
    return temp;
}

char* Get_Dernier_Temp() {
    return dernier_quad->temporaire;
}

void Afficher_QUAD() {

    printf("----------------------------Table Des Quadruplets ----------------------------\n");
    
    Liste_QUAD L = QUAD;
    printf("%12s\t%12s\t%12s\t%12s\t%s\n\n","NUM", "OPERATEUR" , "OPERANDE1", "OPERANDE2", "TEMPORAIRE");
    if(L == NULL) {
        printf("\t\t\t     La table est vide\n");
    }
    else {
        while(L != NULL)
        {   
            
            printf("%12d\t%12s\t%12s\t%12s\t%s\n",L->num ,L->operateur, L->operande1, L->operande2, L->temporaire);
            L = L->suivant;
        }
    }
    
    printf("\n");
}



void Affectation_QUAD(char operande1[], char operande2[]) {
    
    if(strcmp(operande1, "") == 0) {
        char* temporaire = Generer_Temp();
        Inserer_Element_QUAD(":=", operande2, "", temporaire);
        Empiler(temporaire);
    }
    else {
        if(strcmp(operande2, "") == 0) {
            char op2[50];
            Depiler(op2);
            Inserer_Element_QUAD(":=", op2, "", operande1);
        }
        else {
            Inserer_Element_QUAD(":=", operande2, "", operande1);
        }
        
    }
     
}

void Addition_QUAD(char operande1[], char operande2[]) {
    
    char* temporaire = Generer_Temp();
    if(strcmp(operande1, "") == 0 && strcmp(operande2, "") == 0) {
        char op1[50], op2[50];
        Depiler(op2);
        Depiler(op1);
        Inserer_Element_QUAD("+", op1, op2, temporaire);
    } 
    else {
        Inserer_Element_QUAD("+", operande1, operande2, temporaire);
    }
    Empiler(temporaire);
    
}
void Soustraction_QUAD(char operande1[], char operande2[]) {
    char* temporaire = Generer_Temp();
    if(strcmp(operande1, "") == 0 && strcmp(operande2, "") == 0) {
        char op1[50], op2[50];
        Depiler(op2);
        Depiler(op1);
        Inserer_Element_QUAD("-", op1, op2, temporaire);
    } 
    else {
        Inserer_Element_QUAD("-", operande1, operande2, temporaire);
    }
    Empiler(temporaire);
}

void Moins_QUAD(char operande[]) {
    char* temporaire = Generer_Temp();
    
    if(strcmp(operande, "") == 0) {
        char op[50];
        Depiler(op);
        Inserer_Element_QUAD("-", "0", op, temporaire);
    } 
    else {
        Inserer_Element_QUAD("-", "0", operande, temporaire);
    }
    Empiler(temporaire);
}

void Plus_QUAD(char operande[]) {
    char* temporaire = Generer_Temp();
    
    if(strcmp(operande, "") == 0) {
        char op[50];
        Depiler(op);
        Inserer_Element_QUAD("+", "0", op, temporaire);
    } 
    else {
        Inserer_Element_QUAD("+", "0", operande, temporaire);
    }
    Empiler(temporaire);
}

void Division_QUAD(char operande1[], char operande2[]) {
    
    char* temporaire = Generer_Temp();
    if(strcmp(operande1, "") == 0 && strcmp(operande2, "") == 0) {
        
        char op1[50], op2[50];
        Depiler(op2);
        Depiler(op1);
        Inserer_Element_QUAD("/", op1, op2, temporaire);
    } 
    else {
        Inserer_Element_QUAD("/", operande1, operande2, temporaire);
    }
    Empiler(temporaire);
}

void Multiplication_QUAD(char operande1[], char operande2[]) {
    
    char* temporaire = Generer_Temp();
    if(strcmp(operande1, "") == 0 && strcmp(operande2, "") == 0) {
        char op1[50], op2[50];
        Depiler(op2);
        Depiler(op1);
        Inserer_Element_QUAD("*", op1, op2, temporaire);
    } 
    else {
        Inserer_Element_QUAD("*", operande1, operande2, temporaire);
    }
    Empiler(temporaire);
}



void Sup_QUAD() {
    
    char op1[50], op2[50];
    Depiler(op2);
    Depiler(op1);

    Liste_QUAD p;
    char* temporaire = Generer_Temp(); 
    Inserer_Element_QUAD("BLE", "", op1, op2);
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", num_quad);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);

}

void Inf_QUAD() {

    char op1[50], op2[50];
    Depiler(op2);
    Depiler(op1);


    Liste_QUAD p;
    char* temporaire = Generer_Temp(); 
    Inserer_Element_QUAD("BGE", "", op1, op2);
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", num_quad);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
}
void Sup_Egal_QUAD(char operande1[], char operande2[]) {

    char op1[50], op2[50];
    Depiler(op2);
    Depiler(op1);

    Liste_QUAD p;
    char* temporaire = Generer_Temp(); 
    Inserer_Element_QUAD("BL", "", op1, op2);
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", num_quad);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
}
void Inf_Egal_QUAD() {
    
    char op1[50], op2[50];
    Depiler(op2);
    Depiler(op1);
    
    Liste_QUAD p;
    char* temporaire = Generer_Temp(); 
    Inserer_Element_QUAD("BG", "", op1, op2);
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", num_quad);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
}
void Egal_Egal_QUAD() {

    char op1[50], op2[50];
    Depiler(op2);
    Depiler(op1);
    
    Liste_QUAD p;
    char* temporaire = Generer_Temp(); 
    Inserer_Element_QUAD("BNE", "", op1, op2);
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", num_quad);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
}
void Non_Egal_QUAD() {

    char op1[50], op2[50];
    Depiler(op2);
    Depiler(op1);

    Liste_QUAD p;
    char* temporaire = Generer_Temp(); 
    Inserer_Element_QUAD("BE", "", op1, op2);
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", num_quad);
    Depiler_QUAD(&p);
    sprintf(p->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
}


void And_QUAD() {
    
    char* temporaire;
    char temp1[50], temp2[50];
    Liste_QUAD q;
    temporaire = Generer_Temp();

    Depiler(temp1);                         
    Depiler(temp2);
    Inserer_Element_QUAD("BZ", "", temp1, "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD("BZ", "", temp2, "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", num_quad);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", dernier_quad->num);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
}
void Or_QUAD() {

    char* temporaire;
    char temp1[50], temp2[50];
    Liste_QUAD q;
    temporaire = Generer_Temp();

    Depiler(temp1);                         
    Depiler(temp2);
    Inserer_Element_QUAD("BNZ", "", temp1, "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD("BNZ", "", temp2, "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", num_quad);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", dernier_quad->num);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);

}
void Not_Quad() {

    char* temporaire;
    char temp[50];
    Liste_QUAD q;
    temporaire = Generer_Temp();

    Depiler(temp);                         
    Inserer_Element_QUAD("BZ", "", temp, "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "0", "", temporaire);
    Inserer_Element_QUAD("BR", "", "", "");
    Empiler_QUAD(dernier_quad);
    Inserer_Element_QUAD(":=", "1", "", temporaire);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", num_quad);
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", dernier_quad->num);
    Empiler(temporaire);
    
}




void Routine_If_Apres_Cond() {

    //quadruplets cond
    char temp[50];
    Depiler(temp); 
    Inserer_Element_QUAD("BZ", "", temp, "");
    Empiler_QUAD(dernier_quad);

}

void Routine_If_Apres_Inst1() {

    //quadruplets inst1
    Liste_QUAD q;
    Depiler_QUAD(&q);
    Inserer_Element_QUAD("BR", "", "", "");
    sprintf(q->operande1, "(%d)", num_quad);
    Empiler_QUAD(dernier_quad);
}

void Routine_If_Apres_Inst2() {

    //quadruplets inst2
    Liste_QUAD q;
    Depiler_QUAD(&q);
    sprintf(q->operande1, "(%d)", num_quad);

}

void Routine_While_Avant_Cond() {
 
    Liste_QUAD q = Allouer_QUAD();
    q->num = num_quad;
    Empiler_QUAD(q);
}

void Routine_While_Apres_Cond() {

    char temp[50];
    Depiler(temp); 
    Inserer_Element_QUAD("BZ", "", temp, "");
    Empiler_QUAD(dernier_quad);
}

void Routine_While_Apres_Inst() {

    Liste_QUAD q2, q1;
    Depiler_QUAD(&q2);
    Depiler_QUAD(&q1);
    Inserer_Element_QUAD("BR", "", "", "");
    sprintf(dernier_quad->operande1, "(%d)", q1->num);
    sprintf(q2->operande1, "(%d)", num_quad);
}

void Routine_For_Apres_Init(char* i, char* pas) {
 
    if(!Entite_Non_Declare(i)) {      
        if(!Est_Une_Constante(i)) {
            if(Est_Un_Entier(i)) {
                Empiler_Type(0);  
            }
            Traitement_Types();
        }
    }
    Incompatibilite_Types(i);
    Affectation_QUAD(i, "");
    Empiler(i);

    char num[50];
    sprintf(num, "(%d)", num_quad + 2);
    Inserer_Element_QUAD("BR", num, "", "");
    Inserer_Element_QUAD("+", i, pas, i);
    Empiler_QUAD(dernier_quad);
}


void Routine_For_Apres_Cond() {

    
    char n[50], i[50];
    Depiler(n);
    Depiler(i);
 
    Empiler_Type(0);
    Traitement_Types();
    Incompatibilite_Types(i);
    char* temp = Generer_Temp();
    char num[50];
    sprintf(num, "(%d)", num_quad + 3);
    Inserer_Element_QUAD("BGE", num, i, n);
    Inserer_Element_QUAD(":=", "0", "", temp);
    sprintf(num, "(%d)", num_quad + 2);
    Inserer_Element_QUAD("BR", num, "", "");
    Inserer_Element_QUAD(":=", "1", "", temp);
    Inserer_Element_QUAD("BZ", "", temp, "");
    Empiler_QUAD(dernier_quad);
    
}


void Routine_For_Apres_Inst() {

    Liste_QUAD q1, q2;
    Depiler_QUAD(&q2);
    Depiler_QUAD(&q1);

    char num[50];
    sprintf(num, "(%d)", q1->num);
    Inserer_Element_QUAD("BR", num, "", "");
    sprintf(num, "(%d)", num_quad);
    strcpy(q2->operande1, num);
    
}

char* Case_Tab(char* entity, char* i) {

    char* concat = Allouer_Char(strlen(entity) + strlen(i) + 2);
    strcpy(concat, entity);
    strcat(concat, "[");
    strcat(concat, i);
    strcat(concat, "]");
    return concat;
}


PILE_TEMP Allouer_Pile() {
    
    PILE_TEMP L = (Element_Pile_Temp*) malloc(sizeof(Element_Pile_Temp));

    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
}

char* Tete_Pile() {
    return PILE->temp;
}

void Empiler(char temp[]) {

    PILE_TEMP p = Allouer_Pile();
    strcpy(p->temp, temp);
    p->suivant = PILE;
    PILE = p;
}

void Depiler(char* temp) {

    strcpy(temp, PILE->temp);
    PILE_TEMP p = PILE;
    PILE = PILE->suivant;
    free(p);
}

void Afficher_Pile() {

    PILE_TEMP p = PILE;
    printf("PILE DES TEMPORAIRES:\n\n");
    if(p == NULL) {
        printf("\t\tVIDE\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%s\t",p->temp);
            p = p->suivant;
        }
        printf("\n");
    }
}






PILE_QUAD Allouer_Pile_QUAD() {
    
    PILE_QUAD L = (Element_Pile_QUAD*) malloc(sizeof(Element_Pile_QUAD));

    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
}

Liste_QUAD Tete_Pile_QUAD() {
    return PILE_Q->quad;
}

void Empiler_QUAD(Liste_QUAD q) {
    
    PILE_QUAD p = Allouer_Pile_QUAD();
    p->quad = q;
    p->suivant = PILE_Q;
    PILE_Q = p;
}

void Depiler_QUAD(Liste_QUAD* q) {
    
    *q = PILE_Q->quad;
    PILE_QUAD p = PILE_Q;
    PILE_Q = PILE_Q->suivant;
    free(p);
}

void Afficher_Pile_QUAD() {

    PILE_QUAD p = PILE_Q;
    printf("PILE DES SAUVEGARDES QUADS:\n\n");
    if(p == NULL) {
        printf("\t\tVIDE\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%s\t",(p->quad)->num);
            p = p->suivant;
        }
        printf("\n");
    }
}

