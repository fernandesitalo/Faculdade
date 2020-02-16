#ifndef CADRASTROEQUIPAMENTO_H
#define CADRASTROEQUIPAMENTO_H

#include <QDialog>
#include "Equipamentos.h"

namespace Ui {
class CadrastroEquipamento;
}

class CadrastroEquipamento : public QDialog
{
    Q_OBJECT

public:
    explicit CadrastroEquipamento(QWidget *parent = 0);
    ~CadrastroEquipamento();

private slots:
    void on_cadrastrarButton_clicked();

    void on_cancelarButton_clicked();

private:
    Ui::CadrastroEquipamento *ui;
    Equipamentos * EQ;

};

#endif // CADRASTROEQUIPAMENTO_H
