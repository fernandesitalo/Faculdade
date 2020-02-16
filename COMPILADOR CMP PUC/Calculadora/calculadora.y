/* calculadora de expressoes */
%{
#include <stdio.h>
%}

/* declarar tokens */
%token NUMBER
%token ADD SUB MUL DIV 
%token APAR FPAR
%token EOL

%%

calclist: calclist expressao EOL  { printf("= %d\n", $2); } 
| /*Quando nada e definido, assume-se epsilon*/ 
;

expressao: fator 		/* default $$ = $1 */
| expressao ADD fator 	{ $$ = $1 + $3; }
| expressao SUB fator 	{ $$ = $1 - $3; }
;

fator: termo 		/* default $$ = $1 */
| fator MUL termo 	{ $$ = $1 * $3; }
| fator DIV termo 	{ $$ = $1 / $3; }
;

termo: NUMBER 			/* default $$ = $1 */
| APAR expressao FPAR 	/* default $$ = $1 */
;

%%

main(int argc, char **argv)
{
	yyparse();
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
