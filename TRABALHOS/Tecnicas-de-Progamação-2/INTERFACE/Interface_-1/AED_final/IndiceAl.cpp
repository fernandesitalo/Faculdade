#include "IndiceAl.h"
#include <cstring>
#include <fstream>
using namespace std;

IndiceAl::IndiceAl()
{
    fstream INDICE("Alugueis.dat",ios_base::in |ios_base::binary);

    if(!INDICE.is_open()) /// SE O ARQUIVO NAO EXISTIR, VAMOS CRIA-LO!
    {
        INDICE.open("Alugueis.dat",ios_base::out |ios_base::binary);
        INDICE.close();// criamos o arquivo
        INDICE.open("Alugueis.dat",ios_base::in | ios_base::out | ios_base::binary);
    }

    INDICE.seekg(0,ios_base::end);

    qtd = INDICE.tellg() / sizeof(INDALUGA); /// total de bytes/ bytes do objeto IND = numero de Objetos INd

    VetAlugados = new INDALUGA[qtd+1];

    INDICE.seekg(0);// COMECAR A LEITURA DO PRIMEIRO BYTE CARAI
    INDICE.read((char *)VetAlugados,sizeof(INDALUGA)*qtd); // le do arquivo exatamente a quantidade de arquivos existentes, no ponteiro 'k'
    INDICE.close();
}

IndiceAl::~IndiceAl()
{
    fstream INDICE("Alugueis.dat",ios_base::out | ios_base::binary);

    for(int i = 0 ; i < qtd ; i++)
        INDICE.write((char *)&VetAlugados[i],sizeof(INDALUGA)); // GRAVA A QUANTIDADE CERTA DE OBJETOS DA CLASSE INDICE;
    INDICE.close();

    delete VetAlugados;
}

int IndiceAl::getqtd()
{
    return qtd;
}

void IndiceAl::getNome(char *A, int posicao)
{
    VetAlugados[posicao].getNomeCliente(A);
}

bool IndiceAl::getDivida(int posicao)
{
    return VetAlugados[posicao].getDivida();
}

void IndiceAl::InserirOrdenadamenteAluguel(INDALUGA A)
{
    if(qtd == 0) /// o primeiro elemento so Inserimos... nao ha como fazer tal verificação
    {
        VetAlugados[0] = A;
        qtd++;
        return;
    }

    int j;


    for(j = qtd-1 ; j >= 0 && A.getCodigoDoAluguel() < VetAlugados[j].getCodigoDoAluguel();j--)
    {
        VetAlugados[j+1] = VetAlugados[j];
    }
    VetAlugados[j+1] = A;
    VetAlugados[j+1].setPosicaoNoArquivo(qtd);
    qtd++; // qtd++ pois sera gravado qtd objetos INDICE
}

bool IndiceAl::VerificarUnicidadeCodigo(long long cod)
{
    if(qtd == 0)
        return true;

    int meio;
    int pi = 0;
    int pf = qtd-1;

    while(pi != pf)
    {
        meio = (pi+pf)/2;

        if(cod > VetAlugados[meio].getCodigoDoAluguel())
            pi = meio + 1;

        else  pf = meio;
    }
    if(cod == VetAlugados[pi].getCodigoDoAluguel() && !VetAlugados[pi].getLixo())
        return false;

    return true;
}

int IndiceAl::PosicaoNoArquivo(long long cod)
{

    int meio;
    int pi = 0;
    int pf = qtd-1;

    while(pi != pf)
    {
        meio = (pi+pf)/2;

        if(cod > VetAlugados[meio].getCodigoDoAluguel())
            pi = meio + 1;

        else  pf = meio;
    }

    return VetAlugados[pi].getPosicaoNoArquivo();

}

long long IndiceAl::getCodigoDoAluguel()
{
  if(qtd)
  return  VetAlugados[qtd-1].getCodigoDoAluguel() + 1;

  return VetAlugados[qtd].getCodigoDoAluguel();


}

long long IndiceAl::getCodigoDoAluguel(int posicao)
{

    return VetAlugados[posicao].getCodigoDoAluguel();
}

void IndiceAl::setCodigoDoAluguel(long long A)
{
    VetAlugados[qtd].setCodigoDoAluguel(A);
}

bool IndiceAl::ehLixo(int posicao)
{
    return VetAlugados[posicao].getLixo();
}

void IndiceAl::setLixo(bool a,int posicao)
{
    VetAlugados[posicao].setLixo(a);
}

void IndiceAl::IsolaINDALUGA(long long codigo)
{
    int i = BuscaNoIndice(codigo);
    qtd--;
    for(; i < qtd ; i++)
    {
        VetAlugados[i+1] = VetAlugados[i];
    }
}

void IndiceAl::ModificaPosicao(long long codigo, int NovaPosicao)
{
    VetAlugados[BuscaNoIndice(codigo)].setPosicaoNoArquivo(NovaPosicao);
}


int IndiceAl::BuscaNoIndice(long long codigo)
{
    int meio;
    int pi = 0;
    int pf = qtd-1;

    while(pi != pf)
    {
        meio = (pi+pf)/2;

        if(codigo > VetAlugados[meio].getCodigoDoAluguel())
            pi = meio + 1;

        else  pf = meio;
    }
    return pi;
}






