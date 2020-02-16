#include <iostream>

using namespace std;

int main()
{
	int valor[1000],novo[1000],i,num,cont = 1,a = 0;
	
	cout << "Digite a quantidade de numeros que seja menor que 1000: "; // quantidade de numeros da sequencia 
	cin >> num;
	
	cout << "Digite a sequencia em ordem crescente: "<<endl; 
	
	for(i = 0 ; i < num ; i++)// leitura dos numeros em ordem crescente 
	{
		cin >> valor[i];	
	}
	

	for( i = 0 ; i < (num-1)  ; i++)
	{
		
		if(valor[i] != valor[i+1]) // comparacao com o proximo vetor seguindo a seqeuncia em ordem crescente 
		{
			novo[a]=valor[i]; // obtencao da nova sequencia 
			a++; // contador
			
			if(cont >= 2 )
			{
				cout << "==> O valor "<<valor[i]<<" se repetiu "<<cont<<" vezes"<<endl;
				cont = 1;
			}
		}
		else
		{
			cont++; // contador de repeticoes de um numero n
		}
		
	}
	
	cout << "Nova sequencia sem repeticoes :"<<endl; // exibicao dos dados de saida
	
	for(i = 0 ; i < a ; i++)
	{
		cout <<novo[i]<<endl;	
	}
}
