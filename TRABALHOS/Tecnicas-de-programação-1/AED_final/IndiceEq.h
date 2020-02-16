#ifndef INDICEEQ_H
#define INDICEEQ_H

#include "INDEQ.h"
#include "Equipamentos.h"

class IndiceEq
{
private:
    INDEQ * VetIndiceEq;
    int qtd;

public:
    IndiceEq();
    ~IndiceEq();

    int getqtd();



     bool VerificaUnicidadeCodigo(long long codigo); /// VERIFICA SE O Codigo E UNICO JA QUE A CHAVE DE BUSCA E por ele!!!!!!!!

     void InsereEqOrdenadoIndice(Equipamentos *B); /// insere o elemento A no vetor IND, apontado por P, ordenadamente


     bool Ehlixo(int posicao); /// e lixo ou nao?


     int BuscaNoIndice(long long int A); /// retorna posicao no INDICE

     int PosicaoNoArquivo(long long A);

     long long getcodigo(int posicaoNoIndice);

     void setLixo(bool true_or_false,int PosicaoNoIndice);

     void IsolaINDEQ(long long codigo);

     void ModificaPosicao(long long codigo,int NovaPosicao);

     int getPosicaoNoArquivo(int posicaoNoIndice);





};

#endif // INDICEEQ_H
