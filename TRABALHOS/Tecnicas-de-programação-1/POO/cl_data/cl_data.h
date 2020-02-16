#ifndef CL_DATA_H
#define CL_DATA_H


class cl_data
{
    private:
        int dia;
        int mes;
        int ano;
        int diaS;

        bool define1(char* entrada); /*    01/09/2016   DD/MM/AAAA                  */
        bool define2(char* entrada); /*    09/01/2016   MM/DD/AAAA                  */
        bool define3(char* entrada); /*01/09/16   DD/MM/AA                          */
        bool define4(char* entrada); /*09/01/16   MM/DD/AA                          */
        bool define5(char* entrada); /*    1 de setembro de 2006                    */
        bool define6(char* entrada); /*    sexta-feira,1 de setembro de 2006        */


    public:
        cl_data(); // metodo construtor que e execultado logo apos a instanciacao da classe no progama principal

        bool set_data(char *a,int op);
        int get_dia();
        int get_mes();
        int get_ano();

        bool valida_data(int d, int m,int a);
        int DiaDaSemana(int d,int m, int a);
        int DEFINEmes(char *A______mes);// retorna o respectivo mes em inteiro ex.: janeiro - 1
        int DEFINEdiasemana(char * D__Dia); // retorna o respectivo dia em inteiro ex.: terca-feira - 2
        bool getData(char *saida,int op);

        ~cl_data();
};

#endif // CL_DATA_H
