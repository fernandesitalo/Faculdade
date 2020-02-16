#include <stdio.h>
#include "Colision.h"
using namespace std;

int main(){
    //freopen("in","r",stdin);
    bool fimDoJogo = true;
    while(fimDoJogo){
        Colision GAME;
        if(!GAME.LeituraJogadores())
        {
            fimDoJogo = false;
        }
        else
        {
            GAME.LeituraLimitesMapa();
            GAME.LeituraDasPedras();
            GAME.LeituraComandos_Joga();
            GAME.ImprimirResultados();
        }
    }
    return 0;
}
