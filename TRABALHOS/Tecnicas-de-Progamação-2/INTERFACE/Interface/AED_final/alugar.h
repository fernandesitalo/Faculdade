#ifndef ALUGAR_H
#define ALUGAR_H

#include <QDialog>

namespace Ui {
class Alugar;
}

class Alugar : public QDialog
{
    Q_OBJECT

public:
    explicit Alugar(QWidget *parent = 0);
    ~Alugar();

private:
    Ui::Alugar *ui;
};

#endif // ALUGAR_H
