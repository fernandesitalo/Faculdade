#include <iostream>

using namespace std;

int main()
{
	int i,dia,mes,ano,s,a,diasemana,ano1,mes1;	//declaracao das variaveis inteiras
	
	for(i = 0 ; i < 50 ; i++) // para(variavel de inicializacao ; condicao ; incremento)
	{    
		cout << "Digite o dia: "; //obtencao dos dados de entrada
		cin >> dia;
		
		cout << "Digite o mes: ";//obtencao dos dados de entrada
		cin >> mes;
		
		cout << "Digite o ano: ";//obtencao dos dados de entrada
		cin >> ano;
		
		mes1 = mes;  //guardar variaveis
		ano1 = ano;  //guardar variaveis
		
		if(mes <= 2) // condicao do exercicio
		{
			mes = mes + 10;
			ano = ano - 1;
		}		
		else // condicao do exercicio
		{
			mes = mes - 2;
		}
		
		s = ano / 100;
		a = ano % 100;
		diasemana =(int) (((2.6*mes-0.2)/1) + dia + a+(a/4) + (s/4) - 2 * s) % 7;
		
		cout << "----------------------------------------------------"<<endl; //bike de pedreiro		
		switch (diasemana)
		{		//exibicao do dia da semana 
			case 0:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a um DOMINGO!"<<endl;
				break;
			case 1:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a uma SEGUNDA-FEIRA!"<<endl;
				break;
			case 2:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a uma TERCA-FEIRA!"<<endl;
				break;
			case 3:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a uma QUARTA-FEIRA!"<<endl;
				break;
			case 4:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a uma QUINTA-FEIRA!"<<endl;
				break;
			case 5:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a uma SEXTA-FEIRA!"<<endl;
				break;
			case 6:
				cout << "==> A data "<<dia<<"/"<<mes1<<"/"<<ano1<<" corresponde a um SABADO!"<<endl;
		}
		cout << "----------------------------------------------------\n\n"<<endl; //penteadeira de puta
	} 	
}
