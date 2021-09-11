#include "newwindow.h"
#include "mainwindow.h"
#include "ui_newwindow.h"
#include <global.h>
#include  <QTabWidget>
#include  <QMessageBox>
#include  <user.h>
#include  <dop.h>
#include  "addnew.h"
#include  <addnew.h>
#include  <otchet.h>
#include<dialog.h>
#include <QFile>
#include <QDate>
#include <QDebug>

NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
  ui -> MonthPanel ->hide();
   ui -> weekPanel ->hide();

daytab();
weektab();
monthtab();
//daytab();

  //

/*
  MyTab.setModal(true); //Открыть новое окно
MyTab.exec();*/

//

// MyTab.tableWidget_2->item(1,1)->text();



    //ui->tableWidget->setRowCount(0);
  //ui->tableWidget->setColumnCount(5);
  //MainWindow::MyTab.show();
//  QString h = MyTab.getitem(0, 3);
 //QMessageBox::information(0, "  ", h);

}

NewWindow::~NewWindow()
{
    delete ui;
}




void NewWindow::monthtab()//заполнение таблицы месяца
{

    ui->tableWidget_5->clear();//очищаем таблицу
     ui->tableWidget_5->setRowCount(0);//обнуление колличества строк
    ui->tableWidget_4->clear();//очищаем таблицу
     ui->tableWidget_4->setRowCount(0);//обнуление колличества строк
     int count = MyTab.getcountrow();
     //получение даты текущей
     QDate data, data1;
      data.setDate(ui->dateEdit_3 ->date().year(), ui->dateEdit_3 ->date().month(), ui->dateEdit_3 ->date().day());
       QString datforM = ui-> dateEdit_3->date().toString("yyyy.MM");
          QString datforN=data.toString("yyyy.MM.dd");
        data1 = data.addDays(30);
        bool flag = false;
               QString  datebl="";

            for (int i = 0; i<count; i++)
            {
           if ( MyTab.getitem_2(i, 0)=="2")
           {
               QString str = MyTab.getitem_2(i, 1);
               //Делим строку на слова разделенные htitnrjq
               data.setDate(ui->dateEdit_3 ->date().year(), ui->dateEdit_3 ->date().month(), ui->dateEdit_3 ->date().day());
               while(data<data1)
               {   datforN=data.toString("yyyy.MM.dd");
                   if(datforN==str)
                      { flag = true;
                       break;
                            }
   data = data.addDays(+1);
           }


               if(flag)
               { QTableWidgetItem *item = new QTableWidgetItem();
                    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                    //ВОТ ТУТ ПРОВЕРКА ВЫПОЛНЕННОСТИ
                    item->setCheckState(Qt::Unchecked);

                     ui->tableWidget_4->setRowCount(ui->tableWidget_4->rowCount() + 1); //добавляем строчку
                    ui->tableWidget_4->setItem(ui->tableWidget_4->rowCount()-1, 0, item );
                    ui->tableWidget_4->setItem   ( ui->tableWidget_4->rowCount()-1, 1, new QTableWidgetItem(str));
                   ui->tableWidget_4->setItem   ( ui->tableWidget_4->rowCount()-1, 2, new QTableWidgetItem(MyTab.getitem_2(i, 3)));
                   if(MyTab.getitem_2(i, 2)=="1")
                   {
                       ui->tableWidget_4->item(ui->tableWidget_4->rowCount()-1, 0)->setBackground(Qt::green);
                       ui->tableWidget_4->item(ui->tableWidget_4->rowCount()-1, 1)->setBackground(Qt::green);
                       ui->tableWidget_4->item(ui->tableWidget_4->rowCount()-1, 2)->setBackground(Qt::green);
                   }
        flag = false;

               }

           }

           if ( MyTab.getitem_2(i, 0)=="3")
           {
          datebl = MyTab.getitem_2(i, 1);

                     if(datforM==datebl)
                    { QTableWidgetItem *item = new QTableWidgetItem();
                    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                    //ВОТ ТУТ ПРОВЕРКА ВЫПОЛНЕННОСТИ
                    item->setCheckState(Qt::Unchecked);

                     ui->tableWidget_5->setRowCount(ui->tableWidget_5->rowCount() + 1); //добавляем строчку
                    ui->tableWidget_5->setItem(ui->tableWidget_5->rowCount()-1, 0, item );
                    ui->tableWidget_5->setItem   ( ui->tableWidget_5->rowCount()-1, 1, new QTableWidgetItem(datebl));
                   ui->tableWidget_5->setItem   ( ui->tableWidget_5->rowCount()-1, 2, new QTableWidgetItem(MyTab.getitem_2(i, 3)));
                   if(MyTab.getitem_2(i, 2)=="1")
                   {
                       ui->tableWidget_5->item(ui->tableWidget_5->rowCount()-1, 0)->setBackground(Qt::green);
                       ui->tableWidget_5->item(ui->tableWidget_5->rowCount()-1, 1)->setBackground(Qt::green);
                       ui->tableWidget_5->item(ui->tableWidget_5->rowCount()-1, 2)->setBackground(Qt::green);
                   }
        flag = false;

               }

           }
            }

    //   ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    //   ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(datstr));


            ui-> tableWidget_5->resizeColumnToContents(0);
            QStringList name_table;
                name_table << " " << "Дата" << "Задача";
                ui->tableWidget_5->setHorizontalHeaderLabels(name_table);
     ui-> tableWidget_4->resizeColumnToContents(0);
         ui->tableWidget_4->setHorizontalHeaderLabels(name_table);


}



