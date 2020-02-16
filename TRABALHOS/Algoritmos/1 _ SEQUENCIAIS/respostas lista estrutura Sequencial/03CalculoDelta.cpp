#include<iostream>
using namespace std;

int main()
// inicio do progama
{
    float A,B,C,DELTA;
    //Declaracao das variaveis necessarias  
	    

    std::cout<<"ATENCAO ! \nO progama funcionara somente com equacoes do SEGUNDO grau ! \n\n\n\n" ;
    //mensagem ao usuario    
     

    std::cout<<"Digite o valor do coeficiente A e tecle 'Enter' \n\n" ;
    std::cin>>A;    
		
    std::cout<<"\nDigite o valor do coeficiente B e tecle 'Enter' \n\n" ;
    std::cin>>B;    
         
    std::cout<<"\nDigite o valor do termo independente e tecle 'Enter' \n\n" ;
    std::cin>>C;
    // Obtenção dos dados de Entrada
         

    DELTA=B*B-4*A*C;
    //Calculo do discriminante/delta

    std::cout<<"\n\nO valor do discriminate(Delta) e : " <<DELTA<< "\n\n\n";
    //Exibição dos resultados de saida 

    
	system("pause");    
    return 0;
 
}
