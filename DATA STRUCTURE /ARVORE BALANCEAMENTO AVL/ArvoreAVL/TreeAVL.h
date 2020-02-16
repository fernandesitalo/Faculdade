#ifndef TREEAVL_H
#define TREEAVL_H
#include "Node.h" /// NODE COM FB
#include "Rotation.h"

template <class type>
class TreeAVL
{
private:
    Node<type> * Root;

    static bool Insert_recursiva(Node<type> **R, type obj);

    static bool Remove_recursiva(type obj, Node<type>** R,bool *e);

    static Node<type>* Maximo(Node<type> * R);

    static void In_Order( Node<type>**R ){
        if( (*R) ){
            TreeAVL<type>::In_Order(&(*R)->Left);
            cout << (*R)->Conteudo << "  | Fb: " <<(*R)->Fb << endl;
            TreeAVL<type>::In_Order(&(*R)->Right);
        }
    }

public:
    void Insert(type obj);

    bool Remove(type obj);

    void print(){ In_Order(&Root); }

    TreeAVL();
};

template<class type>
bool TreeAVL<type>::Insert_recursiva(Node<type> **R, type obj)
{
    if(!(*R))
    {
        Node<type> *P = Node<type>::MontaNode( &obj );
        P->Fb = 0;
        *R = P;
        return true;
    }

    if( (*R)->Conteudo > obj) // obj menor que *R .: vamos para a -=ESQUERDA=-
    {
        if( !TreeAVL<type>::Insert_recursiva(&(*R)->Left, obj) )
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
          Rotation<type>::RSD( R );
          return false;
        }

        Rotation<type>::RDD( R );
        return false;
    }
    else // obj maior que *R .: vamos para a direita
    {


        if(!TreeAVL<type>::Insert_recursiva( &(*R)->Right , obj) )
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
            Rotation<type>::RSE( R );
            return false;
        }

        Rotation<type>::RDE( R );
        return false;
    }
}

template<class type>
bool TreeAVL<type>::Remove_recursiva(type obj, Node<type> **R, bool *e)
{
    if( !(*R) )
    {
        /// O OBJETO NAO EXISTE
        *e = false;
        return false;
    }

    if( obj < (*R)->Conteudo ) // VAMOS PARA A ESQUERDA
    {
        if( TreeAVL<type>::Remove_recursiva(obj,&(*R)->Left,e) )
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
                Rotation<type>::RSE( R );
                return ( !(*R)->Fb );
            }

            /// ROTACAO DUPLA A ESQUERDA
            Rotation<type>::RDE( R );
            return true;
        }

        /// VEIO DA ESQUERDA E NAO HOUVE ALTERACAO DE ALTURA
        return false;
    }

        if(obj > (*R)->Conteudo)
        {
            /// TAMO INDO PROCURANDO....
            if( TreeAVL<type>::Remove_recursiva(obj,&(*R)->Right,e) )
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
                    Rotation<type>::RSD( R );
                    return ( !(*R)->Fb );
                }

                /// ROTACAO DUPLA A DIREITA
                Rotation<type>::RDD( R );
                return true;
            }

            /// veio da direita e nao houve alteracao na ALTURA da subarvore
            return false;
        }

        //// ACHAMOS O ELEMENTO ele esta em (*R)!!! AGORA TEMOS QUE EXCLUI-LO

        if( !(*R)->Left )
        {
            /// NAO TEM FILHO DA ESQUERDA

            Node<type> *x = (*R)->Right;
            Node<type>::DesmontaNode( (*R) );
            (*R) = x;
            *e = true; // .: foi excluido
            return true;
        }

        if( !(*R)->Right )
        {
            /// tem só um filho a esquerda
            Node<type> *x = (*R)->Left;
            Node<type>::DesmontaNode( (*R) );
            (*R) = x;
            *e = true;
            return true;
        }

        /// ACHOU E TEM DOIS FILHOS !!!!!!

        Node<type> * max = TreeAVL<type>::Maximo( (*R)->Left );
        type aux = max->Conteudo;
        max->Conteudo = (*R)->Conteudo;
        (*R)->Conteudo = aux;

        if( TreeAVL<type>::Remove_recursiva( obj , &(*R)->Left , e) )
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
                Rotation<type>::RSE( R );
                return (! (*R)->Fb );
            }

            /// ROTACAO DUPLA A ESQUERDA
            Rotation<type>::RDE( R );
            return true;
        }

        /// VEIO DA ESQUERDA E NAO HOUVE ALTERACAO DE ALTURA
        return false;
}

template<class type>
Node<type> *TreeAVL<type>::Maximo(Node<type> *R)
{
    /* neste metodo e passado o endereço do no a esquerda do no que queremos descobrir o maximo
     * logo, se ele for NULL, temos que retornar NULL, por isso esse primeiro if(!R) ...      */

    if( !R ) return 0; /// return NULL

    if(!(R)->Right ) return R; /// caso nao tenha filho da direta, a retorna ele, pq ele e o maximo/antecessor

    return Maximo( R->Right ); /// continua a procura
}

template<class type>
void TreeAVL<type>::Insert(type obj)
{ TreeAVL<type>::Insert_recursiva( &Root , obj); }

template<class type>
bool TreeAVL<type>::Remove(type obj)
{
    bool e = false;
    TreeAVL<type>::Remove_recursiva(obj,&Root,&e);
    return e;
}

template<class type>
TreeAVL<type>::TreeAVL()
{ Root = 0; }

#endif // TREEAVL_H
