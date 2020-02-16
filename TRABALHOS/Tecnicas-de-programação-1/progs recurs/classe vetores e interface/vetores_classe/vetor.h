#ifndef VETOR_H
#define VETOR_H


class vetor
{
private:
    int n; /// CAPACIDADE MAX DE ELEMENTOS
    int* vet; /// ESTE PONTEIRO RECEBERÁ DINAMICAMENTE O VETOR COM 'n' POSICOES
    int qtd;  /// QUANTIDADE DE ELEMENTOS QUE O VETOR TERÁ


public:
    vetor(int n);
    ~vetor();

    int getqtd();

    int inserir(int x); // retorna 1 se der tudo certo, -1 se o numero ja foi colocado no conjunto e 2 se der falso

    int getposicao(int x);

    int getqnt_total(); // retorna o n



    void uniao(vetor* x , vetor* y);

    void intercessao(vetor *x,vetor* y);

    void diferenca(vetor*x,vetor *y);

    void subcrescente(vetor *x);

    void subdecrescente(vetor* x);

    static bool SAOdisjuntos(vetor *x,vetor *y);

    static bool SAOidenticos(vetor *x,vetor *y);

    static bool subconjunto(vetor *x,vetor *y);

    static int produtoEscalar(vetor *x,vetor *y);

    static int amplitude(vetor *x);

    static bool ehvazio(vetor *x);

    void ordena(vetor *x);

    void intercala(vetor* x,vetor *y);

    static int BUSCABINARIA(vetor* x,int pi,int pf,int elemento);
};

#endif // VETOR_H
