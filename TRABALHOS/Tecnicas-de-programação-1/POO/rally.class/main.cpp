#include <iostream>
#include "equipe.h"
using namespace std;

int main()
{
    float p1,p2,p3,ptotal,maior = 0;
    int tp1,tp2,tp3;
    int t;
    int ni;

    equipe e,m;

    cout << "Digite os Tempos padroes da Corrida"<<endl;
    cout << "Tempo Padrao 1: ";
    cin >> tp1;

    cout << "Tempo Padrao 2: ";
    cin >> tp2;

    cout << "Tempo Padrao 3: ";
    cin >> tp3;

    cout << "Digite o numero de inscricao da primeira equipe: ";
    cin >> ni;

    while(ni != 9999)
    {
        e.setINSCR(ni);

        cout << "Tempo 1: ";
        cin >> t;
        e.setT1(t);

        cout << "Tempo 2: ";
        cin >> t;
        e.setT2(t);

        cout << "Tempo 3: ";
        cin >> t;
        e.setT3(t);

        p1 = e.getPET(tp1,1);
        p2 = e.getPET(tp2,2);
        p3 = e.getPET(tp3,3);

        ptotal = p1 + p2 + p3;

        if(ptotal > maior)
        {
            maior = ptotal;
            m = e;
        }

        cout << "Total de Pontos da equipe "<<ni<<" : "<<ptotal<<"\n\n";

        cout << "Digite o numero de Incricao da proxima equipe: ";
        cin >> ni; /*leitura do proximo numero de inscricao*/
    }

    cout << "\n\nEQUIPE VENCEDORA: "<< m.getINSCR() <<endl;

    p1 = m.getPET(tp1,1);
    p2 = m.getPET(tp2,2);
    p3 = m.getPET(tp3,3);

    ptotal = p1 + p2 + p3;

    cout << "PONTUACAO: "<< ptotal <<"\n\n";

    return 0;
}
