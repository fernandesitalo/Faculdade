#ifndef NODE_H
#define NODE_H

template<class Type>
class Node
{
public:
    Type Conteudo;
    Node<Type>* _next;

    static Node<Type> *MontaNode(Type * _C_){
        Node<Type>* p_node = new Node<Type>; // ALOCA UM ESPAÇO DE MEMORIA PARA O NOVO CONTEINER
        if(!p_node)
            throw "Falha ao Alocar Memoria!";

        p_node->Conteudo = *_C_; // PREENCHE O CONTEINER COM O CONTEUDO PASSADO COMO PARAMETRO
        p_node->_next = 0;

        return p_node; // RETORNA O PONTEIRO DO CONTEINER ALOCADO AQUI
    }

    static void DesmontaNode(Node *no){ // DELETA DIRETO; SE O PROGAMADOR QUISER, QUE ACESSE O TOPO PRIMEIRO
        delete no;
    }
};

#endif // NODE_H
