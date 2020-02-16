#ifndef CARTA_H
#define CARTA_H
class Carta
{
private:
    char naipe;
    int valor;
public:
    void set_carta(int valor_, char naipe_);
    void get_carta(int *valor_, char *naipe_);
    Carta();
};

#endif // CARTA_H
