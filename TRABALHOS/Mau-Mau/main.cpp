#include "Jogo.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int N,J;
    scanf(" %d",&N);    
    for(int ct = 1 ; ct <= N ; ++ct){
        scanf(" %d",&J);
        Jogo Game(J);
        while(!Game.FimDoJogo__()){
            Game.Leitura_Distribuicao_Cartas();
            Game.JogaRodada();
        }
        printf("Vencedor da partida %d: Jogador %d.\n",ct,Game.Ganhador());
    }
    return 0;
}
