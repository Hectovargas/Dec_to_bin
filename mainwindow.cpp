#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    num_bin = new int();
    residuo = new int();
    binario = new QString();
    decimal = new int();
    valor = new int();
    digito = new QChar();
    pos = new int();
    operacion = new bool();
}

MainWindow::~MainWindow()
{
    decimal = NULL;
    delete decimal;
    valor = NULL;
    delete valor;
    num_bin = NULL;
    delete num_bin;
    digito = NULL;
    delete digito;
    num_bin = NULL;
    delete num_bin;
    pos = NULL;
    delete pos;
    binario = NULL;
    delete binario;
    operacion = NULL;
    delete operacion;
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if( index == 0){
        ui->label_3->setText("Binario a Decimal");
        ui->label->setText("Binario:");
        ui->label_2->setText("Decimal:");
        *operacion = false;
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
    if( index == 1){
        ui->label_3->setText("Decimal a Binario");
        ui->label->setText("Decimal:");
        ui->label_2->setText("Binario:");
        *operacion = true;
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
}

void MainWindow::Bin_Dec(){
    *decimal = 0;
    *pos = binario->length() - 1;

    while (true){
        *digito = binario->at(*pos);
        *valor = digito->digitValue();
        *decimal += *valor * pow(2, (binario->length() - 1 - *pos));
        (*pos)--;
        if(*pos<0){break;}
    }

}


void MainWindow::Dec_Bin()
{
    *num_bin = *decimal;
    *binario = "";

    if(*num_bin == 0) {
        *binario = "0";
        return;
    }

    while(*num_bin > 0){
        *residuo = *num_bin % 2;
        *num_bin = *num_bin / 2;
        *binario = QString::number(*residuo) + *binario;
    }
}

bool MainWindow::esBinarioValido(const QString &texto) {
    for (int i = 0; i < texto.length(); ++i) {
        QChar c = texto.at(i);
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}


void MainWindow::on_pushButton_clicked()
{
    QString texto = ui->lineEdit->text();

    if(*operacion == false){

        if (!esBinarioValido(texto)) {
            QMessageBox::warning(this, "Error", "Entrada binaria no valida.\nSolo use digitos 0 y 1.");
            return;
        }

        delete binario;
        binario = new QString(texto);
        Bin_Dec();
        ui->lineEdit_2->setText(QString::number(*decimal));

    }else{

        delete binario;
        binario = new QString("");
        bool esNumero;
        int numero = texto.toInt(&esNumero);

        if(!esNumero) {
            QMessageBox::warning(this, "Error", "Debe ingresar un numero decimal valido.");
            return;
        }
        *decimal = numero;
        Dec_Bin();
        ui->lineEdit_2->setText(*binario);

    }
}

