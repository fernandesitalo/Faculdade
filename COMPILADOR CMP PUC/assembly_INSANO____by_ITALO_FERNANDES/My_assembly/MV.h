#include "lexer_mv.h"
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <iostream>

const int maxregs = 20;
const int maxmemo = 2e4;

/*
 "DOCUMENTACAO BASICA"
 *
 * TA TUDO COMO INTEIRO.... CASO NECESSARIO COLOCAR UNS DOUBLE NESSSA HISTORIA!!
 * POSICAO DE MEMORIA EH UM NUMERO INTEIRO !!
 * REGISTRADORES VAO DE 'r0' ATE 'r9'
 * A MEMORIA TEM 2e4 POSICOES !!
 *
 *

  OPERACOES DE MEMORIA:
    - "load" : [registrador] [registrador|valor - posicao de memoria] // obtem o valor da posicao de op2 na memoria e coloca em op1
    - "store": [registrador] [registrador|valor - posicao de memoria] // guarda na posicao op2 da memoria o valor de op1

  OPERACOES COM PILHA:
   - "pop" : [registrador|valor]  // tira da pilha o valor de op1
   - "push": [registrador|valor]  // coloca na pilha o valor de op1

  OPERACOES ARITIMETICAS:
   - "add" : [registradorDestino]  [registrador] [registrador|valor] // regDest = op1+op2
   - "sub" : [registradorDestino]  [registrador] [registrador|valor] // regDest = op1-op2
   - "mul" : [registradorDestino]  [registrador] [registrador|valor] // regDest = op1*op2
   - "div" : [registradorDestino]  [registrador] [registrador|valor] // regDest = op1/op2
   - "mod" : [registradorDestino]  [registrador] [registrador|valor] // regDest = op1%op2
   - "pot" : [registradorDestino]  [registrador] [registrador|valor] // regDest = op1^op2

   OPERACOES LOGICAS:
   - "and" : [registradorDestino]  [registrador|valor] [registrador|valor] // regDest = op1&op2
   - "or"  : [registradorDestino]  [registrador|valor] [registrador|valor] // regDest = op1|op2
   - "not" : [registradoDestino] [registrador|valor] // regDest = !op1

   OPERACOES DESVIOS:
   - "jeq" : [registrador|valor] [registrador|valor] [registrador|valor] // se op1 == op2 vai para a posicao op3
   - "jne" : [registrador|valor] [registrador|valor] [registrador|valor] // se op1 != op2 vai para a posicao op3
   - "jlt" : [registrador|valor] [registrador|valor] [registrador|valor] // se op1 <  op2 vai para a posicao op3
   - "jle" : [registrador|valor] [registrador|valor] [registrador|valor] // se op1 <= op2 vai para a posicao op3
   - "jgt" : [registrador|valor] [registrador|valor] [registrador|valor] // se op1 >  op2 vai para a posicao op3
   - "jge" : [registrador|valor] [registrador|valor] [registrador|valor] // se op1 >= op2 vai para a posicao op3

  OPERACOES INPUT AND OUTPUT
   - "print" : [registrador|valor] // imprime op1 na tela
   - "read" :  [registrador] // le o valor desse registrador apatir da entrada - arquivo/teclado
*/



class MV{
  public:
  std::vector<instruction> Instrucoes;
  std::stack<int> stk; // para empilhar registradores
  int registrador[maxregs];
  int memoria[maxmemo];
  int pc;

  public:
  MV(std::string &in){
    pc = 0;
    memset(memoria,0,sizeof memoria);
    memset(registrador,0,sizeof registrador);
    lexer_mv LEXER(in);
    if(!LEXER.process()){
      std::cout << "O CODIGO ESTA ERRADO!\n";
      exit(0);
    }
    Instrucoes = LEXER.getLista();
  }

  void debug(){
    // ajudou nos testes alfa
    std::cout << "------------------------\n";
    std::cout << "r1: " << registrador[1] << "    r2: " << registrador[2] << "    r3: " << registrador[3] << '\n';
    std::cout << "pc: " << pc<< "\n";
    std::cout << "------------------------\n\n\n";
  }

