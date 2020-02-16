#ifndef ALUGAREQUIPAMENTO_H
#define ALUGAREQUIPAMENTO_H

#include <QDialog>
#include "INDALUGA.h"
#include <QListWidgetItem>

namespace Ui {
class AlugarEquipamento;
}

class AlugarEquipamento : public QDialog
{
    Q_OBJECT

public:
    explicit AlugarEquipamento(QWidget *parent = 0);
    ~AlugarEquipamento();

private slots:
    void on_InserirButton_clicked();

    void on_finalizarButton_clicked();

    void limpaTabela();

    void listarTodos();

    void on_listWidget_itemClicked(QListWidgetItem *item);


    void on_DeletButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_finalizarButton_2_clicked();

    void on_finalizarButton_3_clicked();

private:
    Ui::AlugarEquipamento *ui;
    float soma;
    int qtd;
    INDALUGA *Pedido;

    long long eqs[11];
};

#endif // ALUGAREQUIPAMENTO_H
