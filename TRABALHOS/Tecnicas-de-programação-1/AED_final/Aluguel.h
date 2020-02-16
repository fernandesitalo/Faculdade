#ifndef ALUGUEL_H
#define ALUGUEL_H

#include <QDialog>

namespace Ui {
class Aluguel;
}

class Aluguel : public QDialog
{
    Q_OBJECT

public:
    explicit Aluguel(QWidget *parent = 0);
    ~Aluguel();

private:
    Ui::Aluguel *ui;
};

#endif // ALUGUEL_H
