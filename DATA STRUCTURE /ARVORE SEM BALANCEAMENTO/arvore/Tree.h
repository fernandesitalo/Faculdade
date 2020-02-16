/* FAZER SOBRECARGA DE OPERADOR PARA O CONTEUDO DA ARVORE PARA INSERÇÃO
 *
 *
*/

#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
using namespace std;
#include "Node.h"

template<class type>
class Tree
{
private:
    Node<type>* Root;

    static void Inserir_recursivo(Node<type>* P, Node<type> **R);

    static Node<type>* Maximo(Node<type>* R); /// POR COINCIDENCIA É O ANTECESSOR

    static bool Delete(type obj,Node<type> ** R);

    static void In_Order( Node<type> **R);

public:
    bool Insere(type * conteudo);
    bool Insere(type conteudo);

    bool Remove(type obj);

    void Print_In_Order();

    Tree();
};
//_____________________________________________________________________________________


template<class type>
void Tree<type>::Inserir_recursivo(Node<type> *P, Node<type> **R)
{
    if( !(*R) ) /// É FOLHA .: INSERIR
    {
        *R = P;
    }
    else /// TEM ELEMENTO LA .: NÃO É FOLHA
     {
        if(P->Conteudo > ((*R)->Conteudo) )  /// INSERIR NA SUBARVPRE A DIREITA
        {
            Tree<type>::Inserir_recursivo( P , &(*R)->Right );
        }
        else /// INSERIR NA SUBARVORE A ESQUERDA
        {
            Tree<type>::Inserir_recursivo(P,&(*R)->Left);
        }
    }
}

template<class type>
Node<type>* Tree<type>::Maximo( Node<type> *R )
{
    if( !R ) return 0 ; /// return NULL;

    if( !R->Right ) return R;

    return Tree<type>::Maximo( R->Right );
}


template<class type>
bool Tree<type>::Insere(type *conteudo)
{
    Node<type> *P = Node<type>::MontaNode(conteudo);
    if(!P) return false;

    Inserir_recursivo(P,&Root);

    return true;
}

template<class type>
bool Tree<type>::Insere(type conteudo)
{
    Node<type> *P = Node<type>::MontaNode(&conteudo);
    if(!P) return false;

    Inserir_recursivo(P,&Root);

    return true;
}


template<class type>
bool Tree<type>::Remove(type obj)
{
    return Delete( obj , &Root);
}

template<class type>
void Tree<type>::Print_In_Order()
{ In_Order(&Root); }


template<class type>
Tree<type>::Tree()
{ Root = 0;}


template<class type>
void Tree<type>::In_Order(Node<type> **R){
    if( (*R) ){
        Tree<type>::In_Order(&(*R)->Left);
        cout << (*R)->Conteudo << endl;
        Tree<type>::In_Order(&(*R)->Right);
    }
}

template <class type>
bool Tree<type>::Delete( type obj , Node<type> **R )
{
    if(!(*R)) return false;

    if(obj < ((*R)->Conteudo)) return Tree<type>::Delete( obj , &(*R)->Left );

    if(obj > ((*R)->Conteudo)) return Tree<type>::Delete( obj , &(*R)->Right );

    if( !(*R)->Left )
    {
       Node<type> *X = (*R)->Left;
       Node<type>::DesmontaNode( (*R) );
       (*R) = X;

       return true;
    }

    if( !(*R)->Right )
    {
        Node<type> *X = (*R)->Right;
        Node<type>::DesmontaNode( (*R) );
        (*R) = X;

        return true;
    }

    Node<type>* max = Tree<type>::Maximo( (*R)->Left );

    type aux = max->Conteudo;
    max->Conteudo = (*R)->Conteudo;
    (*R)->Conteudo = aux;

    return Tree<type>::Delete( obj , &(*R)->Left );
}
#endif // TREE_H
