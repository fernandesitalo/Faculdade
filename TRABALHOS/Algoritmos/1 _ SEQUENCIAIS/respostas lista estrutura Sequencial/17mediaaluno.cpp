#include <iostream>

using namespace std;

int main ()

{
		float av1,av2,av3,av4,media;
		
		cout << "Favor,digite sua nota da avaliação 1 : ";
		cin >>av1;
		
		cout << "Favor,digite sua nota da avaliação 2 : ";
		cin >>av2;
		
		cout << "Favor,digite sua nota da avaliacao 3 : " ;
		cin >>av3;
		
		cout << "Favor,digite sua nota da avaliacao 4 : ";
		cin >>av4;
		
		// calculos 
		
		media=(av1*2+av2*4+av3*6+av4*8)/20;
		
		cout << "\n Sua media eh "<<media<<" !!";
	}
		
