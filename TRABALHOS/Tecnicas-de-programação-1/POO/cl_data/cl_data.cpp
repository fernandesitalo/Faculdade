#include "cl_data.h"
#include <string.h>

cl_data::cl_data() // metodo construtor , serve para inicializar atributos
{
    dia = 0;
    mes = 0;
    ano = 0;
}
cl_data::~cl_data()
{
// nao precisa de destrutor, nada foi alocado dinamicamente
}

bool cl_data::set_data(char *a,int op) /// 6 maneiras diferentes para setar
{
    switch(op)
    {
    case 1:
        if(!define1(a))
            return false;
        break;

    case 2:
        if(! define2(a))
            return false;
        break;

    case 3:
        if(! define3(a))
            return false;
        break;

    case 4:
        if(! define4(a))
            return false;
        break;
    case 5:
        if(! define5(a))
            return false;
        break;
    case 6:
        if(! define6(a))
            return false;
        break;

    default:
        return false;
    }

    return true;
}


int cl_data::get_dia()
{
    return dia;
}


int cl_data::get_mes()
{
    return mes;
}


int cl_data::get_ano()
{
    return ano;
}


bool cl_data::define1(char* entrada) ///   01/09/2016   DD/MM/AA
{
    int d,m,a;// dia , mes , ano
    int i;

    for(i = 0 ,d = 0;entrada[i] != '/' && d <= 31 && i < 3 ; i++)
    {
        d *= 10;
        d += entrada[i] - '0';
    }
        if(d > 31 || d < 1)
            return false;

    for(i++,m = 0 ;entrada[i] != '/' && m <= 12 ; i++)
    {
        m *= 10;
        m += entrada[i] - '0';
    }
        if(m > 12 || m < 1)
            return false;

    for (i++,a = 0 ; entrada[i] <= '9' && entrada[i] >= '0' && entrada[i] != '\0' ; i++)
    {
        a *= 10;
        a += entrada[i] - '0';// '0' e o mesmo que 48
    }


    if(valida_data(d,m,a))
    {
        dia = d;
        mes = m;
        ano = a;
        diaS = DiaDaSemana(d,m,a);
        return true;
    }

    return false;
}



bool cl_data::define2(char* entrada) ///09/01/2016   MM/DD/AA
{
    int d,m,a;
    int i;

    for(i = 0 ,m = 0 ;entrada[i] != '/' && m <= 12; i++)
    {
        m *= 10;
        m += entrada[i] - '0';
    }
        if(m > 12 || m < 1 || i == 3)
            return false;

    for(i++ ,d = 0;entrada[i] != '/' && d <= 31 ; i++)
    {
        d *= 10;
        d += entrada[i] - '0';
    }
        if(d > 31 || d < 1)
            return false;

    for (i++,a = 0 ; entrada[i] <= '9' && entrada[i] >= '0' && entrada[i] != '\0' ; i++)
    {
        a *= 10;
        a += entrada[i] - '0';// '0' e o mesmo que 48
    }


    if(valida_data(d,m,a))
    {
        dia = d;
        mes = m;
        ano = a;
        diaS = DiaDaSemana(d,m,a);
        return true;
    }

    return false;
}


bool cl_data::define3(char* entrada) /*01/09/2016  DD/MM/AA */
{
    int d,m,a;// dia , mes , ano
    int i;

    for(i = 0 ,d = 0;entrada[i] != '/' && d <= 31 ; i++)
    {
        d *= 10;
        d += entrada[i] - '0';
    }
        if(d > 31 || d < 1)
            return false;

    for(i++,m = 0 ;entrada[i] != '/' && m <= 12 ; i++)
    {
        m *= 10;
        m += entrada[i] - '0';
    }
        if(m > 12 || m < 1)
            return false;

    for (i++,a = 0 ; entrada[i] <= '9' && entrada[i] >= '0' && entrada[i] != '\0' ; i++)
    {
        a *= 10;
        a += entrada[i] - '0';// '0' e o mesmo que 48
    }
        if(a < 1000)
            a += 2000;
        else
            return false;

    if(valida_data(d,m,a))
    {
        dia = d;
        mes = m;
        ano = a;
        diaS = DiaDaSemana(d,m,a);
        return true;
    }

    return false;
}



