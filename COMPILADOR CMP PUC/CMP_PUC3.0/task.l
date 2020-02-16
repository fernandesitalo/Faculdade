	/* %option debug */
%option noyywrap

%{

#include<stdio.h>
#include<string.h>
#include<map>
#include<cmath>
using namespace std;

#include "parser.tab.h"
extern string buffer;
%}

%%
"enquanto"				{ return WHILE;		}
"sera"					{ return IF;		}
"nenao"					{ return ELSE;		}


"[funcao]"				{ return FUNCAO;	}

"principal"  			{ return MAIN;	}

"="						{ return ATRIB;		}
";"						{ return PV;  		}
"+" 					{ return ADD; 		}
"-"	 					{ return SUB; 		}
"%"						{ return MOD;		}
"*" 					{ return MUL; 		}
"/" 					{ return DIV; 		}
"(" 					{ return APAR;		}
")" 					{ return FPAR;		}
"{" 					{ return ACH;		}
"}" 					{ return FCH;		}
"escreva"				{ return ESCREVA;	}
"leia"					{ return LEIA;		}
"^"						{ return POT; 		}
">"						{ return MAIOR;		}
"<"						{ return MENOR;		}
">="				    { return MAIORIGUAL;}
"<="				    { return MENORIGUAL;}
"=="				    { return IGUAL;		}
"~="				    { return DIFERENTE;	}



[0-9]+					{ yylval.val = atoi(yytext); return NUM;								}
[a-zA-Z][0-9a-zA-Z]*	{ buffer = yytext; yylval.id = (char*) buffer.data(); return VAR; 		}
[ \t] 					{ /* ignorar os tabs */ 												}
. 						{ printf("CARACTER INVALIDO: %c\n", *yytext); 							}
%%


