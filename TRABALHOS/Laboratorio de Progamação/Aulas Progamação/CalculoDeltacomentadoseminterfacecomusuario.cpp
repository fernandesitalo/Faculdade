#include<iostream>
int main( )
{
//Declarações das variáveis Necessárias
float A,B,C,DELTA;
//Obtencao dos dados de entrada
std::cin>>A; //mesma coisa que 'leia A' guarda o valor de A 
std::cin>>B; //mesma coisa que 'leia B'
std::cin>>C; //mesma coisa que 'leia c'
//cálculo do Discriminante-formula
DELTA=B*B-4*A*C; 
//Exibição dos Resultados de Saída 
std::cout<<DELTA;
//comando de saida de dados 
}
