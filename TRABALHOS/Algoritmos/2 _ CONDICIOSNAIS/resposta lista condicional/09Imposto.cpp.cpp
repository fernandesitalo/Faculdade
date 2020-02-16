#include <iostream>
using namespace std;

int main()
{
	float ndep,salario,taxa,impt_parcial,impt_bruto,impt_liquido,impt_final,sm; // declaracao das variaveis necessarias
	
	//obtencao dos dados de entrada
	cout << "Digite o numero de dependentes e tecle 'Enter': ";
	cin >> ndep;	
	cout << "Digite o salario do funcionario e tecle 'Enter': R$";
	cin >> salario;	
	cout << "Digite a taxa de imposto normal que ja foi pago pelo funcionario e tecle 'Enter'";
	cin >> taxa;
	
	sm = 880; //salario minimo
	
	if(salario > 12*sm) // se o salario dor maior que 12 salarios minimos , o imposto bruto equivale a uma taxa de 20%
	{
		impt_parcial = 0.20*salario ;
		impt_bruto = impt_parcial*0.04 + impt_parcial;
	}
		else
		{		
			if(salario > 5*sm)// se o salario dor maior que 05 salarios minimos , o imposto bruto equivale a uma taxa de 8%
			{	
				impt_parcial = 0.08*salario ;
				impt_bruto = impt_parcial*0.04 + impt_parcial;
			}
				else // se o salario dor menor que 5 salarios minimos , imposto bruto igual a zero
				{
					impt_bruto = 0;
				}
			
		}

	impt_liquido = impt_bruto - ndep*300.00;
	
	impt_final = impt_liquido - (salario*taxa/100);
	
	if(impt_final < 0)
	{
		impt_final = impt_final*-1;
		
		cout<< "O imposto a ser recebido eh R$"<<impt_final; // exibicao dos resultados de saida
	}
		else
		{
			cout << "O imposto a ser pago eh R$"<<impt_final; // exibicao dos resultados de saida 
		}
}
