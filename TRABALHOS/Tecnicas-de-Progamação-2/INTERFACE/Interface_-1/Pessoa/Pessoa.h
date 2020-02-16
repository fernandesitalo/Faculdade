#ifndef PESSOA_H
#define PESSOA_H
#include <QString>

class Pessoa
{
private:
    QString nome;
    QString email;
    QString cpf;

public:
    Pessoa();

    void set_nome(QString nome);
    QString get_nome() const;

    void set_email(QString email);
    QString get_email() const;

    void set_cpf(QString cpf);
    QString get_cpf() const;
};

#endif // PESSOA_H
