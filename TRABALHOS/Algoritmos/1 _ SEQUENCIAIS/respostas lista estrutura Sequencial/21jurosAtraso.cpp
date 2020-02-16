#include<iostream>

using namespace std;

int main()
{
	float x,tempo,taxa,valoratualizado; //declaracao das variaveis
	
	cout << "===============JURO DE PARCELAS EM ATRASO==============="<<endl;

	//obtencao dos resultados de entrada
	cout << "favor,digite o valor da prestacao e tecle 'Enter': ";
	cin >> x;
	
	cout << "Favor digite o tempo de atraso(em dias) e tecle 'Enter': ";
	cin >> tempo;
	
	cout << "Favor,digite a taxa de juros ( % ) e tecle 'Enter': ";
	cin >> taxa;
	
		//calculos
		valoratualizado = 	x+(x*(taxa/100)*tempo);
		
	//exibicao dos resultados de saida
	cout << "\n\nO valor atualizado da prestacao eh: R$"<<valoratualizado<<endl;
	
	return 0;	
}
