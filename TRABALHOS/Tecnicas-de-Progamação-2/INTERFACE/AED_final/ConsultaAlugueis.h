#ifndef CONSULTAALUGUEIS_H
#define CONSULTAALUGUEIS_H

#include <QDialog>
#include <QListWidgetItem>
#include "INDALUGA.h"

namespace Ui {
class ConsultaAlugueis;
}

class ConsultaAlugueis : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultaAlugueis(QWidget *parent = 0);
    ~ConsultaAlugueis();

private slots:
    void ListarTodos();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void ExibeNaTela(INDALUGA *X);
    void limpaTabela();

    void on_DevolucaoButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ConsultaAlugueis *ui;
    long long codAluguel;
};

#endif // CONSULTAALUGUEIS_H
