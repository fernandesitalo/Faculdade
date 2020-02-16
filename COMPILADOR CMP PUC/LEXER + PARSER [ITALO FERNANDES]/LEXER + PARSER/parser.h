#ifndef parser_h
#define parser_h
#include "lexer.h"

namespace analyzer{

#define debug(str_) std::cerr << str_                                                   \


#define SUCESS (-1)

/*
  se a expressao estiver certa, apos a checagem, o token atual sera um delim ';'
  se deu errado eu sei o primeiro token que deu erro, vai ser indicado por posErro


  GRAMATICA EXPRESSAO:

  EXPRESSAO ->  TERMO RESTO1
  RESTO1    ->  + TERMO RESTO1 | - TERMO RESTO1 | EPSILON
  TERMO     ->  FATOR RESTO2
  RESTO2    ->  * FATOR RESTO2 | / FATOR RESTO2 | % FATOR RESTO2 | EPSILON
  FATOR     ->  BASE RESTO3    |  ( EXPRESSAO )                                 /// MODIFICACAO NECESSARIA AQUI
  RESTO3    ->  ^ EXPOENTE     |  EPSILON
  BASE      ->  ID  | NUM
  EXPOENTE  ->  ID  | NUM


*/

class Parser{
  private:
  std::vector<token> LISTA;   // lista de token gerada no lexer
  token atual;              // token atual
  int idx;            // index do token atual
  int posErro;

  public:
  Parser(std::string in){   // construtor
    Lexer L;
    LISTA = L.analisa(in);
    idx = 0;
    if((int)LISTA.size() > idx) atual = LISTA[idx];
  }

  // retorna posicao do primeiro token errado, se estiver tudo certo, retona SUCESS
  int checkExpressao(){
    posErro = SUCESS;
    expressao();
    return posErro;
  }

  void expressao(){

    if(stop()) return;

    if(atual.type == ID || atual.type == NUM){
      termo();
      resto1();
    }
    else if(atual.value == "("){
      termo();
      resto1();
    }
    else{
      debug("ERRO EXPRESSAO!\n");
      if(posErro == SUCESS)  posErro = idx;
    }
  }

  void termo(){

    if(stop()) return;

    if(atual.value == "("){
      fator();
      resto2();
    }
    else if(atual.type == ID || atual.type == NUM){
      fator();
      resto2();
    }
    else{
      debug("ERRO TERMO!\n");
      if(posErro == SUCESS)  posErro = idx;
    }
  }

  void resto1(){
    if(chegouaofim()){
      if(posErro == SUCESS) posErro = idx;
      return;
    }
    if( fimDeIntrucao() ) return;

    if(atual.value == "+"){
      debug("  $$$ OPERADOR + RECONHECIDO\n");
      nextToken();
      termo();
      resto1();
    }
    else if(atual.value == "-"){
      debug("  $$$ OPERADOR - RECONHECIDO\n");
      nextToken();
      termo();
      resto1();
    }
    else{
      debug("EPSILON RESTO1\n");
    }
  }

  void resto2(){

    if(stop()) return;

    if(atual.value == "*"){
      debug("  $$$ OPERADOR * RECONHECIDO\n");
      nextToken();
      fator();
      resto2();
    }
    else if(atual.value == "/"){
      debug("  $$$ OPERADOR / RECONHECIDO\n");
      nextToken();
      fator();
      resto2();
    }
    else if(atual.value == "%"){
      debug("  $$$ OPERADOR % RECONHECIDO\n");
      nextToken();
      fator();
      resto2();
    }
    else{
      debug("EPSILON RESTO2\n");
    }
  }

  void resto3(){
    if(chegouaofim()){
      if(posErro == SUCESS) posErro = idx;
      return;
    }
    if( fimDeIntrucao() ) return;

    if(atual.value == "^"){
      nextToken();
      expoente();
    }
    else{
      debug("EPSILON RESTO3\n");
    }
  }

  void fator(){
    if(stop()) return;

    if(atual.type == ID || atual.type == NUM){
      base();
    }
    else if(atual.value == "("){
      debug("  $$$ OPERADOR ( RECONHECIDO\n");
      nextToken(); // é igual a '('
      expressao();
      if(atual.value == ")"){

      debug("  $$$ OPERADOR ) RECONHECIDO\n");

      nextToken(); // tem de ser igual a ')'

        if(stop()) return;

        if(atual.value  == "+" || atual.value == "-")
          resto1();
        else if(atual.value == "*" || atual.value == "/" || atual.value == "%")
          resto2();
        else if(atual.value == "^")
          resto3();
        else{
          if(posErro == SUCESS)  posErro = idx;
        }
      }
      else{
        if(posErro == SUCESS)  posErro = idx;
      }
    }
    else{
      if(posErro == SUCESS)  posErro = idx;
    }
  }

  void base(){
    if(atual.type == ID || atual.type == NUM){
      debug("  ### BASE RECONHECIDA\n");
      nextToken();
    }
    else{
      if(posErro == SUCESS) posErro = idx;
    }
  }

  void expoente(){
    if(atual.type == ID || atual.type == NUM){
      debug("  ### EXPOENTE RECONHECIDO\n");
      nextToken();
    }else{
      if(posErro == SUCESS) posErro = idx;
    }
  }

  // anda com o 'ponteiro' para o token atual
  void nextToken(){
    idx++;
    if(!chegouaofim())
      atual = LISTA[idx];
  }

  // nao tem mais token
  bool chegouaofim(){
    return (idx == (int)LISTA.size());
  }

  // achou um ';'
  bool fimDeIntrucao(){
    if(!chegouaofim()) return atual.value == ";";
    return false;
  }

  // chegou ao final da analise ou n?
  bool stop(){
    if(chegouaofim()){
      if(posErro == SUCESS) posErro = idx; // chegou ao fim sem um ';'
      return true;
    }
    return fimDeIntrucao();                 // achou um ';'
  }

  //
  std::vector<token> getListaToken(){
    return LISTA;
  }

};
#endif
}
