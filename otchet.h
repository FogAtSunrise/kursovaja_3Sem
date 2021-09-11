#ifndef OTCHET_H
#define OTCHET_H

#include <QDialog>

namespace Ui {
class Otchet;
}

class Otchet : public QDialog
{
    Q_OBJECT

public:
    explicit Otchet(QWidget *parent = nullptr);
    ~Otchet();

private:
    Ui::Otchet *ui;
};

#endif // OTCHET_H
