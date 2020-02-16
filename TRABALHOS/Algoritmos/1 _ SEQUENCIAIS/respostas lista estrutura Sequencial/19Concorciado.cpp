#include <iostream>

using namespace std;

int main()
{
	int x,pg;
	float valor,atualpago,saldodevedor;   //decaracao das variaveis
	
	cout << "=================PROGAMA CONSORCIO=================\n\n";
	
	cout << "Digite o numero total de prestacoes: ";
	cin >> x;
	cout << "Digite a quantidade de prestacoes pagas: ";
	cin >> pg;
	cout << "Digite o valor atual da prestacao: ";
	cin >> valor;
	
	//calculos
	atualpago = valor*pg;	  
	saldodevedor = (x-pg)*valor;
	
	//exibicao dos resultados de saida 
	cout << "\n\ntotal ja pago: R$"<<atualpago<<endl;	
	cout << "Saldo devedor: R$"<<saldodevedor<<endl;
	
	return 0; //fim progama

	
}
