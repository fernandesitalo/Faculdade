#include "cl_data.h"
#include <iostream>
using namespace std;

cl_data::cl_data()
{
    dia = mes = ano = 0;
}

bool cl_data::set_data(char *entrada,int op)
{
    int a,d,m;
    /*defnir dia , mes , e ano*/

    switch(op)
     {
     case 1:
          d = ((entrada[0] - '0')*10) + ( entrada[1] - '0' );
          m = ((entrada[3] - '0')*10) + ( entrada[4] - '0' );
          a = ((entrada[6] - '0')*1000) + ((entrada[7] - '0')*100)   + ((entrada[8] - '0')*10) +   ( entrada[9] - '0' );


         cout << d << "    /   "<<m<<"    /   "<<a<<"\n\n";
         break;


      case 2:

         break;
     }

    return true;


}












