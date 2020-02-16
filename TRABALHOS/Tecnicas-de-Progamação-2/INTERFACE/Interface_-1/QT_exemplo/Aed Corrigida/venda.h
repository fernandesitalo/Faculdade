#ifndef VENDA_H
#define VENDA_H
#include "games.h"

#include <QDialog>

namespace Ui {
class venda;
}

class venda : public QDialog ,public games
{
    Q_OBJECT

public:
    explicit venda(QWidget *parent = 0);
    ~venda();

public slots:

private slots:
    void on_fim_clicked();

    void on_adicionar_clicked();


private:
    Ui::venda *ui;
    int qtd;
    float soma;
    games v[10];
    int p;
};

#endif // VENDA_H
