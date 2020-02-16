#include <iostream>

using namespace std;

int main()
{
	int i;
	long double s,t;
	
	t = 2.0/50.0;
	s = t;
	
	for( i = 2 ; i<= 50 ; i++)
	{
		t = (float) t * (104 - 2 * i ) / (51 - i);
		s += t;
	}	
	cout << "Soma dos termos: "<<s<<endl;
}
