#ifndef Lexer_h
#define Lexer_h
#include "token.h"
#include <map>
#include <vector>


/*
  ID         0
  NUM        1
  OPR_AR     2
  OPR_REL    3
  OPR_LOG    4
  DELIM      5
  IF         6
  ELSE       7
  WHILE      8
  ATRIB      9
  ERRO      10
	PRINT			11
	SCAN			12

  std::string const types[maxt] = {"ID", "NUM", "OPR_AR", "OPR_REL", "OPR_LOG", "DELIM", "IF", "ELSE", "WHILE", "ATRIB", "ERRO", "PRINT","SCAN"}; // "hash" simples dos tipos, posicao da string eh seu hash - "mapa" e o contra hash

*/

class Lexer{
  private:

  std::map<std::string,int> mapa, palavrasReservadas; // unordered_map das palavras reservadas, se encontrar um ID, vou verificar se este ID esta neste map...
  // caso esteja, eh uma palavra revervada e seu type é o conteudo desta string no map

  public:
  Lexer(){ 
		pre();   
  }
  
  void pre(){
		// contra mapa
    for(int idx = 0 ; idx < tkn::maxt ; ++idx){
      mapa[ types[idx] ] = idx;
      // types esta na class token!
    }

    // MAPEANDO Palavras reservadas
    palavrasReservadas["while"] = 8;
    palavrasReservadas["else"] = 7;
    palavrasReservadas["if"] = 6;
    palavrasReservadas["and"] = 4;
    palavrasReservadas["or"] = 4;
    palavrasReservadas["not"] = 4;
    palavrasReservadas["print"] = 11;
    palavrasReservadas["scan"] = 12;
	}

  bool isdelim(const char & a){
    for(auto i : delim)
      if(a == i) return true;
    return false;
  }

  bool isopr_ar (const char & a){
    for(auto i : opr_ar)
      if(a == i) return true;
    return false;
  };

  std::vector<token> analisa(std::string in){

    std::vector<token> LIST;

    // funcao lambda - trata caso ID
    auto trata_caso_id = [&](std::string token_atual)->void{
      if(palavrasReservadas.count(token_atual))
        LIST.push_back({palavrasReservadas[token_atual],token_atual});
      else
        LIST.push_back({ ID , token_atual });
    };

    // analisador comeca aqui!
    // tratei caso a caso - fluxograma ta cmg..
    // fiz com o automato tbm, porem o codigo n ficou legivel como este.

  // CASO QUE VAI DAR ERRO: 10---10 ////////////////////// arrumar sa porra dps

    int sz = in.size(), idx = 0;
    std::string token_atual;
    std::string nd = "";
    while(sz > idx){

      if(in[idx] == ' ' || in[idx] == '\n'){ // ignora espaço
        idx++;
        continue;
      }

      token_atual = "";

      if(isalpha(in[idx])){                                                           // TRATA ID
        while(sz > idx && (isalpha(in[idx]) || isdigit(in[idx])) ) token_atual += in[idx++];
        trata_caso_id(token_atual);
      }
      else if(in[idx] == '-' || isdigit(in[idx])){  // TRATA DIGITO
        if(in[idx] == '-')
          token_atual = '-',idx++;

        if(sz > idx && isdigit(in[idx])){
          while(sz > idx && isdigit(in[idx])) // enquanto for digito
            token_atual += in[idx++];

          if(sz > idx && in[idx] == '.'){     // o numero eh decimal

            if(sz > idx+1 && isdigit(in[idx+1])){
              token_atual += in[idx];
              idx++;

              while(sz > idx && isdigit(in[idx])) // pega parte decimal
                token_atual+=in[idx++];

              LIST.push_back({ NUM ,token_atual});
            }
            else { // caso em que encontra "NUM." , o ponto era zueira
              LIST.push_back({ NUM , token_atual}),
              LIST.push_back({ ERRO , "." }),
              idx++;
            }
          }
          else LIST.push_back({ NUM ,token_atual}); // OPR_AR que veio apos um digito!

          if(sz > idx && isopr_ar(in[idx])) { // OPR_AR apos NUM (pode ser um '-')
            LIST.push_back({ OPR_AR ,nd+in[idx]});
            idx++;
          }
        }
        else LIST.push_back({ OPR_AR ,token_atual});  // '-' não faz parte de um numero .: considera opr_ar
      }
      else if(isdelim(in[idx])){
        LIST.push_back({ DELIM ,nd+in[idx]});  // trata DELIM
        idx++;
      }
      else if(isopr_ar(in[idx])){
        LIST.push_back({ OPR_AR ,nd+in[idx]});  // trata OPR_AR
        idx++;
      }
      else{
        // tratar casos de OPERADORES RELACIONAIS na "UNHA"
        if(sz > idx+1 && in[idx] == '!' && in[idx+1] == '='){
          LIST.push_back({ OPR_REL ,"!="});       // !=
          idx+=2;
        }
        else if(in[idx] == '='){
          if(sz > idx+1 && in[idx+1] == '='){
            LIST.push_back({ OPR_REL ,"=="});     // ==
            idx+=2;
          }
          else{
            LIST.push_back({ ATRIB ,"="});        // =
            idx++;
          }
        }
        else if(in[idx] == '<'){
          if(sz > idx+1 && in[idx+1] == '='){
            LIST.push_back({ OPR_REL ,"<="});       // <=
            idx+=2;
          }
          else{
            LIST.push_back({ OPR_REL ,"<"});      // <
            idx++;
          }
        }
        else if(in[idx] == '>'){
          if(sz > idx+1 && in[idx+1] == '='){
            LIST.push_back({ OPR_REL ,">="});       // >=
            idx+=2;
          }
          else
            LIST.push_back({ OPR_REL ,">"}),idx++;       // >
        }
        else{
          LIST.push_back({ ERRO , nd+in[idx]});     // erro lexico
          idx++;
        }
      }
    }
    return LIST;
  }
};
#endif
