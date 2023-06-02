%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "TS.h"
    #include "QUAD.h"
    #include "RS.h"
    #include "GEN.h"
    #include "OPTIM.h"

    int yylex();
    int yyerror(char *);
    extern FILE *yyin;
    extern int line, col;
    int nature;
    char* type;
    char* valeur; 
    Liste_Element_Struct Liste = NULL;
    bool div_par_zero = false;
    int nb_erreurs = 0;

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

S: idf acc_ouv mc_var acc_ouv LISTE_DEC acc_fer mc_code acc_ouv LISTE_INST acc_fer acc_fer {Inserer_Element_TS1($1, 99, "p", "p"); YYACCEPT;}
;

LISTE_DEC: LISTE_DEC DEC 
         | 
; 

DEC:  TYPE LISTE_VAR pvg  
    {   
        //associer a chaque variable de LISTE_VAR le type 'type'
        MAJ_TS1(type);
    }
    | mc_const idf aff VALEUR pvg
    {      
        if(!Double_Declaration_Entite($2)) {
            //nature = 0 (const)
            //inserer le nom de la cst dans la table ts1
            Inserer_Element_TS1($2, 0, type, valeur);
        }
    }
    | mc_struct acc_ouv LISTE_DEC_SIMPLE acc_fer idf pvg
    {
        if(!Double_Declaration_Structure($5)) {

            //Inserer le nom de la structure dans la table ts 2
            Inserer_Element_TS2($5);
            
            MAJ_TS2($5, Liste);
        }

        Liste = NULL;
    }
; 
VALEUR: entier  
        {
            type = Allouer_Char(8);
            valeur = Allouer_Char(strlen($1) + 1);
            strcpy(type, "INTEGER");
            strcpy(valeur, $1);
        }
        | reel    
        {   
            type = Allouer_Char(6);
            valeur = Allouer_Char(strlen($1) + 1);
            strcpy(type, "FLOAT");
            strcpy(valeur, $1);
        }
;

TYPE: TYPE_SIMPLE
    | mc_struct idf 
    {
        if(!Structure_Non_Declare($2)) { 
            
            type = Allouer_Char(strlen($2));
            strcpy(type, $2);
        }
    }
;
TYPE_SIMPLE: mc_integer {type = Allouer_Char(8); strcpy(type, "INTEGER");}
           | mc_float   {type = Allouer_Char(6); strcpy(type, "FLOAT");}
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
    | INST_WHILE
    | INST_FOR
;

INST_AFF: idf aff EXP pvg
        {
            if(!Entite_Non_Declare($1)) {      
                if(!Est_Une_Constante($1)) {
                    if(strcmp(Get_Idf_Type($1), "INTEGER") == 0) {
                        Empiler_Type(0);    
                    }
                    else {
                        Empiler_Type(1);
                    }
                    Traitement_Types();
                }
            }
            Incompatibilite_Types($1);
            Affectation_QUAD($1, "");
        }
        | idf point idf aff EXP pvg
        {
            char* idf = Idf_Point_Idf($1, $3);
            if(!Entite_Non_Declare(idf)) {
                if(strcmp(Get_Idf_Type(idf), "INTEGER") == 0) {
                    Empiler_Type(0);    
                }
                else {
                    Empiler_Type(1);
                }
                Traitement_Types();
            }
            Incompatibilite_Types(idf);
            Affectation_QUAD(idf, "");
        }
        |
        idf croch_ouv entier croch_fer aff EXP pvg
        {
            if(!Entite_Non_Declare($1)) {      
                if(!Est_Une_Constante($1)) {
                    if(Est_Un_Tableau($1)) {
                        if(!Out_Of_Bounds($1, atoi($3))) {
                            if(strcmp(Get_Idf_Type($1), "INTEGER") == 0) {
                                Empiler_Type(0);    
                            }
                            else {
                                Empiler_Type(1);
                            }
                            Traitement_Types();
                        }
                    }    
                }
            }
            Incompatibilite_Types_Tab($1, $3);
            Affectation_QUAD(Case_Tab($1, $3), "");
        }
;

EXP:  EXP plus EXP          
    {   
        Addition_QUAD("", "");     
        Traitement_Types();
        div_par_zero = false;
    }
	| EXP moins EXP         
    {
        Soustraction_QUAD("", ""); 
        Traitement_Types();
        div_par_zero = false;
    }
	| EXP slash EXP         
    {   
        Division_QUAD("", ""); 
        Division_Par_Zero(div_par_zero);
        Traitement_Types();
        div_par_zero = false;
    }
	| EXP etoile EXP        
    {   
        Multiplication_QUAD("", ""); 
        Traitement_Types();
        div_par_zero = false;
        
    }
    | moins EXP
    {
        Moins_QUAD("");
        div_par_zero = false;
    }
    | plus EXP
    {
        Plus_QUAD("");
        div_par_zero = false;
    }
	| idf                   
    {   
        if(!Entite_Non_Declare($1))
        {    
            if(strcmp(Get_Idf_Type($1), "INTEGER") == 0) {
                Empiler_Type(0);    
            }
            else {
                Empiler_Type(1);
            }
        }
        Affectation_QUAD("", $1);
    }         
    | idf point idf                 
    {   
        char* idf = Idf_Point_Idf($1, $3);
        if(!Entite_Non_Declare(idf))
        {
            if(strcmp(Get_Idf_Type(idf), "INTEGER") == 0) {
                Empiler_Type(0);    
            }
            else {
                Empiler_Type(1);
            }
        }
        Affectation_QUAD("", idf);
    }   
    | idf croch_ouv entier croch_fer
    {
        if(!Entite_Non_Declare($1)) {
            if(Est_Un_Tableau($1)) {
                if(!Out_Of_Bounds($1, atoi($3))) {
                    if(strcmp(Get_Idf_Type($1), "INTEGER") == 0) {
                        Empiler_Type(0);    
                    }
                    else {
                        Empiler_Type(1);
                    }
                }
            }
        }
        Affectation_QUAD("", Case_Tab($1,$3));
    }             
    | entier                
    {   
        Empiler_Type(0);
        Affectation_QUAD("", $1);
        if(atoi($1) == 0) {
            div_par_zero = true;
        }
    } 
	| reel                  
    {
        Empiler_Type(1);
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

INST_WHILE: APRES_COND_WHILE acc_ouv LISTE_INST acc_fer {Routine_While_Apres_Inst();}
;
APRES_COND_WHILE: AVANT_COND_WHILE par_ouv COND par_fer {Routine_While_Apres_Cond();}
;
AVANT_COND_WHILE: mc_while                              {Routine_While_Avant_Cond();}
;

INST_FOR: AVANT_INST_FOR acc_ouv LISTE_INST acc_fer                                {Routine_For_Apres_Inst();}
;
AVANT_INST_FOR: AVANT_COND_FOR EXP par_fer                                         {Routine_For_Apres_Cond();}
;
AVANT_COND_FOR: mc_for par_ouv idf deux_points EXP deux_points entier deux_points  {Routine_For_Apres_Init($3, $7);}
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

    if(nb_erreurs > 0) {
        exit(1);
    }
    Afficher_TS1();
    Afficher_TS2();
    Afficher_QUAD();
    Optim();
    printf("Optimisation...\n");
    printf("------------------------Apres Optimisation-------------------\n");
    Afficher_QUAD();
    Generer();
    fclose(yyin);
    return 0;
}