%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <float.h>
    #include "ra.tab.h"
    #include "RS.h"

    extern YYSTYPE yylval;
    int line = 1, col = 1;
    int length = 0;
    char sub_str[] = "\0";
    char *str;
    //yywrap : pour le cas de traitement de plusieurs fichiers en mm temps
    //   dans notre cas on traitra un seul fichier
%}

%option noyywrap

chmc_iffre [0-9]
entier {chmc_iffre}+
entier_signe  "("("+"|"-"){entier}")"   
reel ({chmc_iffre}+"."{chmc_iffre}*|{chmc_iffre}*"."{chmc_iffre}+)
reel_signe  "("(("+"|"-"){reel})")"
lettre_min [a-z]
lettre [a-zA-Z]
idf {lettre}({lettre_min}|{chmc_iffre})*
commentaire  "%""%".*
espace ("\t"|" ")+
saut "\n"+

%%
VAR     {col += yyleng; return mc_var;} 
CODE    {col += yyleng; return mc_code;}
INTEGER {col += yyleng; return mc_integer;} 
FLOAT   {col += yyleng; return mc_float;} 
CONST   {col += yyleng; return mc_const;} 
STRUCT  {col += yyleng; return mc_struct;}
IF      {col += yyleng; return mc_if;}
ELSE    {col += yyleng; return mc_else;}
FOR     {col += yyleng; return mc_for;}
WHILE   {col += yyleng; return mc_while;}


{entier}        {   
                    col += yyleng; 
                    if(atoi(yytext) >= -32768 && atoi(yytext)<= 32767)
                    {
                        yylval.nom = strdup(yytext); 
                        return entier;
                    }
                    else 
                    {
                        Erreur_Lexicale(yytext, "entier non valide: un entier doit etre compris entre -32768 et 32767");
                    }
                }

{entier_signe}  {
                    col += yyleng; 
                    str = strdup(yytext); 
                    length = yyleng;
                    strncpy(sub_str, str + 1, length - 2); 
                    sub_str[length-2] = '\0';

                    if(atoi(sub_str) >= -32768 && atoi(yytext)<= 32767)
                    {   
                        yylval.nom = strdup(sub_str); return entier;
                    }
                    else 
                    {
                        Erreur_Lexicale(yytext, "entier non valide: un entier doit etre compris entre -32768 et 32767");
                    }
                }

{idf}           {
                    col += yyleng; 
                    if (yyleng <= 8)
                    {
                        yylval.nom = strdup(yytext); 
                        return(idf);
                    }
                    else {
                        Erreur_Lexicale(yytext, "identificateur non valide: un identificateur ne doit pas depasser 8 caracteres");
                    }
                }


{reel}          {   
                    if(strlen(yytext) <= 9) {
                        col += yyleng; 
                        yylval.nom = strdup(yytext);
                        return reel;
                    }
                    else {
                        Erreur_Lexicale(yytext, "reel non valide: un reel ne doit pas avoir plus que 9 chiffres");
                    }
                    
                }
      

{reel_signe}    {   
                    col += yyleng; 
                    str = strdup(yytext); 
                    length = yyleng;
                    strncpy(sub_str, str+1, length-2); 
                    sub_str[length-2] = '\0';
                    yylval.nom = strdup(sub_str); 
                    return reel;
                }



":" {col += yyleng; return deux_points;}  
"{" {col += yyleng; return acc_ouv;}    
"}" {col += yyleng; return acc_fer;}    
"[" {col += yyleng; return croch_ouv;}  
"]" {col += yyleng; return croch_fer;}          
";" {col += yyleng; return pvg;}        
"," {col += yyleng; return vg;}          
"=" {col += yyleng; return aff;}        
"(" {col += yyleng; return par_ouv;}    
")" {col += yyleng; return par_fer;}    
"." {col += yyleng; return point;}


"+" {col += yyleng; return plus;} 
"-" {col += yyleng; return moins;}
"/" {col += yyleng; return slash;}
"*" {col += yyleng; return etoile;}


"&&" {col += yyleng; return and;}
"||" {col += yyleng; return or;}
"!"  {col += yyleng;  return not;}

">"  {col += yyleng;  return sup;}
"<"  {col += yyleng;  return inf;}
">=" {col += yyleng; return sup_egal;}
"<=" {col += yyleng; return inf_egal;}
"==" {col += yyleng; return egal_egal;}
"!=" {col += yyleng; return non_egal;} 


{espace} {col += yyleng;} 
{saut} {col = 1; line += yyleng;}
{commentaire} 

. {Erreur_Lexicale(yytext, "entite non valide: entite non reconnue");}

%%