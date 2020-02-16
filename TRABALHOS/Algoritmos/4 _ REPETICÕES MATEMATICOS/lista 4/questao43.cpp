#include <iostream>

using namespace std;

int main()
{
	float a,b,u,c,d,v,x,y;
	
	for(;a != 0 ||b != 0 ||u != 0 ||c != 0 ||d != 0 ||v != 0;) // condicao de parada 
	{
		cout << "seja o sistema de equacao:\n           (a)x + (b)y = (u)"<<endl;
		cout << "           (c)x + (d)y = (v)"<<endl;
	
		cout << "Informe os seguintes coeficientes:"<<endl;  // Entrada de dados do progama 
		cout << "(a) :";
		cin >> a;
		cout << "(b) :";
		cin >>b;
		cout << "(u) :";
		cin >>u;
		cout << "(c) :";
		cin >>c;
		cout << "(d) :";
		cin >>d;
		cout << "(v) :";
		cin >>v;
		
		// calculo das incognitas do sistema de equacao	
		x = (d/(a*d-b*c))*u - (b/((a*d-b*c)))*v; 	
		y =  (-c/(a*d-b*c))*u + (a/((a*d-b*c)))*v;
		
		cout << "----------------------------------------"<<endl;
		cout <<"          "<<a<<"x + ("<<b<<")y = "<<u<<endl;
		cout <<"          "<<c<<"x + ("<<d<<")y = "<<v<<endl;
		cout <<"          __________________"<<endl;
		
		cout << "          ==> x = "<<x<<"    y = "<<y<<endl;
		cout << "----------------------------------------"<<endl;	
	}
	
	
	
	
	
	
}
