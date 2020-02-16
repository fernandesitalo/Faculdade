#ifndef NODED_H
#define NODED_H
#include "Aluno.h"


class NodeD
{
public:
    NodeD* next;
    NodeD* prev;
    Aluno Conteudo;


public:
    static NodeD *MontanodeD(Aluno * Conteudo);
    static void DesmontaNodeD(NodeD * No);
    NodeD();
};

#endif // NODED_H
