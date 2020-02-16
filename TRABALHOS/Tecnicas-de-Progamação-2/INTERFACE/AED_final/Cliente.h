#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
private:
    char nome[80];
    long long cpf;
    char endereco[200];
    long long fone;
    bool lixo;
public:
    void setnome(const char* nome);
    void getnome(char *nome);
    void setcpf(const long long cpf);
    long long getcpf();
    void setendereco(const char* endereco);
    void getendereco(char* endereco);
    void setfone(const long long fone);
    long long getfone();
    void setLixo(bool __true_or_false__);
    bool getlixo();


    Cliente();
};
#endif // CLIENTE_H
