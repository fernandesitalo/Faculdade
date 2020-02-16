#include<iostream>

using namespace std;

int main()
{
	int i;
	float soma,termo;
	
	soma = 0;
	for(i = 1 ; i <= 50 ; i++)
	{
		termo =(float)(i*2-1) / i; 
		soma += termo;
	}
	cout<<"Soma dos Termos: "<<soma<<endl;
}
