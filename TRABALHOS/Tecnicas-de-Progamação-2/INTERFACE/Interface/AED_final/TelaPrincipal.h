#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include <QHBoxLayout>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();

private slots:
    void on_CadrastrarClienteButton_clicked();

    void on_AtualizarClienteButton_clicked();

    void on_LixeiraButton_clicked();

    void on_CadrastroEquipamentosButton_clicked();

    void on_AtualizarEquipamentoButton_clicked();

    void on_AlugarButton_clicked();

    void on_AlugarButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::TelaPrincipal *ui;
};

#endif // TELAPRINCIPAL_H
