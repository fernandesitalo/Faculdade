#include <iostream>

#include <math.h>

using namespace std;

int main()
{
	int n,num; // declaracao das variaveis interias 
	float r,alfa,apotema,perimetro,area,lados;	 // declaracao das variaveis reais 
	 
	cout << "Informe o numero de poligonos : "; 
	cin >> num;// entrada de dados
	
	for(n = 1; n <= num; n++)
	{
		cout << "Informe o numero de lados do poligono: ";  
		cin >> lados;		// entrada de dados
		cout << "Informe o raio da circunferencia na qual esta inscrito o poligono : ";  
		cin >> r;// entrada de dados
		
		alfa = ((180 / lados)*M_PI)/180.0; // descobrir a metade do angulo de um triangulo do poligo e tranformar para rad	
		apotema = cos(alfa) * r;
		perimetro = sin(alfa) * r * 2 * lados ; // sen(alfa) * r descobre somente o comprimento de metade de um lado do poligono , por isso 2*n
		area = (perimetro * apotema)/2.0;
		
		cout << "A area do poligono equivale a: "<<area<<endl; // exibição dos dados de entrada 
		cout << "-------------------------------------------"<<endl; // bike de pedreiro zé tiao 
	}
}
