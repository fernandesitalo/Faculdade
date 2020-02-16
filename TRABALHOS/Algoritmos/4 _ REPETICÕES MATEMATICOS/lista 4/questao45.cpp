#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	int x,hx,fx,gx,y;
	
	cout << " x    |   y  "<<endl;
	cout << "------|------"<<endl;
	
	
	
	for(x = 1; x <= 10; x++ )
	{
		hx = x*x - 16;
		
		if(hx >= 0) // inicio das condicoes do progama 
		{
			fx = hx;
		}
		else
		{
			fx = 1;
		}
			if( fx == 0)
			{
				gx = x*x + 16;
			}
			else
			{
				if(fx > 0)
				{
					gx = 0;
				}
			}
	
	cout.precision(3);
	y =fx + gx; // funcao 
	cout <<fixed<<"   "<<x<<"  |     "<<y<<endl; // exibicao da tabela 	
	}
	
}
