#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Interface.h"
#include "Matriz.h"

int main()
{
    int linha_A,linha_B,coluna_A,coluna_B;

    int op;


    Interface::PrintfMenu();
    cin>>op;
    while(op)
    {
        switch(op)
        {
            case 1:///soma
            {
                cout << "\n::::Matriz A::::\n";
                cout <<"Quantidade de Linhas: ";
                cin >> linha_A;
                cout << "Quantidade de Colunas: ";
                cin >> coluna_A;

                Matriz A(linha_A,coluna_A);
                cout << "\n=>Digite a Matriz A "<<linha_A<<"x"<<coluna_A<<":"<<endl;
                Interface::ReadMatrix(&A);

                cout << "\n\n::::Matriz B::::\n";
                cout <<"Quantidade de Linhas: ";
                cin >> linha_B;
                cout << "Quantidade de Colunas: ";
                cin >> coluna_B;

                Matriz B(linha_B,coluna_B);
                cout << "\n=>Digite a Matriz B "<<linha_B<<"x"<<coluna_B<<":"<<endl;
                Interface::ReadMatrix(&B);

                system("clear");
                cout << "::::Matriz A + Matriz B::::\n\n";
                Matriz C(coluna_A,linha_B);
                C.SOMA(&A,&B);
                Interface::PrintMatrix(&C);
                cout << "\n\n\n";
             }
             break;

            case 2://multiplicao
            {
                cout << "\n::::Matriz A::::\n";
                cout <<"Quantidade de Linhas: ";
                cin >> linha_A;
                cout << "Quantidade de Colunas: ";
                cin >> coluna_A;

                Matriz A1(linha_A,coluna_A);
                cout << "\n=>Digite a Matriz A "<<linha_A<<"x"<<coluna_A<<":"<<endl;
                Interface::ReadMatrix(&A1);

                cout << "\n\n::::Matriz B::::\n";
                cout <<"Quantidade de Linhas: ";
                cin >> linha_B;
                cout << "Quantidade de Colunas: ";
                cin >> coluna_B;

                Matriz B1(linha_B,coluna_B);
                cout << "\n=>Digite a Matriz B "<<linha_B<<"x"<<coluna_B<<":"<<endl;
                Interface::ReadMatrix(&B1);

                system("clear");
                cout << "::::Matriz A x Matriz B::::\n\n";
                Matriz C1(coluna_A,linha_B);
                C1.MULTIPLICACAO(&A1,&B1);

                Interface::PrintMatrix(&C1);
                cout << "\n\n\n";
            }
            break;

            case 3:// determinante - LAPLACE
            {
                cout << "\n::::Matriz A::::\n";
                cout <<"Quantidade de Linhas: ";
                cin >> linha_A;
                cout << "Quantidade de Colunas: ";
                cin >> coluna_A;

                Matriz A2(linha_A,coluna_A);
                cout << "\n=>Digite a Matriz A "<<linha_A<<"x"<<coluna_A<<":"<<endl;
                Interface::ReadMatrix(&A2);

                system("clear");
                cout << "DETERMINANTE DA MATRIZ A: "<<A2.DETERMINANTE()<<endl;
                cout << "\n\n\n";
             }
            break;

        default:
            cout << "Opcao errada AMIGAO...\n";
        }
        Interface::PrintfMenu();
        cin>>op;
    }
    system("clear");
    cout << "~FALOW"<<endl;

}
