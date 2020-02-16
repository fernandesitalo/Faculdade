#include <stdio.h>
#include <biblioteca_do_italo.h> // by : Italo Fernandes Goncalves

int main()
{
	double num; //declaracao
	
	printf("\t-= RAIZ QUADRADA =-\n\n");	
	printf("Digite um numero: ");
	scanf("%lf",&num); //obtencao do dado de entrada
		
	printf("Raiz quadrada de %lf eh %lf",num,raizQD(num)); //exibicao dos dados de entrada
	return 0;
}
