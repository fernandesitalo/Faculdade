#include <iostream>

using namespace std;

int main ()
{
	int i,sinal;
	long double s,t;
	
	sinal = 1;
	s = 0;
	for(i = 1 ; i <= 30 ; i++)
	{
	
		t =(float) (485.0 - i * 5.0)/ (i + 9.0)*sinal;
		s += t;
		sinal *= -1;
	}
	cout << "Soma dos termos: "<<s<<endl;
}
