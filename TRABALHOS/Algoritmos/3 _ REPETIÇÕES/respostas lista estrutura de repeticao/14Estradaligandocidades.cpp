#include <iostream>

using namespace std;

int main()
{
	float a,b,vel,t; //declaracao das variaveis reais 
	
	//obtencao dos dados iniciais 
	cout << "==>Quilometro Inicial: ";
	cin >>a;
	cout << "==>Quilometro Final: ";
	cin >>b;
	
	while(a != b) //enquanto a diferente que b
	{
		vel = 20;
		
		while(vel <= 80) //enquanto velocidade menor igual a 80
		{
			t = (b - a)/vel;
			
			if(t > 2) // se tempo maior que 2 horas
			{
				cout << "----------------------------------------------"<<endl;
				cout << "   QUILOMETRO inicial: "<<a<<" km"<<endl;
				cout << "   QUILOMETRO final: "<<b<<" km"<<endl;
				cout << "   Velocidade: "<<vel<<" km/h"<<endl;
				cout << "   Tempo decorrido: "<<t<<" Horas"<<endl;
				cout << "----------------------------------------------"<<endl;	
			}			
			vel = vel + 10;	
		}
		//obtencao dos novos dados de entrada
		cout << "\n\n==>Quilometro Inicial: ";
		cin >>a;
		cout << "==>Quilometro Final: ";
		cin >>b;				
	}
	//NADA		
}
