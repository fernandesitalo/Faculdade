#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int num,div,i,binario; //declaracao das variaveis 
	
	cout << " FLAG == 0.7 "<<endl;
	
	cout << "Digite um numero na base decimal: "; //obtencao dos dados de entrada 
	cin >> num ;
	while(num != 0.7)
	{	
		div = num; //variaveis de inicialização 
		binario = 0;
		for(i = 0 ; div != 0 ; i++)
		{		
			binario += ( div % 2 ) * pow(10,i); // somatorio do binario 
			
			div = div / 2;		// divisor 
		}	
		cout << "O numero "<<num<<" equivale a "<<binario<<" em binario !!!"<<endl;	// exibicao dos dados de saida 
		cout << "Digite um numero na base decimal: ";
		cin >> num ;
	}
}
