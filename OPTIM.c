#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "OPTIM.h"
extern Liste_QUAD QUAD;
Liste_Temp LT=NULL, l=NULL, t=NULL;
bool changement = true;

Liste_QUAD p;

void Optim()
{
    changement=true;
    while(changement){
        changement=false;
        PropagExpress();
    }
    changement=true;
    while(changement){
        changement=false;
        PropagCopies();
    } 
    changement=true;
    while(changement){ 
        changement=false;
        EliminExpRed();
    }
    /*
    changement=true;
    while(changement){
        changement=false;
        SimplAlg();
    }*/
    
}

void EliminExpRed(){
    Liste_QUAD c, d;
    p = QUAD;
    while(p != NULL){
        printf("\n ===========Avant=========== \n");
        printf("%12d\t%12s\t%12s\t%12s\t%s\n",
                p->num ,p->operateur, p->operande1, p->operande2, p->temporaire);
        if(!strcmp(p->operateur, ":=")){
            Inserer_Element_TEMP(p->temporaire, p->operande1, p->num, p->operateur);
            printf("\n%12d\t%12s\t%12s\t%12s\n",l->num, l->temp, l->valeur, l->operateur);
            t=LT;
            
            while(t != NULL && (t->num < p->num)){
                if(!strcmp(t->valeur, p->operande1)){
                strcpy(p->operande1, t->temp);
                changement=true;
                }
                t=t->suivant;
            }
            printf("\n ===========Apres=========== \n");
            printf("%12d\t%12s\t%12s\t%12s\t%s\n",
                p->num ,p->operateur, p->operande1, p->operande2, p->temporaire);
        }
        else{
            if(!strcmp(p->operateur, "+") || !strcmp(p->operateur, "-")  
            || !strcmp(p->operateur, "*") || !strcmp(p->operateur, "/") ){
                c=p->suivant;d=p;
                VerifExpRed(c, d);
            }
        }
        p=p->suivant;
    }
    printf("\nEliminExpRed: %d\n", changement);
    p = QUAD;
}
void VerifExpRed(Liste_QUAD c, Liste_QUAD p){
    while(c != NULL && strcmp(c->temporaire, p->temporaire)){
        if(!strcmp(p->operateur, c->operateur) &&
        ((!strcmp(c->operande1, p->operande1) && !strcmp(c->operande2, p->operande2) )
      || (!strcmp(c->operande2, p->operande1) && !strcmp(c->operande1, p->operande2) ))){
            strcpy(c->operateur, ":=");
            strcpy(c->operande1, p->temporaire);
            strcpy(c->operande2, "");
            changement=true;
        }
        c=c->suivant;
    }
}

void PropagCopies(){
    Liste_QUAD c;
    p=QUAD;
    while(p != NULL){
        c=p->suivant;
        while(c != NULL && strcmp(c->temporaire, p->temporaire) ){
            //printf("\n%s == %s\n", c->operande1, p->temporaire);
            if(!strcmp(c->operande1, p->temporaire)){
                if(!strcmp(p->operateur, ":=")){
                    strcpy(c->operande1, p->operande1);
                    changement=true;
                }
            }
            else{
                if(!strcmp(c->operande2, p->temporaire)){
                    if(!strcmp(p->operateur, ":=")){
                        strcpy(c->operande2, p->operande1);
                        changement=true;
                    }
                }
            }
            c=c->suivant;
        }
        p=p->suivant;
    }
    p = QUAD;
    printf("\nPropagCopies: %d\n", changement);

}

void PropagExpress(){
    Liste_QUAD c, q, d;
    p=QUAD;
    while(p != NULL){
        c=p->suivant;
        d=p;
        int nbrOcc = 0;
        if(!strcmp(p->operateur, ":=")){
            while(c != NULL){
                if(!strcmp(p->temporaire, c->operande1)
                || !strcmp(p->temporaire, c->operande2)){
                    nbrOcc++;
                    q=c;
                }
                if(nbrOcc == 0){d=d->suivant;}
                c=c->suivant;
            }
            if(nbrOcc == 1){
                if(!strcmp(q->operande1, p->temporaire)){
                    if(!strcmp(p->operateur, ":=")){
                        strcpy(q->operande1, p->operande1);
                    }
                }
                else{
                    if(!strcmp(p->operateur, ":=")){
                        strcpy(q->operande2, p->operande1);
                    }
                }
                if(QUAD == p){QUAD = QUAD->suivant;}
                p=p->suivant;
                changement=true;
            }
            else{p=p->suivant;}
        }
        else{p=p->suivant;}
    }
    p=QUAD;
    printf("\nPropagExpress: %d\n", changement);

}

