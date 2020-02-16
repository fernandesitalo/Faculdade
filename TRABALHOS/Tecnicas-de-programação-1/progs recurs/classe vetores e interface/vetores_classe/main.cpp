#include "vetor.h"
#include "interface.h"
#include <iostream>
using namespace std;

int main()
{
    char op;
    int qtdA,qtdB;

    cout << ">> Quantidade de elementos do vetor A: ";
    cin >> qtdA;
    vetor A(qtdA);
    interface::leia_objeto(&A);

    cout << ">> Quantidade de elementos do vetor A: ";
    cin >> qtdB;
    vetor B(qtdB);
    interface::leia_objeto(&B);

    vetor U(qtdA+qtdB); // uniao
    vetor I(qtdA); // intersecao
    vetor D(qtdA+qtdB); // diferenca
    vetor S1(qtdA);//subdecrescente
    vetor S2(qtdB);
    vetor A1(qtdA); // vetor auxiliar que pode ser ordenado
    vetor B1(qtdB); // vetor auxiliar que pode ser ordenado
    vetor C1(qtdA+qtdB); // A+B ordenado e intercalado
    int aux,aux1;
    op = interface::exibe_menu();
    while( op != 's')
    {
        switch(op)
        {

        case 'a'://Descubra se A e/ou B sao conjuntos vazios
            if(vetor::ehvazio(&A))
                cout << "A e um conjunto vazio!\n";
            else
                cout<< "A nao e um conjunto vazio!\n";

            if(vetor::ehvazio(&B))
                cout << "B e um conjunto vazio!\n";
            else
                cout<< "B nao e um conjunto vazio!\n";
            break;

        case 'b':// Uniao: A e B
            U.uniao(&A,&B);
            interface::imprima_objeto(&U);
            break;

        case 'c':// Intercessao: A e B
            I.intercessao(&A,&B);
            interface::imprima_objeto(&I);
            break;

        case 'd'://Diferenca: A - B
            D.diferenca(&A,&B);
            interface::imprima_objeto(&D);
            break;

        case 'e':// Diferenca: B - A
            D.diferenca(&B,&A);
            interface::imprima_objeto(&D);
            break;

        case 'f'://Descubra se A e subconjunto de B
            if(vetor::subconjunto(&A,&B))
                cout << "A e um sub conjunto de B";
            else
                cout << "A nao e um sub conjunto de B";
            break;

        case 'g'://Descubra se B e subconjunto de A
            if(vetor::subconjunto(&B,&A))
                cout << "B e um sub conjunto de A";
            else
                cout << "B nao e um sub conjunto de A";
            break;

        case 'h'://Descubra se A e B sao conjuntos identicos
            if(vetor::SAOidenticos(&A,&B))
                cout << "Os conjuntos A e B Sao identicos!\n";
            else
                cout << "Os conjuntos A e B nao sao identicos!\n";
            break;

        case 'i'://Descubra se A e B sao conjuntos disjuntos
            if(vetor::SAOdisjuntos(&A,&B))
                cout << "Os conjuntos A e B sao disuntos!\n";
            else
                cout << "Os conjuntos A e B NAO sao disjuntos!\n";
            break;

        case 'j'://Amplitude dos Conjuntos A e B
            cout << "Amplitude conjunto A: "<<A.amplitude(&A)<<endl;
            cout << "Amplitude conjunto B: "<<B.amplitude(&B)<<endl;
            break;

        case 'k'://Produto escalar entre A e B
                cout << "Produto escalar entre os conjuntos A e B: "<<vetor::produtoEscalar(&A,&B)<<endl;
            break;

        case 'l'://subcadeia ordenada de forma Crescente de A
            S1.subcrescente(&A);
            interface::imprima_objeto(&S1);
            break;

        case 'm'://Conjunto H - Maior subcadeia ordenada de Forma Decrescente de B
            S2.subdecrescente(&B);
            interface::imprima_objeto(&S2);
            break;

        case 'n'://n -Conjunto I, Vetores A  e B Intercalados e Ordenados
            A1.ordena(&A);
            B1.ordena(&B);
            C1.intercala(&A1,&B1);
            interface::imprima_objeto(&C1);
            break;

        case 'o':
            cout << "Conjunto A: ";
            interface::imprima_objeto(&A);
            cout << "Conjunto B: ";
            interface::imprima_objeto(&B);
            break;

        case 'P': /// buscar um elemento do vetor A por busca binaria
            A1.ordena(&A);
            cout << "DIGITE O ELEMENTO A SER PROCURADO: ";
            cin>>aux1;

            aux = vetor::BUSCABINARIA(&A1,0,A1.getqnt_total(),aux1);

            if(A1.getposicao(aux) == aux1)
               cout << "O ELEMENTO "<<A1.getposicao(aux)<<" PROCURADO ESTA NA POSICAO: "<<aux<<" DO VETOR A ORDENADO!!"<<endl;
            else
               cout << "Este Elemento Nao EXISTE neste CONJUNTO!!!\n\n";
            break;

        case 'Q': ///buscar um elemento do vetor B por busca binaria

            B1.ordena(&B);
            cout << "DIGITE O ELEMENTO B SER PROCURADO: ";
            cin>>aux1;

            aux = vetor::BUSCABINARIA(&B1,0,B1.getqnt_total(),aux1);

            if(B1.getposicao(aux) != aux1)
                cout << "Este Elemento Nao EXISTE neste CONJUNTO!!!\n\n";
            else
                cout << "O ELEMENTO "<<B1.getposicao(aux)<<" PROCURADO ESTA NA POSICAO: "<<aux<<" DO VETOR B ORDENADO!!"<<endl;

            break;


        default:
            cout << "Opção Invalida. Digite novamente Parça... ";
        }

        op = interface::exibe_menu();
    }
    cout << "~Ate Mais Parça!!\n  Bons estudos!!\n\n";
    return 0;
}
