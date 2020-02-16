#include <iostream>

using namespace std;

int main()

{
	int conta;// declaracao variavel inteira
	string name,mensagem; // declaracao variavel iteral string
	float saldoSemestral,saldoMedioMensal; // declaracao variavel ponto flutuante
	
	cout << "Nome do cliente: "; //obtencao do nome d cliente
	getline (cin,name);
	
	cout << "Numero da Conta: "; // obtencao do numero da conta
	cin >>conta;
	
	cout << "Saldo Bancario total do Semestre: R$"; // obtenção do saldo semestral do cliente 
	cin >> saldoSemestral;
	
	saldoMedioMensal=saldoSemestral/6.0;
	
	if(saldoMedioMensal <= 1000)
	{
		mensagem = "\nTarifa BASICA de R$25.00";
	}
		else
		{
			if(saldoMedioMensal <= 2000)
			{
				mensagem = "\nTarifa PRATA de R$20.00";
			}
				else
				{
					if(saldoMedioMensal <= 3500)
					{
						mensagem = "\nTarifa OURO de R$13.00";
					}
						else
						{
							mensagem = "\nTarida PREMIO R$0.00 (isenta)";
						}
				}
		}
		
	cout << mensagem;
} 	
