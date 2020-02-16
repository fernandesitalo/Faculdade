#include <stdio.h>
#include "Colision.h"
using namespace std;

int main(){
    //freopen("in","r",stdin);
    while(1){
        Colision GAME;
        if(!GAME.LeituraJogadores()) break;
        GAME.LeituraLimitesMapa();
        GAME.LeituraDasPedras();
        GAME.LeituraComandos_Joga();
        GAME.ImprimirResultados();
        puts("");
    }
    return 0;
}
