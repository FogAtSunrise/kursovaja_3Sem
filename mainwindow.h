#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <newwindow.h>
#include "dop.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  //static int glob;

  Dop MyTab;
  static QString ht;
private slots:
    void on_VhodButton_clicked();

    void on_pushButtonReg_clicked();

    void on_VhodButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButtonReg_2_clicked();

private:
    Ui::MainWindow *ui;
    //Второе окно
    NewWindow *window;

};
#endif // MAINWINDOW_H
