#include "interface.h"
#include "cl_data.h"
#include <iostream>
using namespace std;

interface::interface()
{

}
void interface::menu()
{
    cout << "\t -----------= MENU DE ENTRADA  =-----------\n";
    cout << "\t(1). Ex.: 28/10/2016 ---- DD/MM/AAAA\n";
    cout << "\t(2). Ex.: 10/28/2006 ---- MM/DD/AAAA\n";
    cout << "\t(3). Ex.: 28/10/16 ------ DD/MM/AA\n";
    cout << "\t(4). Ex.: 10/28/06 ------ MM/DD/AA\n";
    cout << "\t(5). Ex.: 28 de outubro de 2016\n";
    cout << "\t(6). Ex.: Sexta-feira,28 de outubro de 2016\n";
    cout << "\t\t(7). SAIR\n";
    cout << "\t -----------= ================ =-----------\n\n";
}

void interface::menuFormato()
{
    cout << "\n\t --= ESCOLHA O FORMATO DA DATA PARA EXIBICAO =--\n";
    cout << "\t(1). DD/MM/AAAA   Ex.: 28/10/2016\n";
    cout << "\t(2). MM/DD/AAAA   Ex.: 10/28/2006\n";
    cout << "\t(3). DD/MM/AA     Ex.: 28/10/16\n";
    cout << "\t(4). MM/DD/AA     Ex.: 10/28/06\n";
    cout << "\t(5). Ex.: 28 de outubro de 2016\n";
    cout << "\t(6). Ex.: Sexta-feira,28 de outubro de 2016\n";
    cout << "\t***DIGITE 7 PARA SAIR***\n";
    cout << "\t --= ============================================= =--\n\n";
}


