#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Dec_Bin();
    void Bin_Dec();
    bool esBinarioValido(const QString &texto);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int *num_bin;
    int *residuo;
    int *decimal;
    int *valor;
    QChar *digito;
    int *pos;
    QString *binario;
    bool *operacion; //0 binaria y 1 decimsl

};
#endif // MAINWINDOW_H
