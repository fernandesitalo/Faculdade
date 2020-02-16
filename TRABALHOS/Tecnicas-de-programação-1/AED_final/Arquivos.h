#ifndef ARQUIVOS_H
#define ARQUIVOS_H
#include "Cliente.h"
#include "Equipamentos.h"
#include "Aluga.h"


class Arquivos
{
public:
    static void NovoCliente(Cliente *A);

    static void PegaCliente(Cliente *A, int posicao );

    static void SobreescreveCliente(Cliente *A,int posicao);

    static void EsvaziarLixeiraClientes();




    static void NovoEquipamento(Equipamentos* B);

    static void PegaEquipamento(Equipamentos *B, int posicao);

    static void SobreescreveEquipamento(Equipamentos *B, int posicao);

    static void EsvaziarLixeiraEquipamentos();




    static void NovoAluguel(INDALUGA * A);

    static void PegaAluguel(INDALUGA * A, int posicao);

    static void SobreescreveAluguel(INDALUGA*A,int posicao);

    static void EsvaziarLixeiraAluguel();




    Arquivos();
};

#endif // ARQUIVOS_H
