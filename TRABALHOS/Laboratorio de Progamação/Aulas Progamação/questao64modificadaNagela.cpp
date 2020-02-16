/* elabora um algoritmo para obter uma lista de numeros e para cada 
   numero obtido, determinar e exibir se é perfeito ou nao.
   
   obs1.: numero perfeito e aquele cuja soma de seus divisores, 
   exeto ele proprio, e igual ao numero. ex: 6 e perfeito porque 1+2+3=6
   
   obs2.: a lista de numeros a serem obtidos devera ser finalizada por 0
   
   obs3.: validat ps dados de entrada. permitir somente a digiacao de 
   numeros inteiros positivos. */
   
#include <iostream>

using namespace std;

int main()
{
	int auxint,soma = 0,divisor = 1;
	float num;
	
	cout << "Informe um numero inteiro positivo: ";
	cin >>num;	
	
	while(num != 0)
	{
		auxint = num; // convercao implicita --- expliplicita seria aux = (int) num 
		while(auxint != num || num < 0)
		{
			cout << "Dado INVALIDO. Digite novamente: ";
			cin >>num;
			
			auxint = num; // convercao implicita 			 
		}
		
	while(divisor <= num)
	{
		if((int)num%divisor == 0)
		{
			soma += divisor;
		}	
		divisor += 1;
	}
	
			
		if(soma == num)
		{
			cout << "Numero e Perfeito"<<endl;
		}	
		else
		{
			cout << "Numero NAO e Perfeito"<<endl;
		}
		
		
	cout << "Informe um numero inteiro positivo: ";
	cin >>num;				
	}	
		
		
}



   
   
