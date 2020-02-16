#include "cpf_cl.h"

#define NULL 0

bool cpf_cl::valida_formato(char *aux)
{
    int i;

    for(i = 0 ; aux[i] != '\0'; i++);

    if(i == 11)
    {
        return true; // o formato e validooooo!!!!!! birl!!!
    }

    return false; // formato e invalido

}


char* cpf_cl::getcpf()
{
    return cpf;
}


bool cpf_cl::setcpf(char *aux)
{

   int i,soma,digito1,digito2,temp;

    if( !(valida_formato(aux)) )
    {
        cpf = NULL;
        return false;
    }

// CHEGUEI AQUI ENTAO TA TUDO SUSSA, FORMATO OK


// VALIDAR UM CASO ESPECIAL , QNDO TODOS DIGITOS SAO IGUAIS
    for(i = 0 ; aux[i+1] == aux[i] && i < 11; i++);

    if(i == 10)
    {
        cpf = NULL;
        return false; // tudo igual nesse cpf, invalido!
    }


// CHEGUEI ATE AQUI , ENTAO ESTA OK ATE AGR... AQUI COMECA A VALIDACAO DE VERDADE


    digito1 = aux[9] - '0';
    digito2 = aux[10] - '0';


    // VALIDACAO DO PRIMEIRO DIGITO
    for(soma = 0,i = 10 ; i >= 2 ; i--)
    {
        soma += (aux[10 - i]-'0') * i;
    }

    temp = ((soma*10)%11); // regra de validacao

    if(temp >= 10)
        temp = 0;


    if(temp == digito1)
    {
        //VALIDACAO DO SEGUNDO DIGITO
        for(soma = 0,i = 11 ; i >= 2 ; i--)
        {
            soma += (aux[11 - i]-'0') * i;
        }

        temp = ((soma*10)%11); // regra de validacao
        if(temp >= 10)
            temp = 0;

        if(digito2 == temp)
        {
            cpf = aux; // deu de boa
            return true;
        }
    }

    cpf = NULL;
    return false;
}

