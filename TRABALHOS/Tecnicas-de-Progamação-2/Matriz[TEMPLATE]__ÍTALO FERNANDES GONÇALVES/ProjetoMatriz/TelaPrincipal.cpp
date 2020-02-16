#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include <QMessageBox>
#include <QFont>
#include <QLabel>
#include <QPalette>
#include <QInputDialog>

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    A = 0;
    B = 0;
    ui->pushButton_DeletarMatA->setEnabled(false);
    ui->pushButton_DeletarMatB->setEnabled(false);
    ui->pushButton_ApagarResultado->setEnabled(false);
    InfMatA();
    InfMatB();
    InfMatC();
    P = -1;
    ui->radioButtonModeDinamic->setChecked(true);

}

TelaPrincipal::~TelaPrincipal()
{
    ui->tableWidgetMatrizA->clear();
    ui->tableWidgetMatrizB->clear();
    ui->tableWidgetMatrizC->clear();

    if(A) delete A;
    if(B) delete B;
    delete ui;
}

void TelaPrincipal::MostrarResultado(const MAT::Matriz<int> * const R) const
{
    ui->tableWidgetMatrizC->clear();
    ui->tableWidgetMatrizC->setColumnCount(0);
    ui->tableWidgetMatrizC->setRowCount(0);


    int linha = R->getQuantidadeDeLinhas();
    int coluna = R->getQuantidadeDeColunas();

    ui->tableWidgetMatrizC->setColumnCount(coluna);
    ui->tableWidgetMatrizC->setRowCount(linha);
    ui->tableWidgetMatrizC->gridStyle();
    ui->tableWidgetMatrizC->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableWidgetMatrizC->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetMatrizC->verticalHeader()->setResizeMode(QHeaderView::Stretch);

    //ui->tableWidgetMatrizC->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidgetMatrizC->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for(int i = 0 ; i < linha ; ++i){
        for(int j = 0 ; j < coluna ; ++j){
            ui->tableWidgetMatrizC->setItem(i,j,new QTableWidgetItem(QString::number(R->getElemento(i,j))));
        }
    }
}

void TelaPrincipal::AnaliseMat_X(const MAT::Matriz<int> * const X, int Matriz_X) const
{
    switch(Matriz_X){
    case 1:
        setColorLabel(ui->label_TriangularSuperiorMatA,X->ETriangularSuperior());
        setColorLabel(ui->label_TriangularInferiorMatA,X->ETriangularInferior());
        setColorLabel(ui->label_SimetricaMatA,X->ESimetrica());
        setColorLabel(ui->label_IdentidadeMatA,X->EIdentidade());
        setColorLabel(ui->label_OrtogonalMatA,X->EOrtogonal());
        setColorLabel(ui->label_PermutacaoMatA,X->EPermutada_1());
        break;
    case 2:
        setColorLabel(ui->label_TriangularSuperiorMatB,X->ETriangularSuperior());
        setColorLabel(ui->label_TriangularInferiorMatB,X->ETriangularInferior());
        setColorLabel(ui->label_SimetricaMatB,X->ESimetrica());
        setColorLabel(ui->label_IdentidadeMatB,X->EIdentidade());
        setColorLabel(ui->label_OrtogonalMatB,X->EOrtogonal());
        setColorLabel(ui->label_PermutacaoMatB,X->EPermutada_1());
        break;
    case 3:
        setColorLabel(ui->label_TriangularSuperiorMatC,X->ETriangularSuperior());
        setColorLabel(ui->label_TriangularInferiorMatC,X->ETriangularInferior());
        setColorLabel(ui->label_SimetricaMatC,X->ESimetrica());
        setColorLabel(ui->label_IdentidadeMatC,X->EIdentidade());
        setColorLabel(ui->label_OrtogonalMatC,X->EOrtogonal());
        setColorLabel(ui->label_PermutacaoMatC,X->EPermutada_1());
        break;
    }
}


