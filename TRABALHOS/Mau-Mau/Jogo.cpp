#include "Jogo.h"
#define Teste__ 0

void Jogo::Leitura_Distribuicao_Cartas()
{
    monte->clear();
    lixo->clear();
    Circular->ClearList();
    char valor;
    char naipe;
    int g;
    cycle::iterator it = Circular->begin();

    for(g = 0 ; it->size() == 0 ; ++g,++it)
    {
        for(int i = 0 ; i < 5 ; i++)
        {
            scanf(" %c %c",&valor,&naipe);
            it->push(make_carta(valor,naipe));
        }
    }
    for(int aux = g*5 ; aux < 104 ; ++aux){ /// leitura do baralho
        scanf(" %c %c",&valor,&naipe);
        monte->push(make_carta(valor,naipe));
    }
#if Teste__
    printf("Antes da Distribuicao:\n");
    printf("MONTE: %d\n",monte->size());
    printf("LIXO: %d\n",lixo->size());
    printf("Depois da districuicao de cartas!\n");
    printf("Total de Cartas no MONTE: %d\n",monte->size());
    printf("Total de Cartas no LIXO: %d\n",lixo->size());
    printf("\n\n\n");
#endif
}

bool Jogo::FimDoJogo__(){return FimDoJogo;}

int Jogo::Ganhador()
{
    if(Circular->size() != 1) return -1;
    cycle::iterator it = Circular->begin();
    return it.NumConteiners();
}


void Jogo::JogaRodada()
{
    cycle::iterator it;    
    it = Circular->begin();
    bool FimDaRodada = false;
    bool SentidoHorario = true;
    Carta aux;
    // na primeira jogada, o lixo esta vazio...
    // coloca ela no lixo pra ser referencia pros proximos...
    // ja pega a primeira carta dele, que vai ser a maior...
    it->pop_front(&aux);
    lixo->push(aux);
    bool CartaAtivada = true;

    while(!FimDaRodada)
    {
        CartaCastigo(CartaAtivada,SentidoHorario,it);
        CartaAtivada = false;

        SentidoHorario? ++it:--it;
        if(it->pop(lixo->top(),&aux))
        {// entrou aqui e pq retirou uma carta entao mete o loco, segue inteiro
            lixo->push(aux);
            CartaAtivada = true;
            if(!it->size())
            { // it.size() == 0
                FimDaRodada = true;
                CartaCastigo(CartaAtivada,SentidoHorario,it);
            }
        }
        else
        {
            aux = CompraCarta();
            if( aux == lixo->top())
            { // a carta que o cara acabou de comprar vai poder ser descartada!
                lixo->push(aux);
                CartaAtivada = true;
            }
            else
                it->push(aux);
        }
    }
    RetiraJogadorDaRodada();
    if(Circular->size() == 1) FimDoJogo = true;
}

void Jogo::RetiraJogadorDaRodada()
{
    cycle::iterator maior = Circular->begin();
    cycle::iterator it = Circular->begin();
    ++it;// o primeiro jogador ja comeca com maior numero de pontos
#if Teste__
    printf("Jogador[%d] = %d\n",maior.NumConteiners(),maior->Pontos());
#endif

    for(int i = 1 ; i < Circular->size() ; ++it,++i){
        if(it->Pontos() > maior->Pontos()){
            maior = it;
        }
#if Teste__
    printf("Jogador[%d] = %d\n",it.NumConteiners(),it->Pontos());
#endif
    }  

    printf("%d\n",maior.NumConteiners());
    Circular->pop(maior);
}

Carta Jogo::CompraCarta()
{
    Carta aux = monte->top();
    monte->pop();
    if(monte->empty()){
        NovoMonte();
    }
    return aux;
}

void Jogo::NovoMonte()
{
    Carta TopoDoLixo = lixo->top();
    lixo->pop();
    while(!lixo->empty()){
        monte->push(lixo->top());
        lixo->pop();
    }
    lixo->push(TopoDoLixo);
}

void Jogo::CartaCastigo(bool &CartaAtivada, bool &SentidoHorario, Iter<list> &Jogador)
{
    if(CartaAtivada){
        Carta aux;
        switch (lixo->top().getValor()) {
        case 'L': // carta de Estado
            SentidoHorario = !SentidoHorario;
            break;
        case 'A':// proximo jogador nao joga
            SentidoHorario? ++Jogador:--Jogador;
            break;
        case 'G':// proximo jogador compra 2 cartas
            SentidoHorario? ++Jogador:--Jogador;
            for(int i = 0 ; i < 2 ; i++){
                aux = CompraCarta();
                Jogador->push(aux);
            }
            SentidoHorario? --Jogador:++Jogador;
            break;
        case 'I':// proximo jogador compra 3 cartas
            SentidoHorario? --Jogador:++Jogador;
            for(int i = 0 ; i < 3 ; i++){
                aux = CompraCarta();
                Jogador->push(aux);
            }
            SentidoHorario? ++Jogador:--Jogador;
            break;
        }
    }
}


Jogo::Jogo(int _Numeros_de_Jogadores__)
{
    Circular = new cycle(_Numeros_de_Jogadores__,list());
    monte = new stack<Carta>;
    lixo = new stack<Carta>;
    Circular->EnumeraConteiners(); /// enumera todos conteiners de 1 ate a quantidade Existente
    FimDoJogo = false;
}

Jogo::~Jogo()
{
    lixo->clear();
    monte->clear();
    Circular->ClearList();
    delete lixo;
    delete monte;
    delete Circular;
}
