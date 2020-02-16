#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int num,n,div,decimal;
	
	cout << "Digite um numero da base 3: "; //obtencao dos dados de entrada 
	cin >> num;
	
	while(num != 0)
	{
		div = num;    // variaveis de inicialização 
		decimal = 0;
		
		for(n = 0 ; div != 0 ; n++)
		{	
			decimal += (div%10) * pow(3,n);	  // reto da divisao por 10 vezes 3 elevado a n --- formula dejesada 
			div = div / 10;				// resultado da divisao por 10
		}
		
		cout << "O numero "<<num<<" de base 3 equivale a "<<decimal<<" na base 10"<<endl;  // exibicao dos dados de saida 
		
		cout << "_________________________________________________________\n_________________________________________________________"<<endl; // bike de pedreiro 
		
		cout << "Digite um numero da base 3: ";
		cin >> num;
	}
}
