#ifndef ADDNEW_H
#define ADDNEW_H

#include <QDialog>

namespace Ui {
class AddNew;
}

class AddNew : public QDialog
{
    Q_OBJECT

public:
    explicit AddNew(QWidget *parent = nullptr);
    ~AddNew();
signals:
    void newz();
private slots:

    void  setitem(int dnm, QString dat,  QString tema,  QString op, QString zvon);
    void on_checkD_stateChanged(int arg1);

    void on_checkN_stateChanged(int arg1);

    void on_checkM_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::AddNew *ui;
};

#endif // ADDNEW_H
