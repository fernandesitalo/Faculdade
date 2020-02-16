#include <iostream>

using namespace std;

int main()
{
	char sexo,xp; //declaracao variaveis caracter
	int inscr,id,novasxp,menor,inscr_menor,masc,fem,qntd_velhos,soma_id,media_velhos;//declaracao das variaveis inteiras
	//variaveis de inicializacao
	novasxp = 0;
	menor = 1000000;
	masc = 0;
	fem = 0;
	qntd_velhos = 0;
	soma_id = 0;	
	//inicio
	cout << "Numero de Inscricao do Candidato: ";
	cin >>inscr;	
	while(inscr != 0) //enquanto inscricao diferente de 0
	{
		//obtencao dos dados de entrada
		cout << "Idade : ";
		cin >>id;		
		cout << "Sexo do candidato ? ::: (m)masculino ou (f)feminino: ";
		cin >>sexo;		
		cout << "Experiencia no Servico ? ::: (s)sim ou (n)nao: ";
		cin >>xp;
	
		while(xp != 's' && xp != 'S' && xp != 'N' && xp != 'n') //validacao da resposta
		{
			cout << "DIGITE UMA RESPOSTA VALIDA, (S) SIM OU (N)NAO ?? : ";
			cin >>xp;
		}
		
			if(sexo <= 90) //tranformacao da resposta
			{
				sexo = sexo + 32;
			}
		
		switch (sexo) // selecao dos dados para pesquisa
		{					
			case 'f':
				fem++;
				if(xp == 's' || xp == 'S')
				{
					if(id < 35)
					{
						novasxp++;
					}
						if( id < menor)
						{
							menor = id;
							inscr_menor = inscr;
						}
					}					
					break;
					
			case 'm':
				masc++;					
				if(id > 45)
				{
					soma_id= soma_id + id;
					qntd_velhos++;
				}	
		}
		cin.ignore();
		cout << "__________________________________________________"<<endl; // inicio de uma nova etapa com um novo candidato
		cout << "Numero de Inscricao do Candidato: ";
		cin >>inscr;		
	}
	media_velhos = (float)soma_id/qntd_velhos;
	
	//Exibicao dos dados de saida	
	cout << "\n\n::::::: Candidata jovem com experiencia ::::::"<<endl;
	cout << "==>Idade: "<<menor<<endl;
	cout << "==>Inscricao: "<<inscr_menor<<endl;
	
	cout << "\n==>Total de mulheres de idade inferior a 35 anos com experiencia na area: "<<novasxp<<endl;

	cout << "\n==>Total de canditados do sexo Feminino: "<<fem<<endl;
	cout << "==>Total de candidatos do sexo Masculino: "<<masc<<endl;
	
	cout << "\n==>Media de idade dos homens com mais de 45 anos: "<<media_velhos<<endl;

	return (0);
}
