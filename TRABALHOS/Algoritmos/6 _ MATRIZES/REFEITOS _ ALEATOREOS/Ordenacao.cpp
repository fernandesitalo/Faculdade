#include<iostream>

using namespace std;

int main()
{
	int vet[10],i,n,aux;
	
	cout << "Digite uma sequencia aleatoria de 05 numeros: "<<endl;
	
	for(n = 0 ; n < 5 ; n++) // leitura dos 05 numeros a serem lidos 
	{
		cin >> vet[n];
	}
	
	for( n = 0 ; n < 5 ; n++)    // inicio da ordenacao dos valores 
	{
		for(i = 0; i < 5; i++) 
		{
/* Este for verifica a sequencia em si ,a cada par, qual o menor , dessa forma , forma uma nova sequencia fazendo a mesma coisa*/			

			if(vet[i] > vet[i+1]) 
			{
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;	
			}
			else
			{
				if(n>1)
				i = 5;	
			}
		}
	}
	cout << "A nova sequencia Ordenada: "<<endl; // exibicao da nova sequencia 
		for(n = 0 ; n < 5 ; n++)
		{
			cout << vet[n]<<endl;
		}
}
