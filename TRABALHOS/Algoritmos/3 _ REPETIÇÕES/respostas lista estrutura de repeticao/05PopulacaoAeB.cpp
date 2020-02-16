#include <iostream>

using namespace std;

int main()
{
	int anos; // declaracao das variaveis inteiras 
	float a,b; // declaracao das variaveis reais 
	
	a = 90000000;   // populacao inicial de  A
	b = 200000000;	//populacao inicial de B
	anos = 0;   // zerando contador 	

	while(b > a) // ou b > a
	{		
		a = a + (0.03*a);		
		b = b + (0.015*b);		
		anos++;  //contador 
	}	
	
	cout << "\nA populacao 'A' vai ultrapassar ou igualar a polulacao 'B' em "<<anos<<" anos !"<<endl; //exibicao dos dados de saida 
}
