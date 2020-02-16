#ifndef STACK_H
#define STACK_H
#include "SimpleNode.h"

namespace my {
template<class New_Type>
class stack
{
private:
    SimpleNode<New_Type>* _top;
    int _qtd;

public:
    bool push(New_Type* Conteudo);// sobrecarga da chamada de funcao
    bool push(New_Type Conteudo);// sobrecarga da chamada de funcao

    bool pop();

    New_Type top() const; ///TOP - TOP OF STACK

    int size(); /// SIZE - SIZE OF STACK

    bool empty(); /// EMPTY - RETURN TRUE IF STACK IS EMPTY

    void clear();

    stack();

    ~stack();
};


template<class New_Type>
bool stack<New_Type>::push(New_Type *Conteudo){  /// PUSH A ELEMENT
    SimpleNode<New_Type> *NovoTop = SimpleNode<New_Type>::MontaSimpleNode(Conteudo);
    if(!NovoTop) return false;
    NovoTop->next = _top;
    _top = NovoTop;
    ++_qtd;
    return true;
}

template<class New_Type>
bool stack<New_Type>::push(New_Type Conteudo)
{
    SimpleNode<New_Type> *NovoTop = SimpleNode<New_Type>::MontaSimpleNode(&Conteudo);
    if(!NovoTop) return false;
    NovoTop->next = _top;
    _top = NovoTop;
    ++_qtd;
    return true;
}

template<class New_Type>
bool stack<New_Type>::pop(){   /// POP A ELEMENT OF stack
    if(!_top) return false;
    SimpleNode<New_Type>* aux = _top;
    _top = _top->next;
    SimpleNode<New_Type>::DesmontaSimpleNode(aux);

    --_qtd;
    return true;
}

template<class New_Type>
New_Type stack<New_Type>::top() const {return _top->conteudo;}

template<class New_Type>
int stack<New_Type>::size() {return _qtd;}


template<class New_Type>
bool stack<New_Type>::empty(){ return (!_top);}

template<class New_Type>
void stack<New_Type>::clear()
{
    while(_top){ // execução de varios pop's ate a pilha ficar vazia
        SimpleNode<New_Type>* aux = _top;
        _top = _top->next;
        SimpleNode<New_Type>::DesmontaSimpleNode(aux);
    }
    _qtd = 0;
    _top = 0;
}


template<class New_Type>
stack<New_Type>::stack(){
    _top = 0;_qtd = 0;
}


template<class New_Type>
stack<New_Type>::~stack(){
    while(_top){ // execução de varios pop's ate a pilha ficar vazia
        SimpleNode<New_Type>* aux = _top;
        _top = _top->next;
        SimpleNode<New_Type>::DesmontaSimpleNode(aux);
    }
    _qtd = 0;
}

}


#endif // STACK_H
