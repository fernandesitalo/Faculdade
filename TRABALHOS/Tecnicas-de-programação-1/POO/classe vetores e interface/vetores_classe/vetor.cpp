#include "vetor.h"

vetor::vetor(int n)
{
    this->n = n;
    vet = new int[n];
    qtd = 0;
}

vetor::~vetor()
{
    delete vet;
}

int vetor::getqnt_total() // retorna o n
{
    return n;
}

int vetor::getqtd()
{
   return qtd;
}

int vetor::inserir(int x)
{
    int i;
    if(qtd < n)
    {
        for( i = qtd - 1 ; vet[i] != x && i >= 0; i--);
        if(i == -1)
        {
            vet[qtd] = x;
            qtd++;
            return 1; // retorna 1 se deu tudo certo
        }

         else
            return -1; // retorna -1 se o elemento inserido ja existe
    }
    return 2; // maior que 1 se deu ruim , isto e , nao tem mais espaço
}


int vetor::getposicao(int x)
{
    if(x < qtd && x < n)
    {
        return vet[x];
    }

    return 0/1; // error
}

void vetor::uniao(vetor* x , vetor* y) // TESTADO--OK
{
    int i,k;
    qtd = 0;

    for(i = 0 ; i < x->qtd ; i++)
        vet[i] = x->vet[i];

    qtd = i;

    for( i = 0 ; i < y->qtd ; i++)
    {
        for( k = 0 ; k < x->qtd && y->vet[i] != x->vet[k]; k++);

        if(k >= x->qtd)
        {
            vet[qtd] = y->vet[i];
            qtd++;
        }
    }
}


void vetor::intercessao(vetor *x,vetor* y)
{
    qtd = 0;
    int i,k;

    for(i = 0 ; i < x->qtd ; i++)
    {
        for(k = 0; k < y->qtd-1 && x->vet[i] != y->vet[k] ; k++);

        if(x->vet[i] == y->vet[k])
        {
            vet[qtd] = x->vet[i];
            qtd++;
        }
    }
}

void vetor::diferenca(vetor *x,vetor *y)
{
    qtd = 0;
    int k,i;

    for(i = 0 ; i < x->qtd ; i++)
    {
        for(k = 0 ; k < y->qtd && x->vet[i] != y->vet[k] ; k++);

        if(k == y->qtd)
        {
            vet[qtd] = x->vet[i];
            qtd++;
        }
    }
}

void vetor::subcrescente(vetor *x)      // MAIOR SUB CADEIA CRESCENTE DE X
{
    qtd = 0;
    int i,k;
    int inicio = 0; // inicio da sub cadeia
    int fim = 0; // fim da sub cadeia

    for(i = 0 ; i < x->qtd ; i++) // sera verificada a existencia de m subcadeias, uma a uma
    {

        for(k = i; k < x->qtd-1 && x->vet[k] < x->vet[k+1] ; k++);
        // este for e executado enquanto A[K] for menor que A[K+1] , isto e , enquanto formar uma sequencia crescente
        // i marca o inicio da sub cadeia ordenada
        // no final desde laco de repeticao , K marca o final da subcadeia ordenada


        if(k - i > fim - inicio)
        {
            inicio = i; // guarda o inicio da maior subcadeia
            fim = k; // guarda o final da sub cadeia
        }
        i = k; // ate k foi verificado a existencia desta sub cadeia
    }

        for(k = 0,i = inicio ; i <= fim ; i++) // coloca no novo objeto , a maior sub cadeia crescente
        {
            vet[qtd] = x->vet[i];
            qtd++;
        }
}

void vetor::subdecrescente(vetor *x)      // MAIOR SUB CADEIA CRESCENTE DE X
{
    qtd = 0;
    int i,k;
    int inicio = 0; // inicio da sub cadeia
    int fim = 0; // fim da sub cadeia

    for(i = 0 ; i < x->qtd ; i++) // sera verificada a existencia de m subcadeias, uma a uma
    {

        for(k = i; k < x->qtd-1 && x->vet[k] > x->vet[k+1] ; k++);
        // este for e executado enquanto formar uma sequencia decrescente
        // i marca o inicio da sub cadeia ordenada
        // no final desde laco de repeticao , K marca o final da subcadeia ordenada


        if(k - i > fim - inicio)
        {
            inicio = i; // guarda o inicio da maior subcadeia
            fim = k; // guarda o final da sub cadeia
        }
        i = k; // ate k foi verificado a existencia desta sub cadeia
    }

        for(k = 0,i = inicio ; i <= fim ; i++) // coloca no novo objeto , a maior sub cadeia crescente
        {
            vet[qtd] = x->vet[i];
            qtd++;
        }
}

