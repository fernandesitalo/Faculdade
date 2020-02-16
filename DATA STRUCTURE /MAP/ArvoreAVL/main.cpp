#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#include <map>

#include "TreeAVL.h"

int main(){

    TreeAVL<int,int> T;
    T.Insert( 1 , 5 );
    T.Insert( 2 , 2 );
    T.Insert( 3 , 4 );


    printf("%d\n",T[1] );
    printf("%d\n",T[2] );
    printf("%d\n",T[3] );
    T.Clear();

    puts("---------");

    printf("%d\n",T[1] );
    printf("%d\n",T[2] );
    printf("%d\n",T[3] );



    return 0;
}
