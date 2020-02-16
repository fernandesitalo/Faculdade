#include "Aluno.h"
#include <string.h>

void Aluno::set(int k, char *n)
{
    key = k;
    strcpy(nome,n);
}

Aluno::Aluno()
{

}
