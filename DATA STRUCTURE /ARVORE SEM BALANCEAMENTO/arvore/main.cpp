#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

#define TESTE 0


int main(){

#if TESTE
    Tree<int> T;

    T.Insere(2);
    T.Insere(5);
    T.Insere(7);
    T.Insere(9);
    T.Insere(6);
    T.Insere(1);

    T.Insere(3);
    T.Insere(0);
    T.Insere(8);
    T.Insere(13);
    T.Insere(60);

    T.Print_In_Order();
    puts("________________________________");

    puts("Removendo 60-13-0-8-3");
    T.Remove(60);
    T.Remove(13);
    T.Remove(0);
    T.Remove(8);
    T.Remove(3);

    puts("________________________________");

    T.Print_In_Order();

#endif

    return 0;
}
