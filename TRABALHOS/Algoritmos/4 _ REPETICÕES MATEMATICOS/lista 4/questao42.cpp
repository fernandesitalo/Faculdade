#include <iostream>

#include <math.h>

using namespace std;

int main()
{
	float x1,x2,y1,y2,distancia; // declaracao das variaveis reais necessarias 
	
	
	cout << "Sejam os pontos (x1,y1) e (x2,y2), informados para calcular a distancia entre eles \n\n"; //informacao ao usuario

	cout << "Digite o valor de x1: ";
	cin >> x1;	
	cout << "Digite o valor de y1: ";
	cin >> y1;
	
	cout << "Digite o valor de x2: ";
	cin >>x2;
	cout << "Digite o valor de y2: ";
	cin >>y2;
	
	
	while(x1 != 0 || x2 != 0 || y1 != 0 || y2 != 0) // enquanto (condicao)
	{
		distancia = sqrt(pow(x2-x1,2)+ pow(y2-y1,2));
		
		cout << "Distancia entre os dois pontos e de "<<distancia<<" unidades"<<endl; //exibição dos dados de saida 
		
		cout << "Digite o valor de x1: ";
		cin >> x1;	
		cout << "Digite o valor de y1: ";
		cin >> y1;
	
		cout << "Digite o valor de x2: ";
		cin >>x2;
		cout << "Digite o valor de y2: ";
		cin >>y2;
	}
}
