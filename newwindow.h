#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QMainWindow>
#include "dop.h"


namespace Ui {
class NewWindow;
}

class NewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr);
    ~NewWindow();
      Dop MyTab;
      void daytab();
      void weektab();
    //  static QString Login;

    //Сигнал для главно формы при выходе
signals:
        void firstWindow();
     //   void newadd();
        //Переключение между платформами днм
private slots:
        void on_pushButton_clicked();
void newadd();
       void on_month_clicked();

        void on_day_clicked();

        void on_week_clicked();
        //
        //Представление таблицы дня
        //




        void on_UserBut_clicked();

        void on_UserBut_4_clicked();

        void on_UserBut_2_clicked();

        void on_UserBut_3_clicked();

        void on_dateEdit_userDateChanged(const QDate &date);

        void on_pushButton_15_clicked();
        void tabdelbl(QTableWidget *h);
        void monthtab();
        void on_pushButton_16_clicked();

        void on_pushButton_17_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_18_clicked();

        void on_pushButton_19_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_dateEdit_2_userDateChanged(const QDate &date);

        void on_dateEdit_3_userDateChanged(const QDate &date);

        void on_pushButton_22_clicked();
        void deleteAll();
        void checktask(QTableWidget *h);
        int countcheck(QTableWidget *h);
        void change(QTableWidget *h);

        void on_pushButton_24_clicked();

        void on_pushButton_14_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_21_clicked();

        void on_pushButton_23_clicked();

private:
    Ui::NewWindow *ui;
};

#endif // NEWWINDOW_H
