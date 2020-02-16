%{ 
#include<cmath>
#include<cassert>
#include<string>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
string buffer;

extern int yylex();
extern FILE* yyin;
void yyerror(const char* s);
vector<string> codigoMv;

map<string,int> memo;
map<string,int> posMemo;
map<string,int> funcoes;

string getPosMemo(string name){
	if(posMemo[name] == 0) posMemo[name] = posMemo.size();
	return to_string(posMemo[name]);	
}

void add(){}
template<class... Type> void add(const string& s, const Type&... t){
  codigoMv.push_back(s);
  add(t...);
}

int reserva(){
	codigoMv.push_back("");
	return (codigoMv.size()-1);
}

int linhaAtual(){
   return (codigoMv.size()-1);
}

void trocar(int posicao, string comando){
	assert(0 <= posicao&& posicao < codigoMv.size());
	codigoMv[posicao] = comando;
}


struct Rotulo {
	int jmp_verdadeiro;
	int jmp_falso;
};

%}

%union{
	int val;
	char * id;
	struct Rotulo * rotulo;
}

%token LEIA ESCREVA ADD SUB MUL DIV MOD POT ATRIB APAR FPAR PV ELSE ACH FCH MAIOR MENOR IGUAL MENORIGUAL MAIORIGUAL DIFERENTE FUNCAO MAIN
%token<id> VAR
%token<val> NUM
%token<rotulo>  IF WHILE /* para saber onde voltar */
%type<val> expressao termo fator base expoente
%left '-' '+'
%left '*' '/' '%' 
%right '^' 

%type<id> condicao

%%

instrucoes: instrucoes instrucao PV
| instrucoes ifelse
| instrucoes while
| instrucoes funcao
| instrucoes main
|
;

instrucao: VAR ATRIB expressao	{ add("pop r1","store r1 "+getPosMemo((string)$1)); memo[(string)$1] = $3;		}
| ESCREVA expressao				{ add("pop r1","print r1"); 					}
| LEIA VAR						{ add("read r1","store r1 "+getPosMemo($2));	}
| VAR APAR FPAR					{ 
								  if(!funcoes.count($1)){
                                    yyerror("EXISTE MAIS DE UMA FUNCAO COM MESMO NOME, BROTHER!!");
                                  }
                                  add("call " + to_string(funcoes[$1]));
                                }
;


main : MAIN						{	
										if(!codigoMv[0].empty()){
											yyerror("Por acaso, ja viu um programa com duas main?!");
										}
										trocar(0, "jump " + to_string(linhaAtual() + 1)); 
									}
									
	   ACH instrucoes FCH
;


ifelse: IF APAR condicao FPAR 	{ 	
									$1 = new Rotulo();
									$1->jmp_falso = reserva();	
								}
		ACH instrucoes FCH		{ 
									$1->jmp_verdadeiro = reserva();
								}
		ELSE 					{
									trocar($1->jmp_falso,(string)$3 + " r0 r1 " + to_string(linhaAtual()+1));
								}
		ACH instrucoes FCH		{ 
									trocar($1->jmp_verdadeiro,"jump " + to_string(linhaAtual()+1));
									delete $1;				/*DESALOCA*/
								}		
;				
while: 	WHILE 					{ /* salvar onde deverear voltar para repetir*/
									$1 = new Rotulo();
									$1->jmp_verdadeiro = reserva();	
								}
	    APAR condicao FPAR      {  $1->jmp_falso = reserva();	}
	    ACH instrucoes FCH      {
									add("jump " + to_string($1->jmp_verdadeiro)); /* voltar até a condição do while*/
									trocar($1->jmp_falso,(string)$4 + " r0 r1 " + to_string(linhaAtual()+1));
									delete $1;
								}
	   
condicao: expressao MAIOR expressao         { add("pop r1", "pop r0");    $$ = "jle"; } /* operadores vem em ordem invertida*/
|	      expressao		                    { add("pop r0", "move r1 0"); $$ = "jeq"; } /* Qualquer coisa diferente de zero é  verdadeiro*/
| 		  expressao IGUAL expressao         { add("pop r1", "pop r0");    $$ = "jne"; }
| 		  expressao DIFERENTE expressao     { add("pop r1", "pop r0");    $$ = "jeq"; }
| 		  expressao MENOR expressao         { add("pop r1", "pop r0");    $$ = "jge"; }
|         expressao MENORIGUAL expressao    { add("pop r1", "pop r0");    $$ = "jgt"; }
|         expressao MAIOR expressao         { add("pop r1", "pop r0");    $$ = "jle"; }
|         expressao MAIORIGUAL expressao    { add("pop r1", "pop r0");    $$ = "jlt"; }
; 


funcao: FUNCAO VAR APAR FPAR { if(funcoes.count($2)) {
									yyerror("BROTHER, TEM MAIS DE UMA FUNCAO COM MESMO NOME!");
							    }
								funcoes[$2] = linhaAtual() + 1;
							 }
  ACH instrucoes FCH  		 { add("ret"); }
;


instrucao: VAR ATRIB expressao	{ add("pop r1","store r1 "+getPosMemo((string)$1)); memo[(string)$1] = $3;		}
| ESCREVA expressao				{ add("pop r1","print r1"); 					}
| LEIA VAR						{ add("read r1","store r1 "+getPosMemo($2));	}
;

expressao: termo 		{ $$ =  (int)$1;				}
| expressao ADD termo 	{ $$ =  (int)$1 +  (int)$3;		add("pop r2","pop r1", "add r1 r1 r2", "push r1");}
| expressao SUB termo 	{ $$ =  (int)$1 -  (int)$3;		add("pop r2","pop r1", "sub r1 r1 r2", "push r1");}
;

termo: fator 		{ $$ =  (int)$1;			}
| termo MUL fator 	{ $$ =  (int)$1 *  (int)$3; add("pop r2","pop r1", "mul r1 r1 r2", "push r1");}
| termo DIV fator 	{ $$ =  (int)$1 /  (int)$3; add("pop r2","pop r1", "div r1 r1 r2", "push r1");}
| termo MOD fator   { $$ =  (int)$1 %  (int)$3; add("pop r2","pop r1", "mod r1 r1 r2", "push r1");}
;

fator: base 			{ $$ = (int) $1; }
| fator POT expoente	{ $$ = (int) pow((int)$1,(int)$3);	add("pop r2","pop r1", "pot r1 r1 r2", "push r1");	}
| APAR expressao FPAR 	{ $$ =  (int)$2; }
;

base: VAR 		{ $$ = memo[(string)$1]; add("load r1 "+getPosMemo((string)$1) ,"push r1"); }
| NUM			{ $$ =  (int)$1; 		 add("mov r1 "+to_string($1),"push r1");		    }
;

expoente: VAR 	{ $$ = memo[(string)$1];	add("load r1 "+getPosMemo((string)$1),"push r1");}
| NUM			{ $$ = $1;					add("mov r1 "+to_string($1),"push r1");		     }
;
%%

int main(int argc, char **argv){
	yyin = fopen("input", "r");
	reserva(); // espaco para pular para a funcao "principal"
	yyparse(); // roda o parser
	if(codigoMv[0].empty()){
		yyerror("'Principal' não foi declarada! (otario!)");
	}
	fclose(yyin);
	
	for(int i = 0 ; i < (int)codigoMv.size() ; ++i){
		printf("%s\n",codigoMv[i].data());		
	}
	return 0;
}

void yyerror(const char *s){
	fprintf(stderr, "error: %s\n", s);
}
