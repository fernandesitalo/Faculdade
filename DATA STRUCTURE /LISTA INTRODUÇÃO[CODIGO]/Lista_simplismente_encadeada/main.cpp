#include <iostream>
#include <stdio.h>
#include "Node.h"
#include "List.h"
using namespace std;


int main(){

    List L;

    L.push_2(1);
    L.push_2(2);
    L.push_2(3);
    L.push_2(4);
    L.push_2(5);
    L.push_2(6);
    L.push_2(7);
    L.push_2(8);
    L.push_2(9);
    L.push_2(10);

    if(L.search(5) && L.search(4) && L.search(8))
    printf("Elementos 5,4 e 8 encontrados.\n\n");

    printf("Excluindo elementos 5,4 e 8.\n\n");
    L.pop(5); L.pop(4); L.pop(8);

    if(L.search(5)&&L.search(4)&&L.search(8))
        printf("Algum elemento não foi excluido.\n\n");
    else
        printf("Os elementos 4,5 e 8 foram excluidos com sucesso\n\n");

    L.teste();

    return 0;
}
