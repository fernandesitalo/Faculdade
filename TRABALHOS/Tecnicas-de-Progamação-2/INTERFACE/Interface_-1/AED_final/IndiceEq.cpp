#include "IndiceEq.h"
#include "INDEQ.h"
#include <fstream>
using namespace std;

IndiceEq::IndiceEq()// trazer todo o arquivo indice equipamento para memoria
{
    fstream INDICE_EQ("IND_EQ.dat",ios_base::in |ios_base::binary);

    if(!INDICE_EQ.is_open()) /// SE O ARQUIVO NAO EXISTIR, VAMOS CRIA-LO!
    {
        INDICE_EQ.open("IND_EQ.dat",ios_base::out );
        INDICE_EQ.close();
        INDICE_EQ.open("IND_EQ.dat",ios_base::in | ios_base::out | ios_base::binary);
    }

    INDICE_EQ.seekg(0,ios_base::end);

    qtd = INDICE_EQ.tellg() / sizeof(INDEQ); /// total de bytes/ bytes do objeto IND = numero de Objetos INd

    VetIndiceEq = new INDEQ[qtd+1];

    INDICE_EQ.seekg(0);// COMECAR A LEITURA DO PRIMEIRO BYTE CARAI
    INDICE_EQ.read((char *)VetIndiceEq,sizeof(INDEQ)*qtd); // le do arquivo exatamente a quantidade de arquivos existentes, no ponteiro 'k'
    INDICE_EQ.close();
}

IndiceEq::~IndiceEq()
{
    fstream INDICE_EQ("IND_EQ.dat",ios_base::out | ios_base::binary);

    for(int i = 0 ; i < qtd ; i++)
        INDICE_EQ.write((char *)&VetIndiceEq[i],sizeof(INDEQ)); // GRAVA A QUANTIDADE CERTA DE OBJETOS DA CLASSE INDICE;

    INDICE_EQ.close();

    //delete[] VetIndiceEq;
}

int IndiceEq::getqtd()
{
    return qtd;
}

bool IndiceEq::VerificaUnicidadeCodigo(long long codigo)
{
    if(codigo == 0)
    {
        return false;
    }
    if(qtd == 0)
        return true;

    int meio;
    int pi = 0;
    int pf = qtd-1;

    while(pi != pf)
    {
        meio = (pi+pf)/2;

        if(codigo > VetIndiceEq[meio].cod)
            pi = meio + 1;

        else  pf = meio;
    }

    if(codigo == VetIndiceEq[pi].cod && !VetIndiceEq[pi].lixo) // aceso a variavel, pois INDEQ é publico
        return false;

    return true;
}

void IndiceEq::InsereEqOrdenadoIndice(Equipamentos *B)
{
    if(qtd == 0) /// o primeiro elemento so Inserimos... nao ha como fazer tal verificação
    {
        VetIndiceEq[0].setINDEQ(B->getcodigo(),0);
        qtd++;
        return;
    }

    int j;
    INDEQ aux;
    aux.setINDEQ(B->getcodigo(),qtd);

    for(j = qtd-1 ; j >= 0 && aux.cod < VetIndiceEq[j].cod ;j--)
    {
        VetIndiceEq[j+1] = VetIndiceEq[j];
    }

    VetIndiceEq[j+1] = aux;

    qtd++; // qtd++ pois sera gravado qtd objetos INDICE
}

bool IndiceEq::Ehlixo(int posicao)
{
    return VetIndiceEq[posicao].lixo;
}

int IndiceEq::BuscaNoIndice(long long A)
{
    if(qtd == 0)
        return -1;

    int meio;
    int pi = 0;
    int pf = qtd-1;

    while(pi != pf)
    {
        meio = (pi+pf)/2;

        if(A > VetIndiceEq[meio].cod)
            pi = meio + 1;

        else  pf = meio;
    }

    if(A == VetIndiceEq[pi].cod) // aceso a variavel, pois INDEQ é publico
        return pi;

    return -1;
}

int IndiceEq::PosicaoNoArquivo(long long A)
{
    int posicaoIndice = BuscaNoIndice(A);

    if(posicaoIndice < 0 )
        return  -1;

    return VetIndiceEq[posicaoIndice].pos;
}

long long IndiceEq::getcodigo(int posicaoNoIndice)
{
    return VetIndiceEq[posicaoNoIndice].cod;
}

void IndiceEq::setLixo(bool true_or_false, int PosicaoNoIndice)
{
    VetIndiceEq[PosicaoNoIndice].lixo = true_or_false;
}

void IndiceEq::IsolaINDEQ(long long codigo)
{
    int i = BuscaNoIndice(codigo);
    qtd--;
    for(; i < qtd ; i++)
    {
        VetIndiceEq[i+1] = VetIndiceEq[i];
    }
}

void IndiceEq::ModificaPosicao(long long codigo, int NovaPosicao)
{
    VetIndiceEq[BuscaNoIndice(codigo)].pos = NovaPosicao;
}

int IndiceEq::getPosicaoNoArquivo(int posicaoNoIndice)
{
    return VetIndiceEq[posicaoNoIndice].pos;
}






















