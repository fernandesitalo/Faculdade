#include<iostream>
using namespace std;

int main()
{
	int X,Y,A,B,C; // declaracao das variaveis necessarias 
	
	std::cout<<"Favor,digite um numero de 3 digitos para que seja invertido,\nem seguida tecle 'Enter' : \n";
	std::cin>>X;
	//obtencao dos resultados de saida
	
	   	if(X>0) // se X>0 ...

{
	A=X%10;
	B=(X/10)%10;
	C=(X/10)/10;
}
				
		else // se X<0 entao ...
	{
     	Y=X*-1;
		
		A=Y%10*-1;
		B=(Y/10)%10;
		C=(Y/10)/10;
	}
	std::cout<<"\n\n"<<A<<B<<C;
	//exibicao dos rsultados de saida 
}