void TelaPrincipal::on_comboBox_Operacoes_activated(const QString &arg1)
{
    try{
        P = 0;
        int index = ui->comboBox_Operacoes->currentIndex();
        QString texto = arg1;
        MAT::Matriz<int>* C;
        switch(index){
        case 0:
            break;
        case 1: ///A+B
            if(!A || !B) throw QString("Parece que vc nao criou as duas matrizes...Crie e tente a operação novamente!");
            C = * A + B;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 2:///A-B
            if(!A || !B) throw QString("Parece que vc nao criou as duas matrizes...Crie e tente a operação novamente!");
            C = * A - B;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 3:///B-A
            if(!A || !B) throw QString("Parece que vc nao criou as duas matrizes...Crie e tente a operação novamente!");
            C = * B - A;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 4:///AxB
            if(!A || !B) throw QString("Parece que vc nao criou as duas matrizes...Crie e tente a operação novamente!");
            C = * A * B;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 5:///BxA
            if(!A || !B) throw QString("Parece que vc nao criou as duas matrizes...Crie e tente a operação novamente!");
            C = * B * A;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 6:///matrizA x constante
            if(!A) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            P = QInputDialog::getInt(this,"Constante: ","Digite a Constante:");
            texto = " A x "+QString::number(P); //MOSTRAR QUAL RESULTADO ESTA SENDO MOSTRADO
            C = A->MultipicaPorUmNumero(P);
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 7: ///matrizB x constante
            if(!B) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            P = QInputDialog::getInt(this,"Constante: ","Digite a Constante:");
            texto = " B x "+QString::number(P);
            C = B->MultipicaPorUmNumero(P);
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 8: /// A^pontencia
            if(!A) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            P  = QInputDialog::getInt(this,"Expoente: ","Digite o Expoente:");
            texto = " A^"+QString::number(P);
            C = A->Potencia(P);
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 9:///B^POTENCIA
            if(!B) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            P  = QInputDialog::getInt(this,"Expoente: ","Digite o Expoente:");
            texto = " B^"+QString::number(P);
            C = B->Potencia(P);
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 10: /// TRANSPOSTA DE A
            if(!A) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            texto = " A^t";
            C = A->Transposta();
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 11: /// TRANSPOSTA DE B
            if(!B) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            texto = " B^t";
            C = B->Transposta();
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 12: /// IGUALDADE ENTRE MATRIZES
            if(!A || !B) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            if(A == B) QMessageBox::information(this,"RESULTADO","As Matrizes são iguais!");
            else QMessageBox::information(this,"RESULTADO","As Matrizes não são iguais!");
            break;
        case 13: /// DIFERENCA ENTRE MATRIZES
            if(!A || !B) throw QString("Primeiro Crie uma Matriz, depois tente execultar Operações!");
            if(A != B) QMessageBox::information(this,"RESULTADO","As Matrizes são diferentes!");
            else QMessageBox::information(this,"RESULTADO","As Matrizes não são diferentes!");
            break;
        }
        ui->pushButton_ApagarResultado->setEnabled(true);
        if(index != 0 && index < 12)
            ui->label_MatrizResultante->setText("MATRIZ RESULTANTE"+texto);
    }
    catch(QString &erro){
        QMessageBox::information(this,"Atenção!",erro);
    }
//    catch(...){
  //      QMessageBox::information(this,"OPS!","Houve um erro!");
    //}
}
void TelaPrincipal::setColorLabel(QLabel *L, bool comand) const
{
    if(comand){
        QPalette CorDoTexto = L->palette();
        CorDoTexto.setColor(L->foregroundRole(),Qt::blue);
        QFont FonteNegrito;

        FonteNegrito.setBold(true);
        FonteNegrito.setPointSizeF(10);
        L->setFont(FonteNegrito);
        L->setPalette(CorDoTexto);
        L->setEnabled(true);
        return;
    }

    QLabel a;
    QFont FonteNormal;
    FonteNormal.setPointSizeF(10);
    L->setFont(FonteNormal);
    L->setPalette(a.palette());
    L->setEnabled(false);
}
void TelaPrincipal::on_pushButtonCriarMatrizA_clicked()
{
    int linha = ui->comboBox_LinhaMatA->currentIndex();
    int coluna = ui->comboBox_ColunaMatA->currentIndex();

    try{
        if(!linha || !coluna)
            throw QString("Defina a quantidade de Linhas e Colunas da Matriz A");

        A = new MAT::Matriz<int>(linha,coluna);

        ui->comboBox_LinhaMatA->setEnabled(false);
        ui->comboBox_ColunaMatA->setEnabled(false);
        ui->pushButton_DeletarMatA->setEnabled(true);
        ui->pushButtonCriarMatrizA->setEnabled(false);

        ui->tableWidgetMatrizA->setColumnCount(coluna);
        ui->tableWidgetMatrizA->setRowCount(linha);
        ui->tableWidgetMatrizA->gridStyle();
        ui->tableWidgetMatrizA->setSelectionBehavior(QAbstractItemView::SelectItems);
        ui->tableWidgetMatrizA->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
        ui->tableWidgetMatrizA->verticalHeader()->setResizeMode(QHeaderView::Stretch);

        //ui->tableWidgetMatrizA->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //ui->tableWidgetMatrizA->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    catch(QString &erro){
        QMessageBox::critical(this,"Atenção!",erro);
    }
}

