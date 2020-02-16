#ifndef INTERFACE_H
#define INTERFACE_H
#include "vetor.h"

class interface
{
public:

    static void leia_objeto(vetor *x);
    static void imprima_objeto(vetor *x);
    static char exibe_menu();

    ~interface();
    interface();
};

#endif // INTERFACE_H
