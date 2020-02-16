#include "instruction.h"
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>

class lexer_mv{
  public:
  std::string in;
  std::vector<instruction> LISTA;

  lexer_mv(std::string &str){
    in = str;
  }

  // OK
  bool process(){
    std::stringstream ss(in);
    instruction aux;
    LISTA.clear();
    while(ss>>aux.operation){
      aux.op2 = aux.op3 = "";
      int qtdop = qtd_operators(aux.operation);
      if(qtdop == -1){
        return false;
      }
      ss >> aux.op1;
      if(qtdop >= 2) ss >> aux.op2;
      if(qtdop == 3) ss >> aux.op3;
      if ( aux.valid() ){
        LISTA.push_back(aux);
      }
      else{
      else{
        return false;
      }
    }
    return true;
  };
  std::vector<instruction> getLista(){
    return LISTA;
  }
};
