/* um comerciante concede um aumento de 20% nos computadores que ele vende a cada mes.Elaborar um progama para
   calcular e exibir em quantos meses o preço de um determinado computador ultrapassara R$3.200,00 
   ==> dia 2 de maio*/
   
#include <iostream>

using namespace std;

int main()
{
	int meses;
	float preco;
	
	meses = 0;
		
	cout << "Preco inicial: ";
	cin >> preco;
	
	do{ // faça isso (comandos)...    primeiro o laco e execultado e depois e verificada a condicao
		meses++;
		preco *= 1.2;
	}
	
	while(preco <= 3200); // enquanto isso(condicao)
			
	cout << "Utrapassara R$3.200,00 em "<<meses<<" meses";
}
