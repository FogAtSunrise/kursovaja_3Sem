#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newwindow.h"
#include "dop.h"
#include <global.h>
#include<QMessageBox>
#include  <QTableWidget>
#include <QFile>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


   // glob = 7;
    ui->setupUi(this);
     MyTab.inputy(); //заполняем дополнительную таблицу с учетными записями

   //это отерытие допдоп
    /* MyTab.setModal(true); //Открыть новое окно
   MyTab.exec();
*/

    ui->label_3->hide();//скрываем сообщение о
   ui->label_3->setStyleSheet("color: rgb(255, 36, 0)");

  ui->framevhod_2->hide();


  /*
 QString h = MyTab.getitem(0, 4);
QMessageBox::information(0, "  ", h);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

//вход, тобишь проверка введенного пароля и тд  и тп
void MainWindow::on_VhodButton_clicked()
{

     ui->label_3->hide();
   // ui->label_3->setStyleSheet("color: rgb(255, 36, 0)");

  /*  SecondWindow window;
    window.setModal(true); //Открыть новое окно
    window.exec();*/
   // hide();

    //Достаем содержимое полей логина и пароля
    QString login = ui->login->text();
   QString pass = ui->PassText->text();
   //осуществляется поиск логина в списке зарегестрированных пользователей
  int number = MyTab.finLog(login);//этот метод возвращает -1. если не найден логин, иначе - номер строки

   if (number >= 0)//ЛОГИН НАЙДЕН, ПОЛЬЗОВАТЕЛЬ СУЩЕСТВУЕТ
{
       if(pass == MyTab.getitem(number, 2))//ПРОВЕРКА ПАРОЛЯ
           //пароль совпал, заходим в учетную запись
       {
ui->login->clear();
ui->PassText->clear();
//NewWindow nr;

//NewWindow::number1 = 7;

global one;
  one.glob = number;
  one.logos = login;
  window = new NewWindow();
  //неведомая хрень, подключает это окно к кнопке на том окне
  connect (window, &NewWindow::firstWindow, this, &MainWindow::show);
       window -> show();
      this->close();}
       else
           //иначе выводим сообщение об ошибке
          {
    ui->label_3->show();
       }
   }
   else
      {
ui->label_3->show();
   }
}
//
//переходим к панели регистрации из панели входа
//
void MainWindow::on_pushButtonReg_clicked()
{

    ui->label_3->hide();
    ui->login->clear();
    ui->PassText->clear();
    ui->framevhod_2->show();


}
//
//переходим к панели входа от панели регистрации
//
void MainWindow::on_VhodButton_2_clicked()
{
            ui-> PassText_2->clear();
           ui->login_3->clear();
           ui-> login_2->clear();
            ui->framevhod_2->hide();

}


//открытие окна помощи
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(0, "Добро пожаловать в приложение \"Планировщик дел\"!", "Если у вас нет своей учетной записи, пройдите в меню \nрегистрации(нажать кнопку \"Регистрация\"), заполните \nвсе поля и нажмите кнопку регистрации. \nПри удачной регистрации высветится сообщение \"Учетная запись созда\", \nиначе появятся сообщения об ошибке.\nНиже приведены правила для корректного ввода данных\n\n- Ни одно из полей не может быть пустым или состоящим из одних пробелов\n-В каждой записи должно быть от 4 до 20 символов (пробелы не допускаются)\n-Ни одно поле не должно содержать символов \"#\", \"$\", \"%\"\n\n\n Если у вас уже есть учетная запись, то просто введите \nлогин и пароль и нажмите кнопку \"Войти\". \n\nДля выхода закройте окно");
}

//нажата кнопка регистрации на панели регистрации
void MainWindow::on_pushButtonReg_2_clicked()
{

    //отправка данных в метода добавления записи
    MyTab.setitem(ui->login_3->text(),  ui->login_2->text(),  ui->PassText_2->text());
    //создание файла для хранения задач пользователя
    QString filename = "C:\\progQT\\kursachEpta\\"+ui->login_2->text() + ".txt";
    QFile file(filename);
       if(!file.open(QFile::WriteOnly))
       {
           QMessageBox::information(this,tr("Message"),tr("Не удалось открыть файл"));
           return;
       }
    file.close();
    //очистка окон ввода
    ui-> PassText_2->clear();
   ui->login_3->clear();
   ui-> login_2->clear();
}
