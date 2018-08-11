#ifndef GLAVNIPROZOR_H
#define GLAVNIPROZOR_H

#include <QWidget>

namespace Ui {
class GlavniProzor;
}

class GlavniProzor : public QWidget
{
    Q_OBJECT

public:
    explicit GlavniProzor(QWidget *parent = nullptr);
    ~GlavniProzor();

private:
    Ui::GlavniProzor *ui;
};

#endif // GLAVNIPROZOR_H
