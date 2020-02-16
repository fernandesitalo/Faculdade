#include <iostream>

using namespace std;

int main ()
{
	int i;
	float s,t;
	
	s = 0;
	for(i = 1 ; i <= 37 ; i++)
	{
		t =(float) (39.0 - i)*(38.0 - i) / i;
		s += t;
	}
	cout << "Soma dos termos: "<<s<<endl;
}
