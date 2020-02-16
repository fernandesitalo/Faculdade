#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	long double termo = 1,soma = 1,dif,funcao,x;
	
	cout << "Digite um valor para descobrir seu cosseno: ";
	cin >> x;

	cout.precision(2);
	
	x = (x*M_PI)/180.0; // tranformando o angulo em radianos
	
	for(n = 1; n < 20; n++)
	{
		termo =(float) termo *(( x*x )/((n*2-1)*2*n) )* -1;
		soma += termo;	
	}
	
	funcao = cos(x); // x ja esta em radianos
	dif = abs(funcao - soma);	
	cout <<fixed<< "Serie: "<<soma<<"\nFuncao: "<<funcao<<"\nDiferenca entre os dois calculos: "<<dif<<endl;
	// TRANSFORMAR PARA RADIAN0S OS GRAUS ;;;;;;;; PROF ALEXANDRE
		
}
