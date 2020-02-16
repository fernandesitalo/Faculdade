#include <iostream>

using namespace std;

int main()
{
	string nome; // declaracao variavel literal
	float idade; // declaracao variaveis numerica]
	
	
	// obtencao dos dados de entrada 
	cout << "Favor, digite o nome do nadador(a) e tecle 'Enter': ";
	getline (cin,nome);
	
	cout << "Favor, Digite a idade do nadador e tecle 'Enter': ";
	cin >> idade;
	
	
	if(idade >= 18)    // se o nadador tiver idade maior ou igual 17 anos
	{
		cout << " O nadador "<<nome<<" esta na categoria SENIOR !"<<endl;
	}
		else
		{
			if(idade >= 14) // se o nadadot tiver idade maior ou igual a 14
			{
				cout<< " O nadador "<<nome<<" esta na categoria JUVENIL B !"<<endl;
			}
				else
				{
					if(idade >= 11) // se o nadador tiver idade maior ou igual a 11
					{
					cout<< " O nadador "<<nome<<" esta na categoria JUVENIL A !"<<endl;
					}
						else
						{
							if(idade >=8) // se o nadador tiver idade maior ou igual a 8
							{
								cout << " O nadador "<<nome<<" esta na categoria INFANTIL B !"<<endl;
							}
								else
								{
									if(idade >=5) // se o nadador tiver idade maior ou igual a 5
									{
										cout << " O nadador "<<nome<<" esta na categoria INFANTIAL A !"<<endl;
									}
										else
										{
											cout << "O nadador nao possui idade minima para estar em uma categoria ... =("<<endl;
										}											
								}
						}
				}		
		}
}
