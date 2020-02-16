#ifndef CADRASTROCLIENTE_H
#define CADRASTROCLIENTE_H

#include <QDialog>
#include "Arquivos.h"
#include "Cliente.h"

namespace Ui {
class CadrastroCliente;
}

class CadrastroCliente : public QDialog
{
    Q_OBJECT

public:
    explicit CadrastroCliente(QWidget *parent = 0);
    ~CadrastroCliente();
private slots:
    void on_cadrastrarButton_clicked();

    void on_cancelarButton_clicked();

private:
    Ui::CadrastroCliente *ui;
    Cliente *CL;
};

#endif // CADRASTROCLIENTE_H
