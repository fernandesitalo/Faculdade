#include <stdio.h>
#include <math.h>

double raizQD(double y);

int main()
{
	double num;
	
	printf("numero: ");
	scanf("%lf",&num);
	
	num = raizQD(num);
	
	printf("\n%lf",num);
	
}

double raizQD(double y)
{
	double x1,x,dif;	
	x = y/2.0; // primeira aproximacao	
	do
	{
		x1 = ( (x*x)  + y) / (2* x); // aproximacoes sucessivas
		
		dif = fabs(x - x1); // diferenca entre o termo anterior e o termo atual
		
		x = x1;
	}
	while(dif > 0.000001); // faço o procedimento das aproimacoes sucessivas enquanto esta diferenca for maior que 0.000001
	
	return x;	// retornar a raiz quadrada
}
