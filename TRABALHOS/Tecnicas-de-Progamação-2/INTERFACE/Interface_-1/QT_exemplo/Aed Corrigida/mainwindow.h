#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "games.h"
#include "venda.h"
#include "estoque.h"

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_venda_clicked();

    void on_Consulta_clicked();

    void on_Consulta_3_clicked();

private:
    Ui::MainWindow *ui;
    games *jogo;
};

#endif // MAINWINDOW_H
