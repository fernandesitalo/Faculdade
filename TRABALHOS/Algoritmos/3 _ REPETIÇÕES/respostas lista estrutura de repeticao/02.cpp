#include <iostream>

using namespace std;

int main()
{
	string sexo,sexomaior,sexomenor;  // declaracao das variaveis tipo literal
	float altura,menor,maior,somaalt,mediamulheres; //declaracao das vaariaveis reais
	int homens,mulheres, i;  // declaracao das variaveis inteiras
	
	// dados inicio do progama 
	maior = -1;   
	menor = 10000;	
	homens = 0; //quantidade de homens
	mulheres = 0; //qntidade de mulheres
	somaalt = 0; //soma altura
	



	
	for(i = 0 ; i < 3 ; i = i + 1)
	{
		cout << "Sexo da pessoa: \a";  //obtencao dos dados de entrada
		cin >> sexo;		
		cout << "Altura da pessoa: \a";//obtencao dos dados de entrada
		cin >> altura;
		cout <<"--------------------------------------"<<endl;
		
		if(sexo[0] == 'M' || sexo[0] == 'm' ) // se for do sexo masculino 
		{
			homens++;
		}
		else  // se nao for do sexo masculino sera do sexo feminino 
		{
			somaalt = somaalt + altura;
			mulheres++;
		}
		
			if(altura < menor) 
			{
				menor = altura;// menor altura sera guardado na variavel menor 
				sexomenor = sexo; // sexo da pessoa mais baixa
			}
				if(altura > maior)
				{
					maior = altura; // a altura mais alta sera guardada na variavel maior 
					sexomaior = sexo; // o sexo da pessoa que tem a maior altura sera quardado nesta variavel
				}		
	}
	
	mediamulheres = somaalt/mulheres; // media da altura das mulheres 
	
	//mexibicao dso resultados de saida 
	cout << "\n\n=====Maior altura: "<<maior<<"\n=====Sexo da pessoa de maior altura: "<<sexomaior<<endl;
	cout << "\n\n=====Menor altura: "<<menor<<"\n=====Sexo da pessoa de menor altura: "<<sexomenor<<endl;
	cout << "\n=====Media das altura das mulheres: " <<mediamulheres<<endl;
	cout << "\n=====Numero de homens: "<<homens<<endl;	
}
