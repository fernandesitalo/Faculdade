#include "interface.h"
#include "vetor.h"
#include <iostream>

#include <stdlib.h>

interface::interface()
{
// hello word
}

void interface::leia_objeto(vetor *x)
{
    int valor,i;

    for (i = 0 ; i < x->getqnt_total() ; i++)
    {
        std::cout << i+1<<"º elemento: ";
        std::cin >>valor;

        switch(x->inserir(valor))
        {
        case -1:

            std::cout<< "ELEMENTO JA INSERIDO, DIGITE NOVAMENTE...\n";
            std::cout << i+1<<"º elemento: ";
            std::cin >>valor;
            while(x->inserir(valor) == -1)
            {
                system("clear");
                std::cout<< ">>ELEMENTO JA INSERIDO, DIGITE NOVAMENTE...\n\n";

                std::cout << i+1<<"º elemento: ";
                std::cin >>valor;
            }
            break;


        case 2:
            i = x->getqnt_total();

            system("clear");
            std::cout << "ERRO 404 - MEMORIA CHEIA PARÇA";
            break;

        }
    }
}


void interface::imprima_objeto(vetor *x)
{
    std::cout << "{ ";
    for (int i = 0 ; i < x->getqtd() ; i++)
    {
        std::cout <<"("<< x->getposicao(i)<<")";
    }
    std::cout<<" }\n\n";
}

char interface::exibe_menu()
{
    char op;

    std::cout<<"\n\t======================>>>Menu de Opcoes<<<===========================\n";
    std::cout<<"\t(a)- Descubra se A e/ou B sao conjuntos vazios\n";
    std::cout<<"\t(b)- Uniao: A e B\n";
    std::cout<<"\t(c)- Intercessao: A e B\n";
    std::cout<<"\t(d)- Diferenca: A - B\n";
    std::cout<<"\t(e)- Diferenca: B - A\n";
    std::cout<<"\t(f)- Descubra se A e subconjunto de B\n";
    std::cout<<"\t(g)- Descubra se B e subconjunto de A\n";
    std::cout<<"\t(h)- Descubra se A e B sao conjuntos identicos\n";
    std::cout<<"\t(i)- Descubra se A e B sao conjuntos disjuntos\n";
    std::cout<<"\t(j)- Amplitude dos Conjuntos A e B\n";
    std::cout<<"\t(k)- Produto escalar entre A e B \n";
    std::cout<<"\t(l)- Conjunto G - Maior subcadeia ordenada de forma Crescente de A\n";
    std::cout<<"\t(m)- Conjunto H - Maior subcadeia ordenada de Forma Decrescente de B\n";
    std::cout<<"\t(n)- Conjunto I, Vetores A  e B Intercalados e Ordenados\n";
    std::cout<<"\t(P)- NOVO!!!! PESQUISAR UM ELEMENTO NO VETOR 'A' >>BUSCA BINARIA<<\n";
    std::cout<<"\t(Q)- NOVO!!!! PESQUISAR UM ELEMENTO NO VETOR 'B' >>BUSCA BINARIA<<\n";
    std::cout<<"\t(o)- Exibir os 2 conjuntos novamente\n";
    std::cout<<"\t(s)- Sair do Progama\n";
    std::cout<<"\t______________________________________________________________________\n";

    std::cout<<"~ Digite a opcao desejada: ";
    std::cin>>op;

    system("clear");
    return op;
}

