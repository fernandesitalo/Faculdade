#include <iostream>

#include <cstring>

using namespace std;


int main()
{
	//char a[] = "cebola";
	char b[] =  "dadidola";
	char a[] = "cebola";
	
	
	if(strcoll(a,b) > 0)
		cout << a;
	else
		cout << b;


}
