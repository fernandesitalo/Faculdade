#ifndef STACK_H
#define STACK_H
#include "Node.h"

namespace My {
template<class New_Type>
class stack
{
private:
    Node<New_Type>* _top;
    int _qtd;

public:
    bool push(New_Type* Conteudo);// sobrecarga da chamada de funcao
    bool push(New_Type Conteudo);// sobrecarga da chamada de funcao

    bool pop();

    New_Type top() const; ///TOP - TOP OF STACK

    int size(); /// SIZE - SIZE OF STACK

    bool empty(); /// EMPTY - RETURN TRUE IF STACK IS EMPTY

    stack();

    ~stack();
};


template<class New_Type>
bool stack<New_Type>::push(New_Type *Conteudo){  /// PUSH A ELEMENT
    Node<New_Type> *NovoTop = Node<New_Type>::MontaNode(Conteudo);
    if(!NovoTop) return false;
    NovoTop->_next = _top;
    _top = NovoTop;
    ++_qtd;
    return true;
}

template<class New_Type>
bool stack<New_Type>::push(New_Type Conteudo)
{
    Node<New_Type> *NovoTop = Node<New_Type>::MontaNode(&Conteudo);
    if(!NovoTop) return false;
    NovoTop->_next = _top;
    _top = NovoTop;
    ++_qtd;
    return true;
}

template<class New_Type>
bool stack<New_Type>::pop(){   /// POP A ELEMENT OF stack
    if(!_top) return false;
    Node<New_Type>* aux = _top;
    _top = _top->_next;
    Node<New_Type>::DesmontaNode(aux);

    --_qtd;
    return true;
}


template<class New_Type>
New_Type stack<New_Type>::top() const {
    return _top->Conteudo;
}

template<class New_Type>
int stack<New_Type>::size() {return _qtd;}


template<class New_Type>
bool stack<New_Type>::empty(){ return (!_top);}


template<class New_Type>
stack<New_Type>::stack(){
    _top = 0;_qtd = 0;
}


template<class New_Type>
stack<New_Type>::~stack(){
    while(_top){ // execução de varios pop's ate a pilha ficar vazia
        Node<New_Type>* aux = _top;
        _top = _top->_next;
        Node<New_Type>::DesmontaNode(aux);
    }
    _qtd = 0;
}

}


#endif // STACK_H
