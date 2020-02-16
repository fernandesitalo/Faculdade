#ifndef INTERFACE_H
#define INTERFACE_H

#include "Matriz.h"


class Interface
{
public:
    Interface();

    static void ReadMatrix(Matriz* X); // LEITURA DA MATRIZ

    static void PrintMatrix(Matriz* X); // IMRIME A MATRIZ

    static void PrintfMenu(); // IMPRIME MENU
};

#endif // INTERFACE_H
