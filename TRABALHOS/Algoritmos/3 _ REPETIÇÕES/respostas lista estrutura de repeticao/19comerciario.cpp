#include <iostream>

using namespace std;

int main()
{

	float salariobase,comissaox,comissaoy,salarioliquido,salariobruto; //declaracao das variaveis reais
	int i,cores,pb,inscricao;             // declaracao das variaveis inteiras
	
	cout.precision(2);
	
	cout << "Digite o Salario Minimo dos comerciario: R$";
	cin >>salariobase;
		
	for(i = 0; i < 20 ; i++)
	{
		//obtencao dos dados de entrada do funcionario/comerciario
		cout << "Numero de Inscricao: ";
		cin >>inscricao;
		cout << "Numero de tv's a cores vendidas: ";
		cin >>cores;
		cout << "Numero de tv's preto e branca vendidas: ";
		cin >>pb;
		
		//condicoes 
		if(cores >= 10)
		{
			comissaox = 100 * cores;
		}
		else
		{
			comissaox = 50 * cores;
		}
		
			if(pb >= 20)
			{
				comissaoy = 40 * pb;
			}
			else
			{
				comissaoy = 20 * pb;
			}
		//calculos salario liquido e bruto
		salariobruto = salariobase + comissaox + comissaoy;
		salarioliquido = salariobase - (0.08*salariobase) + comissaox + comissaoy;
		
		//exibicao dos dados de saida
		cout << "\n-----------------------------------------------"<<endl;
		cout << " ==>Inscricao: "<<inscricao<<endl;
		cout << " ==>Salario BRUTO: R$"<<fixed<<salariobruto<<endl;
		cout << " ==>Salario LIQUIDO: R$"<<fixed<<salarioliquido<<endl;
		cout << "-----------------------------------------------\n"<<endl;
	}
}
