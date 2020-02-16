#ifndef generatorAssembly_h
#define generatorAssembly_h
#include "parser.h"
#include <stack>
#include <math.h>

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

  TODAS AS VERIFICAÇÕES DESNECESSARIAS FORAM TIRADAS... (JAH QUE TENHO CERTEZA DE QUE ESTA TUDO CERTO.....)
*/

// para melhor leitura do codigo...
#define ADD   101
#define SUB   102
#define DIV   103
#define MULT  104
#define REST  105
#define POT   106

class generatorAssembly{
  private:
  std::vector<token> LISTA;   // lista de token gerada no lexer
  token atual;              // token atual
  int idx;            // index do token atual
  std::stack<int> stk; // pilha normal --- INTEIROS
  std::map<std::string, int > memo; // Memoria
  std::map<std::string, int > idx_memo;// <variavel , posicao na memoria>
  int Erro;

  public:
  generatorAssembly(std::string in){
    Parser P(in);
    LISTA = P.getListaToken();
    Erro = P.check();
    idx = 0;        // ponteiro para instrução atual
    memo.clear();   // limpa memoria
    if((int)LISTA.size() > idx)
      atual = LISTA[idx];
  }

  // GERA CODIGO EM ASSEMBLY
  int GERA_CODIDO(){
    if(Erro != SUCESS) return Erro;
    list_instruction();
    return SUCESS;
  }

  // LISTA_DE_INSTRUCAO -> INTRUCAO LISTA_DE_INSTRUCAO | EPSILON
  void list_instruction(){
    while(!chegouaofim()){
      instruction();
    }
  }

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  void scan(std::string &str){
    /// int aux;
    /// std::cin >> aux; /// NÃO EH PARA LER NADA, SOH GERAR O CODIGO!!!!!!!!

    // variavel nao existia na memoria ainda....
    if(!memo.count(str)){
      idx_memo[str] = memo.size();
    }
//    memo[str] = aux;
    printf("read\tr1\n");
    printf("store\tr1 %d\n",idx_memo[str]); //  guarda o valor da variavel lida na memoria
    printf("\n");
  }

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  void print(int aux){
    printf("pop\tr1\n");
    printf("print\tr1\n");
    printf("\n");
  }

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  void instruction(){
    if(fimDeIntrucao()) return;
    if(atual.type == ID){           // ATRIBUICAO
      std::string aux = atual.value;
      nextToken(); // id
      nextToken(); // =
      expressao();
      // variavel nao existia ainda na memoria
      if(!memo.count(aux)){
        idx_memo[aux] = memo.size();
        memo[aux] = 0;
      }
      memo[aux] = stk.top();
      stk.pop();
      printf("pop\tr1\n");
      printf("store\tr1 %d\n",idx_memo[aux]); // coloca na respectiva posicao index_memoria
      printf("\n");
    }
    else if(atual.type == PRINT){   // ESCRITA
      nextToken();
      expressao();
      print(stk.top()); // ok - gera codigo
      stk.pop();
    }
    else if(atual.type == SCAN){    // LEITURA
      nextToken(); // scan
      nextToken(); // (
      scan(atual.value);  // ok - gera codigo
      nextToken(); // id
      nextToken(); // )
    }
    nextToken();
  }

