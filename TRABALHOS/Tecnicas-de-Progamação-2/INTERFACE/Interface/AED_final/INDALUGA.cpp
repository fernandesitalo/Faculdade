#include "INDALUGA.h"
#include <cstring>


void INDALUGA::setNomeDoCliente(const char *A)
{
    strcpy(NomeDoCliente,A);
}

void INDALUGA::AdicionaEquipamento(long long codigo, int quantidadaAlugada)
{
    Codigos[QtdDeEqAlugados] = codigo;
    Quantidades[QtdDeEqAlugados]= quantidadaAlugada;
    QtdDeEqAlugados++;
}

void INDALUGA::setQtdTotalAlugada(int A)
{
    QtdDeEqAlugados = A;
}

void INDALUGA::setPrecoTotal(float A)
{
    Preco = A;
}

float INDALUGA::getPrecoTotal()
{
    return Preco;
}

void INDALUGA::setDivida(bool true_or_false)
{
    Divida = true_or_false;
}

bool INDALUGA::getDivida()
{
    return Divida;
}

int INDALUGA::getCodigo(int posicao)
{
    return Codigos[posicao];
}

int INDALUGA::getQuantidadeAlugada(int posicao)
{
    return Quantidades[posicao];
}

int INDALUGA::VerificaCodigo(long long cod)
{

    for(int i = QtdDeEqAlugados ; i >= 0 ; i--)
    {
        if(cod == getCodigo(i))
            return i;
    }
    return -50;
}

void INDALUGA::AlteraQuantidade(int posicao, int quantidade)
{
    Quantidades[posicao] = quantidade;
}

void INDALUGA::getNomeCliente(char *A)
{
    strcpy(A,NomeDoCliente);
}

void INDALUGA::setLixo(bool vf)
{
    lixo = vf;
}

bool INDALUGA::getLixo()
{
    return lixo;
}

INDALUGA::INDALUGA()
{
    QtdDeEqAlugados = 0;
    Divida = false;
    CodigoDoAluguel = 999;
    lixo = false;
    PosicaoNoArquivo = 0;
}
