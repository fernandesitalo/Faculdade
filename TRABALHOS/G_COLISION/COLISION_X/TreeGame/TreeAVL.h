#ifndef TREEAVL_H
#define TREEAVL_H
#include "Node.h" /// NODE COM FB
#include "Rotation.h"
template <class pos,class type>
class TreeAVL
{
private:
    Node<pos,type> * Root;

    int qtd;

    static bool Insert_recursiva(Node<pos,type> **R, type obj, pos Pos);

    static bool Remove_recursiva(pos Pos, Node<pos,type>** R,bool *e);

    static Node<pos,type>* Busca_recursiva(pos Pos,Node<pos,type> *R);

    static Node<pos,type>* Maximo(Node<pos,type> * R);

    Node<pos,type>* Busca(pos);

    static void clear_recursivo(Node<pos,type> **R);

public:
    void insert(pos Pos ,type obj);

    bool remove(pos Pos);

    int size();

    type& operator[](pos Pos);

    void clear();

    type* find(pos Pos);

    TreeAVL();

    ~TreeAVL();
};


template<class pos, class type>
Node<pos,type>* TreeAVL<pos,type>::Busca_recursiva(pos Pos, Node<pos,type> *R)
{
    if(!R) return 0;
    if( R->Position == Pos ) return R;

    if( Pos > R->Position ) return TreeAVL<pos,type>::Busca_recursiva(Pos, R->Right);
    else return TreeAVL<pos,type>::Busca_recursiva(Pos, R->Left);
}

template<class pos,class type>
Node<pos,type> *TreeAVL<pos,type>::Maximo(Node<pos,type> *R)
{
    /* neste metodo e passado o endereço do no a esquerda do no que queremos descobrir o maximo
     * logo, se ele for NULL, temos que retornar NULL, por isso esse primeiro if(!R) ...      */

    if( !R ) return 0; /// return NULL

    if(!(R)->Right ) return R; /// caso nao tenha filho da direta, a retorna ele, pq ele e o maximo/antecessor

    return Maximo( R->Right ); /// continua a procura
}


template<class pos,class type>
void TreeAVL<pos,type>::insert(pos Pos ,type obj)
{
    TreeAVL<pos,type>::Insert_recursiva( &Root , obj , Pos);
    qtd++;
}

template<class pos,class type>
bool TreeAVL<pos,type>::remove(pos Pos)
{
    bool e = false;
    TreeAVL<pos,type>::Remove_recursiva( Pos , &Root ,&e);
    if(e) qtd--;
    return e;
}

template<class pos, class type>
int TreeAVL<pos,type>::size()
{ return qtd; }


template<class pos, class type>
Node<pos,type>* TreeAVL<pos,type>::Busca(pos Pos)
{
    return TreeAVL<pos,type>::Busca_recursiva(Pos,Root);
}

template<class pos, class type>
type& TreeAVL<pos,type>::operator[](pos Pos)
{
    Node<pos,type>*aux = TreeAVL<pos,type>::Busca(Pos);

    if(!aux){
        this->Insert(Pos,type());
        aux = TreeAVL<pos,type>::Busca(Pos);
        qtd++;
    }

    return aux->Conteudo;
}


template<class pos, class type>
void TreeAVL<pos,type>::clear()
{
    TreeAVL<pos,type>::clear_recursivo(&Root);
    qtd = 0; Root = 0;
}

template<class pos, class type>
type* TreeAVL<pos,type>::find(pos Pos)
{
    Node<pos,type>*aux = TreeAVL<pos,type>::Busca(Pos);

    if(!aux) return 0;

    return &(aux->Conteudo);
}

template<class pos, class type>
void TreeAVL<pos,type>:: clear_recursivo(Node<pos,type> **R)
{
    if( (*R) ){
        if((*R)->Left)
            TreeAVL<pos,type>::clear_recursivo(&(*R)->Left);
        if((*R)->Right)
            TreeAVL<pos,type>::clear_recursivo(&(*R)->Right);

        Node<pos,type>::DesmontaNode( (*R) );
        (*R) = 0;//NULL
    }
}

