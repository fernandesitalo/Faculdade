#ifndef ALUNO_H
#define ALUNO_H


class Aluno
{
private:
    char nome[100];
    int matricula;
    float freq;
    float N1,N2;

public:
    Aluno();
    Aluno(char *nome,float n1, float n2, float fq, int mat);
    void setmatricula(int matricula);
    int getmatricula();
    void setnome(char* nome);
    void getnome(char* aux);
    void setnota(int n1n2, float _Nota);
    float getnota(int n1n2);
    void setfreq(float freq);
    float getfreq();

    bool operator> (Aluno b);
    bool operator< (Aluno b);
    Aluno operator= (Aluno b);
};

#endif // ALUNO_H
