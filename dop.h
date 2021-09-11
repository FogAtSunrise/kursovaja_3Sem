#ifndef DOP_H
#define DOP_H

#include <QDialog>
#include  <QTabWidget>
#include  <QTableWidget>

namespace Ui {
class Dop;
}

class Dop : public QDialog
{
    Q_OBJECT

public:

    explicit Dop(QWidget *parent = nullptr);
    ~Dop();
public:
 void inputy();
 int inputy_two();
QString getitem(int i, int j);
QString getitem_2(int i, int j);
void Setitem_2(int i, int j, QString d);
void Setitem(int i, int j, QString d);
void setitem(QString n,  QString l,  QString p);
void setitem_2(int dnm, QString dat,  QString tema,  QString op, QString zvon);
void outputy();
void opovest(QString z, QString mean);
int numberstr(QString z);
void outputy_2();
void delstr(QString z);
void checkV(QString z);
int getcountrow();
int finLog(QString log);
   //QTableWidget *tableWidget;
public:
    Ui::Dop *ui;
private slots:

};

#endif // DOP_H
