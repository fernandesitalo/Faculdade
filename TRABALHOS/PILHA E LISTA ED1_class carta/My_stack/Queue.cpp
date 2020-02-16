#include "Queue.h"

Queue::~Queue()
{
    while(!Head){
        // EXECULTAR VARIOS POPS (DELETAR/DESALOCAR ESPACO DE MEMORIA) ATE A FILA SE ESVAZIAR

        Node * No_a_ser_deletado = Head;
        Head = Head->_next;
        Node::DesmontaNode(No_a_ser_deletado);
        Qtd_--;// Por via das Duvidas...
    }
}

bool Queue::push(Carta *conteudo)
{
    Node * No_a_ser_inserido = Node::MontaNode(conteudo);

    if(!No_a_ser_inserido) // valida o ponteiro para Node criado em Montanode
        return false;

    No_a_ser_inserido->_next = 0;

    if(!Head) /// ISTO É, SE O TOPO FOR NULL, ENTAO ESTE E O PRIMEIRO ELEMENTO A SER INSERIDO
    {
        Head = No_a_ser_inserido;
    }
    else /// E UM NODE QLQER QUE NAO E O PRIMEIRO
    {
        Tail->_next = No_a_ser_inserido;
    }

    Tail = No_a_ser_inserido; // O NO QUE CONTEM 'CONTEUDO' E INSERIDO NO 'RADO' DA FILA
    Qtd_++;
    return true;
}

bool Queue::pop()
{
    if(!Head)
        return false;

    Node *No_a_ser_retirado = Head; /// GUARDA O ENDEREÇO DE MEMORIA DE QM ESTA EM HEAD, PARA DELETA-LO APOS APONTAR HEAD PARA _NEXT

    Head = Head->_next;
    /*
     *
    ::::::::::::CASO QNDO SE TEM UM UNICO ELEMENTO NA FILA::::::::::
    ->LEMBRETE. HEAD E TAIL APONTAM PARA O MESMO ELEMENTO NESTE CASO
    Se Head apontar para null, qndo apontar parar o proximo do topo,
    Quer dizer que a fila esta vazia. Porem Tail ainda aponta para o
    endereco de memoria deletado, o antigo topo, por isso, devemos
    apontar Tail para Null.
    *
    */

    if(!Head)
        Tail = 0;

    Node::DesmontaNode(No_a_ser_retirado);
    Qtd_--;
    return true;
}

Carta *Queue::front() const
{
    return &Head->_carta;
}

int Queue::size() const
{
    return Qtd_;
}

bool Queue::empty() const
{
    return (!Head);
}

Carta *Queue::back() const
{
    return &Tail->_carta;
}

