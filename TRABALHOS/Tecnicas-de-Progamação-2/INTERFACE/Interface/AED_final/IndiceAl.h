#ifndef INDICEAL_H
#define INDICEAL_H

#include "INDALUGA.h"
#include "IndiceAl.h"

class IndiceAl
{
public:
    INDALUGA *VetAlugados;
    int qtd;

public:
    IndiceAl();

    ~IndiceAl();

    int getqtd();

    void getNome(char*A,int posicao);

    bool getDivida(int posicao);

    void InserirOrdenadamenteAluguel(INDALUGA A);

    bool VerificarUnicidadeCodigo(long long cod);

    int PosicaoNoArquivo(long long cod);

    long long getCodigoDoAluguel();

    long long getCodigoDoAluguel(int posicao);

    void setCodigoDoAluguel(long long A);

    bool ehLixo(int posicao);

    void setLixo(bool a,int posicao);

    void IsolaINDALUGA(long long codigo);

    int BuscaNoIndice(long long codigo);

    void ModificaPosicao(long long codigo, int NovaPosicao);



};

#endif // INDICEAL_H
