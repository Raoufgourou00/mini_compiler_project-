%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "TS.h"
    #include "QUAD.h"
    #include "RS.h"

    int yylex();
    int yyerror(char *);
    extern FILE *yyin;
    extern int line, col;
    int nature;
    char type[10];
    char valeur[20]; 
    Liste_Element_Struct Liste = NULL;
    bool div_par_zero = false;
    

%}
%union  {
                char* nom;
        }
%token mc_var mc_code mc_integer mc_float mc_const mc_struct mc_if mc_else  mc_for mc_while  
%token deux_points acc_ouv acc_fer croch_ouv croch_fer pvg vg aff par_ouv par_fer point
%token plus moins slash etoile and or not sup inf sup_egal inf_egal egal_egal non_egal
%token<nom> idf reel entier 
%left or
%left and
%left not
%left egal_egal inf sup inf_egal sup_egal non_egal
%left plus moins
%left etoile slash
%start S  
%%

S: idf acc_ouv mc_var acc_ouv LISTE_DEC acc_fer mc_code acc_ouv LISTE_INST acc_fer acc_fer {printf("programme syntaxiquement juste\n");YYACCEPT;}
;

LISTE_DEC: LISTE_DEC DEC 
         | 
; 

DEC:  TYPE LISTE_VAR pvg  
    {
        MAJ_TS1(type);
    }
    | mc_const idf aff VALEUR pvg
    {      
        if(!Double_Declaration_Entite($2)) {
            Inserer_Element_TS1($2, 0, type, valeur);
        }
    }
    | mc_struct acc_ouv LISTE_DEC_SIMPLE acc_fer idf pvg
    {
        if(!Double_Declaration_Structure($5)) {

            Inserer_Element_TS2($5);
            MAJ_TS2($5, Liste);
        }

        Liste = NULL;
    }
; 
VALEUR: entier  
        {
            strcpy(type, "INTEGER");
            strcpy(valeur, $1);
        }
        | reel    
        {
            strcpy(type, "FLOAT");
            strcpy(valeur, $1);
        }
;

TYPE: TYPE_SIMPLE
    | mc_struct idf 
    {
        if(!Structure_Non_Declare($2)) {      
            strcpy(type, $2);
        }
    }
;
TYPE_SIMPLE: mc_integer {strcpy(type, "INTEGER");}
           | mc_float   {strcpy(type, "FLOAT");}
;

LISTE_VAR: LISTE_VAR vg idf
        {   
            if(!Double_Declaration_Entite($3)) {          
                Inserer_Element_TS1($3, 1, "#", "#");
            }
        }
        |  LISTE_VAR vg idf croch_ouv entier croch_fer
        {
           if(!Double_Declaration_Entite($3)) {      
                if(!Taille_Negative($3, atoi($5))) {
                    Inserer_Element_TS1($3, 2, "#", $5);
                }
           }
        }
        |  idf
        {
            if(!Double_Declaration_Entite($1)) {      
                Inserer_Element_TS1($1, 1, "#", "#");
            }
        }
        |  idf croch_ouv entier croch_fer 
        {
            if(!Double_Declaration_Entite($1)) {    
                if(!Taille_Negative($1, atoi($3))) {  
                    Inserer_Element_TS1($1, 2, "#", $3);
                }
            }
        }
;

LISTE_DEC_SIMPLE: LISTE_DEC_SIMPLE DEC_SIMPLE
                | 
;
DEC_SIMPLE: TYPE_SIMPLE LISTE_VAR_SIMPLE pvg
            {
                MAJ_Liste_Element_Struct(Liste, type);
            }
;

LISTE_VAR_SIMPLE: LISTE_VAR_SIMPLE vg idf
                {
                    if(!Double_Declaration_Entite_Structure(Liste, $3)) {
                        Inserer_Element(&Liste, $3, "#");
                    }
                }
                | idf
                {
                    if(!Double_Declaration_Entite_Structure(Liste, $1)) {
                        Inserer_Element(&Liste, $1, "#");
                    }
                }
;


LISTE_INST: LISTE_INST INST 
          |
;

INST: INST_AFF
    | INST_IF 
    | INST_FOR
;

INST_AFF: idf aff EXP pvg
        {
            if(!Entite_Non_Declare($1)) {      
                Est_Une_Constante($1);
            }
            Affectation_QUAD($1, "");
        }
        | idf point idf aff EXP pvg
        {
            char* idf = Idf_Point_Idf($1, $3);
            Entite_Non_Declare(idf);
            Affectation_QUAD(idf, "");
        }
;

EXP:  EXP plus EXP          
    {   
        Addition_QUAD("", "");     
        div_par_zero = false;
    }
	| EXP moins EXP         
    {
        Soustraction_QUAD("", ""); 
        div_par_zero = false;
    }
	| EXP slash EXP         
    {   
        Division_QUAD("", ""); 
        Division_Par_Zero(div_par_zero);
        div_par_zero = false;
    }
	| EXP etoile EXP        
    {   
        Multiplication_QUAD("", ""); 
        div_par_zero = false;
    }
	| idf                   
    {
        Entite_Non_Declare($1);
        Affectation_QUAD("", $1);
    }                
    | entier                
    {   
        Affectation_QUAD("", $1);
        if(atoi($1) == 0) {
            div_par_zero = true;
        }
    } 
	| reel                  
    {
        Affectation_QUAD("", $1);
        if(atof($1) == 0) {
            div_par_zero = true;
        }
    }
	| par_ouv EXP par_fer   
	;

INST_IF: AVANT_ELSE mc_else acc_ouv LISTE_INST acc_fer  {Routine_If_Apres_Inst2();}
       | AVANT_INST acc_ouv LISTE_INST acc_fer          {Routine_If_Apres_Inst2();}
;
AVANT_ELSE: AVANT_INST acc_ouv LISTE_INST acc_fer       {Routine_If_Apres_Inst1();}
;
AVANT_INST: mc_if par_ouv COND par_fer                  {Routine_If_Apres_Cond(); }
;


INST_FOR: mc_for par_ouv idf deux_points EXP deux_points entier deux_points entier par_fer acc_ouv LISTE_INST acc_fer
;
COND: COND or COND          {Or_QUAD();}
    | COND and COND         {And_QUAD();}
    | not COND              {Not_Quad();}
    | EXP inf EXP           {Inf_QUAD();}
    | EXP sup EXP           {Sup_QUAD();}
    | EXP inf_egal EXP      {Inf_Egal_QUAD();}
    | EXP sup_egal EXP      {Sup_Egal_QUAD();}
    | EXP egal_egal EXP     {Egal_Egal_QUAD();}
    | EXP non_egal EXP      {Non_Egal_QUAD();}
    | par_ouv COND par_fer 
;


%%
int yyerror(char* msg){
    printf("%s : line %d, col %d \n", msg, line, col);
    exit(0);
    return 1;
}
int main(){
    yydebug=0;
    yyin = fopen("in.txt", "r");
    yyparse();
    Afficher_TS1();
    Afficher_TS2();
    Afficher_QUAD();
    fclose(yyin);
    return 0;
}