bool cl_data::define4(char* entrada) /*09/01/2016   MM/DD/AA*/
{
    int d,m,a;
    int i;

    for(i = 0 ,m = 0 ;entrada[i] != '/' && m <= 12; i++) // separa o mes
    {
        m *= 10;
        m += entrada[i] - '0';
    }
        if(m > 12 || m < 1 || i == 3)
            return false;

    for(i++ ,d = 0;entrada[i] != '/' && d <= 31 ; i++) // separa o dia
    {
        d *= 10;
        d += entrada[i] - '0';
    }
        if(d > 31 || d < 1)
            return false;

    for (i++,a = 0 ; entrada[i] <= '9' && entrada[i] >= '0' && entrada[i] != '\0' ; i++) // separa o ano
    {
        a *= 10;
        a += entrada[i] - '0';// '0' e o mesmo que 48
    }
        if(a < 1000)
            a += 2000;
        else
            return false;

    if(valida_data(d,m,a)) // valida, se verdadeiro , atriui aos atributos, se nao, foda-se
    {
        dia = d;
        mes = m;
        ano = a;
        diaS = DiaDaSemana(d,m,a);
        return true;
    }

    return false;
}



bool cl_data::define5(char* entrada) /*1 de setembro de 2006 */
{
    int d,m,a,i;
    int aux;
    char mesEntrada[20];

    for(d = 0, i = 0 ; entrada[i] - '0' <= 9 && entrada[i] - '0' >= 0 && i < 2 ; i++) // pega somente o dia
    {
        d *= 10;
        d += entrada[i] - '0';
    }
    if(d > 31 || i > 2)
        return false;

    for(i += 4,aux = 0; entrada[i] != ' ' ; i++,aux++) // acha o nome do mes
    {
        if(entrada[i] <= 90)
            entrada[i] += 32;

        mesEntrada[aux] = entrada[i];
    }
    mesEntrada[aux] = '\0';


    m = DEFINEmes(mesEntrada);
    if(m > 12)
        return false;

    // define o ano
    for(aux = i+4,a = 0; (entrada[aux] - '0') <= 9 && (entrada[aux] - '0') >= 0 && entrada[aux] != '\0' ; aux++) // sepata o ano
    {
        a *= 10;
        a += entrada[aux] - '0';
    }

    if(valida_data(d,m,a))
    {
        dia = d;
        mes = m;
        ano = a;
        diaS = DiaDaSemana(d,m,a);
        return true;
    }
    return false;
}

bool cl_data::define6(char* entrada) /*    sexta-feira,1 de setembro de 2006      */
{
    int d,m,a,i,ds,aux;
    char diaSemana[20],mesEntrada[20];

    for(i = 0 ; entrada[i] != ',' ;i++) // separa o dia da semana escrito !
    {
        if(entrada[i] <= 90)
            entrada[i] += 32;

        diaSemana[i] = entrada[i];
    }
    diaSemana[i] = '\0';

    ds = DEFINEdiasemana(diaSemana); // retorna o correspondente numerico do dia da semana

    if(ds > 6)
        return false;

    for(i++,d = 0 ;  entrada[i]-'0' <= 9   &&   entrada[i]-'0' >= 0 ; i++)
    {
        d *= 10;
        d += entrada[i] - '0';
    }


    for(i += 4 ,aux = 0 ; entrada[i] != ' ' ; i++,aux++) // separa o mes em uma variavel
    {
        if(entrada[i] <= 90)
            entrada[i] += 32;

        mesEntrada[aux] = entrada[i];
    }


    mesEntrada[aux] = '\0';


    m = DEFINEmes(mesEntrada); // define o mes no seu correspondente numerico

    if(m > 12)
        return false;

    for(i +=4 ,a = 0; entrada[i] - '0' <= 9 && entrada[i] - '0' >= 0 && entrada[i] != '\0'; i++)
    { // define o ano em inteiro
        a *= 10;
        a += entrada[i] - '0';
    }

    int diaSEMANA = DiaDaSemana(d,m,a); // calcula e retorna o dia da semana que a data corresponde

    if(valida_data(d,m,a) && ds == diaSEMANA) // se esta tudo ok, atribuimos os valores as atributos e retornamos verdadeiro
    {
        dia = d;
        mes = m;
        ano = a;
        diaS = ds;
        return true;
    }
    return false;
}

