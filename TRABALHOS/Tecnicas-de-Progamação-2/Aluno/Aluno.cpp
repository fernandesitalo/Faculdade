#include "Aluno.h"
#include <string.h>

void Aluno::setmatricula(int matricula)
{
    this->matricula = matricula;
}

int Aluno::getmatricula()
{
    return this->matricula;
}

void Aluno::setnome(char *nome)
{
    strcpy(this->nome,nome);
}

void Aluno::getnome(char *aux)
{
    strcpy(aux,nome);
}

void Aluno::setnota(int n1n2, float _Nota)
{
    if(n1n2 == 1)
    {
        N1 = _Nota;
    }
    else
    {
        N2 = _Nota;
    }

    /// if(n1n2 != 1 && n1n2 != 2) LANÇAR EXECAO TROW 2;
}

float Aluno::getnota(int n1n2)
{
    /// if(n1n2 != 1 && n1n2 != 2 ) thow a;
    if(n1n2 == 1)
        return N1;
    return N2;
}

void Aluno::setfreq(float freq)
{
    this->freq = freq;
}

float Aluno::getfreq()
{
    return this->freq;
}

Aluno::Aluno()
{
    nome[0] = '\0';
    matricula = N1 = N2 = freq = 0;
}


Aluno::Aluno(char *nome,float n1, float n2, float fq, int mat)
{
    strcpy(this->nome,nome);
    N1 = n1;
    N2 = n2;
    freq = fq;
    matricula = mat;
}

/* SOBRECARGA DO OPERADOR '>'(MAIOR) PARA UMA POSSIVEL ORDENACAO DE OBJETOS DA CLASSE Aluno*/
bool Aluno::operator>(Aluno b)
{
    char aux[100];
    b.getnome(aux);
    return(strcoll(nome,aux) > 0);
}

/* SOBRECARGA DO OPERADOR '<'(MAIOR) PARA UMA POSSIVEL ORDENACAO DE OBJETOS DA CLASSE Aluno*/
bool Aluno::operator<(Aluno b)
{
    char aux[100];
    b.getnome(aux);
    return(strcoll(nome,aux) < 0);
}

Aluno Aluno::operator=(Aluno b)
{
    char aux[100];
    b.getnome(aux);
    strcpy(this->nome,aux); ///COPIA DO NOME
    this->matricula = b.matricula;  /// COPIA DA IDADE
    this->N1 = b.N1;
    this->N2 = b.N2;
    this->freq = b.freq;
    return *this;
}

