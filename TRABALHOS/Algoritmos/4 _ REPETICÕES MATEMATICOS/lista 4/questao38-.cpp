#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int n; // declaracao das variaveis inteiras 
	double x,funcao,soma = 1,termo = 1; // variaveis reais 
	
	cout << "Sendo e^x\nDigite um numero x: ";//obtencao dos dados de entrada 
	cin >>x;
	cout.precision(4);
		
	funcao = exp(x); 

	for(n = 1 ; abs(funcao - soma) > 0.0001 ; n++) // abs(funcao - soma) sera a precisao q devera ser de no max 0.0001
	{		
		termo *= (float)x/n;		//calculo recursivo 
		soma += termo;   //somatorio 
	}
	
	cout <<fixed<< "O valor de x e: "<<x<<endl;
	cout <<fixed<< "Valor calculado atraves da serie: "<<soma<<endl;
	cout << "Valor calculado pela funcao EXP: "<<funcao<<endl;
	cout << "Numero de Termos utilizados na serie: "<<n<<endl;	
}
