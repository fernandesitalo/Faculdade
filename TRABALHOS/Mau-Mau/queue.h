#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

namespace my{
template<class New_Type>
class queue
{
private:
    SimpleNode<New_Type>* Head;
    SimpleNode<New_Type>* Tail;
    int Qtd_;
public:

    bool push(New_Type *conteudo);// sobrecarga da chamada de funcao
    bool push(New_Type conteudo);// sobrecarga da chamada de funcao

    bool pop();

    New_Type front() const;

    int size() const;

    bool empty() const;

    queue();

    ~queue();

    New_Type back() const;
    ///METODO 'back' da STL, segundo CPLUSPLUS:
    ///Retorna uma referência(OU PONTEIRO NO NOSSO CASO) ao último elemento no fila.
    ///Este é o elemento "mais novo" na fila (ou seja, o último elemento da fila).
};

template<class New_Type>
queue<New_Type>::queue()
{
    Head = Tail = 0;
    Qtd_ = 0;
}

template<class New_Type>
queue<New_Type>::~queue()
{
    while(Head){
        // EXECULTAR VARIOS POPS (DELETAR/DESALOCAR ESPACO DE MEMORIA) ATE A FILA SE ESVAZIAR
        SimpleNode<New_Type>* No_a_ser_deletado = Head;
        Head = Head->_next;
        SimpleNode<New_Type>::DesmontaSimpleNode(No_a_ser_deletado);
        Qtd_--;// Por via das Duvidas...
    }
}


template<class New_Type>
bool queue<New_Type>::push(New_Type *conteudo)
{
    try{
        SimpleNode<New_Type> * No_a_ser_inserido = SimpleNode<New_Type>::MontaSimpleNode(conteudo);
        No_a_ser_inserido->_next = 0;

        if(!Head){ /// ISTO É, SE O TOPO FOR NULL, ENTAO ESTE E O PRIMEIRO ELEMENTO A SER INSERIDO
            Head = No_a_ser_inserido;
        }
        else{ /// E UM NODE QLQER QUE NAO E O PRIMEIRO
            Tail->_next = No_a_ser_inserido;
        }

        Tail = No_a_ser_inserido; // O NO QUE CONTEM 'CONTEUDO' E INSERIDO NO 'RADO' DA FILA
        Qtd_++;
        return true;
    }
    catch(const char * erro){
        throw erro;
    }
    catch(...){
        throw "Um erro inesperado aconteceu!";
    }
}

template<class New_Type>
bool queue<New_Type>::push(New_Type conteudo)
{
    try{
        SimpleNode<New_Type> * No_a_ser_inserido = SimpleNode<New_Type>::MontaSimpleNode(&conteudo);

        if(!No_a_ser_inserido) // valida o ponteiro para Node criado em Montanode
            return false;

        if(!Head){ /// ISTO É, SE O TOPO FOR NULL, ENTAO ESTE E O PRIMEIRO ELEMENTO A SER INSERIDO
            Head = No_a_ser_inserido;
        }
        else{ /// E UM NODE QLQER QUE NAO E O PRIMEIRO
            Tail->_next = No_a_ser_inserido;
        }

        Tail = No_a_ser_inserido; // O NO QUE CONTEM 'CONTEUDO' E INSERIDO NO 'RADO' DA FILA
        Qtd_++;
        return true;
    }
    catch(const char * erro){
        throw erro;
    }
    catch(...){
        throw "Um erro inesperado aconteceu!";
    }
}


template<class New_Type>
bool queue<New_Type>::pop()
{
    if(!Head)
        return false;

    SimpleNode<New_Type> *No_a_ser_retirado = Head; /// GUARDA O ENDEREÇO DE MEMORIA DE QM ESTA EM HEAD, PARA DELETA-LO APOS APONTAR HEAD PARA _NEXT

    Head = Head->_next;

    /*  ::::::::::::CASO QNDO SE TEM UM UNICO ELEMENTO NA FILA::::::::::
    ->LEMBRETE. HEAD E TAIL APONTAM PARA O MESMO ELEMENTO NESTE CASO
    Se Head apontar para null, qndo apontar parar o proximo do topo,
    Quer dizer que a fila esta vazia. Porem Tail ainda aponta para o
    endereco de memoria deletado, o antigo topo, por isso, devemos
    apontar Tail para Null.                                       */

    if(!Head)
        Tail = 0;

    SimpleNode<New_Type>::DesmontaSimpleNode(No_a_ser_retirado);
    Qtd_--;
    return true;
}

template<class New_Type>
New_Type queue<New_Type>::front() const{ return Head->Conteudo;} ///inline


template<class New_Type>
int queue<New_Type>::size() const{ return Qtd_;} /// inline

template<class New_Type>
bool queue<New_Type>::empty() const{return (!Head);} /// inline

template<class New_Type>
New_Type queue<New_Type>::back() const{return Tail->Conteudo;} /// inline

} // Fim Namespace My

#endif // QUEUE_H