int cl_data::DiaDaSemana(int d,int m, int a) // funcao que retorna o dia da semana de acordo com a data definida
{
    int maux = m;
    int aaux = a;
    if(m <= 2)  // composicao da formula para a descoberta do dia da semana
    {
        maux += 10; // janeiro corresponde ao mes 11 e fevereiro ao mes 12 do ano anterior !!
        aaux -= 1;
    }
    else
    {
        maux -= 2; // aos demais meses , cada um correponde a 2 menos que seu correpondente numerico
    }
    int s = a / 100;
    aaux = a % 100;

    return ((int) (((2.6*maux - 0.2)/1) + d + aaux + (aaux/4) + (s/4) - 2*s) % 7);
}

bool cl_data::valida_data(int dia, int mes,int ano) // valida a data
{
    if(dia < 01 || dia > 31 || mes > 12 || mes < 01 || ano < 0) // se o usuario digitar alguma coisa errada o progama ja para aqui
    {
        return false;
    }

    // ate aqui aparentemente ta tudo ok , vamos continuar

    if(mes == 02) // mes de fevereiro
    {
        if((ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0))
        {
            if(dia > 29)  //para ano bissexto
            {
                return false;
            }
            return true;
        }

        // se não deu resto zero e pq o ano em questao , e um ano NAO bissexto , neste caso , fev so vai ate dia 28

        if(dia > 28)
        {
            return false;
        }
        return true;
    }

    // se não e mes 02 , entao ....

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11)	// meses com 30 dias
    {
        if(dia <= 30)
        {
            return true;
        }
        return false;
    }
    // se nao e mes 02 e não e nenhum mes que tem 30 dias e pq e um mes de 31 dias, e se tem 31 dias , ta valendo
    return true;
}


int cl_data::DEFINEmes(char* A______mes) // retorna o correspondente numerido de cada mes
{
    char meses[12][13] = {"janeiro","fevereiro","marco","abril","maio","junho",
                          "julho","agosto","setembro","outubro","novembro","dezembro"};
    int i;
    for(i = 0 ; i < 12 && (strcmp(A______mes,meses[i])!= 0); i++);
    return (i+1);
}

int cl_data::DEFINEdiasemana(char * D__Dia) // retorna o correspondente numerido de cada dia da semana
{
    char dias_semana[7][20] = {"domingo","segundaMfeira","terçaMfeira",
                               "quartaMfeira","quintaMfeira","sextaMfeira","sabado"};
    int i;
    for(i = 0 ; i < 7 && (strcmp(D__Dia,dias_semana[i])!= 0); i++);
    return i;
}



