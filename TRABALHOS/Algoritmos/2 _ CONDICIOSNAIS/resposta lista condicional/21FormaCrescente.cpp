#include <iostream>

using namespace std;

int main()
{
	int a,b,c,aux; // declaracao variaveis inteiras 
	
	
	// obtencao dos dados de entrada
	cout << "Digite um numero: ";
	cin >> a ;
	
	cout << "Digite um numero: ";
	cin >> b;
	
	cout << "Digite um numero: ";
	cin >> c;
	
	
	if(a > b || a > c) // A nao e o menor
	{ 
		if(b < c) // C não e o menor , então b e o menor 
		{ 
			aux = a;   // colocar b em a
			a = b;
			b = aux;
			
		}

			else // entao c e o menor 
			{		
				aux = a;  // colocar c em a
				a = c;
				c = aux;			
			}
	
	}		
				if(b > c) // a e o menor , e b maoir que c, entao colocar b em c
				{
					aux = b; // colocar b em c
					b = c;
					c = aux;
				}
		
	cout <<"\nOrdem Crescente: "<<a<<","<<b<<","<<c; // imprimir resultados de saida, no caso os valores em ordem crescente, da maneira mais simples !!!!
}
