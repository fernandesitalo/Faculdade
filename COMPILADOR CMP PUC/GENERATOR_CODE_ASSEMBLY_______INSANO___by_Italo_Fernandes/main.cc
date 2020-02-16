/*
>> by: Italo Fernandes
>> ATENÇÂO!?#%
>> compilado com: g++ -Wall -Wextra -fsanitize=address -std=c++11 -o "%e" "%f"
  GRAMATICA:
  *
  EXPRESSAO ->  TERMO RESTO1
  RESTO1    ->  + TERMO RESTO1 | - TERMO RESTO1 | EPSILON
  TERMO     ->  FATOR RESTO2
  RESTO2    ->  * FATOR RESTO2 | / FATOR RESTO2 | % FATOR RESTO2 | EPSILON
  FATOR     ->  BASE RESTO3    |  ( EXPRESSAO )
  RESTO3    ->  ^ (EXPOENTE)  | ^ EXPOENTE   |  EPSILON          ~ EXPOENTE ENTRE PARENTESES TBM PODE!
  BASE      ->  ID  | NUM
  EXPOENTE  ->  ID  | NUM
  // OPERACOES SOMENTE COM NUMEROS INTEIRO!!!!!!!!!!!!!
  * PAU NO CU DO USUARIO
*/

#include "generatorAssembly.h"
using namespace std;

#define PROGRAMA "prog"
#define MY_ASSEMBLY "CODIGO_ASSEMBLY_GERADO"

string read_archive(string nome_do_arquivo);

int main(){

  // string prog = read_archive(PROGRAMA); // taca no arquivo os programas
  string prog = "A = 10; B = 2; print(A^B); print(A+B); print(A-B); print(A*B); print(A%B); print(A/B);"; // PARA TESTE ALFA

  generatorAssembly GA(prog);
  cerr << "TESTANDO...\n";

  if(GA.GERA_CODIDO() == SUCESS){
    cerr << "GRAVANDO ASSEMBLY...\n";
    freopen(MY_ASSEMBLY,"w",stdout);
    GA = generatorAssembly(prog);
    GA.GERA_CODIDO();
    cerr << "FINISH\n";
  }
  else{
    cerr << "O CODIGO POSSUI ERROS!\n\n\n";
    cout << "O CODIGO POSSUI ERROS!\n\n\n";
  }

}


// ler arquivo, coloca o programa todo em uma string
string read_archive(string nome_do_arquivo){
  freopen(nome_do_arquivo.data(),"r",stdin);
  string prog,line;
  while(cin >> line){
    prog += line;
    prog += " ";
  }
  return prog;
}