  // OBTEN ELEMENTO DO TOKEN ... OU DA MEMORIA(SE ID) OU O VALOR NUMERICO (SE NUM)
  int get(){
    int aux = stk.top();
    stk.pop();
    return aux;
  }

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  void calc(int op){
    int op1 = get(); // tira da pilha
    printf("pop\tr2\n");
    int op2 = get();  // tira da pilha
    printf("pop\tr1\n");

    if(op == ADD){
      stk.push( (op1+op2) );
      printf("add\tr1 r1 r2\n");
    }
    else if(op == SUB){
      stk.push((op1-op2));
      printf("sub\tr1 r1 r2\n");
    }
    else if(op == DIV){
      if(op2 == 0){
        /// NEM GRAVAR NO ARQUIVO
        std::cout << " DIVISÃO POR ZERO! (se fudeo)\n";
        exit(0); // encerrar o programa
      }
      stk.push((op1/op2));
      printf("div\tr1 r1 r2\n");
    }
    else if(op == REST){
      if(op2 == 0){
        /// NEM GRAVAR NO ARQUIVO
        std::cout << " DIVISÃO POR ZERO! (se fudeo)\n";
        exit(0); // encerrar programa
      }
      stk.push((op1%op2));
      printf("mod\tr1 r1 r2\n");
    }
    else if(op == POT){
      stk.push((int)pow(op1,op2));
      printf("pot\tr1 r1 r2\n");
    }
    else if(op == MULT){
      stk.push((op1*op2));
      printf("mul\tr1 r1 r2\n");
    }
    printf("push\tr1\n");
    printf("\n");
  }

  void expressao(){ // ok
    if(fimDeIntrucao()) return;
    if(atual.type == ID || atual.type == NUM){
      termo();
      resto1();
    }
    else{// if(atual.value == "("){
      termo();
      resto1();
    }
  }

  void termo(){  // ok
    if(fimDeIntrucao()) return;
    if(atual.value == "("){
      fator();
      resto2();
    }
    else if(atual.type == ID || atual.type == NUM){
      fator();
      resto2();
    }
  }

  void resto1(){ // ok
    if( fimDeIntrucao() ) return;
    if(atual.value == "+"){
      nextToken();
      termo();
      calc(ADD);
      resto1();
    }
    else if(atual.value == "-"){
      nextToken();
      termo();
      calc(SUB);
      resto1();
    }
  }

  void resto2(){ // ok
    if(fimDeIntrucao()) return;
    if(atual.value == "*"){
      nextToken();
      fator();
      calc(MULT);
      resto2();
    }
    else if(atual.value == "/"){
      nextToken();
      fator();
      calc(DIV);
      resto2();
    }
    else if(atual.value == "%"){
      nextToken();
      fator();
      calc(REST);
      resto2();
    }
  }

  void resto3(){ // ok
    if( fimDeIntrucao() ) return;
    if(atual.value == "^"){
      nextToken();
      expoente();
      calc(POT);
    }
  }

  void fator(){ // ok
    if(fimDeIntrucao()) return;

    if(atual.type == ID || atual.type == NUM){
      base();
      resto3();
    }
    else if(atual.value == "("){
      nextToken();
      expressao();
      nextToken();
    }
  }

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  int getValue(token aux){ // coloca em r1 o valor do token aux, estando na memoria ou sendo uma constante...
    if(aux.type == ID){
      printf("load\tr1 %d\n",idx_memo[aux.value]);
      return memo[aux.value];    // ID
    }
    printf("mov\tr1 %d\n",std::stoi(aux.value));
    return std::stoi(aux.value); // NUM
  };

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  void base(){
    int value = getValue(atual); // gera codigo - em r1 esta o valor do token atual
    stk.push(value);
    printf("push\tr1\n");
    nextToken();
    printf("\n");
  }

  // >>>>>>>> AQUI - gera codigo <<<<<<<
  void expoente(){
    if(atual.value == "("){
      fator();
    }else{
      int value = getValue(atual); // gera codigo -- em r1 esta o valor do token atual
      stk.push(value);
      printf("push\tr1\n");
      printf("\n");
      nextToken();
    }
  }

  void nextToken(){
    idx++;// anda com o 'ponteiro' para o token atual
    if(!chegouaofim())
      atual = LISTA[idx];
  }

  bool chegouaofim(){// nao tem mais token
    return (idx >= (int)LISTA.size());
  }

  bool fimDeIntrucao(){  // achou um ';'
    if(!chegouaofim()) return atual.value == ";";
    return false;
  }

  std::vector<token> getListaToken(){
    return LISTA;
  }
};
#endif
