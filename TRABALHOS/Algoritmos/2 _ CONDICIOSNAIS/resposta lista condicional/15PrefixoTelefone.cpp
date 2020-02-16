#include <iostream>

using namespace std;

int main()
{
	
	string bairro,mensagem; //declaracao variavel literal 
	int fone,prefixo;     //declaracao variavel inteira 
	
	//obtencao dos dados de entrada
	cout << "Bairro do usuario: ";
	cin >> bairro;	
	cout << "Numero de telefone do usuario: ";
	cin >> fone;
	
	prefixo = fone/10000; // obtendo somente o prefixo do telefone
	
	if(bairro[0] <= 90) //transformando a letra maiuscula em minuscula , para melhor funcionamento do progama 
	{
		bairro[0] = bairro[0] + 32;
	}	
	
		if(prefixo == 3223 || prefixo == 3225 || prefixo == 3212 && bairro == "oeste")
		{	
			cout<< "\nBairro e numero corretos !"<<endl;	
		}
			else 
			{
				if(prefixo == 3223 || prefixo == 3224 || prefixo == 3212 && bairro == "centro")
				{
					cout<< "\nBairro e numeros corretos !"<<endl;				
				}
					else
					{
		
						if(prefixo == 3251 || prefixo == 3285 && bairro == "bueno")
						{							
							cout<< "\nBairro e numero corretos !"<<endl;																	
						}
			
						else
						{
							if(prefixo == 3233 || prefixo == 3291 && bairro == "campinas")
							{
								cout<< "\nBairro e numero corretos !"<<endl;													
							}
							else
							{
								if(prefixo == 3241 || prefixo == 3242 || prefixo == 3243 || prefixo == 3281 && bairro == "sul")
								{
									cout<< "\nBairro e numero corretos !"<<endl;							
								}
								else
								{
								cout << "\nBairro e numero INCORRETOS , certifique-se que o nome do bairro e o numero estao escritos corretamente"<<endl;
								}
							}
						}
					}
			}
}