template<class pos,class type>
TreeAVL<pos,type>::TreeAVL()
{ Root = 0; qtd = 0;}

template<class pos, class type>
TreeAVL<pos,type>::~TreeAVL()
{ clear(); }

template<class pos,class type>
bool TreeAVL<pos,type>::Insert_recursiva(Node<pos,type> **R, type obj , pos Pos )
{
    if(!(*R))
    {
        Node<pos,type> *P = Node<pos,type>::MontaNode( &Pos , &obj );
        P->Fb = 0;
        *R = P;
        return true;
    }

    if((*R)->Position == Pos) /// OBJETO JÁ EXISTE, ENTAO VAMOS SUBSTITUI-LO
    {
        (*R)->Conteudo = obj;
        return false;
    }


    if( (*R)->Position > Pos) // obj menor que *R .: vamos para a -=ESQUERDA=-
    {
        if( !TreeAVL<pos,type>::Insert_recursiva(&(*R)->Left, obj , Pos) )
        {
            /// SIGNIFICA QUE INSERIU E A SUB ARVORE QUE O NÓ FOI INSERIDO NAO CRESCEU
            return false;
        }

        /* .: INSERIU O NÓ E RETORNOU TRUE, SE RETORNOU TRUE, O BALANCEIO MUDOU... */
        /* LEMBRANDO QUE ESTAMOS "VOLTANDO" DA ESQUERDA... */

        if((*R)->Fb == 0 ) /// A SUBARVORE DA ESQUERDA CRESCEU, E SE ANTES FB = 0, ENTÃO A ALTURA DA ARVORE|SUB
        {                  /// PASSA A PENDER PARA A ESQUERDA, ONDE INSERIU...
            (*R)->Fb = -1;
            return true;
        }

        if((*R)->Fb == +1)///A SUBARVORE DA ESQUEDA CRESCEU POREM NÃO HOUVE MUDANÇA NA ALTURA DA ARVORE EM SI ANALISADA
        {                /// .: RETURN FALSE PQ NAO ALTEROU A ALTURA DE NADA....
            (*R)->Fb = 0;
            return false;
        }

        // (*R)->Fb == -1 .: IRIA PARA MENOS DOIS, MAIS NÃO VAI!!!!!!!!!!!!

        if( (*R)->Left->Fb == -1 )
        { // rotacao simples a Direita
          Rotation<pos,type>::RSD( R );
          return false;
        }

        Rotation<pos,type>::RDD( R );
        return false;
    }
    else // obj maior que *R .: vamos para a direita
    {


        if(!TreeAVL<pos,type>::Insert_recursiva( &(*R)->Right , obj , Pos) )
        {
            /// INSERIU NA SUB ARVORE DA DIREITA E NÃO ALTEROU O Fb DE NADA ....
            return false;
        }
         /* .: INSERIU O NÓ NO LADO DIREITO DA SUBARVORE E A ALTURA MUDOU*/
         /* LEMBRANDO QUE ESTAMOS "VOLTANDO" DA DIREITA*/

        if((*R)->Fb == 0)
        {
            (*R)->Fb = +1;
            return true;
        }

        if((*R)->Fb == -1)
        {
            (*R)->Fb = 0;
            return false;
        }

        // (*R)->Fb == 1 .: IRIA PARA MAIS DOIS, MAIS NAO VAI!!! VAMOS BALANCEAR

        if((*R)->Right->Fb == +1)
        {
            Rotation<pos,type>::RSE( R );
            return false;
        }

        Rotation<pos,type>::RDE( R );
        return false;
    }
}

