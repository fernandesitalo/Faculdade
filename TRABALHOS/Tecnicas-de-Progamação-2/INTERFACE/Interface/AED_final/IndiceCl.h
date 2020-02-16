#ifndef INDICECL_H
#define INDICECL_H
#include "Cliente.h"
#include "INDCL.h"
///CHAVE DE BUSCA - NOME DO CLIENTE
class IndiceCl
{
private:
    INDCL *VetIndiceCl; // VetIndiceCl é um vetor de INDCL
    int qtd;  // quantidade de objetos INDCL que existem no arquivo CADRASTRO
public:
    IndiceCl();

    int getPosicaoNoArquivo(char *A); // retorna posicao do nome A no indice

    int getqtd(); // retorna quantidade de nomes no indice

    void getNome(char *A,int PosicaoNoIndice);// POSICAO DO INDICE

    void InsereOrdenado(Cliente * A); // insere o elemento A no vetor IND, apontado por P, ordenadamente

    int BuscaNoIndice(char *NomeDoCliente); // retorna posicao no INDICE

    bool VerificaUnicidadeNome(const char *NomeDoCliente); // VERIFICA SE O NOME E UNICO JA QUE A CHAVE DE BUSCA E PELO NOME!!!!!!!!

    void setLixo(bool __true_or_false__, int posicao);

    bool Ehlixo(int posicao);

    void IsolaINDCL(char *NomeDoCliente); /// OBJETO INDCL E "CHEGADO PARA O LADO"

    void ModificaPosicao(char *NomeDoCliente, int NovaPosicao); // SETA UMA NOVA POSICAO PARA ESTE NOME QUE E PASSADO COMO PARAMETRO

    ~IndiceCl();
};

#endif // INDICECL_H
