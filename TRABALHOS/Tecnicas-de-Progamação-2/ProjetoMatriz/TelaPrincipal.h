#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include "Matriz.h"
#include <QTableWidgetItem>
#include <QLabel>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();
    void InfMatA()const;
    void InfMatB()const;
    void InfMatC()const;
    void MostrarResultado(MAT::Matriz const * const R)const;
    void AnaliseMat_X(MAT::Matriz const * const X,int Matriz_X)const;
    void setColorLabel(QLabel * L, bool comand)const;

private slots:    
    void on_pushButton_CriarMatB_clicked();

    void on_pushButton_DeletarMatA_clicked();

    void on_pushButton_DeletarMatB_clicked();

    void on_tableWidgetMatrizA_itemChanged(QTableWidgetItem *item);

    void on_pushButtonCriarMatrizA_clicked();

    void on_comboBox_Operacoes_activated(int index);

    void on_tableWidgetMatrizB_itemChanged(QTableWidgetItem *item);

    void on_pushButton_ApagarResultado_clicked();

    void on_comboBox_LinhaMatA_activated(int index);

    void on_comboBox_LinhaMatB_activated(int index);

private:
    Ui::TelaPrincipal *ui;
    MAT::Matriz *A;
    MAT::Matriz *B;
};

#endif // TELAPRINCIPAL_H
