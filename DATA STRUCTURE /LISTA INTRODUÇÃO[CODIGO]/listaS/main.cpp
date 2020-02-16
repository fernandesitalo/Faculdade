#include <stdio.h>
#include "Lista_SO.h"
using namespace std;


int main(){

    Lista_SO L;
    int a = 9;

    L.push(&a);
    a = 8;
    L.push(&a);
    a = 77777;
    L.push(&a);

    a = 12;

    L.push(&a);


    L.pop(77777,&a);

    printf("%d\n",a);





    return 0;
}

