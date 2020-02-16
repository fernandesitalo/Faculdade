#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int i,a,n; // declaracao das variaveis inteiras 
	float soma=0,num[100];  // declaracao das variaveis reais 
	
	cout << "DIGITE OS 100 VALORES NUMEROS DE ACORDO COM A QUESTAO "<<endl
	for(i = 0 ; i < 100 ; i++)
	{
		cin >> num[i]; // leitura dos 
	}

	cout <<"==========================================="<<endl;

	for(i = 0, a = 99 ; i < 50 ; i++,a--)
	{
		soma += pow(num[i]-num[a],3);		
	}
	cout << "Somatorio da questao: "<<soma<<endl; //exibicao dos dados de saida 
}