  // simula as intrucoes
  void process(){
    instruction cur;
    while(!itsOver()){
      // std::cout << "HERE\n";

      cur = getInstructionCurrent();

      if(is_opIO(cur.operation)){
        process_IO(cur);
      }
      if(is_opjump(cur.operation)){
        process_opjump(cur);
      }
      else if(is_mov(cur.operation)){
        process_mov(cur);
      }
      else if(is_aritmetic(cur.operation)){
        process_aritmetic(cur);
      }
      else if(is_logic(cur.operation)){
        process_logic(cur);
      }
      else if(is_opmemo(cur.operation)){
        process_opmemo(cur);
      }
      else if(is_opstack(cur.operation)){
        process_opstack(cur);
      }
      nextIntruction();
      // debug();
    }
  }

  // "mov"
  void process_mov(instruction & current){
    int &regDest = registrador[getRegs(current.op1)];
    int regOp1 = getOperating(current.op2);
    regDest = regOp1;
  }
  // print and read
  void process_IO(instruction & current){
    if(current.operation == "print"){
      std::cout << getOperating(current.op1) << '\n';
    }else{
      std::cin >> registrador[getRegs(current.op1)];
    }
  };

//"add","sub","mul","div","mod","pot"
  void process_aritmetic(instruction &current){
    int &regDest = registrador[getRegs(current.op1)];
    int regOp1 = getOperating(current.op2);
    int regOp2 = getOperating(current.op3);

    if(current.operation == "add"){
      regDest = regOp1+regOp2;
    }
    else if(current.operation == "sub"){
      regDest = regOp1-regOp2;
    }
    else if(current.operation == "mul"){
      regDest = regOp1*regOp2;
    }
    else if(current.operation == "div"){
      regDest = regOp1/regOp2;
    }
    else if(current.operation == "mod"){
      regDest = regOp1%regOp2;
    }
    else{ // "pot"
      regDest = pow(regOp1,regOp2);
    }
  }

//"and","or","not"
  void process_logic(instruction &current){
    int &regDest = registrador[getRegs(current.op1)];
    int regOp1 = getOperating(current.op2);
    int regOp2 = getOperating(current.op3);
    if(current.operation == "and"){
      regDest = regOp1&regOp2;
    }
    else if(current.operation == "or"){
      regDest = regOp1|regOp2;
    }
    else { // not
      regDest = !regOp1;
    }
  }

//  "load","store"
  void process_opmemo(instruction &current){
    int &regDest = registrador[getRegs(current.op1)];
    int regOp1 = getOperating(current.op2);
    if(current.operation == "load"){
      regDest = memoria[regOp1];
    }else{ // store
      memoria[regOp1] = regDest;
    }
  }

//"pop","push"
  void process_opstack(instruction &current){
    int &reg = registrador[getRegs(current.op1)];
    if(current.operation == "pop"){
      reg = stk.top();
      stk.pop();
    }
    else{
      stk.push(reg);
    }
  }

//"jump","jeq","jne","jlt",jle","jgt","jge"
  void process_opjump(instruction & current){
    int reg1 = registrador[getRegs(current.op1)];
    int reg2 = getOperating(current.op2);
    int location = getOperating(current.op3) - 1; // vou para uma acima ... e depois vou dar um nextInstruction()....

    if(current.operation == "jump"){
      pc = reg1; // location
    }
    else if(current.operation == "jeq"){
      if(reg1 == reg2) pc = location;
    }
    else if(current.operation == "jne"){
      if(reg1 != reg2) pc = location;
    }
    else if(current.operation == "jlt"){
      if(reg1 < reg2) pc = location;
    }
    else if(current.operation == "jle"){
      if(reg1 <= reg2) pc = location;
    }
    else if(current.operation == "jgt"){
      if(reg1 > reg2) pc = location;
    }
    else{// if(current.operation == "bge"){
      if(reg1 >= reg2) pc = location;
    }
  }

  // ------------------------------------------------
  // ------------------------------------------------
  instruction getInstructionCurrent(){
    return Instrucoes[pc];
  };

  void nextIntruction(){
    pc++;
  };

  int getRegs(std::string &aux){
    return (aux[1]-'0');
  }

  bool itsOver(){ // é o final?
    return (pc >= (int)Instrucoes.size());
  };

  int getOperating(std::string aux){
    if((int)aux.size() == 0) return 0;
    if(is_reg(aux))
      return registrador[getRegs(aux)];
    if(is_number(aux))
      return std::stoi(aux);
    std::cout << "OPERADOR INVALIDO\n";
    exit(0);
  };
  // -----------------------------------------
  // -----------------------------------------
};

