#include <iostream>

using namespace std;

int main ()
{
	int i,sinal;
	float s,t;
	
	sinal = 1;
	s = 0;
	for(i = 1 ; i <= 50 ; i++)
	{
		t =(float) (1003.0-i*3.0)/i *sinal;
		s += t;
		sinal *= -1;
	}
	cout << "Soma dos termos: "<<s<<endl;
}
