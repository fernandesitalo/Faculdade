

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long double t,s;
	int i;
		
	t = 4;
	s = t;	
	for(i = 1 ; i <= 15 ; i++ )
	{
		cout << t << endl;
		t = t * (pow(i+2,2)) / (pow(i+1,2) * i) * -1;
		s = s + t;		
	}		
	cout <<s<<endl;
}
