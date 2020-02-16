#include <iostream>

#include <math.h>

using namespace std;

int main()
{
	float media,n1,n2,n3; //dealracao variavel ponto flutuante
	int tipo;     //declaracao variavel inteira 
	
	cout << "Digite a a nota 1 e tecle 'enter': ";
	cin >> n1;
	cout << "Digite a a nota 2 e tecle 'enter': ";
	cin >> n2;
	cout << "Digite a a nota 3 e tecle 'enter': ";
	cin >> n3;
	
	//tabela com os tipos de media 
	cout <<"\n\n                  (1) MEDIA ARITMETICA "<<endl;
	cout <<"                  (2) MEDIA PONDERADA "<<endl;
	cout <<"                  (3) MEDIA HARMONICA"<<endl;
	cout <<"                  (4) MEDIA GEOMETRICA"<<endl;
	cout <<"                  (5) MEDIA QUADRATICA\n\n"<<endl;
	
	
	//obtencao do tipo de media a ser calculada 
	cout <<"Escolha a media a ser calculada e informe a numero correspondente: ";
	cin >>tipo;
	
	//inicio dos calculos , no caso , da media desejada 
	if(tipo == 1)
	{
		media = (n1+n2+n3)/3;
	} 
		else
		{
			if(tipo == 2)
			{
				media = ((n1*3)+(n2*3)+(n3*4))/10;
			}
				else
				{
					if(tipo == 3)
					{
						media =3/(1/n1+1/n2+1/n3);
					}
						else
						{
							if(tipo == 4)
							{
								media = pow((n1*n2*n3),1.0/3.0);
							}
								else
								{
									media = sqrt((n1*n1+n2*n2+n3*n3)/3);
								}
						}
				}
		}
	
	cout << "A media escolhida eh "<<media; // exibicao dos dados de saida
	
	return 0;
}
