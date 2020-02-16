#ifndef NOMESCODIGOS_H
#define NOMESCODIGOS_H

#include <QDialog>

namespace Ui {
class NomesCodigos;
}

class NomesCodigos : public QDialog
{
    Q_OBJECT

public:
    explicit NomesCodigos(QWidget *parent = 0);
    ~NomesCodigos();

    void ListarTodos();

private:
    Ui::NomesCodigos *ui;
};

#endif // NOMESCODIGOS_H
