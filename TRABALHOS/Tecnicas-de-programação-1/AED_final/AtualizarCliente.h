#ifndef ATUALIZARCLIENTE_H
#define ATUALIZARCLIENTE_H

#include <QDialog>
#include "Cliente.h"
#include <QListWidgetItem>

namespace Ui {
class AtualizarCliente;
}

class AtualizarCliente : public QDialog
{
    Q_OBJECT

public:
    explicit AtualizarCliente(QWidget *parent = 0);
    ~AtualizarCliente();

private slots:
    void on_atualizarButton_clicked(); // VAI ATUALIZAR A PORRA TODA
    // SE O CARA ATUALIZAR O NOME, DELETAR O CADRASTRO ANTIGO, E METER O LOKO CRIANDO UM NOVO CADRAS

    void on_listWidget_itemClicked(QListWidgetItem *item);   // QUANDO SE CLICA EM UM ITEM, PRECISAMOS SETA-LO NOS LINES EDITS DA VIDA

    void exibeCliente(Cliente* P);   // EXIBE O CLIENTE P NA TELA

    void on_comboBox_2_activated(const QString &arg1); // SELECIONA O QUE SERA INSERIDO NA LISTA, FACILITA A BUSCA

    void ListaTodos();   // insere todos clientes na lista

    void listaLetra(char caracter);     // insere somente os nomes que começam com a letra definida

    void on_deletarButton_clicked();

    void on_cancelarButton_clicked();

private:
    Ui::AtualizarCliente *ui;
    Cliente *at; // PONTEIRO CLIENTE, UM OBJ AUXILIAR
    int PosicaoNoArquivo; // POSICAO DO NOME ANTIGO NO ARQUIVO, SE O NOME NAO MUDAR A GENTE METE O LOKO E GRAVA LA EM CIMA MESMO

    char NomeOriginal[80];
    /// CASO CONTRARIO, VAMO TER QUE DELETAR E CRIAR UM NOVO CADRASTRO MESMO!!!

    /// NO CASO MARCO O CADRASTRO COMO LIXO, E CRIO UM NOVO CADRASTRO NA BOA....

    ///  NO FIM, NO DESTRUTOR DA PORRA TODA, A GENTE DELETA DE VERDADE!!!!!!! SEGUE O MESMO RACIOCINO ....
};

#endif // ATUALIZARCLIENTE_H
