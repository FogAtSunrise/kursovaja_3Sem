#include "otchet.h"
#include "ui_otchet.h"

Otchet::Otchet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Otchet)
{
    ui->setupUi(this);
}

Otchet::~Otchet()
{
    delete ui;
}
