#include <iostream>
#include <stdio.h>
using namespace std;

#include "Aluno.h"
#include "ListaDE.h"



int main(){

    Aluno aux;

    ListaDE L;

    aux.set(1,"UMMMM");
    L.push(&aux);

    aux.set(2,"DOIIIIS");
    L.push(&aux);


    aux.set(3,"TREEESSSSS");
    L.push(&aux);

    printf("LSITAGEM DOS ELEMENTOS INSERIDOS: \n");

    L.printLista();
    printf("\n\n");





    aux.set(0,"lixo");
    L.pop(2,&aux);

    cout << "POP ELEMENTO DE KEY: 2::::::   " << aux.key << "    " << aux.nome << endl;



















    return 0;
}
