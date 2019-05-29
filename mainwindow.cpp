#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLCDNumber>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setWindowTitle("CALCULADORA SUMA HUEVOS");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::leertecla(double valtecla)
{
    if(mod==0)
    {
        n1 = (n1*10)+valtecla;
    }
    else
    {
        if(n3==0.0)
        {
            n3=valtecla/ pow (10,pot);
            pot++;
        }
        else
        {
            n3 = (valtecla/ pow (10,pot));
            pot++;
        }

    }
    n1=n1+n3;
    ui->Display->display(n1);
}

void MainWindow::guardarteclas()
{
    if (n2 == 0.0)
    {
        Var_a = n1;
        n1 = 0;
        n2++;
    }
    else {
        Var_a = resultado;
        n1 = 0;
    }
}

void MainWindow::on_btn_0_clicked()
{
    leertecla(0);
}

void MainWindow::on_btn_1_clicked()
{
    leertecla(1);
}

void MainWindow::on_btn_2_clicked()
{
    leertecla(2);
}

void MainWindow::on_btn_3_clicked()
{
    leertecla(3);
}

void MainWindow::on_btn_4_clicked()
{
    leertecla(4);
}

void MainWindow::on_btn_5_clicked()
{
    leertecla(5);
}

void MainWindow::on_btn_6_clicked()
{
    leertecla(6);
}

void MainWindow::on_btn_7_clicked()
{
    leertecla(7);
}

void MainWindow::on_btn_8_clicked()
{
    leertecla(8);
}

void MainWindow::on_btn_9_clicked()
{
    leertecla(9);
}

void MainWindow::on_btn_borrar_clicked()
{
    ui->Display->display(0);
    n1=0;
    n2=0;
    suma=0;
    resta=0;
    multiplica=0;
    divide=0;
    resultado=0;
    opc=0;
    Var_a=0;
    Var_b=0;
    n3=0;
    mod=0;
    pot=1;
}

void MainWindow::on_suma_clicked()
{
    guardarteclas();
    opc=1;
    n3=0;
    pot=1;
    mod=0;
}

void MainWindow::on_resta_clicked()
{
   guardarteclas();
   opc=2;
   n3=0;
   pot=1;
   mod=0;
}

void MainWindow::on_multiplica_clicked()
{
    guardarteclas();
    opc=3;
    n3=0;
    pot=1;
    mod=0;
}

void MainWindow::on_divide_clicked()
{
    guardarteclas();
    opc=4;
    n3=0;
    pot=1;
    mod=0;
}

void MainWindow::on_igual_clicked()
{
    switch (opc)
    {
        case 1:
            Var_b=n1;
            suma=Var_a+Var_b;
            resultado=suma;
            ui->Display->display(resultado);
             QMessageBox::about(this,"RESULTADO", "La operacion fue una Suma: \n"
                                                  "El resultado fue: " + QString::number(resultado));
            n1=0;
            opc=0;
            mod=0;

        break;

        case 2:
            Var_b=n1;
            resta=Var_a-Var_b;
            resultado=resta;
            ui->Display->display(resultado);
            QMessageBox::about(this,"RESULTADO", "La operacion fue una Resta: \n"
                                                 "El resultado fue: " + QString::number(resultado));
            n1=0;
            opc=0;
            mod=0;
        break;

        case 3:
            Var_b=n1;
            multiplica=Var_a*Var_b;
            resultado=multiplica;
            ui->Display->display(resultado);
            QMessageBox::about(this,"RESULTADO", "La operacion fue una Multiplicacion: \n"
                                                 "El resultado fue: " + QString::number(resultado));
            n1=0;
            opc=0;
            mod=0;
        break;

        case 4:

        Var_b=n1;
        if (Var_b == 0.0)
        {
            ui->Display->display("ERROR");
            QMessageBox::about(this,"RESULTADO", "La operacion fue una Division: \n"
                                                 "No puede dividir entre 0 = ERROR");
            //valtecla = 0;         //n1 se carga con 0
            n1=0;
            n2=0;
            suma=0;
            resta=0;
            multiplica=0;
            divide=0;
            resultado=0;
            opc=0;
            Var_a=0;
            Var_b=0;
            mod=0;
            break;
        }
        else {

            divide=Var_a/Var_b;
            resultado=divide;
            ui->Display->display(resultado);
            QMessageBox::about(this,"RESULTADO", "La operacion fue una División: \n"
                                                 "El resultado fue: " + QString::number(resultado));
            n1=0;
            opc=0;
            mod=0;
            break;
        }

    }
}

void MainWindow::on_btn_punto_clicked()
{
    mod =1;
}
