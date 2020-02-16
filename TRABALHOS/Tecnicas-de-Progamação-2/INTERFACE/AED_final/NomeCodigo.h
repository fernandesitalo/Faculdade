#ifndef NOMECODIGO_H
#define NOMECODIGO_H

#include <QDialog>

namespace Ui {
class NomeCodigo;
}

class NomeCodigo : public QDialog
{
    Q_OBJECT

public:
    explicit NomeCodigo(QWidget *parent = 0);
    ~NomeCodigo();
    void listarTodos();
private:
    Ui::NomeCodigo *ui;
};

#endif // NOMECODIGO_H