void NewWindow::weektab()//заполнение таблицы недели
{

    ui->tableWidget_2->clear();//очищаем таблицу
     ui->tableWidget_2->setRowCount(0);//обнуление колличества строк
    ui->tableWidget_3->clear();//очищаем таблицу
     ui->tableWidget_3->setRowCount(0);//обнуление колличества строк
     int count = MyTab.getcountrow();

     //получение даты текущей
     QDate data, data1;
      data.setDate(ui->dateEdit_2 ->date().year(), ui->dateEdit_2 ->date().month(), ui->dateEdit_2 ->date().day());
       QString datstr=data.toString("yyyy.MM.dd");
        data1 = data.addDays(+7);
        bool flag = false;
               QString timebl = "", datebl="";

            for (int i = 0; i<count; i++)
            {
           if ( MyTab.getitem_2(i, 0)=="1")
           {
               QString str = MyTab.getitem_2(i, 1);
               //Делим строку на слова разделенные htitnrjq
               QStringList lst = str.split(" ");
               datebl = lst.at(0);
               timebl = lst.at(1);
               data.setDate(ui->dateEdit_2 ->date().year(), ui->dateEdit_2 ->date().month(), ui->dateEdit_2 ->date().day());
               while(data<data1)
               {   datstr=data.toString("yyyy.MM.dd");
                   if(datstr==datebl)
                      { flag = true;
                       break;
                            }
   data = data.addDays(+1);
           }


               if(flag)
               { QTableWidgetItem *item = new QTableWidgetItem();
                    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                    //ВОТ ТУТ ПРОВЕРКА ВЫПОЛНЕННОСТИ
                    item->setCheckState(Qt::Unchecked);

                     ui->tableWidget_3->setRowCount(ui->tableWidget_3->rowCount() + 1); //добавляем строчку
                    ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1, 0, item );
                    ui->tableWidget_3->setItem   ( ui->tableWidget_3->rowCount()-1, 1, new QTableWidgetItem(timebl+" "+datebl));
                   ui->tableWidget_3->setItem   ( ui->tableWidget_3->rowCount()-1, 2, new QTableWidgetItem(MyTab.getitem_2(i, 3)));
                   if(MyTab.getitem_2(i, 2)=="1")
                   {
                       ui->tableWidget_3->item(ui->tableWidget_3->rowCount()-1, 0)->setBackground(Qt::green);
                       ui->tableWidget_3->item(ui->tableWidget_3->rowCount()-1, 1)->setBackground(Qt::green);
                       ui->tableWidget_3->item(ui->tableWidget_3->rowCount()-1, 2)->setBackground(Qt::green);
                   }
        flag = false;

               }

           }

           if ( MyTab.getitem_2(i, 0)=="2")
           {
          datebl = MyTab.getitem_2(i, 1);

               data.setDate(ui->dateEdit_2 ->date().year(), ui->dateEdit_2 ->date().month(), ui->dateEdit_2 ->date().day());
               while(data<data1)
               {   datstr=data.toString("yyyy.MM.dd");
                   if(datstr==datebl)
                      { flag = true;
                       break;
                            }
   data = data.addDays(+1);
           }


               if(flag)
               { QTableWidgetItem *item = new QTableWidgetItem();
                    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                    //ВОТ ТУТ ПРОВЕРКА ВЫПОЛНЕННОСТИ
                    item->setCheckState(Qt::Unchecked);

                     ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() + 1); //добавляем строчку
                    ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1, 0, item );
                    ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 1, new QTableWidgetItem(datebl));
                   ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 2, new QTableWidgetItem(MyTab.getitem_2(i, 3)));
                   if(MyTab.getitem_2(i, 2)=="1")
                   {
                       ui->tableWidget_2->item(ui->tableWidget_2->rowCount()-1, 0)->setBackground(Qt::green);
                       ui->tableWidget_2->item(ui->tableWidget_2->rowCount()-1, 1)->setBackground(Qt::green);
                       ui->tableWidget_2->item(ui->tableWidget_2->rowCount()-1, 2)->setBackground(Qt::green);
                   }
        flag = false;

               }

           }
            }

    //   ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    //   ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(datstr));


            ui-> tableWidget_2->resizeColumnToContents(0);
            QStringList name_table;
                name_table << " " << "Дата" << "Задача";
                ui->tableWidget_2->setHorizontalHeaderLabels(name_table);
     ui-> tableWidget_3->resizeColumnToContents(0);
         ui->tableWidget_3->setHorizontalHeaderLabels(name_table);


}


