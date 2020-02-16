// by: Italo Fernandes
// ATENÇÂO!?#%
// compilado com: g++ -Wall -Wextra -fsanitize=address -std=c++11 -o "%e" "%f"



/*
  GRAMATICA:

  EXPRESSAO ->  TERMO RESTO1
  RESTO1    ->  + TERMO RESTO1 | - TERMO RESTO1 | EPSILON
  TERMO     ->  FATOR RESTO2
  RESTO2    ->  * FATOR RESTO2 | / FATOR RESTO2 | % FATOR RESTO2 | EPSILON
  FATOR     ->  BASE RESTO3    |  ( EXPRESSAO )                                 /// MODIFICACAO NECESSARIA AQUI
  RESTO3    ->  ^ EXPOENTE     |  EPSILON
  BASE      ->  ID  | NUM
  EXPOENTE  ->  ID  | NUM


*/

#include "parser.h"

using namespace std;

int main(){


  // teste alfa
  // analyzer::Parser P("1+2+3-2/2*2%2+60+1+2+(10+10)+2*1;");
  // analyzer::Parser P("(1)+(2)+(3);");
  // analyzer::Parser P("123+123+123+123+4+5+6+8000*(90*-1)");
  // analyzer::Parser P("70*2%1+1+2-1-4/2^10/10/10/10/10+(2)^9000000;");
  // analyzer::Parser P("+10");
  analyzer::Parser P("10+2+-2;");         /// PROBLEMA NO LEXIXO?!!!?!??!?!

  cout << "TOKEN\tVALUE\n";

  auto LISTA = P.getListaToken();

  for (auto i : LISTA){
    cout << tkn::types[i.type] << "\t" << i.value << '\n';
  }
  cout << "\n\n";

  int resultado = P.checkExpressao();
  cout << (resultado == SUCESS ? "\nSUCESS!" : "\nFALED!") << '\n';

  cout <<"\n";
}
