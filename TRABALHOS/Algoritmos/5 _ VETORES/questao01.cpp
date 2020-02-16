#include <iostream>

using namespace std;

int main()
{
	float temp[121],menor = 1000,maior = -4000,soma = 0,media; // declaracao das variaveis necessarias 
	int n,dias = 0;
	
	cout <<"USE A TEMPERATURA EM GRAUS CELSIUS!!"<<endl;
	for( n = 0 ; n < 121 ; n++)
	{
		cout << "Informe a temperatura no dia "<<n+1<<": "; // obtencao dos dados de entrada 
		cin >> temp[n];
		
		while(temp[n] > 40 || temp [n] < 15)//validacao 
		{
			cout << "Nao foram registradas temperaturas superiores a 40 C ou inferiores a 15 C neste periodo. \nFavor Digite a temperatura novamente: ";
			cin >> temp[n];
		}
		soma +=temp[n]; // soma das temperaturas para calculo da media de temperatura 
	}
	
	media = soma / 121.0; // calculo da media de temperatura 
	
	for (n = 0 ; n < 121 ; n++) // obtem a maior a menor e os dias nos quais a temperatura foi inferior a media 
	{
		if(temp[n] < menor)
		{
			menor = temp[n];
		}
		
		if(temp[n] > maior)
		{
			maior = temp [n];
		}
		
		if(temp[n] < media)
		{
			dias++;
		}
	}
	
	cout << "\n\n\n===> A menor temperatura registrada foi de : "<<menor<<" Celsius "<<endl;    //exibicao dos dados de saida 
	cout << "===> A maior temperatura registrada foi de : "<<maior<<" Celsius "<<endl; //exibicao dos dados de saida 
	cout << "===> A media de temperatura foi de : "<<media<<" Celsius "<<endl; //exibicao dos dados de saida 
	cout << "===> "<<dias<<" dias tiveram temperatura inferior que a media "<<endl; //exibicao dos dados de saida 
	
	
	
	
	
	
}

	
