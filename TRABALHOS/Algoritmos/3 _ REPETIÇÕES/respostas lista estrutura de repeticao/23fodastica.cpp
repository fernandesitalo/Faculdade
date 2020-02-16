#include <iostream>

using namespace std;

int main()

{
	int dia1,mes1,ano1,dia2,mes2,ano2,dd,totdia,tot; // variaveis necessarias 	
	
	totdia = 0;
	cout << "====>DATA INICIAL<===="<<endl;
	cout << "Dia: ";
	cin >>dia1;
	cout << "Mes: ";
	cin >>mes1;	
	cout << "Ano: ";
	cin >>ano1;	
	
	cout << "====>DATA FINAL<===="<<endl;
	cout << "Dia: ";
	cin >>dia2;	
	cout << "Mes: ";
	cin >>mes2;	
	cout << "Ano: ";
	cin >>ano2;	
		
	while((mes1 != mes2) || (ano1 != ano2)) /* enquanto o mes1 for diferente do mes2 e o ano 1 diferente do ano2 , o laco vai ser execultado
	isso fara com que o progama so pare qndo o mes e o ano forem iguais........ se o meses forem iguais e o ano diferente o progama continua rodando...
	entao no proximo laco o mes vai ser diferente , execultando o laco ate  igualar os meses de novo (qndo atinge o mes 12 , o mes volta ao mes 1)
	e assim ate o ano se igualar e o mes tbm !!!!!  */
	{									
		if(mes1 == 02) // se for o mes de fevereiro , que envolve a questao do bissexto
		{
			if((ano1 % 4 == 0) && (ano1 % 100 != 0 || ano1 % 400 == 0))
			{
				dd = 29; //bissexto
			}
			else
			{
				dd = 28; //nao bissexto
			}
		}
		else
		{
			if(mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11) // meses com 30 dias
			{
				dd = 30;
			}
			else // se nao e meses com 30 dias sera mes de 31 dias !!!!
			{
				dd = 31;
			}
		}				
		totdia = totdia + dd;		
		mes1++;			
		if(mes1 == 13) // quando atingir o mes de dezembro , basta voltar a janeiro e acrescentar mais um ano a variavel ano
		{
			mes1 = 1;
			ano1++;
		}
	}
	tot = totdia + dia2 - dia1;		
	cout << "\nDiferenca entre as duas datas: "<<tot<<" DIAS!"<<endl;	
}
