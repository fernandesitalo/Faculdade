#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	float x,y; // declaracao das variaveis necessarias 
	
	
	cout << "-----------------.-----------------"<<endl; // bike de pedreiro 
	cout << "        X        |     Y = tg(x)"<<endl;   // cabeçalho da tabela 
	cout << "-----------------:-----------------"<<endl;  // separa as linhas da tabela  
	cout.precision(2);
	for(x = -4 ; x <= 4 ; x+= 0.1)
	{
		y = tan(x*M_PI);
		
		if(x < 0) // condicoes para imprimir as linhas da tabela corretamente 
		{
		cout <<fixed<<"     "<<x<<"Pi";
		}
		else
		{
			cout <<fixed<<"      "<<x<<"Pi";// espaco a mais para suprir o espaço do sinal negativo
		}
	
		if( y > 100)  // qndo x = k*pi + pi/2 (k pertence aos reais) a tangente tende ao infinito e ultrapassa o valor 100 , desta forma concertando o erro do progama
		{
			cout <<"     |      °°"<<endl;
		}
		else
		{
		
			if(y < 0)
			{
				cout <<"     |      "<<y<<endl;
			}
			else
			{
				cout <<"     |       "<<y<<endl;
			}
		}

		cout << "-----------------:-----------------"<<endl; // separa as linhas da tabela  
	}
}
