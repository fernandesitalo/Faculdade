/* Obter 5 numeros inteiros equivalentes a 5 meses e calcular e exibir qntos dias tem cada um deses meses */
// 14 de abril de 2016
#include <iostream>

using namespace std;

int main()
{
	int MES,contador; // declaracao das variaveis inteiras
	string mensagem; //declaracao das variaveis literais 
	float mes;

	contador = 1;
	while(contador < 5) // numero de vezes que  o progama sera execultado
	{
	contador++;
	cout << "\nDigite o numero referente ao mes desejado: ";
	cin >>mes;	
	
		MES = (int) mes/1;
		
		while(mes < 01 || mes > 12 || MES != mes) // validacao dos meses 
		{
			cout << "::::::::::DIGITE UM MES VALIDO: ";
			cin >>mes;
		}
	
		switch (MES)  //estrutura de selecao switch case
		{			
			case 1:
				mensagem = "==>O mes de Janeiro tem 31 dias!\n";
				break;
			case 2:
				mensagem = "==>O mes de fevereiro tem 28 dias !(ou 29 em anos bissextos)\n";
				break;
			case 3:
				mensagem = "==>O mes de marcoo tem 31 dias!\n";
				break;
			case 4:
				mensagem = "==>O mes de abril tem 30 dias!\n";
				break;
			case 5:
				mensagem = "==>O mes de maio tem 31 dias!\n";
				break;
			case 6:
				mensagem = "==>O mes de junho tem 30 dias!\n";
				break;
			case 7:
				mensagem = "==>O mes de julho tem 31 dias!\n";
				break;
			case 8:
				mensagem = "==> mes de agosto tem 31 dias!\n";
				break;
			case 9:
				mensagem = "==>O mes de setembro tem 30 dias!\n";
				break;
			case 10:
				mensagem = "==>O mes de outubro tem 31 dias!\n";
				break;
			case 11:
				mensagem = "==>O mes de maio tem 30 dias!\n";
				break;
			case 12:
				mensagem = "==>O mes de maio tem 31 dias!\n";	
		}
	cout <<mensagem;  //exibicao dos dados de saida
	}
}
