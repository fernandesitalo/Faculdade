#ifndef CADASTRO_H
#define CADASTRO_H
#include "games.h"


#include <QDialog>

namespace Ui {
class cadastro;
}

class cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit cadastro(QWidget *parent = 0);
    ~cadastro();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::cadastro *ui;
    games * jogo;
};

#endif // CADASTRO_H