template<class pos,class type>
bool TreeAVL<pos,type>::Remove_recursiva(pos Pos, Node<pos,type> **R, bool *e)
{
    if( !(*R) )
    {
        /// O OBJETO NAO EXISTE
        *e = false;
        return false;
    }

    if( Pos < (*R)->Position ) // VAMOS PARA A ESQUERDA
    {
        if( TreeAVL<pos,type>::Remove_recursiva(Pos ,&(*R)->Left,e) )
        {
            /// RETORNOU TRUE .: DELETOU E REDUZIU A SUBARVORE

            if((*R)->Fb == -1) //se era -1 passa a ser 0, pois a sub arvore da esquerda diminiu... e a dir se manteve
            {
                (*R)->Fb = 0;
                return true; // retorna true pois ...
            }

            if((*R)->Fb == 0)
            {
                (*R)->Fb = +1;
                return false; // retorna false pois
            }

            /// (*R)->Fb == 1 , IRIA PARA MAIS DOIS .: VAMOS ROTACIONAR ESSA PORRA
            if( (*R)->Right->Fb != -1 )
            {
                /// ROTACAO SIMPLES A ESQUERDA
                Rotation<pos,type>::RSE( R );
                return ( !(*R)->Fb );
            }

            /// ROTACAO DUPLA A ESQUERDA
            Rotation<pos,type>::RDE( R );
            return true;
        }

        /// VEIO DA ESQUERDA E NAO HOUVE ALTERACAO DE ALTURA
        return false;
    }

        if(Pos > (*R)->Position)
        {
            /// TAMO INDO PROCURANDO....
            if( TreeAVL<pos,type>::Remove_recursiva( Pos ,&(*R)->Right,e) )
            {
                /// DELETOU E REDUZIU A ARVORE DA DIREITA

                if((*R)->Fb == 0)
                {
                    (*R)->Fb = -1;
                    return false;
                }

                if((*R)->Fb == +1)
                {
                    (*R)->Fb = 0;
                    return true;
                }

                /// (*R)->Fb == -1, iria para -2, mais nao vai ...
                if((*R)->Left->Fb != 1)
                {
                    ///  ROTACAO SIMPLES A DIREITA
                    Rotation<pos,type>::RSD( R );
                    return ( !(*R)->Fb );
                }

                /// ROTACAO DUPLA A DIREITA
                Rotation<pos,type>::RDD( R );
                return true;
            }

            /// veio da direita e nao houve alteracao na ALTURA da subarvore
            return false;
        }

        //// ACHAMOS O ELEMENTO ele esta em (*R)!!! AGORA TEMOS QUE EXCLUI-LO

        if( !(*R)->Left )
        {
            /// NAO TEM FILHO DA ESQUERDA

            Node<pos,type> *x = (*R)->Right;
            Node<pos,type>::DesmontaNode( (*R) );
            (*R) = x;
            *e = true; // .: foi excluido
            return true;
        }

        if( !(*R)->Right )
        {
            /// tem só um filho a esquerda
            Node<pos,type> *x = (*R)->Left;
            Node<pos,type>::DesmontaNode( (*R) );
            (*R) = x;
            *e = true;
            return true;
        }

        /// ACHOU E TEM DOIS FILHOS !!!!!!

        Node<pos,type> * max = TreeAVL<pos,type>::Maximo( (*R)->Left );

        type aux_c = max->Conteudo;
        pos aux_p = max->Position;

        max->Conteudo = (*R)->Conteudo;
        max->Position = (*R)->Position;

        (*R)->Conteudo = aux_c;
        (*R)->Position = aux_p;

        if( TreeAVL<pos,type>::Remove_recursiva( Pos , &(*R)->Left , e) )
        {
            /// RETORNOU TRUE .: DELETOU E REDUZIU A SUBARVORE

            if((*R)->Fb == -1) //se era -1 passa a ser 0, pois a sub arvore da esquerda diminiu... e a dir se manteve
            {
                (*R)->Fb = 0;
                return true; // retorna true pois ...
            }

            if((*R)->Fb == 0)
            {
                (*R)->Fb = +1;
                return false; // retorna false pois
            }

            /// (*R)->Fb == 1 , IRIA PARA MENOS DOIS .: VAMOS ROTACIONAR ESSA PORRA

            if((*R)->Right->Fb != -1)
            {
                /// ROTACAO SIMPLES A ESQUERDA
                Rotation<pos,type>::RSE( R );
                return (! (*R)->Fb );
            }

            /// ROTACAO DUPLA A ESQUERDA
            Rotation<pos,type>::RDE( R );
            return true;
        }

        /// VEIO DA ESQUERDA E NAO HOUVE ALTERACAO DE ALTURA
        return false;
}


#endif // TREEAVL_H
