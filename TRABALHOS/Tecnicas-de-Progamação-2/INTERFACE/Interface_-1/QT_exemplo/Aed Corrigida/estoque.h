#ifndef ESTOQUE_H
#define ESTOQUE_H
#include "indice.h"
#include <QDialog>
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class estoque;
}

class estoque : public QDialog
{
    Q_OBJECT

public:
    explicit estoque(QWidget *parent = 0);
    ~estoque();

    void listv();
    void listv(char *a);
private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_bot_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::estoque *ui;
};

#endif // ESTOQUE_H
