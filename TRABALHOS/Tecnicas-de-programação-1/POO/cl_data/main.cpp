#include <iostream>
#include <stdlib.h>
#include "interface.h"
#include "cl_data.h"
using namespace std;

int main()
{
    int cont = 0;
    int op;
    char entrada[200],saida[200];
    cl_data obj;

    interface::menu(); // imprime o menu para o usuario SETAR a data como desejar
    cout << "ESCOLHA UMA OPCAO DO MENU: ";
    cin >> op;
    cin.ignore();

    cout << "Digite a Data Conforme a opcao escolhida: \n";  /// leitura da data
    cin.get( entrada ,200);

    while(!obj.set_data(entrada,op) && cont < 2) // se a data for invalida e feita uma nova leitura ... ate que a data esteja correta !!!!
    {
        cont++;
        system("clear");
        cout << "ATENCAO!!\nInforme uma data Valida...\nVoce tem mais "<< 3-cont <<" chances!\n\n";
        cin.ignore();
        cin.get(entrada,200);
    }
    system("clear");

    if(cont < 2)
    {
       interface::menuFormato();
       cout << "Opcao: ";
       cin >> op;
       while(op != 7)    /// aqui o usiario escolhe como a data poderá ser exibida, conforme a especificação do exerc
       {
           system("clear");
           obj.getData(saida,op);
           cout << saida <<"\n\n";

           interface::menuFormato();
           cout << "Opcao: ";
           cin>>op;
       }
    }
    else
        cout << "Suas Chances acabaram...\n";

   cout << "~Ate mais Parça!!\n\n\n";
    return 0;
}


