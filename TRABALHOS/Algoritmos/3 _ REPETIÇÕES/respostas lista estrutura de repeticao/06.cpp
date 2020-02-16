#include <iostream>

using namespace std;

int main()
{
	int t,hrs,min,seg;	// declaracao variaveis inteiras
	float g;  // declaracao variaveis reais
	
		
	t = 0; // variaveis de inicializacao
	cout << "Digite a massa em gramas do material radioativo: ";
	cin >>g;	
	if ( g < 0.5)
	{
		cout << "A massa deste material radioativo ja e menor que 0.5g!";
	}
	else
	{	
		while ( g > 0.5 ) // enquanto(condicao)
		{		
			t = t + 50;  // a cada vez que as gramas sao menores que 0.5 se passam 50 segundos 
			g = g * 0.5; // gramas recebe metade de gramas
		}	
	
	hrs = (t / 60) / 60; // separando horas
	min = (t / 60) % 60; // separando minutos
	seg = t % 60; // separando segundo
	
	//exibicao dos resultados de saida
	cout << "A massa final: "<<g<<"g"<<endl;
	cout << "Tempo: "<<hrs<<" horas e "<<min<<" minutos e "<<seg<<" segundos";
	}	
}
