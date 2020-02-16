#include <iostream>

#include <cmath>

using namespace std;

int main ()
{
	float raio,area,volume,comprimento;  //declaracao das variaveis	

	cout << "Favor,digite o valor do raio da esfera e tecle 'Enter': ";
	cin >> raio;
	
		//calculos
		comprimento = 2*M_PI*raio;	
		area = M_PI*pow(raio,2);
			
		volume =0.75*M_PI*pow(raio,3);
	
	//exibicao dos resultados de saida
	cout << "\n\nComprimento: "<<comprimento;
	cout << "\nArea: "<<area;
	cout << "\nVolume: "<<volume;
	
	return 0;
	
}
