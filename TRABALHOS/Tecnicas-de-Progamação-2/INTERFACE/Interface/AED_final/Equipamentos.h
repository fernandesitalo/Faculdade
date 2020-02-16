#ifndef EQUIPAMENTOS_H
#define EQUIPAMENTOS_H


class Equipamentos
{
private:
    unsigned long long codigo;
    char nome[80];
    float preco;
    char descricao[200];
    bool lixo;
    int qtd;
public:
    void setcodigo(const long long codigo);
    long long getcodigo();
    void setnome(const char* nome);
    void getnome(char* nome);
    void setpreco(float preco);
    float getpreco();
    void setdescricao(const char* descricao);
    void getdescricao(char* descricao); 
    void setlixo(bool __true_or_false);
    bool getlixo();
    int getqtd();
    void setqtd(int quantidade);

    Equipamentos();
};


#endif // EQUIPAMENTOS_H
