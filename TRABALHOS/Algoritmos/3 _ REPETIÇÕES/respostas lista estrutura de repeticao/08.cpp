#include <iostream>

using namespace std;

int main()
{
	
	int i,sim,nao; // declaracao das variaveis inteiras  
	float x,y,fem_sim,masc_nao; // declaracao das variaveis reais 
	string sexo,resp; // declaracao das variaveis literias 

	//variaveis de inicializacao 
	fem_sim = 0;
	masc_nao = 0;
	sim = 0;
	nao = 0;


	for(i = 0 ; i < 2000 ; i = i + 1)	//para (variaveis de inicio ; condicao ; incremento)
	{	
	//obtencao dos dados de entrada 
	cout << "Sexo do entrevistado (m/f) :";
	cin >> sexo;
	cout << "Resposta do entrevistado (s/n) :";
	cin >> resp;
	cout << "-------------------------"<<endl;

	if(resp[0] == 'S' || resp[0] == 's') // se a resposta for sim 
		{
			sim = sim + 1; // somar 1 se a resposta dor sim e acumular esse resultado para contabiliza-lo dps 		
			if(sexo[0] == 'F' || sexo[0] == 'f')
			{
				fem_sim = fem_sim + 1;//pessoas do sexo fem que votaram sim
			}
		}	
		if(resp[0] == 'N' || resp[0] == 'n') // se a respostas nao for sim , a resposta sera nao
		{
			nao = nao + 1; //somar 1 as respostas q fora 'nao' para contabilizar 		
			if(sexo[0] == 'M' || sexo[0] == 'm')
			{
				masc_nao = masc_nao + 1;//pessoas do sexo masc q votaram nao 
			}
		}
	}	
	
	x = (fem_sim * 100)/2000; //porcentagem de pessoas do sexo fem  que responderam sim 
	y = (masc_nao * 100)/2000; //porcentagem de pessoas do sexo masc que responderam nao
	
	// exibicao dos resultados de saida 
	cout << "Pessoas que votaram sim: "<<sim<<endl;
	cout << "Pessoas que votaram nao: "<<nao<<endl;
	cout << "\n\nPorcentagem das pessoas do sexo feminino que votaram sim: "<<x<<endl;
	cout << "Porcentagem das pessoas do sexo masculino que votaram nao: "<<y<<endl;
		
	return 0;	
}
