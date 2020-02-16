#include "venda.h"
#include "ui_venda.h"
#include "indice.h"
#include "arquivo.h"
#include <QTableWidgetItem>
#include <QStringList>
#include <QMessageBox>

venda::venda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::venda)
{
    ui->setupUi(this);
    soma =0;
    qtd = 0;
    p=0;
}

venda::~venda()
{
    delete ui;
}

void venda::on_fim_clicked()
{
    arquivo c;
    indice a;
    int i;
    char nome[30];

    for(i=0;i<p;i++)
    {
        v[i].getnome(nome);
        c.sobrescrever(&v[i],a.getposic(nome));
    }

    this->hide();
}

void venda::on_adicionar_clicked()
{
    try
        {
            indice a;
            games b;
            arquivo c;
            QMessageBox show;
            int d;
            char nome[30];
            strcpy(nome,ui->nomeedit->text().toStdString().c_str());
            d = a.getposic(nome);
            if(d >= 0)
            {
                c.ler(&b,d);
                if(b.getqtd() >= ui->qtdedit->text().toInt())
                {
                     //this->produtos[p]=d;
                     ui->tableWidget->insertRow(qtd);
                     QTableWidgetItem *item1 = new QTableWidgetItem(nome);
                     QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(ui->qtdedit->text().toInt()));
                     QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(b.getvalor()*ui->qtdedit->text().toInt()));
                     soma = soma + b.getvalor()*ui->qtdedit->text().toInt();
                     ui->tableWidget->setItem(qtd,0,item1);
                     ui->tableWidget->setItem(qtd,1,item2);
                     ui->tableWidget->setItem(qtd,2,item3);
                     b.setqtd(b.getqtd()-ui->qtdedit->text().toInt());
                     ui->lineEdit->setText(QString::number(soma));
                     b.setqtd(b.getqtd()-ui->qtdedit->text().toInt());
                     v[p] = b;
                     p++;
                }
                else
                {
                    show.information(this," "," Quandidade insuficiente ");
                }
            }
            else
            {
                show.warning(this,"","Game nao encontrado");
            }
            qtd++;
    }
    catch(const char v)
    {
        QMessageBox::warning(this,"","Erro de memoria");

    }
    catch(...)
    {
        QMessageBox::warning(this,"","Quantidate de games insuficiente");
    }
}


