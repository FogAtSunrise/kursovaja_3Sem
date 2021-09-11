#include "addnew.h"
#include "ui_addnew.h"
#include  <QMessageBox>
#include  <QTimeEdit>
#include <global.h>
#include <QDebug>
#include <QDate>
#include <QFile>
#include <QTextEdit>
AddNew::AddNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNew)
{
    ui->setupUi(this);
}

AddNew::~AddNew()
{
    delete ui;
}

void AddNew::on_checkD_stateChanged(int arg1)
{
    if (ui->checkD->isChecked() == true)
    {
     //ui->checkD->setChecked(true);
       ui->checkN->setChecked(false);
         ui->checkM->setChecked(false);
    }



}

void AddNew::on_checkN_stateChanged(int arg1)
{
    if (ui->checkN->isChecked() == true)
    {

       ui->checkD->setChecked(false);
         ui->checkM->setChecked(false);
    }
}

void AddNew::on_checkM_stateChanged(int arg1)
{
    if (ui->checkM->isChecked() == true)
    {

       ui->checkN->setChecked(false);
         ui->checkD->setChecked(false);
    }
}


void  AddNew::setitem(int dnm, QString dat,  QString tema,  QString op, QString zvon)
{

  global one;
//добавление новой строки в файл, где хранится весь этот бред
  QFile mFile("C:\\progQT\\kursachEpta\\"+ one.logos+".txt");
     if(!mFile.open(QFile::WriteOnly | QFile::Append | QFile::Text))
     {
         QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
         return;
     }
      QTextStream stream(&mFile);

        stream<<dnm<<"#";
         stream<<dat<<"#";
         stream<<"0"<<"#";
         stream<<tema<<"#";
         stream<<op<<"#";
         stream<<zvon<<"#";


stream<<"\n";

     stream.flush();
     mFile.close();


}
void AddNew::on_pushButton_clicked()
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


    setitem(id, dat, ui->lineEditName->text(),  ui->textEdit->text(), op);

       ui->checkM->setChecked(false);
    ui->checkN->setChecked(false);
      ui->checkD->setChecked(false);
      ui->opov->setChecked(false);
        ui->lineEditName->clear();
      ui->textEdit->clear();

      this->close();  //закрываем это окно
      emit newz(); //пода

     // ui->dateEditD->date() = "";
}