void NewWindow::daytab()//заполнение таблицы дня
{
    int count = MyTab.inputy_two();//таблица с задачами перезаполнение

    ui->tableWidget->clear();//очищаем таблицу

     ui->tableWidget->setRowCount(0);//обнуление колличества строк

     //получение даты текущей
     QDate data;
      data.setDate(ui->dateEdit ->date().year(), ui->dateEdit ->date().month(), ui->dateEdit ->date().day());
       QString datstr=data.toString("yyyy.MM.dd");


    //   ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    //   ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(datstr));

bool flag = false;
       QString timebl = "", datebl="";

    for (int i = 0; i<count; i++)
    {
   if ( MyTab.getitem_2(i, 0)=="1")
   {
       QString str = MyTab.getitem_2(i, 1);
       //Делим строку на слова разделенные htitnrjq
       QStringList lst = str.split(" ");
       datebl = lst.at(0);
       timebl = lst.at(1);
       if(datstr==datebl)
           flag = true;

       if(flag)
       { QTableWidgetItem *item = new QTableWidgetItem();
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            //ВОТ ТУТ ПРОВЕРКА ВЫПОЛНЕННОСТИ
            item->setCheckState(Qt::Unchecked);

             ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1); //добавляем строчку
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, item );

            ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(timebl));
           ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(MyTab.getitem_2(i, 3)));
           if(MyTab.getitem_2(i, 2)=="1")
           {
               ui->tableWidget->item(ui->tableWidget->rowCount()-1, 0)->setBackground(Qt::green);
               ui->tableWidget->item(ui->tableWidget->rowCount()-1, 1)->setBackground(Qt::green);
               ui->tableWidget->item(ui->tableWidget->rowCount()-1, 2)->setBackground(Qt::green);
           }
flag = false;

       }

   }


    }
     ui-> tableWidget->resizeColumnToContents(0);
     QStringList name_table;
         name_table << " " << "Время" << "Задача";
         ui->tableWidget->setHorizontalHeaderLabels(name_table);
/*

    QDate data;
    data.setDate(ui->dateEdit ->date().year(), ui->dateEdit ->date().month(), ui->dateEdit ->date().day());
    QString datstr=data.toString("yyyy.MM.dd");
    */
