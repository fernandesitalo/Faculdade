// by: Italo Fernandes
// ATENÇÂO!?#%
// compilado com: g++ -Wall -Wextra -fsanitize=address -std=c++11 -o "%e" "%f"



/*
   
  GRAMATICA:

  EXPRESSAO ->  TERMO RESTO1
  RESTO1    ->  + TERMO RESTO1 | - TERMO RESTO1 | EPSILON
  TERMO     ->  FATOR RESTO2
  RESTO2    ->  * FATOR RESTO2 | / FATOR RESTO2 | % FATOR RESTO2 | EPSILON
  FATOR     ->  BASE RESTO3    |  ( EXPRESSAO )
  RESTO3    ->  ^ (EXPOENTE)  | ^ EXPOENTE   |  EPSILON					 ~ EXPOENTE ENTRE PARENTESES TBM PODE!
  BASE      ->  ID  | NUM
  EXPOENTE  ->  ID  | NUM


	// OPERACOES SOMENTE COM NUMEROS INTEIRO!!!!!!!!!!!!!
	* PAU NO CU DO USUARIO
*/

#include "interpreter.h"


using namespace std;

int main(){ 
  analyzer::Interpreter I("A = 2; B = 0; print(A^B); print(A+B); print(A-B); print(A*B); print(A%B); print(A/B);");
  cout <<  (I.executa() == SUCESS ? "SUCESS" : "TEM MERDA NESSE CODIGO!\n") << '\n';
  cout <<"\n";
}
