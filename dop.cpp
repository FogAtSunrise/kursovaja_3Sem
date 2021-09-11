#include "dop.h"
#include "ui_dop.h"
#include <global.h>
#include  <QTabWidget>
#include  <QMessageBox>
#include  <QTableWidget>
#include <QFile>
#include <QDebug>
#include <QDate>
Dop::Dop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dop)
{
    ui->setupUi(this);
 //inputy();//заполнение таблицы с паролями
//inputy_two();//заполнение  таблицы с данными
}

Dop::~Dop()
{
    delete ui;
}

//метод - получение значения заданной ячейки
QString Dop::getitem(int i, int j)
{
    return ui->tableWidget->item(i,j)->text();
}

//метод задает значение указанной ячейке
void Dop::Setitem(int i, int j, QString d)
{
   ui->tableWidget->setItem   ( i, j, new QTableWidgetItem(d));
}

//создает новую сроку для даннных новой учетной записи
void Dop::setitem(QString n,  QString l,  QString p)
{
   ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);//количество строк увеличиваем
  int count  = ui->tableWidget->rowCount()-1;
  QDate cd = QDate::currentDate();//объект класса даты для получения текущей даты

  //заполнение строки дополнительной таблицы
  Setitem(count, 0, "0");
  Setitem(count, 1, l);
  Setitem(count, 2, p);
  Setitem(count, 3, n);
  Setitem(count, 4, cd.toString("dd.MM.yyyy"));
//добавление новой строки в файл, где хранится весь этот бред
  QFile mFile("C:\\progQT\\kursachEpta\\Data.txt");
     if(!mFile.open(QFile::WriteOnly | QFile::Append | QFile::Text))
     {
         QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
         return;
     }
      QTextStream stream(&mFile);

      for (int j = 0; j<5; j++)
         {
        stream<<ui->tableWidget->item(count,j)->text()<<"#";
         }

stream<<"\n";

     stream.flush();
     mFile.close();

}

//в этод метод отправляется логин введенный пользователем, логин ищется в таблице, если он есть, то метод возращает номер строки, в которой найден логин, иначе возвращает -1
int Dop::finLog(QString log)
{
    inputy();
    bool f = false;
    int number = 0;
    int count  = ui->tableWidget->rowCount();
    for (int i = 0; i<count; i++)
    {
       if (log == ui->tableWidget->item(i,1)->text())
       {
           f = true;
           number = i;
           break;  }
    }

    if(f)
        return number;
    else return -1;

}

//метод для перезаписвания файла, не знаю, буду ли использовать, но пусть останется на случай глобальных изменений
void Dop::outputy()
{
    QFile mFile("C:\\progQT\\kursachEpta\\Data.txt");

       if(!mFile.open(QFile::WriteOnly | QIODevice::WriteOnly | QFile::Text))
       {
           QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
           return;
       }

       //колличество строк в таблице
       int count  = ui->tableWidget->rowCount();

       //
       QTextStream stream(&mFile);
       for (int i = 0; i<count; i++)
       { for (int j = 0; j<5; j++)

           {
          stream<<ui->tableWidget->item(i,j)->text()<<"#";
           }
           stream<<"\n";
       }

       stream.flush();
       mFile.close();
}

int Dop::getcountrow()
{
    return ui->tableWidget_2->rowCount();
}
//
//заполнение таблицы с паролем
//
void Dop::inputy()
{

    QFile file("C:\\progQT\\kursachEpta\\Data.txt");
    //QFile file("./kursachEpta/Data.txt");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!file.atEnd())
            {
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                //читаем строку
                QString str = file.readLine();
                //Делим строку на слова разделенные htitnrjq
                QStringList lst = str.split("#");
                ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(lst.at(0)));
                ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(lst.at(1)));
                ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(lst.at(2)));
                ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(lst.at(3)));
                ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(lst.at(4)));
                  // выводим первых три слова
               // qDebug() << lst.at(0) << lst.at(1)<<lst.at(2);
            }

        }
        else
        {
            qDebug()<< "don't open file";
        }
}
//
//заполнение второй таблицы с записями
//
int Dop::inputy_two()
{
    ui->tableWidget_2->clear();//очищаем таблицу

     ui->tableWidget_2->setRowCount(0);//обнуление колличества строк
    global one;
QString filename = "C:\\progQT\\kursachEpta\\"+one.logos + ".txt";
    QFile file(filename);
    //QFile file("./kursachEpta/Data.txt");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!file.atEnd())
            {
                ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() + 1);
                //читаем строку
                QString str = file.readLine();
                //Делим строку на слова разделенные htitnrjq
                QStringList lst = str.split("#");
                ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 0, new QTableWidgetItem(lst.at(0)));
                  ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 1, new QTableWidgetItem(lst.at(1)));
                    ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 2, new QTableWidgetItem(lst.at(2)));
                      ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 3, new QTableWidgetItem(lst.at(3)));
                        ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 4, new QTableWidgetItem(lst.at(4)));
                          ui->tableWidget_2->setItem   ( ui->tableWidget_2->rowCount()-1, 5, new QTableWidgetItem(lst.at(5)));

                  // выводим первых три слова
               // qDebug() << lst.at(0) << lst.at(1)<<lst.at(2);
            }

        }
        else
        {
            qDebug()<< "don't open file";
        }
        return ui->tableWidget_2->rowCount();
}

