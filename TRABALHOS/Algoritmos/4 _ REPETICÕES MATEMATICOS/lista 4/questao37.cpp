#include <iostream>

using namespace std;

int main()
{
	int fat,i,den,sinal;
	float soma,termo;
	
	
	den = 1;
	soma = 1;
	fat = 1;
	sinal = -1;
	for(i = 2; i <=50 ; i++)
	{
		fat = fat * i ;
		den = den*2 + 1 ;		
		termo = (float)fat/den * sinal;
		soma += termo;	
		sinal *= -1;
		cout<<termo<<endl;	
	}
	
	cout << "Soma dos termos : "<<soma<<endl;
}