/*
    QString str = "1999.03.12";
 QDate data1 = QDate::fromString(str, "yyyy.MM.dd");
  datstr=data1.toString("yyyy.MM.dd");
 ui->dateEdit ->date() = data1;
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

    ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(datstr));
    ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(str));
*/

    //СТОЛБЕЦ ЧЕКБОКСОВ

   /*   const int ROW_COUNT = ui->tableWidget->rowCount();
      for (int i = 0; i < ROW_COUNT; ++i) {
         QTableWidgetItem *item = new QTableWidgetItem();
         item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
         item->setCheckState(Qt::Unchecked);
         ui->tableWidget->setItem( i, 0, item );
      }
   ui-> tableWidget->resizeColumnToContents(0);
   */


}

void NewWindow::on_pushButton_clicked()
{

    this->close();  //закрываем это окно
    emit firstWindow(); //подаем сигнал первому окну, чтоб открывалось
}

//переход к панели месяца
void NewWindow::on_month_clicked()
{

  ui->dayPanel->show();
  ui -> MonthPanel ->show();
  ui -> weekPanel ->show();
}
//переход к панели дня
void NewWindow::on_day_clicked()
{
    ui->dayPanel->show();
    ui -> MonthPanel ->hide();
    ui -> weekPanel ->hide();
}
//переход к панели недели
void NewWindow::on_week_clicked()
{
    ui->dayPanel->show();
    ui -> MonthPanel ->hide();
    ui -> weekPanel ->show();
}


void NewWindow::on_UserBut_clicked()
{
   User j;
     j.setModal(true); //Открыть новое окно
    j.exec();
}


//открыть окно помощи в учетной записи
void NewWindow::on_UserBut_4_clicked()
{
    QMessageBox::information(0, "Вы находитесь на главной странице своей учетной записи.", "\n1. Чтобы изменить данные о пользоветеле или удалить учетную запись нажмите \nкнопку \"Пользователь\". Откроется новое окно, в котором можно изменить имя, логин и пароль \nпольователя, а также удалить учетную запись, нажав кнопку \"Удалить учетную запись\". \n2. Чтобы создать отчет, нажмите кнопку \"Создать отчет\", в новом окне выберите промежуток \nвремени (также можно автоматически распечатать все выполненные дела за все время) и название файла, \nв который сохранить отчет. Нажмите кнопку \"Создать\". \n3.Чтобы добавить задачу, нажмите кнопку \"добавить задачу\", заполните все поля в новом окне и нажмите \"Добавить\". \nНиже приведены правила для корректного ввода данных\n\n- Ни одно из полей не может быть пустым или состоящим из одних пробелов\n-В каждой записи должно быть от 4 до 20 символов (пробелы не допускаются)\n-Ни одно поле не должно содержать символов \"#\", \"$\", \"%\"");
}

//переход к окну добавления задачи

void NewWindow::on_UserBut_2_clicked()
{
    AddNew *j = new AddNew();
    connect(j, &AddNew::newz, this, &NewWindow::newadd);
    //  j.setModal(true); //Открыть новое окно
    j->show();
   j->exec();
}
void NewWindow::newadd()
{
    daytab();
    weektab();
    monthtab();
}
//переходи в окно создание отчета
void NewWindow::on_UserBut_3_clicked()
{
    Otchet j;
      j.setModal(true); //Открыть новое окно
     j.exec();
}


//изменение даты для первой таблицы

void NewWindow::on_dateEdit_userDateChanged(const QDate &date)
{
daytab();
}
//change date for week
void NewWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
    weektab();
}
//change date for month
void NewWindow::on_dateEdit_3_userDateChanged(const QDate &date)
{
    monthtab();
}
//
//удаление отмеченой строки из таблицы
//
void NewWindow::tabdelbl(QTableWidget *h)
{
    int count =  h->rowCount(); //количество строк в таблице
    for (int i = 0; i < count; i++)
    {
        if(h->item(i,0)->checkState() == Qt::Checked)
    {
            MyTab.delstr(h->item(i,2)->text());
          h->removeRow(i);
          count--;
          i--;
        }
    }
}

