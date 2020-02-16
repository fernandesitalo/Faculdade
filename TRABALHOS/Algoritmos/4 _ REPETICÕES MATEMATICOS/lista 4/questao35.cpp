#include <iostream>

using namespace std;

int main()
{
	int n;
	long double termo,soma;
	termo = 100;
	soma = termo;
	
	cout.precision(12);
	
	for(n = 1 ; n < 20 ; n++)
	{
		termo =(float) termo * (100 - n) / (n*(101 - n));
		soma += termo;
	}
	cout <<fixed<< "A soma dos 20 primeiros termos da sequencia e igual a "<<soma<<endl;
}
