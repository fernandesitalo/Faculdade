#include<iostream>

using namespace std;

int main ()
{
	string resp;
	float valor;
	
	cout << "Informe o valor basico do carro : R$";
	cin >> valor;
	
	
	cout << "\n\n------------------ ADCIONAIS ------------------"<<endl;
	
	cout << "     Ar condicionado       R$ 3.000,00"<<endl;
	cout << "     Direcao Hidraulica    R$ 2.500,00"<<endl;
	cout << "     Pintura Metalica      R$  800,00"<<endl;
	cout << "     Vidros Eletricos      R$ 1.000,00"<<endl;
	cout << "-----------------------------------------------"<<endl;
	
	
	cout << "\nAdicionar ao carro ar condionado ? (sim/nao)"<<endl;
	cin >> resp;
	
	if(resp[0] == 's' || resp[0] == 'S')
	{
		valor = valor + 3000;
	}
	
	cout << "Adicionar ao carro Direcao Hidraulica ? (sim/nao)"<<endl;
	cin >> resp;

		if(resp[0] == 's' || resp[0] == 'S')
		{
			valor = valor + 2500;
		}
	
	cout << "Adicionar Pintura Metalica ao carro ? (sim/nao)"<<endl;
	cin >> resp;
	
			if(resp[0] == 's' || resp[0] == 'S')
			{
				valor = valor + 800;
			}	
	
	cout << "Adcionar Vidros Eletricos ao carro ? (sim/nao)"<<endl;
	cin >> resp;
	
				if(resp[0] == 's' || resp[0] == 'S')
				{
					valor = valor + 1000;
				}
	cout << "\nO preco total do carro eh R$"<<valor<<endl;
}
