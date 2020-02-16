	/* elaborar um progama para receber 3 numeros inteiros e colocar
	os tres numeros recebidos em ordem crescente */
	
	
	
	
#include <iostream>

using namespace std;

int main()
{
	int a,b,c;  // declaracao das variaveis necessarias 
	
	//obtencao dos resultados de saida 
	cout << "digite 3 numeros e para cada um tecle 'Enter': "<<endl;
	cin >> a;
	cin >> b;
	cin >> c;
	
	
	
	if(a >= b && a >= c ) // A e o maior
	{
		if(b > c)
		{
			cout <<c<<","<<b<<","<<a;	
		}
		else
		{
			cout <<b<<","<<c<<","<<a;
		}
	}
	else
	{
		if(b >= c && b >= a) // B e o maior 
		{
			if(a > c)
			{
				cout <<c<<","<<a<<","<<b;
			}
			
			else
			{
				cout <<a<<","<<c<<","<<b;
			}
		}
		
		else  // C e o maior 
		{
			if(a > b)
			{
				cout <<b<<","<<a<<","<<c;
			}
			else
			{
				cout <<a<<","<<b<<","<<c;
			}
		}
	}		
}
	
