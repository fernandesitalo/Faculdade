#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	float x,y; // declaracao das variaveis necessarias 
	
	
	cout << "-----------------.-----------------"<<endl; // bike de pedreiro 
	cout << "        X        |     Y = cos(x)"<<endl;   // cabeçalho da tabela 
	cout << "-----------------:-----------------"<<endl;  // separa as linhas da tabela  
	cout.precision(2);
	for(x = -4 ; x <= 4 ; x+= 0.1)
	{
		y = cos(x*M_PI);
		
		if(x < 0) // condicoes para imprimir as linhas da tabela corretamente 
		{
		cout <<fixed<<"     "<<x<<"Pi";
		}
		else
		{
			cout <<fixed<<"      "<<x<<"Pi";
		}
	
		if(y < 0)
		{
			cout <<"     |      "<<y<<endl;
		}
		else
		{
			cout <<"     |       "<<y<<endl;
		}
	
		cout << "-----------------:-----------------"<<endl; // separa as linhas da tabela  
	}
}