void TelaPrincipal::on_pushButton_CriarMatB_clicked()
{
    int linha = ui->comboBox_LinhaMatB->currentIndex();
    int coluna = ui->comboBox_ColunaMatB->currentIndex();

    try{
        if(!linha || !coluna)
            throw QString("Defina a quantidade de Linhas e Colunas da Matriz A");

        B = new MAT::Matriz<int>(linha,coluna);

        ui->comboBox_LinhaMatB->setEnabled(false);
        ui->comboBox_ColunaMatB->setEnabled(false);
        ui->pushButton_DeletarMatB->setEnabled(true);
        ui->pushButton_CriarMatB->setEnabled(false);

        ui->tableWidgetMatrizB->setColumnCount(coluna);
        ui->tableWidgetMatrizB->setRowCount(linha);
        ui->tableWidgetMatrizB->gridStyle();
        ui->tableWidgetMatrizB->setSelectionBehavior(QAbstractItemView::SelectItems);
        ui->tableWidgetMatrizB->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
        ui->tableWidgetMatrizB->verticalHeader()->setResizeMode(QHeaderView::Stretch);

       // ui->tableWidgetMatrizB->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //ui->tableWidgetMatrizB->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
    catch(QString &erro){
        QMessageBox::critical(this,"Atenção!",erro);
    }
}

void TelaPrincipal::on_pushButton_DeletarMatA_clicked()
{
    if(A){ /// SO VAI DELETAR ALGUMA COISA SE EXISTIR ALGUMA COISA PARA DELETAR
        delete A; /// DELETA O QUE ESTA APONTADO POR 'A'
        A = 0;

        ui->pushButtonCriarMatrizA->setEnabled(true);
        ui->comboBox_ColunaMatA->setEnabled(true);
        ui->comboBox_LinhaMatA->setEnabled(true);

        ui->tableWidgetMatrizA->clear();
        ui->tableWidgetMatrizA->setColumnCount(0);
        ui->tableWidgetMatrizA->setRowCount(0);
        ui->comboBox_LinhaMatA->setCurrentIndex(0);
        ui->comboBox_ColunaMatA->setCurrentIndex(0);

        ui->pushButton_DeletarMatA->setEnabled(false);

        InfMatA();
        InfMatC();

        int aux = ui->comboBox_Operacoes->currentIndex();
        if(aux != 7 && aux != 9 && aux != 11){/// inicializa as informacoes da matriz C somente se a operacao envolvida
            InfMatC();                           /// depende de B, isto é, depende somente de A....
            ui->tableWidgetMatrizC->clear();
            ui->tableWidgetMatrizC->setRowCount(0);
            ui->tableWidgetMatrizC->setColumnCount(0);
            ui->pushButton_ApagarResultado->setEnabled(false);
            ui->label_MatrizResultante->setText("MATRIZ RESULTANTE");
            ui->comboBox_Operacoes->setCurrentIndex(0);
        }
    }
}

void TelaPrincipal::on_pushButton_DeletarMatB_clicked()
{
    if(B){
        delete B;
        B = 0; // apontar para NULL... motivos de segurança e Logica do progama

        ui->pushButton_CriarMatB->setEnabled(true);
        ui->comboBox_ColunaMatB->setEnabled(true);
        ui->comboBox_LinhaMatB->setEnabled(true);

        ui->tableWidgetMatrizB->clear();
        ui->tableWidgetMatrizB->setColumnCount(0);
        ui->tableWidgetMatrizB->setRowCount(0);
        ui->comboBox_LinhaMatB->setCurrentIndex(0);
        ui->comboBox_ColunaMatB->setCurrentIndex(0);
        InfMatB();

        ui->pushButton_DeletarMatB->setEnabled(false);

        int aux = ui->comboBox_Operacoes->currentIndex();
        if(aux != 6 && aux != 8 && aux != 10){/// reinicializa as informacoes da matriz C somente se a operacao envolvida
            InfMatC();                           /// depende de B, isto é, depende somente de A....
            ui->tableWidgetMatrizC->clear();
            ui->tableWidgetMatrizC->setRowCount(0);
            ui->tableWidgetMatrizC->setColumnCount(0);
            ui->pushButton_ApagarResultado->setEnabled(false);
            ui->label_MatrizResultante->setText("MATRIZ RESULTANTE");
            ui->comboBox_Operacoes->setCurrentIndex(0);
        }
    }
}


void TelaPrincipal::on_tableWidgetMatrizB_itemChanged(QTableWidgetItem *item)
{
    try{
        if(item->text().toInt() == 0 && item->text() != "0"){
            item->setText("0");
        }

        B->setElemento(item->text().toInt(),item->row(),item->column());
        AnaliseMat_X(B,2);

        if(ui->comboBox_Operacoes->currentIndex() != 0 && ui->radioButtonModeDinamic->isChecked()){
            on_comboBox_Operacoes_activated(ui->comboBox_Operacoes->currentIndex());
        }
    }
    catch(QString &erro){
        QMessageBox::critical(this,"Atenção",erro);
    }
    catch(...){
        QMessageBox::critical(this,"Atenção","Fatel error 404");
    }
}

void TelaPrincipal::on_tableWidgetMatrizA_itemChanged(QTableWidgetItem *item)
{
    /// SETA O ELEMENTO QUE ESTA SENDO MODIFICADO EM DETERMINADO MOMENTO.
    try{
        if(item->text().toInt() == 0 && item->text() != "0"){
            item->setText("0");
        }
        A->setElemento(item->text().toInt(),item->row(),item->column());
        AnaliseMat_X(A,1);

        if(ui->comboBox_Operacoes->currentIndex() != 0 && ui->radioButtonModeDinamic->isChecked()){
            on_comboBox_Operacoes_activated(ui->comboBox_Operacoes->currentIndex());
        }
    }
    catch(QString &erro){
        QMessageBox::critical(this,"Atenção",erro);
    }
    catch(...){
        QMessageBox::critical(this,"Atenção","Fatel error 404");
    }
}

void TelaPrincipal::on_pushButton_ApagarResultado_clicked()
{
    ui->tableWidgetMatrizC->clear();
    ui->tableWidgetMatrizC->setColumnCount(0);
    ui->tableWidgetMatrizC->setRowCount(0);
    ui->pushButton_ApagarResultado->setEnabled(false);
    InfMatC();
    ui->label_MatrizResultante->setText("MATRIZ RESULTANTE");
    ui->comboBox_Operacoes->setCurrentIndex(0);
}

void TelaPrincipal::on_comboBox_LinhaMatA_activated(int index)
{
    ui->comboBox_ColunaMatA->setCurrentIndex(index);
}

void TelaPrincipal::on_comboBox_LinhaMatB_activated(int index)
{
    ui->comboBox_ColunaMatB->setCurrentIndex(index);
}

void TelaPrincipal::InfMatA() const
{
    setColorLabel(ui->label_TriangularSuperiorMatA,false);
    setColorLabel(ui->label_TriangularInferiorMatA,false);
    setColorLabel(ui->label_SimetricaMatA,false);
    setColorLabel(ui->label_IdentidadeMatA,false);
    setColorLabel(ui->label_OrtogonalMatA,false);
    setColorLabel(ui->label_PermutacaoMatA,false);
}

void TelaPrincipal::InfMatB() const
{
    setColorLabel(ui->label_TriangularSuperiorMatB,false);
    setColorLabel(ui->label_TriangularInferiorMatB,false);
    setColorLabel(ui->label_SimetricaMatB,false);
    setColorLabel(ui->label_IdentidadeMatB,false);
    setColorLabel(ui->label_OrtogonalMatB,false);
    setColorLabel(ui->label_PermutacaoMatB,false);
}

void TelaPrincipal::InfMatC() const
{
    setColorLabel(ui->label_TriangularSuperiorMatC,false);
    setColorLabel(ui->label_TriangularInferiorMatC,false);
    setColorLabel(ui->label_SimetricaMatC,false);
    setColorLabel(ui->label_IdentidadeMatC,false);
    setColorLabel(ui->label_OrtogonalMatC,false);
    setColorLabel(ui->label_PermutacaoMatC,false);
}



void TelaPrincipal::on_comboBox_Operacoes_activated(int index) //// força o pedido de um calculo conforme o que modo dinamico
{
    try{
        MAT::Matriz<int>* C;
        switch(index){
        case 0:
            break;
        case 1: ///A+B
            if(!A || !B) break;
            C = * A + B;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 2:///A-B
            if(!A || !B) break;
            C = * A - B;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 3:///B-A
            if(!A || !B) break;
            C = * B - A;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 4:///AxB
            if(!A || !B) break;
            C = * A * B;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 5:///BxA
            if(!A || !B) break;
            C = * B * A;
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 10: /// TRANSPOSTA DE A
            if(!A) break;
            C = A->Transposta();
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        case 11: /// TRANSPOSTA DE B
            if(!B) break;
            C = B->Transposta();
            MostrarResultado(C);
            AnaliseMat_X(C,3);
            delete C;
            break;
        }
    }
    catch(...){
    }
}

void TelaPrincipal::on_radioButtonModeDinamic_clicked(bool checked)
{
    if(checked && ui->comboBox_Operacoes->currentIndex() != 0){
        on_comboBox_Operacoes_activated(ui->comboBox_Operacoes->currentIndex());
    }
}
