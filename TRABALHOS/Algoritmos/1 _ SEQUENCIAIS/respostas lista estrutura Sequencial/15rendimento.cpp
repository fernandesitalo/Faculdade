#include <iostream>

#include <cmath>

using namespace std;

int main ()

{
	// inicio do progama 
	
	float i,p,n,valoracumulado;  //declaracao das variaveis necessarias 
	/* i= taxa mensal
	   p= constante de aplicacao mensal
	   n= numero de meses  */
	   
	cout << " ==========CALCULO DO RENDIMENTO DE UMA APLICACAO PROGAMADA===============\n\n";
	
	//obtencao dos dados de entrada
	cout << "\nFavor, digite o valor de aplicacao mensal: ";
    cin >> p;
    cout << "\nFavor, digite o valor da taxa mensal ( % ): ";
	cin >> i; 	
	cout << "\nFavor,digite o numero de meses desta aplicacao: ";
	cin >> n;
			
		valoracumulado = ((pow(1+i,n)-1)/i)*p;	//calculos
	
	cout << "\n\n\nO rendimento do valor eh: R$"<<valoracumulado<<endl; // exibicao dos resultados de saida 
	
	return 0; 	//fim do progama 
}
	
	 

	
	
	
	
	
	
	
	

