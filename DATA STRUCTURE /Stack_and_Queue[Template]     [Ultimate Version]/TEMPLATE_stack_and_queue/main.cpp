#include <stdio.h>
#include "queue.h"
#include "stack.h"



int main(){

    My::stack<int> s;
    My::queue<int> q;


    s.push(10);
    s.push(9);
    s.push(8);

    printf("Tamanho da pilha: %d\n",s.size());

    printf("%d\n",s.top());
    s.pop();
    printf("%d\n",s.top());



    printf("Tamanho da fila: %d\n",q.size());


    return 0;
}
