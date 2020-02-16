#include<iostream>
#include<stdio.h>
using namespace std;

class carta{
	public:
		int valor;
		char naipe;
	public:		
		void set(int val, char nai)
		{
			valor = val;
			naipe = nai;	
		}
		
		void get(int val,char nai)
		{
			val = valor;
			nai = naipe;
		}
};





class NODE{
	public:
		carta conteudo; // Conteúdo do NODE, não importa o que é
		NODE* next; 

	static NODE* MontaNODE(carta * ct)
	{		
		NODE *p_node = new NODE;
		p_node->conteudo = *ct;
		p_node->next = NULL; 
		return p_node;
	}
	
	static void DesmontaNODE(NODE* N/*,carta C*/)
	{
		//C = N->conteudo;
		delete N;		
	}
	
};



class stack{
	private:
		NODE * _top_;
	public:	
		bool push(carta *A){			
			NODE * temp = NODE::MontaNODE(A);			
			temp->next = _top_;
			_top_ = temp;				
			return true;
		}
		bool pop(){						
			if(_top_ == NULL)
				return false;
			
			NODE* temp = _top_;
			_top_ = _top_->next;
			NODE::DesmontaNODE(temp); // Delete no topo
			return true;			
		}
		NODE* top(){			
			return _top_;
		}
		bool empty(){
			return (!_top_);
		}
		
		stack(){
		_top_ = NULL;
		}    
};


int main(){
	
	stack pilha;
	
	carta aux;
	
	aux.set(1,'A');
	
	pilha.push(&aux);
	
	cout << pilha.top()->conteudo.naipe << "        "<< pilha.top()->conteudo.valor;
	
	
	/*
	 * IMPLEMENTAR: top de maneira mais eficaz, retorna ponteiro para o objeto que esta no top, podendo acessar os atributos
	 * REVISAR: push e pop, estão mais ou menos, otimiza-los!
	 * 
	 * */
	
	
	
	
	return 0;
}
