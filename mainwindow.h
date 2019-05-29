#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool smallDecimalPoint() const;
    void setSmallDecimalPoint(bool);

private slots:
    void on_btn_0_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_borrar_clicked();
    void on_suma_clicked();

    void on_igual_clicked();
    void on_resta_clicked();
    void on_multiplica_clicked();
    void on_divide_clicked();

    void leertecla(double valtecla);
    void guardarteclas();

    void on_btn_punto_clicked();

private:
    Ui::MainWindow *ui;

private:
    double n1 = 0;
    double n2 = 0;
    double suma = 0;
    double resta = 0;
    double multiplica = 0;
    double divide = 0;
    int opc = 0;
    double resultado =0;
    double resultadom = 1;
    double Var_a=0;
    double Var_b=0;
    double n3=0;
    int mod =0;
    int pot=1;
};

#endif // MAINWINDOW_H
