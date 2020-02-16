#include <iostream>

using namespace std;

int main()
{
	int num[10]; //VETOR
	int n; // variavel inteira 
	
	cout << "Digite uma sequencia de 10 numeros para ser invertida: "<<endl;
	
	for(n = 0 ; n <= 9 ; n++)
	{
		cin >> num[n]; // leitura de cada variavel do vetor  
	} 
		cout <<"Sequencia invertida: "<<endl;
	for(n = 9 ; n >=  0 ; n--)
	{
		cout << num[n] << endl; // exibicao dos dados de saida
	}
}
