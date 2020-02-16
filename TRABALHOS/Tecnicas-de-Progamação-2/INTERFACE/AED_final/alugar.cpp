#include "alugar.h"
#include "ui_alugar.h"

Alugar::Alugar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alugar)
{
    ui->setupUi(this);
}

Alugar::~Alugar()
{
    delete ui;
}
