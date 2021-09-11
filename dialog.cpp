#include "dialog.h"
#include "ui_dialog.h"
#include  <QMessageBox>
#include  <newwindow.h>
#include  <QTimeEdit>
#include <global.h>
#include  <dop.h>
#include <QFile>
#include <QDate>
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    MyTab.inputy_two();
   int idStr;
    global one;
        idStr = MyTab.numberstr(one.change1);
        QString dnm = MyTab.getitem_2(idStr, 0);
        if (dnm == "1")
        {ui->checkD->setChecked(true);
            ui->lineEditNameD->setText(MyTab.getitem_2(idStr, 1));
        }
            else  if (dnm == "2")
        {ui->checkN->setChecked(true);
             ui->lineEditNameN->setText(MyTab.getitem_2(idStr, 1));
        }
            else if (dnm == "3")
        {ui->checkM->setChecked(true);
             ui->lineEditNameM->setText(MyTab.getitem_2(idStr, 1));
        }

       ui->lineEditName->setText(MyTab.getitem_2(idStr, 3));
       ui->textEdit->setText(MyTab.getitem_2(idStr, 4));
       dnm = MyTab.getitem_2(idStr, 5);
       if (dnm == "1")
       {ui->opov->setChecked(true);}
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_checkD_stateChanged(int arg1)
{
    if (ui->checkD->isChecked() == true)
    {
     //ui->checkD->setChecked(true);
       ui->checkN->setChecked(false);
         ui->checkM->setChecked(false);
    }



}

void Dialog::on_checkN_stateChanged(int arg1)
{
    if (ui->checkN->isChecked() == true)
    {

       ui->checkD->setChecked(false);
         ui->checkM->setChecked(false);
    }
}

void Dialog::on_checkM_stateChanged(int arg1)
{
    if (ui->checkM->isChecked() == true)
    {

       ui->checkN->setChecked(false);
         ui->checkD->setChecked(false);
    }
}

void Dialog::on_pushButton_clicked()
{
    QString d, t;
    QString dat;
    QString op;
    int id = 0;
    //проверка первого блока, какая задача, на день, неделю или месяц
     if (ui->checkD->isChecked() == true)
     {

         d = ui-> dateEditD->date().toString("yyyy.MM.dd");

         t = ui->timeEdit->time().toString("H:mm");
         dat = d+" "+t;
        id = 1;
       // QMessageBox::critical(0, "Ошибка",d+" "+t);
     }
     else
    if (ui->checkN->isChecked() == true)
    {

        d = ui-> dateEditN->date().toString("yyyy.MM.dd");
        dat = d;
        id = 2;
       //QMessageBox::critical(0, "Ошибка",d);
    }
     else
        if (ui->checkM->isChecked() == true)
        {
            d = ui-> MdateEdit->date().toString("yyyy.MM");
            dat = d;
            id = 3;
          // QMessageBox::critical(0, "Ошибка",d);
        }
        else{
            QMessageBox::critical(0, "Ошибка", "Выберите один из чекбоксов");
            return;
        }


     //блок с оповещениями

    if (ui->opov->isChecked() == false)
        op = "0";
    else op = "1";
    global one;
    int idStr = MyTab.numberstr(one.change1);
    MyTab.Setitem_2(idStr, 0, QString::number(id));
    MyTab.Setitem_2(idStr, 1, dat);
MyTab.Setitem_2(idStr, 3, ui->lineEditName->text());
    MyTab.Setitem_2(idStr, 4, ui->textEdit->text());
    MyTab.Setitem_2(idStr, 5, op);

MyTab.outputy_2();
//global one;
//MyTab.delstr(one.change1);
 //  MyTab.setitem_2(id, dat, ui->lineEditName->text(),  ui->textEdit->text(), op);

       ui->checkM->setChecked(false);
    ui->checkN->setChecked(false);
      ui->checkD->setChecked(false);
      ui->opov->setChecked(false);
        ui->lineEditName->clear();
      ui->textEdit->clear();
        ui->lineEditNameD->clear();
          ui->lineEditNameN->clear();
      ui->lineEditNameM->clear();
//MyTab.outputy_2();
//this->close();  //закрываем это окно
emit newzz(); //пода

     this->close();  //закрываем это окно

}
