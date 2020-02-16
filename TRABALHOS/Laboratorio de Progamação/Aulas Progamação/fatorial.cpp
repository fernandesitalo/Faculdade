
#include <iostream>

using namespace std;

int main()
{
	int n,i,fat;

	fat = 1;
	cout << "Digite o numero fatorial: ";
	cin >> n;	
	for (i = 2 ; i <= n ; i++) // variavel de inicializacao começa no 2 por o numero 1 nao e nescessario 
	{
		fat = fat * i;  // multiplicacao ate i igual a n  ex.: 3! = 3*2*1 => 6 ......... 3! = 3*2 => 6 
	}
	cout << "Fatorial deste numero eh: "<<fat<<endl; //exibicao dos dados de saida
}
