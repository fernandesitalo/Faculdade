/*Em uma matriz são armazenadas em cada linha as populações dos 
 * dez municípios mais populosos de cada um dos Estados Brasileiros
 * Elaborar um programa para: a)Obter os dados da matriz
 * b)Calcular qual a menor população do 26º Estado
 * c)Calcular a soma das populações dos municípios mais populosos de cada Estado
 * d)Calcular qual o município menos populoso e a qual estado pertence
 * e) Exibir os dados calculados
 * Obs:A 1ª coluna contém as populações dos municípios mais populosos de cada Estado */
#include <iostream>
using namespace std;
int main ()
{

//Declaração das Variáveis Necessárias

long int pop[26][10], menor, soma;

int i, j, municipio, estado;

//Obtenção dos Dados de Entrada
for(i=0; i<26; i++)
	{
	for(j=0; j<10; j++)
		{
			cout<<"Informe a população do "<<i+1<<"º Estado e do "<<j+1<<"º município: ";
			cin>>pop[i][j];
		}
	}
//Cálculo da menor população do 26º Estado
menor=pop[26][0];
for(i=1;i<10;i++)
		if(pop[26][i]>menor)
			menor=pop[26][i];
//Exibição da menor população do 26º Estado
cout<<"A população do 26º Estado é: "<<menor<<endl;
//Cálculo da soma das populações dos municípios mais populosos de cada Estado
soma=0;

for(i=0;i<26;i++)
	soma+=pop[i][0];
//Exibição da soma das populações dos municípios mais populosos de cada Estado
cout<<"A soma das populações dos municípios mais populosos de cada Estado é: "<<soma<<endl;
//Cálculo do município menos populoso e a qual estado pertence
menor=soma;

for(i=0; i<26; i++)
	for(j=1; j<10; j++)
		if(pop[i][j]<menor)
			{
				menor=pop[i][j];
				estado=i;
				municipio=j;
			}
//Exibição do município menos populoso e a qual estado pertence
	cout<<"O municipio menos populoso é: "<<municipio<<" e pertence ao Estado"<<estado<<endl;
}
