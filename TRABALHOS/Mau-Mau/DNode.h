#ifndef DNODE_H
#define DNODE_H

template<class Type>
class DNode
{
public:
    Type Conteudo;
    DNode<Type>* _next;
    DNode<Type>* _prev;

    static DNode<Type> *MontaNode(Type * _C_){
        DNode<Type>* p_node = new DNode<Type>; // ALOCA UM ESPAÇO DE MEMORIA PARA O NOVO CONTEINER
        if(!p_node)
            throw "Falha ao Alocar Memoria!";

        p_node->Conteudo = *_C_; // PREENCHE O CONTEINER COM O CONTEUDO PASSADO COMO PARAMETRO
        p_node->_next = 0;
        p_node->_prev = 0;

        return p_node; // RETORNA O PONTEIRO DO CONTEINER ALOCADO AQUI
    }

    static void DesmontaNode(DNode *no){ // DELETA DIRETO; SE O PROGAMADOR QUISER, QUE ACESSE O TOPO PRIMEIRO
        delete no;
    }
};





#endif // DNODE_H
