#ifndef CL_DATA_H
#define CL_DATA_H


class cl_data
{
private:
    int dia;
    int mes;
    int ano;



//   bool valida(int d, int m , int a);

public:

    bool set_data(char *entrada,int op);





    cl_data();
};

#endif // CL_DATA_H
