#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List //LISTA NUTELA - SEM ORDENACAO E SEM BOIOLAGEM, LISTA BRUTA
{
private:
    Node *Head_;
    int qtd_;
public:
    void push(int conteudo);
    void push_2(int conteudo);
    bool pop(int k);
    int size();
    bool search(int k);


    void teste();

    ~List();
    List();
};

#endif // LIST_H
