#ifndef CPF_CL_H
#define CPF_CL_H


class cpf_cl
{
private:
    char *cpf; // vai receber um vetor de caracteres

    bool valida_formato(char *aux);// so valida

public:
    char* getcpf(); // retorna um ponteiro para o cpf

    bool setcpf(char *aux); // tem como parametro o cpf lido na main

};

#endif // CPF_CL_H
