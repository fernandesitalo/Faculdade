#ifndef FICHA_H
#define FICHA_H


class Ficha
{
private:
    int Jogador; // Os possíveis valores são { 1 , 2 , 3 , 4 }
    char Cor; //  Os possíveis valores são  { ‘A’ , ‘V’ , ‘R’ , ‘B’, ‘P’ }
    int Torre; //  Os possíveis valores são { 1 , 2 , 3 , 4 , 5 , 6 }
public:

    void set(int Num_jogador,char Cor_da_ficha,int Torre_da_ficha);

    int getJogador();
    void setJogador(int Num_jogador);

    char getcor();
    void setcor(char Cor_da_ficha);

    void setTorre(int Torre_da_ficha);
    int getTorre();
    Ficha(int Jogador_ficha,char Cor_da_ficha,int Torre_de_insercao);
    Ficha();
};

#endif // FICHA_H
