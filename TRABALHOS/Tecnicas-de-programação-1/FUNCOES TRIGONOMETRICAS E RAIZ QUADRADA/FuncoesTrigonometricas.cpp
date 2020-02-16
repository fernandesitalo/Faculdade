#include <stdio.h>
#include <stdlib.h>
#include <biblioteca_do_italo.h> // BIBLIOTECA BY: ITALO FERNANDES GONCALVES

void menu(); // Imprime o menu na tela

int main() // poderosa int main
{
	double graus,radianos,aux;
	double temp; // variavel temporaria usada na tangente
	char opcao;	
	int i;
	
	printf("~Bem Vindo Usuario!\n\n");	
	
	printf("Informe o Angulo(em graus): ");
	scanf("%lf",&graus);
	aux = graus;
	
	while(aux >= 360) // reducao para a primeira volta trigonometrica
	{
		aux -= 360;
	}	
	radianos = (aux * M_PI)/180.0; // conversao para radianos
	
	do
	{
		system("pause");
		system("cls");
		
/*menu*/menu();// esta funcao imprime o menu na tela	
		
		printf("\n **** ANGULO: %lf ****\n",graus);
		printf("\n>>Opcao: ");
		scanf("%s",&opcao); // leitura da opcao desejada
			
		switch(opcao)
		{
			case 's': 
				printf("\n ~O SENO de %lf eh %lf\n\n",graus,myseno(radianos));			
				break;				
					
					
			case 'c':
				printf("\n ~O COSSENO de %lf eh %lf\n\n",graus,mycos(radianos));
				break;
				
										
			case 't':				
				if(!mytan(radianos,&temp)) // temp e a variavel ponteiro (por isso o uso do &)que conterá a tangente, caso ela exista!
				{							// a funcao usa ponteiro para modificar o valor no progama , pois e necessario huehuheuhe
					printf("\n ~A tangente de %lf NAO existe!\n\n",graus);
				}
				else
				{
					printf("\n ~A TANGENTE de %lf eh %lf\n\n",graus,temp);
				}								
				break;
				
										
			case 'r':
				printf("Digite um novo Angulo: ");
				scanf("%lf",&graus);
				aux = graus;					
				while(aux >= 360)
				{
					aux -= 360;
				}	
				radianos = (aux * M_PI)/180.0;							
				break;
				
									
			case 'e':
				printf("\n~Ate mais!\n~Bons Estudos!\n\n");
				break;
				
															
			default:
					printf("\n~Opcao Invalida, Digite Novamente...\n\n");			
		}
		
	}while(opcao != 'e'); //condicao de parada ja establecida
	
	return 0;	
}

void menu()
{	 // exibe menu
	printf(" -= MENU  DE  OPCOES =-\n");
	printf("\t s -SENO\n");
	printf("\t c -COSSENO\n");
	printf("\t t -TANGENTE\n");
	printf("\t r -Retry ~NOVO ANGULO \n"); // r de retry
	printf("\t e -EXIT\n");
}
