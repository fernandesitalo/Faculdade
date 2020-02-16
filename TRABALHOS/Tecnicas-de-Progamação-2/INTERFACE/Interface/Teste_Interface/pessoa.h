#ifndef PESSOA_H
#define PESSOA_H

class Pessoa
{
private:
    char nome[60], endereco[60], telefone[20];
    unsigned long long cpf;
    int idade;
public:
    void setNome(const char *nome);
    void setEndereco(const char *endereco);
    void setTelefone(const char *telefone);
    void setCpf(unsigned long long cpf);
    void setIdade(int idade);
    char* getNome();
    char* getEndereco();
    char* getTelefone();
    unsigned long long getCpf();
    int getIdade();
};

#endif // PESSOA_H
