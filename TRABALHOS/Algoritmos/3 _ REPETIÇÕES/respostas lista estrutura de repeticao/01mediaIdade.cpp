#include <iostream>

using namespace std;

int main()
{	
	int soma,id,media,qntd;  // declaracao das variaveis necessarias 	
	soma = 0; //variavel de inicializacao
	qntd = 0; //variavel de inicializacao	
	
	cout << "Digite a Idade: "; // obtencao do 1 dado de entrada 
	cin >> id;
	cout << "------------------"<<endl;
	
	while(id != 0)
	{
		qntd++;  // contador 
		soma = soma + id;  // soma das idades
		
		cout << "Digite a Idade: "; // obtencao dos seguintes dados de entrada 
		cin >> id;
		cout << "------------------"<<endl;
	}
	
	media = soma / qntd; // media aritmetica
	
	cout << "\n\nMedia de Idade desde Grupo de Individuos : " << media<<endl;  // exibicao dos resultados de saida 
}
