#ifndef ATUALIZAREQUIPAMENTO_H
#define ATUALIZAREQUIPAMENTO_H

#include <QDialog>
#include "Equipamentos.h"
#include <QListWidgetItem>

namespace Ui {
class AtualizarEquipamento;
}

class AtualizarEquipamento : public QDialog
{
    Q_OBJECT

public:
    explicit AtualizarEquipamento(QWidget *parent = 0);
    ~AtualizarEquipamento();

private slots:

    void on_BuscaButton_clicked();

    void ExibeEquipamento(Equipamentos *B);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void listaTodos();

    void on_cancelarButton_clicked();

    void on_atualizarButton_clicked();

    void on_ApagarButton_clicked();

    void on_ListarButton_clicked();

private:
    Ui::AtualizarEquipamento *ui;
    Equipamentos *EQ;
    long long CodigoOriginal;
    char nome[80];
};

#endif // ATUALIZAREQUIPAMENTO_H
