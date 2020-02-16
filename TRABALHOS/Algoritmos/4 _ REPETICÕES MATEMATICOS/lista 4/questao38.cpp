#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int n;
	float x,funcao,soma = 1,termo = 1,dif;
	
	cout << "Sendo e^x\nDigite um numero x: ";
	cin >>x;
	
	funcao = exp(x);
	
	dif = 1;
	
	for(n = 1 ; dif > 0.00001 ; n++)
	{		
		termo *= (float)x/n;		
		soma += termo;
		
		dif = abs(funcao - termo);
	}
	
	cout << "O valor de x e: "<<x<<endl;
	cout << "Valor calculado atraves da serie: "<<soma<<endl;
	cout << "Valor calculado pela funcao EXP: "<<funcao<<endl;
	cout << "Numero de Termos utilizados na serie: "<<n<<endl;	
}
