#include <iostream>
using namespace std;

int main()
{
	//inicio do progama 
	
	int m5,m10,m25,m50,m1real,reais,cent,total;	//decalracao das variaveis necessarias 
	//float 
	

	//inicio - entrada de dados
	cout << "Digite a quantidade de moedas de 5 centavos e tecle 'Enter' : ";
	cin >>m5;
		
	cout << "\nDigite a quantidade de moedas de 10 centavos e tecle 'Enter' : ";
	cin >>m10;
	
	cout << "\nDigite a quantidade de moedas de 25 centavos e tecle 'Enter' : ";
	cin >>m25;
	
	cout << "\nDigite a quantidade de moedas de 50 centavos e tecle 'Enter' : ";
	cin >>m50;
	
	cout << "\nDigite a quantidade de moedas de 1real e tecle 'Enter' : ";
	cin >>m1real;
	//fim - entrada de calculos
	

	// calculos	
	total = (m5*0.05 + m10*0.10 + m25*0.25 + m50*0.5 + m1real)*100;
	
	reais = total/100;
	
	cent = total%100;
	
	
	cout << "\n\nVoce tem "<<reais<<" reais e "<<cent<<" centavos"; //exibicao dos resultados de saida
	
	
	
	return 0;
	system("pause");   
	
	// fim do progama
	
	}
	
