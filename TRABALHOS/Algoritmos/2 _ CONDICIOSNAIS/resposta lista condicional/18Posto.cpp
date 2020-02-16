#include <iostream>

using namespace std;

int main()
{
	char tipo;  //Declaracao variavel char - caractere
	float litros,preco;   //decalracao ponto flutuante
	
	//obtencao dos dados de entrada
	cout << "Digite a inicial do combustivel desejado [a/d/g] : ";
	cin >> tipo;	
	cout << "Quantidade em litros: ";
	cin >> litros;
	
	
	if(tipo <= 90) //caso o usuario de uma de espertinho e digite a letra em maiusculo 
	{
		tipo = tipo + 32;
	}
	
	
	if(tipo == 'a')
	{
		preco = 1.805 * litros;		
	}
		else
		{
			if(tipo == 'd')
			{
				preco = 1.053 * litros;
			}
				else
				{	
					if (tipo == 'g')		
					{
						preco = 2.565 * litros;
					}	
						else
						{
							cout << "Voce digitou uma inicial invalida!";
						}				
				}
		}	
	cout << "Valor a ser pago pelo combustivel: R$"<<preco;  //exibicao dos resultados de saida 
	
	return 0;
}
