#include <iostream>
using namespace std;

int main()
{
	float salario,reajuste; //Declaracao das variaveis necessarias
	
	cout << "Digite o salario do funcionario e tecle 'Enter': ";
	cin >> salario;
	
	if(salario <= 350.00) 
	{// se o salario for menor que 350 reais o reajuste sera de mais 50%
		reajuste = salario + 0.5*salario;
	}
		else // se o salario não e menor q 350 reias , então ele e maior que 350 reais, nesse caso recebera um aumento de 30 %
		{
			reajuste = salario + 0.3*salario;
		}
		
		cout << "\n\nO salario reajustado do funcionario eh R$"<<reajuste<<endl; // exibicao dos resultados de saida
				
		return 0;
}
