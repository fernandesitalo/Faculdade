#include <iostream>

using namespace std;

int main()
{
	float a,b,c,d,soma;  // declaracao das variaveis
	
	cout << "Digite 4 numeros distindos, e para cada um, tecle 'Enter' em seguida: \n";  //obtencao dos dados
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;	
	
	// condicoes para saber os 3 menores numeros
	if(a >= b && a >= c && a >=d )
	{
		soma = b+c+d;		
	}	
		else 
		{	
			if(b >= a && b >= c && b >= d)
			{
				soma = a+c+d;			
			}		
				
				else
				{			
					 if(c >= a && c >= b && c >= d)
					{
						soma = a+b+d;			
					}			
						else 
						{				
							soma = a+b+c;					
						}
			
				}
		}
	cout << "Soma dos 3 menores: "<<soma<<endl;
	
	return 0;
}

