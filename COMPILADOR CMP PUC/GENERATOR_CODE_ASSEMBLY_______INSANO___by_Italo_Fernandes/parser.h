#ifndef parser_h
#define parser_h
#include "lexer.h"

//~ #define debug(str_) std::cerr << str_
#define debug(str_) ;               // gambiarra do seculo

#define SUCESS (-1)

/*
  se a expressao estiver certa, apos a checagem, o token atual sera um delim ';'
  se deu errado eu sei o primeiro token que deu erro, vai ser indicado por posErro
  GRAMATICA EXPRESSAO:
  EXPRESSAO ->  TERMO RESTO1
  RESTO1    ->  + TERMO RESTO1 | - TERMO RESTO1 | EPSILON
  TERMO     ->  FATOR RESTO2
  RESTO2    ->  * FATOR RESTO2 | / FATOR RESTO2 | % FATOR RESTO2 | EPSILON
  FATOR     ->  BASE RESTO3    |  ( EXPRESSAO )
  RESTO3    ->  ^ (EXPOENTE)  | ^ EXPOENTE   |  EPSILON          ~ EXPOENTE ENTRE PARENTESES TBM PODE!
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

  Parser(std::vector<token> &aux){   // construtor
    LISTA = aux;
    idx = 0;
    if((int)LISTA.size() > idx)
      atual = LISTA[idx];
  }

  int list_instruction(){
    while(posErro == SUCESS && !chegouaofim()){
      instruction();
    }
    return posErro;
  }

  void instruction(){
    if(stop()) return;

    if(atual.type == ID){
      nextToken();
      if(chegouaofim() || atual.value != "="){
        posErro = idx;
        return;
      }
      nextToken();
      expressao();
    }
    else if(atual.type == PRINT){
      nextToken();
      if(stop()) return;
      expressao();
    }
    else if(atual.type == SCAN){
      nextToken();
      if(chegouaofim() || atual.value != "("){
        posErro = idx;
        return;
      }
      nextToken();
      if(chegouaofim() || atual.type != ID){
        posErro = idx;
        return;
      }
      nextToken();
      if(chegouaofim() || atual.value != ")"){
        posErro = idx;
        return;
      }
      nextToken();
    }
    if(atual.value != ";") posErro = idx; // token atual sempre sera o ";" depois da instrução (qualquer que seja)
    nextToken();
  }

  // retorna posicao do primeiro token errado, se estiver tudo certo, retona SUCESS
  int check(){
    posErro = SUCESS;
    list_instruction();
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
    if(stop()) return;
    if(atual.value == "^"){
      debug("OPERADOR POTENCIA RECONHECIDO\n");
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
      resto3();
    }
    else if(atual.value == "("){
      debug("  $$$ OPERADOR ( RECONHECIDO\n");
      nextToken(); // é igual a '('
      expressao();
      if(atual.value == ")"){
        debug("  $$$ OPERADOR ) RECONHECIDO\n");
        nextToken(); // tem de ser igual a ')'
        if(stop()) return;
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
    if(atual.value == "("){
      fator();
    }
    else if(atual.type == ID || atual.type == NUM){
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

  // chegou ao final da analise da instrução atual?
  // ou
  // já achou algum erro
  bool stop(){
    if(posErro != SUCESS) return true;
    if(chegouaofim()){
      if(posErro == SUCESS) posErro = idx; // chegou ao fim sem um ';'
      return true;
    }
    return fimDeIntrucao();                 // achou um ';'
  }

  std::vector<token> getListaToken(){
    return LISTA;
  }
};
#endif