bool cl_data::getData(char *saida,int op)
{
    int aux,i = 0;
    char meses[12][13] = {"janeiro","fevereiro","marco","abril","maio","junho",
                          "julho","agosto","setembro","outubro","novembro","dezembro"};

    char dias_semana[7][20] = {"Domingo","Segunda-feira","Terça-feira",
                               "Quarta-feira","Quinta-feira","Sexta-feira","Sabado"};

    switch(op)
    {
    case 1:
        saida[i++] = dia / 10 + '0';
        saida[i++] = dia % 10 + '0';
        saida[i++] = '/';
        saida[i++] = mes / 10 + '0';
        saida[i++] = mes % 10 + '0';
        saida[i++] = '/';
        aux = ano;
        saida[i++] = aux / 1000 + '0';
        aux %= 1000;
        saida[i++] = aux / 100 + '0';
        aux %= 100;
        saida[i++] = aux / 10 + '0';
        aux %= 10;
        saida[i++] = aux + '0';
        saida[i] = '\0';
        break;

    case 2:
        saida[i++] = mes / 10 + '0';
        saida[i++] = mes % 10 + '0';
        saida[i++] = '/';
        saida[i++] = dia / 10 + '0';
        saida[i++] = dia % 10 + '0';
        saida[i++] = '/';
        aux = ano;
        saida[i++] = aux / 1000 + '0';
        aux %= 1000;
        saida[i++] = aux / 100 + '0';
        aux %= 100;
        saida[i++] = aux / 10 + '0';
        aux %= 10;
        saida[i++] = aux + '0';
        saida[i] = '\0';
        break;

    case 3:
        saida[i++] = dia / 10 + '0';
        saida[i++] = dia % 10 + '0';
        saida[i++] = '/';
        saida[i++] = mes / 10 + '0';
        saida[i++] = mes % 10 + '0';
        saida[i++] = '/';
        aux = ano;
        aux %= 1000;
        aux %= 100;

        saida[i++] = aux / 10 + '0';
        saida[i++] = aux % 10 + '0';
        saida[i] = '\0';
        break;

    case 4:
        saida[i++] = mes / 10 + '0';
        saida[i++] = mes % 10 + '0';
        saida[i++] = '/';
        saida[i++] = dia / 10 + '0';
        saida[i++] = dia % 10 + '0';
        saida[i++] = '/';
        aux = ano;
        aux %= 1000;
        aux %= 100;
        saida[i++] = aux / 10 + '0';
        saida[i++] = aux % 10 + '0';
        saida[i] = '\0';
        break;

    case 5:
        saida[i++] = dia / 10 + '0';
        saida[i++] = dia % 10 + '0';
        saida[i++] = ' ';
        saida[i++] = 'd';
        saida[i++] = 'e';
        saida[i++] = ' ';

        for(int k = 0 ; meses[mes - 1][k] != '\0' ; k++)
            saida[i++] = meses[mes - 1][k];

        saida[i++] = ' ';
        saida[i++] = 'd';
        saida[i++] = 'e';
        saida[i++] = ' ';


        aux = ano;
        saida[i++] = aux / 1000 + '0';
        aux %= 1000;
        saida[i++] = aux / 100 + '0';
        aux %= 100;
        saida[i++] = aux / 10 + '0';
        aux %= 10;
        saida[i++] = aux + '0';
        saida[i] = '\0';
        break;

    case 6:

        for(i = 0 ;  dias_semana[diaS][i] != '\0' ; i++)
            saida[i] =  dias_semana[diaS][i];

        saida[i++] = ',';
        saida[i++] = dia / 10 + '0';
        saida[i++] = dia % 10 + '0';

        saida[i++] = ' ';
        saida[i++] = 'd';
        saida[i++] = 'e';
        saida[i++] = ' ';

        for(int k = 0 ; meses[mes - 1][k] != '\0' ; k++)
            saida[i++] = meses[mes - 1][k];

        saida[i++] = ' ';
        saida[i++] = 'd';
        saida[i++] = 'e';
        saida[i++] = ' ';


        aux = ano;
        saida[i++] = aux / 1000 + '0';
        aux %= 1000;
        saida[i++] = aux / 100 + '0';
        aux %= 100;
        saida[i++] = aux / 10 + '0';
        aux %= 10;
        saida[i++] = aux + '0';
        saida[i] = '\0';
        break;

    default:
        return false;
    }
    return true;
}