void SimplAlg(){
    p=QUAD;
    Liste_QUAD q, d=NULL;
    int i;
    char b[20], temp_p[20];
    q=p->suivant;
    while(p != NULL){
        int a=-1;
        printf("\nJe suis ici %d\n", p->num);
        if(!strcmp(p->operateur, "*")){
            printf("\nJe suis ici %d\n", p->num);
            if(atoi(p->operande1) != 0 || !strcmp(p->operande1, "0") ){
                a=atoi(p->operande1);
                strcpy(b, p->operande2);
                printf("\nJe suis ici avec %d    %s\n", a, b);
            }
            else{
                if(atoi(p->operande2) != 0 || !strcmp(p->operande2, "0") ){
                    a=atoi(p->operande2);
                    strcpy(b, p->operande1);
                    printf("\nJe suis ici %d    %s\n", a, b);
                }
            }
            if(a != -1){
                int nbrTemp=0;
                char pr_t[20], num[20];
                char *t;
                for(i=0; i<a-1; i++){
                    printf("\nJe suis dans la boucle ici %d\n", p->num);
                    p->num=  p->num+i;
                    changement=true;
                    if(i == a-2){
                        if(i != 0){
                            strcpy(p->operateur, "+");
                            strcpy(p->operande1, pr_t);
                            strcpy(p->operande2, b);
                            strcpy(p->temporaire, temp_p);
                        }
                        else{
                            strcpy(p->operateur, "+");
                            strcpy(p->operande1, b);
                            strcpy(p->operande2, b);
                        }
                        p->suivant=q;
                        int a=1;
                        while(q != NULL){
                            q->num = p->num+a;
                            q=q->suivant;
                            a++;
                        }
                    }
                    else{
                        t= Generer_Temp();
                        if(nbrTemp == 0){
                            strcpy(temp_p, p->temporaire);
                            strcpy(p->operateur, "+");
                            strcpy(p->operande1, b);
                            strcpy(p->operande2, b);
                            strcpy(p->temporaire, t);
                            strcpy(pr_t, t);
                            p->suivant=NULL;
                        }
                        else{
                            d=Allouer_QUAD();
                            p=d;
                            strcpy(p->operateur, "+");
                            strcpy(p->operande1, pr_t);
                            strcpy(p->operande2, b);
                            strcpy(p->temporaire, t);
                            strcpy(pr_t, t);
                            p->suivant=NULL;
                            d=NULL;
                        }
                        nbrTemp++;
                        }
                }
            }
        }
        p=p->suivant;
        q=q->suivant;
        
    }
    printf("\nSimplAlg : %d\n", changement);

}



Liste_Temp Allouer_TEMP(){
    Liste_Temp L;
    L= (Element_Temp*) malloc(sizeof(Element_Temp));
    if(L == NULL)
    {
        fprintf(stderr , "Erreur : Allocation problem .\n");
        exit(EXIT_FAILURE);
    }
    return L;
}
void Inserer_Element_TEMP(char temp[], char valeur[], int num, char operateur[]) {

    if (LT == NULL)
    {
        LT = Allouer_TEMP();
        strcpy(LT->temp, temp);
        strcpy(LT->valeur, valeur);
        LT->num=num;
        strcpy(LT->operateur, operateur);
        LT->suivant = NULL;

        l=LT;
        t=LT;
    }
    else
    {
        l->suivant = Allouer_TEMP();
        l=l->suivant;
        strcpy(l->temp, temp);
        strcpy(l->valeur, valeur);
        l->num=num;
        strcpy(l->operateur,operateur);
        l->suivant=NULL;
    }
}