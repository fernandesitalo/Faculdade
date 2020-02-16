#include "IndiceCl.h"
#include <cstring>
#include <fstream>
using namespace std;



void IndiceCl::InsereOrdenado(Cliente *A)
{
    char nome[80];
    A->getnome(nome);

    if(qtd == 0) /// o primeiro elemento so Inserimos... nao ha como fazer tal verificação
    {
         VetIndiceCl[0].setINDCL(nome,0);
         qtd++;
         return;
    }
    // certificar que o vetor ja esta na memoria
    // certificar tbm que o nome que será inserido nao esta no indice

    int j;
    char temp[80];
    INDCL aux;
    aux.setINDCL(nome,qtd);

    VetIndiceCl[qtd-1].getNome(temp);

    for(j = qtd-1 ; j >= 0 && (strcoll(nome,temp)< 0);j--)
    {
        VetIndiceCl[j+1] = VetIndiceCl[j];

        if(j)
            VetIndiceCl[j-1].getNome(temp);
    }

    VetIndiceCl[j+1] = aux;

    qtd++; // qtd++ pois sera gravado qtd objetos INDICE
}


int IndiceCl::BuscaNoIndice(char *NomeDoCliente) /// RETORNA A POSICAO NO INDICE
{
// Variaveis Necessarias para Busca
    int meio;
    int pi = 0;
    int pf = qtd -1;
    char nome[80];

    while(pi != pf)
    {
        meio = (pi+pf)/2;
        VetIndiceCl[meio].getNome(nome);

        if(strcoll(NomeDoCliente,nome) > 0)
            pi = meio + 1;

        else  pf = meio;
    }
    return pi;
}


bool IndiceCl::VerificaUnicidadeNome(const char *NomeDoCliente) // na verdade uma busca binaria
{                                         // que confere se o nome parametro e igual ao nome da posicao da busca

    if(qtd == 0)
        return true;


    int meio;
    int pi = 0;
    int pf = qtd-1;
    char nome[80];

    while(pi != pf)
    {
        meio = (pi+pf)/2;
        VetIndiceCl[meio].getNome(nome);

        if(strcoll(NomeDoCliente,nome) > 0)
            pi = meio + 1;

        else
            pf = meio;
    }

    VetIndiceCl[pi].getNome(nome);
    if(strcmp(nome,NomeDoCliente) == 0 && !VetIndiceCl[pi].lixo)
        return false;

    return true;
}

void IndiceCl::setLixo(bool __true_or_false__,int posicao)
{
     VetIndiceCl[posicao].lixo =  __true_or_false__;
}

bool IndiceCl::Ehlixo(int posicao)
{
    return VetIndiceCl[posicao].lixo;
}

void IndiceCl::IsolaINDCL(char *NomeDoCliente)
{
    int i = BuscaNoIndice(NomeDoCliente);

    qtd--;
    for(; i < qtd; i++)
    {
        VetIndiceCl[i] = VetIndiceCl[i+1];
    }


}

void IndiceCl::ModificaPosicao(char *NomeDoCliente, int NovaPosicao)
{
    VetIndiceCl[BuscaNoIndice(NomeDoCliente)].setposicao(NovaPosicao);
}


int IndiceCl::getqtd()
{
    return qtd;
}



void IndiceCl::getNome(char *A, int PosicaoNoIndice)//POSICAO DO INIDICE
{
    char aux[80];
    VetIndiceCl[PosicaoNoIndice].getNome(aux);
    strcpy(A,aux);
}

int IndiceCl::getPosicaoNoArquivo(char *A)
{
    int PosicaoNoArquivo = VetIndiceCl[BuscaNoIndice(A)].getPosNoArquivo();
    int PosicaoNoIndice = BuscaNoIndice(A);

    char aux[80];
    VetIndiceCl[PosicaoNoIndice].getNome(aux);
        if(strcmp(A,aux) == 0)
       return PosicaoNoArquivo;
        return -1;
}

IndiceCl::IndiceCl() /// no construtor iremos colocar todo conteudo do indice no ponteiro k, alocado dinamicamente;
{
    fstream INDICE("INDICE.dat",ios_base::in |ios_base::out | ios_base::binary);

    if(!INDICE.is_open()) /// SE O ARQUIVO NAO EXISTIR, VAMOS CRIA-LO!
    {
        INDICE.open("INDICE.dat",ios_base::out );
        INDICE.close();
        INDICE.open("INDICE.dat",ios_base::in | ios_base::out | ios_base::binary);
    }

    INDICE.seekg(0,ios_base::end);

    qtd = INDICE.tellg() / sizeof(INDCL); /// total de bytes/ bytes do objeto IND = numero de Objetos INd

    VetIndiceCl = new INDCL[qtd+1];

    INDICE.seekg(0);// COMECAR A LEITURA DO PRIMEIRO BYTE CARAI
    INDICE.read((char *)VetIndiceCl,sizeof(INDCL)*qtd); // le do arquivo exatamente a quantidade de arquivos existentes, no ponteiro 'k'
    INDICE.close();
}

IndiceCl::~IndiceCl() /// grava no arquivo o vetor de objetos IND, que ja estao ordenados
{
    fstream INDICE("INDICE.dat",ios_base::out | ios_base::binary);

    for(int i = 0 ; i < qtd ; i++)
        INDICE.write((char *)&VetIndiceCl[i],sizeof(INDCL)); // GRAVA A QUANTIDADE CERTA DE OBJETOS DA CLASSE INDICE;
    INDICE.close();

    delete VetIndiceCl;
}
