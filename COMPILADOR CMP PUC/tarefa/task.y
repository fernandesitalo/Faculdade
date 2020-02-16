%{
#include<stdio.h>
#include<string.h>
#include<map>
#include<cmath>
#include <iostream>
using namespace std;
string buffer;
map<string,int> memo;
void yyerror(char *s);
extern int yylex();
%}

/* declaracao dos tokens */
%union {
	int val;
	char *id;
}
%token<id> VAR
%token<val> NUM
%token LEIA ESCREVA ADD SUB MUL DIV MOD POT ATRIB APAR FPAR PV
%type<val> expressao termo fator base expoente
%%

instrucoes: instrucoes instrucao PV  {} 
|
;

instrucao: VAR ATRIB expressao	{ memo[(string)$1] = (int)$3;			}
| ESCREVA expressao				{ printf(" =%d\n",(int)$2); 			}
| LEIA VAR						{ scanf("%d",&memo[(string)$2]);    	}
;

expressao: termo 		{ $$ =  (int)$1;			}
| expressao ADD termo 	{ $$ =  (int)$1 +  (int)$3; }
| expressao SUB termo 	{ $$ =  (int)$1 -  (int)$3; }
;

termo: fator 		{ $$ =  (int)$1;			}
| termo MUL fator 	{ $$ =  (int)$1 *  (int)$3; }
| termo DIV fator 	{ $$ =  (int)$1 /  (int)$3; }
| termo MOD fator   { $$ =  (int)$1 %  (int)$3; }
;

fator: base 			{ $$ = (int) $1;					}
| fator POT expoente	{ $$ = (int) pow((int)$1,(int)$3);	}
| APAR expressao FPAR 	{ $$ =  (int)$2;		   			}
;

base: VAR 		{ $$ = memo[(string)$1]; }
| NUM			{ $$ =  (int)$1; }
;

expoente: VAR 	{ $$ = memo[(string)$1];}
| NUM			{ $$ = $1;}
;


%%

int main(int argc, char **argv){
	yyparse();
}

void yyerror(char *s){
	fprintf(stderr, "error: %s\n", s);
}


