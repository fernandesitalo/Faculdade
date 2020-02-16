#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float t1,t2,t3,f1,f2,f3,d,maior,pontos;
	int inscr,inscr_wins;
	
	
	cout << "====== O tempo sera usado e fornecido em minutos decimais======"<<endl;
	cout << "Tempo Padrao fase 1: ";
	cin >>t1;
	cout << "Tempo Padrao fase 2: ";
	cin >>t2;
	cout << "Tempo Padrao fase 3: ";
	cin >>t3;
	
	pontos = 0;
	
	cout << "\n\nNumero de Incricao da Equipe: ";
	cin >>inscr;
	while(inscr != 9999)
	{		
		cout << "\nTempo despendido Fase 1: ";
		cin >>f1;
		
		d = fabs(t1 - f1);
		
		if(d < 3)
		{
			pontos= pontos + 100;
		}
		else
		{
			if(d >= 3 && d <= 5)
			{
				pontos = pontos + 80;
			}
			else
			{
				pontos = pontos + (80 -(d - 5)/5);
			}			
		}
		
		cout << "Tempo despendido Fase 2: ";
		cin >>f2;
		
		d = fabs(t2 - f2);
		
		if(d < 3)
		{
			pontos= pontos + 100;
		}
		else
		{
			if(d >= 3 && d <= 5)
			{
				pontos = pontos + 80;
			}
			else
			{
				pontos = pontos + (80 -(d - 5)/5);
			}			
		}
		
		cout << "Tempo despendido Fase 3: ";
		cin >>f3;
		d = fabs(t3 - f3);
		
		if(d < 3)
		{
			pontos= pontos + 100;
		}
		else
		{
			if(d >= 3 && d <= 5)
			{
				pontos = pontos + 80;
			}
			else
			{
				pontos = pontos + (80 -(d - 5)/5);
			}			
		}
		
		
		cout << "\n\n==>Numero de Inscricao da Equipe: "<<inscr<<endl;
		cout << "==>Total de Pontos Da Equipe: "<<pontos<<endl;
		
		if(pontos > maior)
		{
			maior = pontos;
			inscr_wins = inscr;
		}	
		cout <<"_________________________________________"<<endl;
		cout << "\nNumero de Incricao da Equipe: ";
		cin >>inscr;
	
		pontos = 0;
	}
	
	cout << "\n:::: EQUIPE VENCEDORA :::: "<<endl;
	cout << "Numero de Incricao: "<<inscr_wins<<endl;
	cout << "Total de Pontos: "<<maior<<endl;
}
