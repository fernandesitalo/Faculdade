#include <iostream>
using namespace std;

int main ()
{ 
	float a,b,c;
	
	cout << "Digite 3 valores, e para cada um tecle 'Enter': "<<endl;
	cin>>a;
	cin>>b;
	cin>>c;	
	if(a < (b + c) && b < (a + c) && c < (a + b))//para formar um triangulo , o comprimento de um dos lados deve ser menor do que a soma dos outros 2	
	{ 
		cout << "Os valores formam um triangulo ! =)";
 	}
 		else
 		{
 			cout <<	"Os valores nao formam um triangulo ... =( \nTente novamente com outros valores !!!";
		}
}