bool vetor::SAOdisjuntos(vetor *x,vetor *y)
{  
    int i,k;

    for(i = 0 ; i < x->qtd ; i++)
    {
        for(k = 0 ; k < y->qtd && x->vet[i] != y->vet[k]; k++);

        if(y->qtd > k)
            return false;
    }
    return true;
}

bool vetor::SAOidenticos(vetor *x,vetor *y)
{
    int i,k;

    if(x->qtd != y->qtd)
    {
        return false;
    }
    for(i = 0 ; i < x->qtd ; i++) // fixa um elemento de A
    {
        for(k = 0 ; k < y->qtd && x->vet[i] != y->vet[k]; k++);
        // compara o elemento fixado com todos de B

        if(k == y->qtd)
        { // se entrar nesse 'if' e pq um elemento de A nao esta em B e portanto nao os conjuntos nao sao identicos
            return false;
        }
    }
    return true;
}

bool vetor::subconjunto(vetor *x,vetor *y)
{    
    int i,k;// retorna se e ou nao um subconjunto de a em b ou vice versa

    if(x->qtd > y->qtd)
        return false;

        for(i = 0 ; i < x->qtd ; i++)
        {
            for(k = 0 ; k < y->qtd-1 && x->vet[i] != y->vet[k] ; k++);

            if(x->vet[i] != y->vet[k])
                return false; // encontra um elemento de A que nao esta em B
        }

    return true; // todos elementos de A estao em B foram verificadas todas possibilidades
}

int vetor::produtoEscalar(vetor* x,vetor* y)
{
    if(x->qtd != y->qtd)
        return 0/1; // assim nao da pra calcular

    int i,pe = 0;//produto escalar

    for(i = 0 ; i < x->qtd ; i++)
        pe += x->vet[i] * y->vet[i];

    return pe;
}



int vetor::amplitude(vetor *x)
{
    int maior,menor,i;

    maior = x->vet[0];
    menor = maior;

    for(i = 1 ; i < x->qtd ; i++)
    {
        if(x->vet[i] < menor)
            menor = x->vet[i];

        else
            if(x->vet[i] > maior)
                maior = x->vet[i];

    }
    return maior - menor;
}

bool vetor::ehvazio(vetor *x)
{
    if(!x->qtd)
        return true;

    return false;
}



void vetor::ordena(vetor *x)
{
  int i,k,aux;

    for(i = 0 ; i < x->qtd ; i++)
        vet[i] = x->vet[i];

    qtd = x->qtd;

    for(i = 1 ; i < qtd ; i++)
    {  // o laco comeca com i = 1 pois nao tem como ordenar um so termo

        aux = vet[i]; // termo q sera guardado para coloca-lo na posicao correta

        for(k=i-1 ; k >= 0 && aux < vet[k] ; k--)
        { // ando uma posição para frente com cada termo menor que o termo auxiliar
            vet[i] = vet[k];
        }

        vet[k+1] = aux; // quando e encontrada a posicao correta inserimos o termo auxiliar
                        // antes de sair do laco 'for' e decrementada uma unidade do k , pois isso K+1
    }
}




void vetor::intercala(vetor* x,vetor* y)
{
    int i;
    int cont1 = 0;
    int cont2 = 0;

    // INTERCALANDO E ORDENADO  ATE UM VETOR ACABAR
    for(i = 0 ; cont1 < x->qtd && cont2 < y->qtd ; i++)
    {
        if(x->vet[cont1] < y->vet[cont2])
        {
            vet[i] = x->vet[cont1];
            cont1++;
        }
        else
        {
            vet[i] = y->vet[cont2];
            cont2++;
        }
    }

    // TERMINA DE COLOCAR OS ELEMNTOS DO OUTRO VETOR Q NAO ACABOU
    for(   ;cont1 < x->qtd ; cont1++,i++)
    {
        vet[i] = x->vet[cont1];
    }

    // TERMINA DE COLOCAR OS ELEMENTOS DO OUTRO VETOR Q NAO ACABOU
    for(   ; cont2 < y->qtd ; cont2++,i++)
    {
        vet[i] = y->vet[cont2];
    }

    qtd = i;
}
