#include<iostream>
using namespace std;
int main()
{
	int vetor[5], maior, posicao, vezes, i;
	for( i=0; i<5; i++ )
	{
		cout<<"Digite o "<< i+1 <<"º digito: ";
		cin>>vetor[i];
	}
	maior = vetor[0];
	vezes = 1;
	posicao = i;
	for( i=1; i<5 ; i++ )
	{
		if( vetor[i] > maior )
		{
			maior = vetor[i];
			posicao = i;
			vezes = 1;
		}
		else if( vetor[i] == maior )
		{
			vezes++;
		}
	}
	cout<<"O maior numero é: "<< maior <<endl;
	cout<<"Aparece na posicao:" << posicao+1 <<endl;
	cout<<"Aparece: "<< vezes <<" vezes"<<endl;
}
		
