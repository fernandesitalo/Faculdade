#ifndef token_h
#define token_h
#include <iostream>
#include <string>

#define ID         0
#define NUM        1
#define OPR_AR     2
#define OPR_REL    3
#define OPR_LOG    4
#define DELIM      5
#define ATRIB      9
#define ERRO       10

namespace tkn{

int const maxt = 20;
std::string const delim = "(),;";
std::string const opr_ar = "+-/%*^";
std::string const types[maxt] = {"ID", "NUM", "OPR_AR", "OPR_REL", "OPR_LOG", "DELIM", "IF", "ELSE", "WHILE", "ATRIB", "ERRO", "VAZIO"}; // "hash" simples dos tipos, posicao da string eh seu hash - "mapa" e o contra hash

}

using namespace tkn;

// quem acessa essa classe, é uma classe privada, a  camada mais alta nem vai saber que essa classe existe, entao pode ser tudo publico

class token{ // token insano
public:
  int type;
  std::string value;
  token():type(11),value(""){/*TOKEN VAZIO*/}
  token(int type,std::string value):type(type),value(value){}

  float getValue(){
    if(type == NUM){
      return std::stof(value);
    }
    return 0;
  }
};
#endif


