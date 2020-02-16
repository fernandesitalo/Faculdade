#ifndef CARTA_H
#define CARTA_H

namespace my{
class Carta
{
private:
    char naipe;
    char valor;

public:    
    void setCarta(char _valor__, char _naipe__);

    void printCarta(); /// TESTES ALFA

    char getNaipe();

    char getValor();

    bool operator<(Carta C) const;

    bool operator!=(Carta C)const;

    bool operator==(Carta C)const;

    Carta(char valor__,char naipe__);

    Carta();
};

Carta make_carta(char valor__,char naipe__);

}



#endif // CARTA_H
