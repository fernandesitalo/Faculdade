#include <iostream>
#include <stdio.h>
using namespace std;

#include <list>


#include "ListaDE.h"

int main(){
    ListaDE<int> L;

    ListaDE<int>::iterator it;

    int a;
    a = 10;
    printf("tamanho : %d\n",L.size());



    L.push(&a);

    it = L.begin();


    printf("%d\n",*it);
    ++it;
    printf("tamanho : %d\n",L.size());
    printf("%d\n",*it);
    printf("tamanho : %d\n",L.size());
    L.pop(it);
    printf("tamanho : %d\n",L.size());

    return 0;
}