//удалить для первой таблицы, тобишь таблица дня
void NewWindow::on_pushButton_15_clicked()
{
    tabdelbl(ui->tableWidget);

/*
    if(ui->tableWidget->item(0,0)->checkState() == Qt::Checked)
        QMessageBox::information(0, "  ", "yes");
        else
            QMessageBox::information(0, "  ", "no");
*/
}
//удаление на неделе
void NewWindow::on_pushButton_22_clicked()
{
     tabdelbl(ui->tableWidget_2);
      tabdelbl(ui->tableWidget_3);
}
//удаление на месяце
void NewWindow::on_pushButton_24_clicked()
{
    tabdelbl(ui->tableWidget_4);
     tabdelbl(ui->tableWidget_5);
}
//выполнить для отмеченных
void NewWindow::checktask(QTableWidget *h)
{
    int count =  h->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {

        if(h->item(i,0)->checkState() == Qt::Checked)
    {
           MyTab.checkV(h->item(i,2)->text());
            h->item(i, 0)->setBackground(Qt::green);
            h->item(i, 1)->setBackground(Qt::green);
            h->item(i, 2)->setBackground(Qt::green);
            h->item(i,0)->setCheckState(Qt::Unchecked);
        }
    }

}
//выполнить для первой таблицы
void NewWindow::on_pushButton_16_clicked()
{
    checktask(ui->tableWidget);
}

//выполнить для недели
void NewWindow::on_pushButton_21_clicked()
{
    checktask(ui->tableWidget_2);
    checktask(ui->tableWidget_3);
}
//выполнить для недели
void NewWindow::on_pushButton_23_clicked()
{
    checktask(ui->tableWidget_4);
    checktask(ui->tableWidget_5);
}
//
//количество отмеченных
int NewWindow::countcheck(QTableWidget *h)
{
    int g = 0;
    int count =  h->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {
        if(h->item(i,0)->checkState() == Qt::Checked)
    {
          g++;
        }
    }

    return g;
}
//
//изменение отмеченных
//
void NewWindow::change(QTableWidget *h)
{global One;
    int count =  h->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {

        if(h->item(i,0)->checkState() == Qt::Checked)
    {

              One.change1 = h->item(i,2)->text();

          break;
        }
    }
      Dialog *j= new Dialog();
     // Dialog j;
     connect(j, &Dialog::newzz, this, &NewWindow::newadd);
    // j.show();
       j->setModal(true); //Открыть новое окно
    j->exec();
   //  j.exec();
}
//изменить
void NewWindow::on_pushButton_17_clicked()
{
   if (countcheck(ui->tableWidget)==1)
   {
      change(ui->tableWidget);
   }
   else
        //QMessageBox::information(0, "  ", h);
    QMessageBox::critical(0, "Ошибка", "Надо отметить одну запись!!!");
}




//включит оповещения
void NewWindow::on_pushButton_2_clicked()
{
//opovest(QString z, QString mean)
    if(ui->tableWidget->item(0,0)->checkState() == Qt::Checked)
        QMessageBox::information(0, "  ", "yes");
        else
            QMessageBox::information(0, "  ", "no");
}

//выключить оповещения
void NewWindow::on_pushButton_18_clicked()
{
    if(ui->tableWidget->item(0,0)->checkState() == Qt::Checked)
        QMessageBox::information(0, "  ", "yes");
        else
            QMessageBox::information(0, "  ", "no");
}

//включить все оповещения
void NewWindow::on_pushButton_19_clicked()
{

}
//выключить все оповещения
void NewWindow::on_pushButton_3_clicked()
{

}

void NewWindow::deleteAll()
{
    global one;
QString filename = "C:\\progQT\\kursachEpta\\"+one.logos + ".txt";
    QFile file(filename);
    //QFile file("./kursachEpta/Data.txt");
        file.open(QIODevice::WriteOnly |QIODevice::Truncate);
        file.close();
        daytab();
        weektab();
        monthtab();
}

//удалить dсе for day
void NewWindow::on_pushButton_4_clicked()
{
 deleteAll();
}
//for week
void NewWindow::on_pushButton_7_clicked()
{
           deleteAll();
    }
//for month
void NewWindow::on_pushButton_14_clicked()
{
    deleteAll();
}








