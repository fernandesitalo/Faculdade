#include "Aluguel.h"
#include "ui_Aluguel.h"

Aluguel::Aluguel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aluguel)
{
    ui->setupUi(this);
}

Aluguel::~Aluguel()
{
    delete ui;
}
