#include <iostream>

#include <cmath>

using namespace std;

int main()
{
	float r,vol;
 
	cout << "    RAIO (CM)       VOLUME(CM^3)\n"<<endl; // titulo da tabela 
	
	for(r = 0.0; r <= 20.0;r += 0.5)
	{				
		vol = (4.0/3.0) * pow(r,3.0)* M_PI; // calculo do volume 
		cout.precision(2); // precisao do numero a ser exibido 
		if(r < 10) // exibicao estilo penteadeira de puta e bike de pedreiro 
		{		
			cout <<fixed<<"     0"<<r<<"          "<<vol<<endl;
		}
		else
		{
			cout <<fixed<<"     "<<r<<"          "<<vol<<endl;
		}
	}
}
