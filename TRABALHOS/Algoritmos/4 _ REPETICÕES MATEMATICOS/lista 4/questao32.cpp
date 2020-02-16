#include <iostream>

#include <math.h>

using namespace std;

int main()
{
	int n,sinal;
	long double s,t;
	
	sinal = 1;
	s=0;	
	for(n = 1 ; n < 52 ; n++)
	{
		t  = (float) 1 / pow(n*2 - 1,3) * sinal;
		s += t;	
		sinal *= -1;		
	}
	s = pow(s * 32.0 , 1.0/3.0);	
	cout << "Pi equivale a "<<s<<" , de acordo com  a sequencia da questao !"<<endl;
}
