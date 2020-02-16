#include "Colision.h"
#include <stdio.h>
using namespace std;

int L[] = {0,1,0,0,-1};
int C[] = {0,0,-1,1,0};

bool Colision::ValidaPosicao(int l, int c)
{ return ( l > -1 && c > -1 && limite_coluna > c && limite_linha > l); }

Colision::Colision(int numero_de_jogadores, int N_linha, int M_coluna)
{
    Jogadores = new Jogador[numero_de_jogadores+1];
    limite_coluna = M_coluna;
    limite_linha = N_linha;
    Num_Jogadores = numero_de_jogadores;
}

Colision::Colision()
{ limite_coluna = limite_linha = Num_Jogadores = 0; Jogadores = 0;}

Colision::~Colision()
{
    if( Jogadores )
         delete []Jogadores;
}

void Colision::setNumJogadores(int qtd)
{
    Num_Jogadores = qtd;
    Jogadores = new Jogador[qtd+2];
}

void Colision::LimitesMapa(int l, int c)
{
    limite_linha = l;
    limite_coluna = c;
}


void Colision::AddJogador(int id, int l, int c, int hp, int dano,int pontosAcao)
{
    Jogadores[id].coluna = c;
    Jogadores[id].linha = l;
    Jogadores[id].hp = hp;
    Jogadores[id].dano = dano;
    Jogadores[id].PontosAcao = pontosAcao;
    Tree.Insert( my::pair(l,c) , id);
}

void Colision::AddPedra(int l, int c)
{ Tree.Insert(my::pair(l,c),PEDRA);}

bool Colision::Action_M(int id, int dir)
{
    if(Jogadores[id].PontosAcao < 1) return false;

    dir /= 2;
    Jogador J = Jogadores[id];

    int l_ = J.linha + L[dir];
    int c_ = J.coluna + C[dir];

    if( ValidaPosicao(l_,c_) &&  !Tree.find(my::pair( l_ , c_ ))){
        Tree.Remove(my::pair(J.linha,J.coluna));
        Tree.Insert( my::pair(l_,c_) , id );
        Jogadores[id].linha = l_;
        Jogadores[id].coluna = c_;
    }


    //______________________ PERDE PONTOS DE ACAO _____________________________
    Jogadores[id].PontosAcao -= 1;
    return true;
}

bool Colision::Action_C(int id, int dir)
{
    if(Jogadores[id].PontosAcao < 4) return false;
    dir /= 2;
    Jogador J = Jogadores[id];

    int l_ = J.linha + L[dir];
    int c_ = J.coluna + C[dir];

    if(ValidaPosicao( l_ , c_ ) && Tree.find(my::pair( l_ , c_ )) == 0){
        Tree.Insert( my::pair(l_,c_), PEDRA );
    }
    //______________________ PERDE PONTOS DE ACAO _____________________________
    Jogadores[id].PontosAcao -= 4;
    return true;
}

bool Colision::Action_D(int id, int dir)
{
    if(Jogadores[id].PontosAcao < 3) return false;

    dir /= 2;
    Jogador J = Jogadores[id];

    int l_ = J.linha + L[dir];
    int c_ = J.coluna + C[dir];

    int *aux = (Tree.find(my::pair( l_ , c_ )));

    if(ValidaPosicao( l_ , c_ ) && aux && *aux == PEDRA){
        Tree.Remove(my::pair(l_,c_));
    }
    //______________________ PERDE PONTOS DE ACAO _____________________________
    Jogadores[id].PontosAcao -= 3;
    return true;
}

bool Colision::Action_A(int id, int dir)
{
    if(Jogadores[id].PontosAcao < 1) return false;

    dir /= 2;

    int l_atk = Jogadores[id].linha + L[dir];
    int c_atk = Jogadores[id].coluna + C[dir];

    bool flag = true;
    while( flag && ValidaPosicao( l_atk , c_atk ) ){
        int *obj = Tree.find(my::pair(l_atk,c_atk));

        if(obj){
            if(*obj > 0){
                Jogadores[*obj].hp -= Jogadores[id].dano;
                if(Jogadores[*obj].hp <= 0){
                    Morte(*obj);
                }
            }
            flag = false;
        }
        else{
            l_atk += L[dir];
            c_atk += C[dir];
        }
    }
    //______________________ PERDE PONTOS DE ACAO _____________________________
    Jogadores[id].PontosAcao -= 1;
    return true;
}

void Colision::Morte(int id)
{
    Tree.Remove(my::pair(Jogadores[id].linha,Jogadores[id].coluna));
    Jogadores[id].coluna = MORTO;
    Jogadores[id].linha = MORTO;
    Jogadores[id].dano = MORTO;
    Jogadores[id].hp = MORTO;
    Jogadores[id].PontosAcao = MORTO;
    Jogadores[id].vivo = false;
}

bool Colision::Vivo(int id)
{ return Jogadores[id].vivo; }

bool Colision::LeituraJogadores()
{
    int n,l,c,hp,dano;
   scanf(" %d",&n);
   if(n == 0) return false;
    setNumJogadores(n);
    for(int i = 1 ; i <= n ; ++i){
        scanf(" %d %d %d %d",&c,&l,&hp,&dano);
        AddJogador(i,l,c,hp,dano,5);
    }
    return true;
}

void Colision::LeituraLimitesMapa()
{
    int l,c;
    scanf(" %d %d",&c,&l);
    this->limite_linha = l;
    this->limite_coluna = c;
}

void Colision::LeituraDasPedras()
{
    int l,c;
    while( scanf(" %d %d",&c,&l), l > -1 && c > -1){
        this->AddPedra(l,c);
    }
}

void Colision::LeituraComandos_Joga()
{
    char cmd;
    int direcao;
    int Jog = 1;
    int num = 0;
    bool flag = true;

    while(scanf(" %c %d",&cmd,&direcao), cmd != 'F' && direcao != 0){
        num++;

        if(flag){
            switch(cmd){
            case 'M':
                if( !Action_M( Jog, direcao) ) flag = false;
                break;
            case 'A':
                if( !Action_A( Jog, direcao) ) flag = false;
                break;
            case 'D':
                if( !Action_D( Jog , direcao) ) flag = false;
                break;
            case 'C':
                if( !Action_C( Jog , direcao) ) flag = false;
                break;
            }
        }

        if(num == 5){
            Jog = Prox_jogador(Jog);
            flag = true;
            num = 0;
            Jogadores[Jog].PontosAcao = 5;
        }
    }
}

int Colision::Prox_jogador( int id )
{
    id++;
    if(id > Num_Jogadores) id = 1;

    while( !Vivo(id) ){
        id++;
        if(id > Num_Jogadores) id = 1;
    }
    return id;
}

void Colision::ImprimirResultados()
{
    for(int id = 1 ; id <= Num_Jogadores ; ++id){
        printf("Jogador %d: ",id);
        if(Vivo(id)){
            printf("(%d,%d) HP: %d\n",Jogadores[id].coluna,Jogadores[id].linha,Jogadores[id].hp);
        }
        else
            puts("MORTO");
    }
}
