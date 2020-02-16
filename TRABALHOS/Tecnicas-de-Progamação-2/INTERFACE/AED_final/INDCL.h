#ifndef INDCL_H
#define INDCL_H


class INDCL
{
public:
    char nome[80];
    int pos;
    bool lixo;
public:
    void setINDCL(const char *nome,int pos);
    void getNome(char *vetorchar);
    void setposicao(int posicao);
    int getPosNoArquivo();
    INDCL();
};

#endif // INDCL_H
