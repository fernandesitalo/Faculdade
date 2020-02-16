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

void INDALUGA::setQtdDeEqAlugados(int A)
{
    QtdDeEqAlugados = A;
}

int INDALUGA::getQtdDeEqAlugados()
{
    return QtdDeEqAlugados;
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

int INDALUGA::VerificaCodigo(long long cod)///////////////////////////////////////
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

long long INDALUGA::getCodigoDoAluguel()
{
    return CodigoDoAluguel;
}

void INDALUGA::setCodigoDoAluguel(long long cod)
{
    CodigoDoAluguel = cod;
}

void INDALUGA::setPosicaoNoArquivo(int pos)
{
    PosicaoNoArquivo = pos;
}

int INDALUGA::getPosicaoNoArquivo()
{
    return PosicaoNoArquivo;
}

void INDALUGA::RetiraEquipamento(int linha)//
{
    for(int i = linha ; i <  QtdDeEqAlugados; i++)
    {
        Codigos[i] = Codigos[i+1];
        Quantidades[i] = Quantidades[i+1];
    }
    QtdDeEqAlugados--;
}

int INDALUGA::BuscaEquipamentoNoPedido(long long cod)//
{
    int i;
    for(i = 0 ; i <  QtdDeEqAlugados && cod != Codigos[i]; i++);
    if(Codigos[i] == cod)
    {
        return i;
    }
    return -1;
}

INDALUGA::INDALUGA()
{
    QtdDeEqAlugados = 0;
    Divida = false;
    CodigoDoAluguel = 10000;
    lixo = false;
    PosicaoNoArquivo = 0;
}
