#include <iostream>

using namespace std;

int main ()
{
	int i,sinal;
	float s,t;

	sinal = 1;	
	s = 0;
	for(i = 1 ; i <= 10 ; i++)
	{
		t =(float) i/(i*i) * sinal;
		s += t;
		sinal *= -1;
	}
	cout << "Soma dos termos: "<<s<<endl;
}
