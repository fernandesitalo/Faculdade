#include <iostream>

using namespace std;

int main()
{
	float a,b,c; //declaracao das variaveis 
	
	
	//Obtencao dos dados de entrada 
	cout << "Digite um Numero: ";
	cin >> a;
	cout << "Digite um Numero: ";
	cin >> b;
	cout << "Digite um Numero: ";
	cin >> c;
	  
	  
	//inicio das condicoes para saber qual e o maior
	
	
	if(a > b) // se a maior que b
	{
		if(a > c)  // ja tenho ctz que 'b' e menor que 'a', entao se 'a' maior que 'c' , 'a' e o maior!!
		{
			cout << a << " E O MAIOR";
		}
			else // se 'a' nao e maior que 'c', entao 'c' e o maior !!!!!'
			{
				cout << c << " E O MAIOR";
			}
	}
	
	else
	{
		if(b > c) // ja sei que 'a' não e o maior ... entao se 'b' e maior que 'c' entao 'b' e o maior !!
		{
			cout << b << " E O MAIOR";
		}
			else   // 'b' não e maior que 'c' , entao 'c' e o maior !!!!
			{
				cout << c << " E O MAIOR";
			}
	}
	return 0;
}
