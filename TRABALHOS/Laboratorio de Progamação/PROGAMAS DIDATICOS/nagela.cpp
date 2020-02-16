#include <iostream>

using namespace std;

int main()
{
	long long int fat;
	int f,aux_int;
	float numero;
	
	
	cout << "Digite um numero para calcular seu fatorial: ";	
	cin>>numero;
	
	aux_int = numero;  // conversao implicita de variavel

	while(aux_int != numero)
		{
			cout << "NUMERO INVALIDO. POR FAVOR DIGITE NOVAMENTE: ";
			cin >>numero;
			aux_int = numero;  // conversao implicita de variavel		
		}	


	while (numero >= 0)
	{
		f = 1;
		fat = 1;		
			while(numero >= f)
			{		
				fat *= f; 
				f++;
			}			
	cout <<fat<<endl; 
	cout << "Digite um numero para calcular seu fatorial: ";	
	cin>>numero;
	aux_int = numero;
				while(aux_int != numero)
				{
					cout << "NUMERO INVALIDO. POR FAVOR DIGITE NOVAMENTE: ";
					cin >>numero;
					aux_int = numero;  // conversao implicita de variavel		
				}	
	}
	
}
