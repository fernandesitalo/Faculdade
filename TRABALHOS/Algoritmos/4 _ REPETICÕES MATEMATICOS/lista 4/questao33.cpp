#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n,x;
	long double t,s;
	cout.precision(20);
	
	cout << "Digite um numero ai , meu caro usuario <3 : ";
	cin >> x;
	
	t = pow (x,25);
	s = t;
	
	for( n = 2 ; n <= 25 ; n++)
	{
		t =(float) t/x /n * -1;
		s = s + t;	
	}
	cout <<fixed<< "Soma : "<<s<<endl;
	
}