//метод - получение значения заданной ячейки
QString Dop::getitem_2(int i, int j)
{
    return ui->tableWidget_2->item(i,j)->text();
}

//метод задает значение указанной ячейке
void Dop::Setitem_2(int i, int j, QString d)
{
   ui->tableWidget_2->setItem   ( i, j, new QTableWidgetItem(d));
}

//создает новую сtроку для даннных
void Dop::setitem_2(int dnm, QString dat,  QString tema,  QString op, QString zvon)
{
  ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() + 1);//количество строк увеличиваем
  int count  = ui->tableWidget_2->rowCount()-1;
  //QDate cd = QDate::currentDate();//объект класса даты для получения текущей даты
   Setitem(count, 0, QString::number(dnm));
  Setitem(count, 1, dat);
  Setitem(count, 2, "0");
  Setitem(count, 3, tema);
  Setitem(count, 4, op);
  Setitem(count, 5, zvon);
  global one;
//добавление новой строки в файл, где хранится весь этот бред
  QFile mFile("C:\\progQT\\kursachEpta\\"+ one.logos+".txt");
     if(!mFile.open(QFile::WriteOnly | QFile::Append | QFile::Text))
     {
         QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
         return;
     }
      QTextStream stream(&mFile);

      for (int j = 0; j<6; j++)
         {
        stream<<ui->tableWidget->item(count,j)->text()<<"#";
         }

stream<<"\n";

     stream.flush();
     mFile.close();


}


void Dop::outputy_2()
{
    global one;
    QString filename = "C:\\progQT\\kursachEpta\\"+one.logos + ".txt";
    QFile mFile(filename);
       if(!mFile.open(QFile::WriteOnly | QIODevice::WriteOnly | QFile::Text))
       {
           QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
           return;
       }
       int count  = ui->tableWidget_2->rowCount();
       QTextStream stream(&mFile);
       for (int i = 0; i<count; i++)
       { for (int j = 0; j<6; j++)

           {
          stream<<ui->tableWidget_2->item(i,j)->text()<<"#";
           }
           stream<<"\n";
       }

       stream.flush();
       mFile.close();
}


int Dop::numberstr(QString z)
{


    int count =  ui->tableWidget_2->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {
        if(ui->tableWidget_2->item(i,3)->text() == z)
    {
          return i;
        }
    }
return -1;
}

//

//удаление строки
//
void Dop::delstr(QString z)
{


    int count =  ui->tableWidget_2->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {
        if(ui->tableWidget_2->item(i,3)->text() == z)
    {
          ui->tableWidget_2->removeRow(i);
      break;
        }
    }
outputy_2();
}

//оповещения
void Dop::opovest(QString z, QString mean)
{


    int count =  ui->tableWidget_2->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {
        if(ui->tableWidget_2->item(i,3)->text() == z)
    {
         ui->tableWidget_2->setItem(i, 5, new QTableWidgetItem(mean));
    }
    }
outputy_2();
    }

//выполнить
void Dop::checkV(QString z)
{


    int count =  ui->tableWidget_2->rowCount(); //количество строк в таблице

    for (int i = 0; i < count; i++)
    {
        if(ui->tableWidget_2->item(i,3)->text() == z)
    {
       // ui->tableWidget_2->item(i,2)->text() = "1";
         ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem("1"));
    }
    }
outputy_2();
    }
//в этод метод
/*int Dop::finLog(QString log)
{
    inputy();
    bool f = false;
    int number = 0;
    int count  = ui->tableWidget->rowCount();
    for (int i = 0; i<count; i++)
    {
       if (log == ui->tableWidget->item(i,1)->text())
       {
           f = true;
           number = i;
           break;  }
    }

    if(f)
        return number;
    else return -1;

}*/
//
//
//
//метод для перезаписвания файла, не знаю, буду ли использовать, но пусть останется на случай глобальных изменений
/*void Dop::outputy()
{
    QFile mFile("C:\\progQT\\kursachEpta\\Data.txt");
       if(!mFile.open(QFile::WriteOnly | QIODevice::WriteOnly | QFile::Text))
       {
           QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
           return;
       }
       int count  = ui->tableWidget->rowCount();
       QTextStream stream(&mFile);
       for (int i = 0; i<count; i++)
       { for (int j = 0; j<5; j++)

           {
          stream<<ui->tableWidget->item(i,j)->text()<<"#";
           }
           stream<<"\n";
       }

       stream.flush();
       mFile.close();
}*/
