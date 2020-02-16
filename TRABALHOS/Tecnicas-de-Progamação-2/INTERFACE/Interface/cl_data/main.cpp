#include <iostream>
using namespace std;
#include "cl_data.h"


void exibe_menu();

int main()
{
    char data[100];

    cin>>data;

    cl_data obj;

    obj.set_data(data,1);


    return 0;
}




void exibe_menu()
{
    cout << "\t\t -= Menu =-\n";
    cout << "1 - DD/MM/AA\n";
    cout << "2 - MM/DD/AA\n\n";
}
