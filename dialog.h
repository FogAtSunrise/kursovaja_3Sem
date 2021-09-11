#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "dop.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
 Dop MyTab;
private slots:
    void on_pushButton_clicked();
    void on_checkD_stateChanged(int arg1);
       void on_checkN_stateChanged(int arg1);
          void on_checkM_stateChanged(int arg1);
signals:
          void newzz();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
