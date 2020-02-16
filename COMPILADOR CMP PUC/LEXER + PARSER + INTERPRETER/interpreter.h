#ifndef interpreter_h
#define interpreter_h
#include "parser.h"
#include <stack>
#include <math.h>
namespace analyzer{

// para melhor leitura do codigo...
#define ADD 	101	
#define SUB 	102
#define DIV 	103
#define MULT 	104
#define REST 	105
#define POT 	106

/*
  se a expressao estiver certa, apos a checagem, o token atual sera um delim ';'
  se deu errado eu sei o primeiro token que deu erro, vai ser indicado por posErro


  GRAMATICA EXPRESSAO:

  EXPRESSAO ->  TERMO RESTO1
  RESTO1    ->  + TERMO RESTO1 | - TERMO RESTO1 | EPSILON
  TERMO     ->  FATOR RESTO2
  RESTO2    ->  * FATOR RESTO2 | / FATOR RESTO2 | % FATOR RESTO2 | EPSILON
  FATOR     ->  BASE RESTO3    |  ( EXPRESSAO )
  RESTO3    ->  ^ (EXPOENTE)  | ^ EXPOENTE   |  EPSILON					 ~ EXPOENTE ENTRE PARENTESES TBM PODE!
  BASE      ->  ID  | NUM
  EXPOENTE  ->  ID  | NUM


	TODAS AS VERIFICAÇÕES DESNECESSARIAS FORAM TIRADAS... (JAH QUE TENHO CERTEZA DE QUE ESTA TUDO CERTO.....)

*/

class Interpreter{
  private:
  std::vector<token> LISTA;   // lista de token gerada no lexer
  token atual;              // token atual
  int idx;            // index do token atual
  std::stack<token> stk;								
  std::map<std::string, int > memo; // Memoria 
  
  int Erro;
  
  public:
  Interpreter(std::string in){ 
    Parser P(in);
    LISTA = P.getListaToken();
    Erro = P.check();
    
    idx = 0;				// ponteiro para instrução atual
    memo.clear(); 	// limpa memoria
    
    if((int)LISTA.size() > idx) 
			atual = LISTA[idx];
  }
  
  // EXECUTA PROGRAMA!
  int executa(){
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
		
	// LEITURA
	void scan(std::string &str){
		int aux;
		std::cin >> aux;
		memo[str] = aux;
	}
	
	// ESCRITA 
	void print(token aux){
		if(aux.type == ID)
			std::cout << memo[aux.value] << std::endl;
		else
			std::cout << aux.value << std::endl;
	}
	
	// INSTRUCAO
	void instruction(){
		if(fimDeIntrucao()) return;
		if(atual.type == ID){						// ATRIBUICAO
			std::string aux = atual.value;
			nextToken(); // id
			nextToken(); // =
			expressao();
			memo[aux] = std::stoi(stk.top().value);
			stk.pop();
		}
		else if(atual.type == PRINT){		// ESCRITA
			nextToken();
			expressao();
			print(stk.top());
			stk.pop();
		}
		else if(atual.type == SCAN){		// LEITURA
			nextToken(); // scan
			nextToken(); // (
			scan(atual.value);
			nextToken(); // id
			nextToken(); // )
		}
		nextToken();
	}
	
	// OBTEN ELEMENTO DO TOKEN ... OU DA MEMORIA(SE ID) OU O VALOR NUMERICO (SE NUM)
	int get(){
		token aux = stk.top();
		stk.pop();
		if(aux.type == ID) return memo[aux.value];
		return std::stoi(aux.value);
	}
	
	// FAZ O CALCULO ... SEM MIMIMI
	void calc(int op){
		int op2 = get();
		int op1 = get();
		
		if(op == ADD){
			stk.push(token(NUM,std::to_string((op1+op2))));
		}
		else if(op == SUB){
			stk.push(token(NUM,std::to_string((op1-op2))));
		}
		else if(op == DIV){
			if(op2 == 0){
				std::cout << " DIVISÃO POR ZERO! (se fudeo)\n";
				exit(0); // HAHAH
			}
			stk.push(token(NUM,std::to_string((op1/op2))));
		}
		else if(op == REST){
			if(op2 == 0){
				std::cout << " DIVISÃO POR ZERO! (se fudeo)\n";
				exit(0); // HAHAH
			}
			stk.push(token(NUM,std::to_string((op1%op2))));
		}
		else if(op == POT){
			stk.push(token(NUM,std::to_string((int)pow(op1,op2))));
		}
		else if(op == MULT){
			stk.push(token(NUM,std::to_string((op1*op2))));
		}
	}

	// INSANO
  void expressao(){
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
	
	// ok
  void termo(){
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
	
	//ok
  void resto1(){
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
	
	// ok
  void resto2(){
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

	// ok
  void resto3(){
    if( fimDeIntrucao() ) return;
    if(atual.value == "^"){
      nextToken();
      expoente();
      calc(POT); 
    }
  }
	
	// ok
  void fator(){
    if(fimDeIntrucao()) return;

    if(atual.type == ID || atual.type == NUM){
      base();
			resto3();
    }
    else if(atual.value == "("){
			nextToken(); // é igual a '('
      expressao();
			nextToken(); // tem de ser igual a ')'
		}
  }
	
	// ok
  void base(){
		stk.push(atual);
		nextToken();
  }
	
	//ok
  void expoente(){ // HERE
		if(atual.value == "("){
			fator();
		}else{
			stk.push(atual);
			nextToken();
		}
  }

  //ok
  void nextToken(){
    idx++;// anda com o 'ponteiro' para o token atual
    if(!chegouaofim())
      atual = LISTA[idx];
  }

  // ok
  bool chegouaofim(){// nao tem mais token
    return (idx >= (int)LISTA.size());
  }

  // achou um ';'
  bool fimDeIntrucao(){
    if(!chegouaofim()) return atual.value == ";";
    return false;
  }

  // EH ISSO AI MESMO
  std::vector<token> getListaToken(){
    return LISTA;
  }

};
#endif
}
