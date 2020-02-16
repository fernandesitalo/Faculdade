#include <iostream>

using namespace std;

int main()
{	
	char cod; //declaracao variavel caracter
	float consumo,consumidor_i,consumidor_r,consumidor_c,soma_consumo,valormaior,valormenor,maior,menor,preco,totpagar,media; //declaracao variavel real
	int c,number; // declaracao variavel inteira
	//variaveis de inicializacao
	consumidor_i = 0;
	consumidor_c = 0;
	consumidor_r = 0;
	maior = -1;
	menor = 999999999;
	c = 0;	
	//obtencao dos dados de entrada
	cout << "Digite o preço do Kwh: R$";
	cin >>preco;	
	cout << "\nDigite o numero do consumidor: ";
	cin >>number;	
	
	while(number != 0)
	{
		//obtencao dos dados de entrada
		cout << "Digite a quantidade de consumido no mes: ";
		cin >>consumo;		
		cout << "CODIGOS DOS TIPOS DE CONSUMIDOR ::: (r)residencial , (c)comercial , (i)industrial"<<endl;
		cout << "Digite o codigo do tipo de consumidor: ";
		cin >> cod;
		
		if(cod <= 90) // transformacao de maiusculas para minusculas
		{
			cod = cod + 32;
		}		
		while(cod != 'r' && cod != 'c' && cod != 'i') // validacao do codigo
		{
			cout << "DIGITE UM CODIGO VALIDO: ";
			cin >>cod;;
		}
		totpagar = consumo * preco;
		cout <<"\n-----------------------------"<<endl;
		cout << "Consumidor: "<<number<<endl;
		cout << "Total a Pagar: R$"<<totpagar<<endl;
		cout <<"-----------------------------"<<endl;
		if(consumo > maior) // designar qual maior consumo
		{
			maior = consumo;
			valormaior = totpagar;
		}		
			if(consumo < menor) // designar qual menor consumo
			{
				menor = consumo;
				valormenor = totpagar;
			}
			
		switch (cod) // estrutura seletiva
		{
			case 'r':
				consumidor_r = consumidor_r + consumo;
				break;
				
			case 'c':
				consumidor_c = consumidor_c + consumo;
				break;
				
			case 'i':
				consumidor_i = consumidor_i + consumo;				
		}
		soma_consumo = soma_consumo + consumo; // total consumido
		c++;//numero de consumidores 
		
		cout << "\nDigite o numero do consumidor: "; 
		cin >>number;
	}
	media =(float)soma_consumo/c;
	//exibicao dos resultados FINAIS
	cout << "|||||||||||||||||||||||||||||||||||||||||| RESULTADOS E DISCURSSOES ||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout << "\n\n==>Maior consumo verificado: "<<maior<<" Kwh"<<endl;
	cout << "==>Total a pagar pelo maior consumo: R$"<<valormaior<<endl;
	
	cout << "\n\n==>Menor consumo verificado: "<<menor<<" Kwh"<<endl;
	cout << "==>Total a pagar pelo menor consumo: R$"<<valormenor<<endl;
	
	cout << "\n\n==>Total Consumido pelos consumidores RESIDENCIAIS: "<<consumidor_r<<" Kwh"<<endl;
	cout << "==>Total Consumido pelos consumidores COMERCIAIS: "<<consumidor_c<<" Kwh"<<endl;
	cout << "==>Total Consumido pelos consumidores INDUSTRIAIS: "<<consumidor_i<<" Kwh"<<endl;
	
	cout << "\n\n==>Media Geral de Consumo: "<<media<<" Kwh"<<endl;
}
