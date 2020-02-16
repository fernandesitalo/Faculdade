#include "DetalhesAluguel.h"
#include "ui_DetalhesAluguel.h"

DetalhesAluguel::DetalhesAluguel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetalhesAluguel)
{
    ui->setupUi(this);
}

DetalhesAluguel::~DetalhesAluguel()
{
    delete ui;
}
