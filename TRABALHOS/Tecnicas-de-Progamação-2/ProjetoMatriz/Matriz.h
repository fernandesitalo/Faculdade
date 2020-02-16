#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>

namespace MAT{// INICIO NAMESPACE 'TP2'

class Matriz
{
private:
    int quantidadeDeColunas;
    int quantidadeDeLinhas;
    int *ptMatriz;

public:
    Matriz(int qLinhas, int qColunas); // CONSTRUTOR..

    ~Matriz(); // DESTRUTOR..

    int getQuantidadeDeLinhas()const{return quantidadeDeLinhas;} // RETORNA QUANTIDADE DE LINHAS..

    int getQuantidadeDeColunas()const{return quantidadeDeColunas;} // RETORNA QUANTIDADE DE COLUNAS...

    void setElemento(int elemento, int linha, int coluna)const; // ATRIBUI VALOR AO ELEMENTO...

    int getElemento(int linha, int coluna)const; // RETORNA O ELEMENTO...

    Matriz* operator+(Matriz const * const mat)const; // SOBRECARGA DO OPERADOR DE ADICAO

    Matriz* operator-(Matriz const * const mat)const; /* ok_implementado-testado*/

    Matriz *operator*(Matriz const * const mat)const; /*ok_implementado-testado*/

    Matriz* Transposta()const; /* ok_implementado-testado */

    Matriz* MultipicaPorUmNumero(int numero)const; /* ok_implementado-testado*/

    bool operator==(Matriz const * const mat)const; /* ok_implementado-testado*/

    bool operator!=(Matriz const * const mat)const; /* ok_implementado-testado*/

    bool EIdentidade()const; /*ok_implementado-testado*/

    bool ESimetrica()const; /* ok_implementado-testado*/

    bool ETriangularInferior()const; /*ok_implementada-testado*/

    bool ETriangularSuperior()const; /*ok_implementada-testado*/

    Matriz *copyMatriz()const; /* ok_implementado-testado*/

    Matriz *Potencia(int grau)const; /*ok_implementado-testado*/

    bool EOrtogonal()const;/*ok_implementado-testado*/

    bool EPermutada_1()const;/*ok_implementado-testado*/

    bool EPermutada_2()const;/*ok_implementado-testado*/
};


}// FIM NAMESPACE 'MAT'

#endif // MATRIZ_H
