#include <iostream>

using namespace std;

int main()
{
	int a,b,c,aux;  // declaracao das variaveis necessarias 
	
	//obtencao dos resultados de saida 
	cout << "digite 3 numeros e para cada um tecle 'Enter': "<<endl;
	cin >> a;
	cin >> b;
	cin >> c;
	
	
	if(a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	
		if( a > c)
		{
			aux = a;
			a = c;
			c = aux;
		}
		
			if(b > c)
			{
				aux = b;
				b = c;
				c = aux;
			}
	cout <<a<<","<<b<<","<<c;
}
