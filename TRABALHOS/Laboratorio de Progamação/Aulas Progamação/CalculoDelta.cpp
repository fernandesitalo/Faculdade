#include<iostream>
int main( )
{
//Declarações das variáveis Necessárias
float A,B,C,DELTA;
//Obtencao dos dados de entrada
std::cout<<"informe o coeficiente A da equação: ";
std::cin>>A;
std::cout<<"Informe o coeficiente B da equação: ";
std::cin>>B;
std::cout<<"Informe o coeficiente C da equação: ";
std::cin>>C;
//cálculo do Discriminante
DELTA=B*B-4*A*C;
//Exibição dps Resultados de Saída
std::cout<< DELTA;
}
