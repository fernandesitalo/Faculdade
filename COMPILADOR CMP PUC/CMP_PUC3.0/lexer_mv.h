#include "instruction.h"
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>

class lexer_mv{
  public:
  std::vector<std::string> in;
  std::vector<instruction> LISTA;

  lexer_mv(std::vector<std::string> &str){
    in = str;
  }

  // OK
  bool process(){
   	instruction aux;LISTA.clear(); 
    for(auto line : in){
		std::stringstream ss(line);
		
		//~ std::cout << " ## " << line << '\n';
		int cnt = 0;
		for(auto i : line){
			if(i == ' ') cnt++;
		}
		
		if(cnt == (int)line.size()){ // NOOPERATION
			aux.operation = "nooperation";
			LISTA.push_back(instruction(aux));
		}
		else {
			while(ss>>aux.operation){
			  aux.op2 = aux.op3 = "";
			  int qtdop = qtd_operators(aux.operation);
			  
			  //~ std::cout << " lexer_mv.h :   " << aux.operation << " " << qtdop << '\n';
			  if(qtdop == 0) {
				 LISTA.push_back(aux);
				 continue;
			  }
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
				return false;
			  }
			}
		}
	}
	
    return true;
  };
  std::vector<instruction> getLista(){
    return LISTA;
  }
};
