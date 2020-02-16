#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pessoa.h"
#include "Lote.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*void on_NOME_returnPressed();

    void on_EMAIL_returnPressed();

    void on_LARGURA_returnPressed();

    void on_FRENTE_returnPressed();*/

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Pessoa *p;
    Lote *l;
};

#endif // MAINWINDOW_H
