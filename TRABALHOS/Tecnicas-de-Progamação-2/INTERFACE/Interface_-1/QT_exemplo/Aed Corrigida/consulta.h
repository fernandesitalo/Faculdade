#ifndef CONSULTA_H
#define CONSULTA_H
#include "indice.h"
#include "games.h"
#include <fstream>
using namespace std;
#include <iostream>
#include "lig.h"
#include "arquivo.h"
#include <cstring>


#include <QDialog>

namespace Ui {
class consulta;
}

class consulta : public QDialog
{
    Q_OBJECT

public:
    explicit consulta(QWidget *parent = 0);
    ~consulta();

private slots:
    void on_procurar_clicked();

    void on_sair_clicked();

private:
    Ui::consulta *ui;
};

#endif // CONSULTA_H
