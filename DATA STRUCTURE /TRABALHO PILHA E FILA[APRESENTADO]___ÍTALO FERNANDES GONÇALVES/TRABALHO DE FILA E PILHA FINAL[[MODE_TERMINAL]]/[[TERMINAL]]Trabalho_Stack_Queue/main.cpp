#include <iostream>
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include "Ficha.h"
#define MAXTORRE 6
#define MAXJOGADORES 4


void ColocaNaTabela(My::Queue<Ficha> * const Jogador, My::Stack<Ficha> * const Torre, int *ordemDeJogada){

    bool FimDoJogo = false;
    Ficha Ficha_aux;
    while(!FimDoJogo)
    {
        for(int k = 0 ; k < 4 ; k++)
        {
            int i = ordemDeJogada[k];
            // ordem dos jogadores... sempre começa
            // pelo azul,dps vermelho, dps roxo, dps branco

            if(!Jogador[i].empty())
            {
                Ficha_aux = *Jogador[i].front();
                //Jogador[i].pop();
                char cor = Ficha_aux.getcor();
                int T = Ficha_aux.getTorre();

                if(cor == 'P')
                {
                    if(!Torre[T].emtpy())Torre[T].pop();
                }
                else
                {
                    int cont= 0;
                    bool inseriu = false;

                    while(cont < 6 && !inseriu)
                    {
                        if(Torre[T].size() < 6) // se tamanho maior que 6, vai para a fila da direita
                        {
                            Torre[T].push(&Ficha_aux);
                            inseriu = true;
                        }
                        else
                        {
                            if(++T == 6)T = 0;
                            cont++;
                        }
                    }
                    if(cont >= 6) // passou por todas torres, e todas estao cheias...
                    {
                        FimDoJogo = true; // o jogo acaba
                        k = 6;
                    }
                }

                if(!FimDoJogo) Jogador[i].pop();
            }
        }
    }
}

int main()
{
    freopen("Entrada.d6j","r", stdin);

    printf("O JOGO - DIAGONAL 6\n\n");

    My::Queue<Ficha> Jogador[MAXJOGADORES]; // Jogador[0],Jogador[1],Jogador[2].... e a sequencia de suas fichas e respectivos comandos
    My::Stack<Ficha> Torre[MAXTORRE]; // Torre[0],Torre[1],Torre[2],Torre[3]....

    char player,color,tower;

    Ficha Ficha_aux;
    int ordemDeJogada[MAXJOGADORES];

    while( (scanf(" %c %c %c",&player,&color,&tower)) != EOF){
        Ficha_aux.set(player-'1',color,tower-'1');
        Jogador[player - '1'].push(&Ficha_aux);

        //printf("*\n");

        switch(color){
        case 'A': // PRIMEIRO JOGADOR DEVE SER O AZUL
            ordemDeJogada[0] = player-'1';
            break;
        case 'V': // SEGUNDO JOGADOR DEVE SER O VERMELH0
            ordemDeJogada[1] = player-'1';
            break;
        case 'R': // TERCEIRO JOGADIR DEVE SER O ROXO
            ordemDeJogada[2] = player-'1';
            break;
        case 'B':// QUARTO JOGADOR DEVE SER O BRANCO
            ordemDeJogada[3] = player-'1';
            break;
        }
    }

    ColocaNaTabela(Jogador,Torre,ordemDeJogada);// sequencia:: Azul, seguido pelo Vermelho, Roxo e Branco;

    /// INICIO DA IMPRESSAO DAS FICHAS RESTANTES
    printf("FICHAS RESTANTES: \n");
    for(int i = 0 ; i < MAXJOGADORES ; i++){
        printf("Jogador %d : ",i+1);

        if(Jogador[i].size() == 0) printf("sem fichas restantes");

        while(!Jogador[i].empty()){
            Ficha_aux = *Jogador[i].front();
            printf("%d%c%d ",Ficha_aux.getJogador()+1,Ficha_aux.getcor(),Ficha_aux.getTorre()+1);
            Jogador[i].pop();
        }
        printf("\n");
    }
    printf("\n\n");
    /// FINAL DA IMPRESSAO DAS FICHAS RESTANTES



    /* INICIO DA CONTAGEM DOS PONTOS E IMPRESSAO DAS FILAS*/
    printf("TABULEIRO PREENCHIDO:\n");
    int pontuacao[MAXJOGADORES] = {0,0,0,0};
    for(int i = 0 ; i < MAXTORRE ; i++){

        for(int k = 0 ; k < MAXTORRE ; k++){
            Ficha_aux = *Torre[i].top();
            printf("%d%c%d\t",Ficha_aux.getJogador()+1,Ficha_aux.getcor(),Ficha_aux.getTorre()+1);

            Torre[i].pop();

            if(k == i)
                pontuacao[Ficha_aux.getJogador()]++;
        }
        printf("\n");
    }
    printf("\n\n");
    /* FIM DA CONTAGEM DOS PONTOS*/


    int MaiorPontuacao = 0;

    printf("PLACAR DO JOGO:\n");
    for(int i = 0 ; i < MAXJOGADORES ; i++){
        switch(i){
        case 0: printf("Jogador %d(Azul):",ordemDeJogada[i]+1); break;
        case 1: printf("Jogador %d(Vermelho):",ordemDeJogada[i]+1); break;
        case 2: printf("Jogador %d(Roxo):",ordemDeJogada[i]+1); break;
        case 3: printf("Jogador %d(Branco):",ordemDeJogada[i]+1); break;
        }
        printf("\t%d ponto(s)\n",pontuacao[ordemDeJogada[i]]);

        if(MaiorPontuacao < pontuacao[ordemDeJogada[i]]) MaiorPontuacao = pontuacao[ordemDeJogada[i]];
    }

    int cont = 0;
    printf("\nPORTANTO PLAYER(S): ");
    for(int i = 0 ; i < 4 ; i++){
        if(MaiorPontuacao == pontuacao[ordemDeJogada[i]]){
            switch(i){
            case 0: printf("AZUL "); break;
            case 1: printf("VERMELHO "); break;
            case 2: printf("ROXO "); break;
            case 3: printf("BRANCO "); break;
            }
            cont++;
        }
    }
    if(cont > 1) printf("FICARAM EMPATADOS!");
    else printf("GANHOU!!\n\n");


    printf("\nFIM DE JOGO!\n\n");

    return 0;
}
