#include <iostream>

#include <math.h>

using namespace std;

int main()
{
	float x,y;
	cout << "Digite o valor de x: ";
	cin >>x;
	cout << "Digite o valor de y: ";
	cin >>y;
	
	while(x!= 0 || y != 0)
	{
		if(x > 0) // 1 quadrante
		{		
			if((y < (3*x)) && (y > (x/3)))   //x do ponto e atribuido a cada equacao da reta . . . entao comparamos o y para saebr se x esta dentro ou fora da regiao
			{
				cout << "Interior"<<endl;
			}
			else
			{
				cout << "Exterior"<<endl;
			}
		}
		if(x < 0) // 3 quadrante 
		{
			if((y > (3*x)) && (y > (x/3)))
			{
				cout << "Interior"<<endl;
			}
			else
			{
				cout << "Exterior"<<endl;
			}
		}
		cout << "Digite o valor de x: ";
		cin >>x;
		cout << "Digite o valor de y: ";
		cin >>y;
	}
}
