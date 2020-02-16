#ifndef SIMPLENODE_H
#define SIMPLENODE_H

template<class _tp>
class SimpleNode
{
public:
    _tp                 conteudo;
    SimpleNode<_tp>*    next;

public:
    SimpleNode(){}

    static SimpleNode<_tp>* MontaSimpleNode(_tp * con)
    {
        try{
            SimpleNode<_tp>* aux = new SimpleNode<_tp>;
            aux->conteudo = *con;
            aux->next = 0;
            return aux;
        }
        catch(...){
            throw "Ocorreu algum erro Inesperado";
        }
    }

    static void DesmontaSimpleNode(SimpleNode<_tp>* No){delete No;}
};

#endif // SIMPLENODE_H
