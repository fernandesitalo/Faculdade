#ifndef ROTATION_H
#define ROTATION_H
#include "Node.h"

template<class pos,class type>
class Rotation
{
public:
    static void RSE( Node<pos,type> ** R); // ROTACAO SIMPLES A ESQUERDA
    static void RSD( Node<pos,type> ** R); // ROTACAO SIMPLES A DIREREITA
    static void RDE( Node<pos,type> ** R); // ROTACAO DUPLA A ESQUERDA
    static void RDD( Node<pos,type> ** R); // ROTACAO DUPLA A DIREITA
};

template<class pos,class type>
void Rotation<pos,type>::RSE(Node<pos,type> **R) // VER SITUACAO DE BALANCEMAENTO GRAFICAMENTE...
{
    /// rotação
    Node<pos,type> * a = *R;
    Node<pos,type> * b = a->Right;
    *R = b;
    a->Right = b->Left;
    b->Left = a;

    /// Acertanto o Fator de Balanceamento dos Nós
    if( !b->Fb ) // b->left == 0 .: as duas sub arvores tem a mesma altura H
    {
        b->Fb = -1;
    }
    else       // b->fb == -1 .: a sub arvore de b pendia para a esquerda...
    {
        b->Fb = a->Fb = 0;
    }
}

template<class pos,class type>
void Rotation<pos,type>::RSD(Node<pos,type> **R) // OLHAR DESENHOS E ESQUEMAS FEITOS
{
    /// rotação
    Node<pos,type> *a = *R;
    Node<pos,type> *b = a->Left;
    *R = b;
    a->Left = b->Right;
    b->Right = a;


    /// Acertando Fator de Balanceamento dos Nós
    if( !b->Fb ) // b->Fb == 0 .: as duas sub arvores tem a mesma altura H
    {
        b->Fb = +1;
    }
    else       // b->Fb == -1 .: a sub arvore de b pendia para a esquerda...
    {
        b->Fb = a->Fb = 0;
    }
}

template<class pos,class type>
void Rotation<pos,type>::RDE(Node<pos,type> **R) /// OLHAR ESQUEMAS DESENHADOS E EXPLICADOS....
{
    /* ROTACAO */
    Node<pos,type> *a = *R;
    Node<pos,type> *b = a->Right;
    Node<pos,type> *c = b->Left; // pode ter FB igual a -1, 0, 1
    *R = c;
    a->Right = c->Left;
    b->Left = c->Right;
    c->Left = a;
    c->Right = b;

    /* ACERTANDO FATOR DE BALANCEAMENTO DOS NÓS*/
    if(c->Fb == -1) // .: a sub arvore pendia para a esquerda
    {
        c->Fb = 0;
        a->Fb = 0;
        b->Fb = 1;
    }
    else
    {
        if(c->Fb == 0) // .: as duas sub arvores tinham a mesma altura
        {
            a->Fb = b->Fb = 0;
        }
        else // c->Fb == 1 .: a sub arvore c pendia para direita
        {
            b->Fb = 0;
            a->Fb = -1;
            c->Fb = 0;
        }
    }
}

template<class pos,class type>
void Rotation<pos,type>::RDD(Node<pos,type> **R) // OLHAR ESQUEMAS E DESENHOS FEITOS
{
    /* ROTACAO */
    Node<pos,type> *a = *R;
    Node<pos,type> *b = a->Left;
    Node<pos,type> *c = b->Right;
    *R = c;
    b->Right = c->Left;
    a->Left = c->Right;
    c->Left = b;
    c->Right = a;

    /* ARRUMANDO FATORES DE BALANCEAMENTO DOS NÓS*/
    if(c->Fb == -1) // sub arvore c pendia para esquerda ->
    {
        b->Fb = 0;
        a->Fb = +1;
        c->Fb = 0;
    }
    else
    {
        if(c->Fb == 0) // sub arvore c estava "certinha" e nao pendia
        {
            a->Fb = b->Fb = 0;
        }
        else // c->Fb == +1 .: suv arvore c pendia para direita <-
        {
            a->Fb = 0;
            b->Fb = -1;
            c->Fb = 0;
        }
    }

}

#endif // ROTATION_H
