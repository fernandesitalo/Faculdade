#include <string>
#include <set>
#include <iostream>


/*TA FEIO MAIS TA BONITO - quantos operandos cada instrucao possui*/

const std::set<std::string> ZeroOperators = {"ret","nooperation"};
const std::set<std::string> oneOperators = {"push","pop","jump","print","read","print","read","call"};
const std::set<std::string> twoOperators = {"load","store","not","mov","call"};
const std::set<std::string> threeOperators = {"add","sub","mul","div","mod","pot","and","or","jeq","jne","jlt","jle","jgt","jge"};


/* NINGUEM MEXE AQUI NESSES CARALHO */
const std::set<std::string> aritmetic = {"add","sub","mul","div","mod","pot"};
const std::set<std::string> logic = {"and","or","not"};
const std::set<std::string> opmemo = {"load","store"};
const std::set<std::string> opstack = {"pop","push"};
const std::set<std::string> opjump = {"jump","jeq","jne","jlt","jle","jgt","jge"};
const std::set<std::string> opIO = {"print","read"}; // input and output

/*PADRAO*/
const std::string move = "mov";

/*PADAO*/
const std::string opCall = "call";

/*PADAO*/
const std::string opRet = "ret";

/*PADAO*/
const std::string opNoOperation = "nooperation";


/*  FUNCOES QUE ENVOLVE INSTRUCAO... TUDO RELACIONADO A INSTRUCAO*/
static int qtd_operators(std::string &aux){ 
  if(ZeroOperators.count(aux)) return 0;
  if(oneOperators.count(aux)) return 1;
  if(twoOperators.count(aux)) return 2;
  if(threeOperators.count(aux)) return 3;
  return -1;
}

static bool is_number(std::string &aux){
  for(auto i : aux) if(isdigit(i)  == 0) return 0;
  return 1;
}

static bool is_opIO(std::string &aux){
  return opIO.count(aux);
}

static bool is_reg(std::string &aux){
  return ((int)aux.size() == 2 && aux[0] == 'r' && aux[1] >= '0' && '9' >= aux[1]);
}

static bool is_mov(std::string &aux){
  return (move == aux);
}
static bool is_ret(std::string &aux){
  return (opRet == aux);
}

static bool is_aritmetic(std::string &aux){
  return aritmetic.count(aux);
}

static bool is_call(std::string &aux){
  return aux == opCall;
}

static bool is_logic(std::string &aux){
  return logic.count(aux);
}

static bool is_opmemo(std::string &aux){
  return opmemo.count(aux);
}

static bool is_opstack(std::string &aux){
  return opstack.count(aux);
}

static bool is_opjump(std::string &aux){
  return opjump.count(aux);
}

/*CLASSE BASE - INSTRUCAO*/
class instruction{
  public:
  std::string operation;
  std::string op1,op2,op3;
  public:
  instruction(){}
  instruction(std::string operation,std::string op1, std::string op2 = "", std::string op3 = "") : operation(operation),op1(op1),op2(op2),op3(op3){}

  bool valid(){
	//~ std::cout << operation << "|" << op1 << "|" << op2 << "|" << op3 << '\n';
    
    if(is_ret(operation)){
		return true;
	}
    if(is_opIO(operation)){
      if(operation == "read"){
        if(!is_reg(op1)) return false;
        return true;
      }
      if(!is_number(op1) && !is_reg(op1)) return false;
      return true;
    }
    if(operation == "not" || operation == move){
      if(!is_reg(op1)) return false;
      if(!is_number(op2) && !is_reg(op2)) return false;
      return true;
    }
    if(is_aritmetic(operation)){
      if(!is_reg(op1)) return false;
      if(!is_reg(op2)) return false;
      if(!is_number(op3) && !is_reg(op3)) return false;
      return true;
    }
    if(is_logic(operation)){
      if(!is_reg(op1)) return false;
      if(!is_number(op2) && !is_reg(op2)) return false;
      if(!is_number(op3) && !is_reg(op3)) return false;
      return true;
    }
    if(is_opmemo(operation)){
      if(operation == "load"){
        if(!is_reg(op1)) return false;
        if(!is_number(op2) && !is_reg(op2)) return false;
        return true;
      }
      if(!is_number(op2) && !is_reg(op2)){return false;}
      if(!is_reg(op1)){ return false;}
      return true;
    }
    if(is_opstack(operation)){
      if(!is_number(op1) && !is_reg(op1)) return false;
      return true;
    }
    if(operation == "jump"){
      if(!is_number(op1)) return false;
      return true;
    }
    if(is_opjump(operation)){
      if(!is_number(op1) && !is_reg(op1)) return false;
      if(!is_number(op2) && !is_reg(op2)) return false;
      if(!is_number(op3) && !is_reg(op3)) return false;
      return true;
    }
	if(is_call(operation)){
		if(!is_number(op1) && !is_reg(op1)) return false;
		return true;
	}
    return false;
  };
};


