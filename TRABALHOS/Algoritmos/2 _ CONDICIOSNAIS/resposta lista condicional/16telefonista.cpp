#include <iostream>

using namespace std;

int main()
{
	int tempo,x,y; // declaracao das variaveis 
	string name;   // declarcao de variavel literal string 
	float custo;	// declaracao de variavel ponto flutuante
	
	cout << "Nome do Usuario: "; //obtencao dos dados de entrada
	getline (cin,name);
	
	cout << "Tempo da ligacao em minutos: "; // obtencao dos dados de entrada
	cin >> tempo;
	
	
	// taxa fixa da ligacao de 2 reais 
	
	tempo = tempo - 3 ;  // os 3 primeiros minutos custam 1 real
	
	x = tempo / 5;  // intervalos de 5 minitos que custaram 2.15
	
	y = tempo % 5; // minutos que sobram dos intervalos de 5 minutos , cada minuto custara 0.85 cents
	
	if(tempo <= 0) // se o tempo e menor ou igual a zero , o usuario não excedeu o limite dos 3 primeiros minutos
	{
		custo = 2+1;
	}
		else
		{
			if(tempo > 0) // se o tempo for maior q 0 entao o usuario permaneceu conversando por mais de 3 minutos 
			{
				custo = 2+1+(2.15 * x) + (0.85 * y);
			}
			
		}
		
	cout << "\n\nUsuario: "<<name<< "\nValor da conta R$: "<<custo; // exibicao dos dados de saida 
	
	return 0;
}

