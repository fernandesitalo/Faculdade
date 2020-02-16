#include <iostream>

#include <cmath>
using namespace std;

int main()
{
	int l,r = 1; //variaveis interias necessarias 
	float alfa,perimetro,semiPerimetro; //declaracao das variaveis necessarias 

	cout << "    NUMERO DE LADOS           SEMIPERIMETRO"<<endl; // titulo da tabelo
	for(l = 5; l <= 100 ; l += 5)
	{
		alfa = ((180/l)*M_PI)/180.0;
		
		perimetro = sin(alfa) * r * 2 * l; // calculo perimetro
		
		semiPerimetro = perimetro / 2 ; //calculo semiperimetro
		
		cout << "         "<<l<<"                      "<<semiPerimetro<<endl; // exibicao das linhas da tabela 
	}
}
