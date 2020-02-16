#include <iostream>

#include <math.h>

using namespace std;

int main()
{
	float area,a,b,x,y;	
	
	cout << "Seja a equacao da reta:  Y = (a)X + (b)"<<endl;		
	cout << "Informe o coeficiente (a): ";
	cin >>a;
	cout << "Informe o coeficiente (b): ";
	cin >>b;
	 
	while(a!= 0 || b!= 0)	
	{	
		if(a == 0 || b == 0)
		{
			cout << "====> Nao e formado triangulo! :("<<endl;
			cout << "----------------------------------------------------------------------------------------"<<endl;
		}
		else
		{
			x = -b/a; // atribuindo valores a equacao da reta conseguimos identificar o triangulo , nesle caso com x = 0 e y = 0
			y = b;			
			area =fabs( (y*x)/2.0);			
			
			cout << "Com a equacao da reta igual a "<<"Y = "<<a<<"X + ("<<b<<") formamos um triangulo de area igual a "<<area<<endl;			
			cout << "----------------------------------------------------------------------------------------"<<endl;
			
			cout << "Seja a equacao da reta:  Y = (a)X + (b)"<<endl;
		
			cout << "Informe o coeficiente (a): ";
			cin >>a;
			cout << "Informe o coeficiente (b): ";
			cin >>b;
		}
	}	 
}
