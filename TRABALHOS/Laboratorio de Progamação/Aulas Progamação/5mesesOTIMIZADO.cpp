// dia 19 de abril
#include <iostream>

using namespace std;

int main()
{
	int MES,contador; // declaracao das variaveis inteiras
	float mes;

	contador = 0;
	while(contador < 5) // numero de vezes que  o progama sera execultado
	{	
	contador++;
	
	cout << "Digite o numero referente ao mes desejado: ";
	cin >>mes;	
	
	MES = (int) mes/1;	/*PARA VALIDAR UM NUMERO INTEIRO , BASTA LER O NUMERO EM FLOAT EM UMA VARIAVEL X :: DPS EM UMA VARIAVEL INT Y DIVIDA
						 O NUMERO POR 1 E SE X == Y ENTAO O NUMERO E INTEIRO CASO CONTRARIO E REAIS E INVALIDO*/
													
		while(mes < 01 || mes > 12 || MES != mes) // validacao dos meses se for maior que 12 ou menor que 01 ou se for um NUMERO real!
		{
			cout << ":::DIGITE UM VALOR VALIDO: ";
			cin >> mes;
			
			MES = (int) mes/1;
		}
		
		switch (MES)  //estrutura de selecao switch case
		{			
			//casos em que os meses contem 31 dias 
			case 1:
			case 3:	
			case 5:
			case 7:
			case 8:	
			case 10:			
			case 12:
				cout << "==>O mes em questao tem 31 dias!\n\n";
				break;					
			//casos em que os meses contem 30 dias
			case 4:
			case 6:	
			case 9:			
			case 11:
				cout << "==>O mes em questao tem 30 dias!\n\n";	
			//unico caso em que o mes tem 28 ou 29 dias
			case 2:
				cout << "==>O mes em questao tem 28 ou 29 dias! (Ano Bissexto) \n\n";
				break;				
		}
	}
}
