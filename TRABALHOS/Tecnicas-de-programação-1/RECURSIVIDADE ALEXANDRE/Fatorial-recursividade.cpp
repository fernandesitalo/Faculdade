#include <stdio.h>


int fat(int n)
{
	if(n == 1)
		return 1;
	
	return fat(n - 1)*n;
}

int main()
{
	int num;
	
	scanf("%d",&num);
	
	printf("Fatorial:  %d ",fat(num));
}
