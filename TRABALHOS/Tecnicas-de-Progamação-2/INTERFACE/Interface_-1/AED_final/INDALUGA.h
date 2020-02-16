#ifndef INDALUGA_H
#define INDALUGA_H
class INDALUGA
{
private:
    char Codigos[10];
    int Quantidades[10];
    char NomeDoCliente[80];
    int QtdDeEqAlugados;
    float Preco;
    bool Divida;
    long long CodigoDoAluguel;
    bool lixo;
    int PosicaoNoArquivo;
public:
    void setNomeDoCliente(const char *A);

    void AdicionaEquipamento(long long codigo,int quantidadaAlugada);

    void setQtdDeEqAlugados(int A);

    int getQtdDeEqAlugados();

    void setPrecoTotal(float A);

    float getPrecoTotal();

    void setDivida(bool true_or_false);

    bool getDivida();

    int getCodigo(int posicao);// codigo do equipamento

    int getQuantidadeAlugada(int posicao);

    int VerificaCodigo(long long cod);

    void AlteraQuantidade(int posicao, int quantidade);

    void getNomeCliente(char *A);

    void setLixo(bool vf);

    bool getLixo();

    long long getCodigoDoAluguel();

    void setCodigoDoAluguel(long long cod);

    void setPosicaoNoArquivo(int pos);

    int getPosicaoNoArquivo();

    void RetiraEquipamento(int linha);

    int BuscaEquipamentoNoPedido(long long cod);
    INDALUGA();
};
#endif // INDALUGA_H
