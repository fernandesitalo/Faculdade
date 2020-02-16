#ifndef CRIARPESSOA_H
#define CRIARPESSOA_H

#include <QDialog>
#include "pessoa.h"

namespace Ui {
class CriarPessoa;
}

class CriarPessoa : public QDialog
{
    Q_OBJECT

public:
    explicit CriarPessoa(QWidget *parent = 0);
    void setPessoa(Pessoa *P);
    ~CriarPessoa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CriarPessoa *ui;
    Pessoa *P;
};

#endif // CRIARPESSOA_H
