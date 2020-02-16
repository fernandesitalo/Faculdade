#include<iostream>
using namespace std;

int main()

{
	int A,B,C,R,S,D; //Declaracao das variaveis necessarias
	
	std::cout<<"Favor digite o valor de A e tecle 'Enter' : ";
	std::cin>>A; // obtencao do termo A
	
	std::cout<<"\n\nFavor digite o valor de B e tecle 'Enter' : ";
	std::cin>>B; // obtencao do temo B 
	
	std::cout<<"\n\nFavor digite o valor de C e tecle 'Enter' : ";
	std::cin>>C; // obtencao do termo C
	
	R=(A*A)+(2*A*B)+(B*B); // Calculo de R
	
    S=(B*B)+(2*B*C)+(C*C); // Calculo de S
    
    D=(R+S)/2; // Calculo de D
    
    std::cout<<"\n\nO valor de D e igual a : "<<D<<"\n";    
	
}
