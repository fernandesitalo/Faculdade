#ifndef DETALHESALUGUEL_H
#define DETALHESALUGUEL_H

#include <QDialog>

namespace Ui {
class DetalhesAluguel;
}

class DetalhesAluguel : public QDialog
{
    Q_OBJECT

public:
    explicit DetalhesAluguel(QWidget *parent = 0);
    ~DetalhesAluguel();

private:
    Ui::DetalhesAluguel *ui;
};

#endif // DETALHESALUGUEL_H
