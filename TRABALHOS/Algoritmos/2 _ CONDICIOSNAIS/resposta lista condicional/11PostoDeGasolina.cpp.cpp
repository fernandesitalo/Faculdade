#include <iostream>
using namespace std;

int main()
{
	float x,preco;  // declaracao das variaveis numericas
	string name;     // declaracao de varievel literal
	
	cout << "Informe o nome do Posto: ";  //obtencao dos dados 
	getline (cin,name);
	cout << "Informe o consumo anual em litros deste posto: ";
	cin >> x;
	
	// 50.000 litros/mes * 12 meses = 600.000 litros/ano
	
	
	if(x <= 600000 )
	{
		preco = 2.13 + 2.13*0.20;
	}
		else 
		{
			preco = 2.13 + 2.13*0.12;
		}
		
	cout << "\n\nO preco de combustivel do posto "<<name<<" sera de R$"<<preco<<endl; // exibicao dos resultados de saida
		
	return (0);
}
