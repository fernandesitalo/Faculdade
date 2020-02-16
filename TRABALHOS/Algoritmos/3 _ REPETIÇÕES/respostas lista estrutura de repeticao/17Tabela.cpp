#include <iostream>
  
using namespace std;

int main()
{
	float preco,precomax,lucro,lucromax;  //declaracao variaveis reais
	int ingressos,ingressomax;       //declaracao vaiaveis inteiras
	
	lucromax = -1;
	cout << "  PRECO          |       INGRESSOS VENDIDOS       |          LUCRO "<<endl; //penteadeira de puta
	cout << "  ---------------|--------------------------------|-------------------"<<endl; //bike de pedreiro
	
	ingressos = 120; //variavel de inicializacao 
	preco = 5;    //variavel de inicializacao
	while(preco >= 1)  //enquanto(condicao)
	{	
		cout.precision (2);  // precisao das casas decimais 
		lucro = (preco * ingressos) - 200;	
		
		cout <<fixed<< "  R$"<<preco<<"         |             "<<ingressos<<"                |         R$"<<lucro<<endl;  // linhas da tabela
		
		ingressos = ingressos + 26;
		preco = preco - 0.5;
		
		if (lucro > lucromax)
		{
			lucromax = lucro;
			precomax = preco;
			ingressomax = ingressos;
		}
	}
	cout << "\n\n======================== L U C R O   M A X ==========================="<<endl;
	cout << "  PRECO          |       INGRESSOS VENDIDOS       |          LUCRO "<<endl; //penteadeira de puta
	cout << "  ---------------|--------------------------------|-------------------"<<endl; //bike de pedreiro
	cout <<fixed<< "  R$"<<precomax<<"         |             "<<ingressomax<<"                |         R$"<<lucromax<<endl;  // linhas da tabela
}
